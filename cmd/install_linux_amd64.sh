#!/bin/bash

# This script will install the libraries needed by gopjrt for Linux/amd64 OS/Platform (also works in Windows+WSL)
#
# - XlaBuilder C wrapper library (and corresponding .h files)
# - CPU PJRT plugin for gopjrt, the thing that actually does the JIT-compilation.
#
# Arguments (environment variables):
#
# - GOPJRT_INSTALL_DIR: if not empty, defines the directory where to install the library. If empty, it install into `/usr/local`.
#   Notice that ${GOPJRT_INSTALL_DIR}/lib must be set in your LD_LIBRARY_CONF -- `/usr/local/lib` usually is included in the path.
# - GOPJRT_NOSUDO: if not empty, it prevents using sudo to install.
#
# Check install_cuda.sh to additionally install the PJRT plugin for CUDA -- for NVidia GPU support.
#
# To execute this without cloning the repository, one can do:
#
# curl -sSf https://raw.githubusercontent.com/gomlx/gopjrt/main/cmd/install_linux_amd64.sh | bash
#
# See: https://github.com/gomlx/gopjrt?#installing
set -e

PLATFORM="linux_amd64"

# Base installation directory:
GOPJRT_INSTALL_DIR="${GOPJRT_INSTALL_DIR:-/usr/local}"
echo "Installing GoPJRT C/C++ dependencies under ${GOPJRT_INSTALL_DIR} (lib/ and include/ sub-directories)"
echo "  - Set GOPJRT_INSTALL_DIR if you want another directory."

# Should it use 'sudo' while installing ?
_SUDO="sudo"
if [[ "${GOPJRT_NOSUDO}" != "" ]] ; then
  echo "  - Not using sudo during installation, disabled with GOPJRT_NOSUDO != ''."
  _SUDO=""
elif command -v sudo > /dev/null ; then
  echo "  - Using sudo when extracting files to final destination (Set GOPJRT_NOSUDO=1 if you don't want sudo to be used)"
else
  echo "  - Not using sudo during installation, no program 'sudo' found in PATH."
  _SUDO=""
fi

# Fetch address of resources for latest release:
download_urls=$(mktemp --tmpdir gopjrt_urls.XXXXXXXX)
curl -s https://api.github.com/repos/gomlx/gopjrt/releases/latest \
  | grep "browser_download_url" \
  | egrep -wo "https.*gz" \
  > ${download_urls}

# Download XlaBuilder C wrapper library and PJRT CPU plugin.
url="$(grep gomlx_xlabuilder_${PLATFORM}.tar.gz "${download_urls}" | head -n 1)"
printf "\nDownloading PJRT CPU plugin from ${url}\n"

mkdir -p "${GOPJRT_INSTALL_DIR}"
pushd "${GOPJRT_INSTALL_DIR}"

tar_file=$(mktemp --tmpdir gopjrt_${PLATFORM}.XXXXXXXX)
curl -L "${url}" > "${tar_file}"

if [[ "${_SUDO}" != "" ]] ; then
  echo "Checking sudo authorization for installation"
  ${_SUDO} printf "\tsudo authorized\n"
fi

list_files=$(mktemp --tmpdir gopjrt_list_files.XXXXXXXX)
${_SUDO} tar xvzf "${tar_file}" > "${list_files}"
ls -lhd $(cat "${list_files}")

# Clean up temporary files.
rm -f "${tar_file}" "${list_files}"

# Remove older version using dynamically linked library -- it would be picked up on this otherwise and fail to link.
# (Remove these lines after v0.5.x).
${_SUDO} rm -f "lib/libgomlx_xlabuilder.so"

popd

echo "Done."
rm -f "${download_urls}"
