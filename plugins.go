package gopjrt

/*
#include "pjrt_c_api.h"
#include "gen_new_struct.h"
#include "gen_api_calls.h"

*/
import "C"
import (
	"fmt"
	"github.com/pkg/errors"
)

// Plugin represents a loaded PJRT plugin that can be used to compile and execute StableHLO code.
//
// Loaded plugins are singletons per platform and cached (GetPlugin will return a pointer to the same plugin if
// called with the same platform or its aliases).
//
// Plugins are searched in the PJRT_PLUGIN_LIBRARY_PATH directory -- or directories, if it is a ":" separated list.
//
// Design document: https://docs.google.com/document/d/1Qdptisz1tUPGn1qFAVgCV2omnfjN01zoQPwKLdlizas/edit
type Plugin struct {
	name, path string
	api        *C.PJRT_Api
}

// pjrtPluginInitialize calls C.PJRT_Plugin_Initialize
func pjrtPluginInitialize(plugin *Plugin) error {
	args := C.new_PJRT_Plugin_Initialize_Args()
	defer cFree(args)
	args.extension_start = nil
	return toError(plugin, C.call_PJRT_Plugin_Initialize(plugin.api, args))
}

// newPlugin creates a new plugin from the api pointer.
// Internal: use GetPlugin instead.
func newPlugin(name, pluginPath string, api *C.PJRT_Api) (*Plugin, error) {
	plugin := &Plugin{name: name, path: pluginPath, api: api}
	err := pjrtPluginInitialize(plugin)
	if err != nil {
		return nil, errors.WithMessagef(err, "initializing PJRT Plugin %s", name)
	}
	return plugin, nil
}

// GetPlugin returns the plugin with the given name -- typically it reflect the platform, e.g: "cpu" or "gpu".
//
// Loaded plugins are singletons and cached (GetPlugin will return a pointer to the same plugin if
// called with the same name or its aliases).
//
// Plugins are searched in the PJRT_PLUGIN_LIBRARY_PATH directory -- or directories, if it is a ":" separated list.
// If it is not set it will search in `/usr/local/lib/gomlx` and the standard libraries directories of the
// system (in linux in LD_LIBRARY_CONFIG and /etc/ld.so.conf file).
func GetPlugin(name string) (*Plugin, error) {
	return loadNamedPlugin(name)
}

// Name returns the name of the plugin, usually it reflects its platform (cpu, gpu, tpu, etc.).
func (p *Plugin) Name() string {
	return p.name
}

// Path returns the path from where the plugin was loaded.
func (p *Plugin) Path() string {
	return p.path
}

// Version returns the version reported by the loaded plugin.
func (p *Plugin) Version() (major, minor int) {
	return int(p.api.pjrt_api_version.major_version), int(p.api.pjrt_api_version.minor_version)
}

// String implements fmt.Stringer. It returns the platform and version of the plugin.
func (p *Plugin) String() string {
	major, minor := p.Version()
	if p.path == p.name {
		return fmt.Sprintf("PJRT plugin (%s) v%d.%d", p.Path(), major, minor)
	}
	return fmt.Sprintf("PJRT %q plugin (%s) v%d.%d", p.Name(), p.Path(), major, minor)
}
