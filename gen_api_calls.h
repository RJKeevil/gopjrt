
/***** File generated by ./cmd/codegen, don't edit it directly. *****/

#ifndef GOMLX_GOPJRT_GEN_API_CALLS
#define GOMLX_GOPJRT_GEN_API_CALLS
#include "pjrt_c_api.h"

#ifdef __cplusplus
extern "C" {
#endif

// call_PJRT_Error_Destroy calls the corresponding PJRT API method.
// Frees `error`. `error` can be nullptr.
extern void call_PJRT_Error_Destroy(const PJRT_Api *api, PJRT_Error_Destroy_Args* args);

// call_PJRT_Error_Message calls the corresponding PJRT API method.
// Gets the human-readable reason for `error`. `message` has the lifetime of
// `error`.
extern void call_PJRT_Error_Message(const PJRT_Api *api, PJRT_Error_Message_Args* args);

// call_PJRT_Error_GetCode calls the corresponding PJRT API method.
extern PJRT_Error* call_PJRT_Error_GetCode(const PJRT_Api *api, PJRT_Error_GetCode_Args* args);

// call_PJRT_Plugin_Initialize calls the corresponding PJRT API method.
// One-time plugin setup. Must be called before any other functions are called.
extern PJRT_Error* call_PJRT_Plugin_Initialize(const PJRT_Api *api, PJRT_Plugin_Initialize_Args* args);

// call_PJRT_Plugin_Attributes calls the corresponding PJRT API method.
// Returns an array of plugin attributes which are key-value pairs. One example
// attribute is the minimum supported StableHLO version.
// TODO(b/280349977): standardize the list of attributes.
extern PJRT_Error* call_PJRT_Plugin_Attributes(const PJRT_Api *api, PJRT_Plugin_Attributes_Args* args);

// call_PJRT_Event_Destroy calls the corresponding PJRT API method.
// Frees `event`. `event` can be `nullptr`.
extern PJRT_Error* call_PJRT_Event_Destroy(const PJRT_Api *api, PJRT_Event_Destroy_Args* args);

// call_PJRT_Event_IsReady calls the corresponding PJRT API method.
// Returns true if this PJRT_Event has completed, including if an error has
// occurred.
extern PJRT_Error* call_PJRT_Event_IsReady(const PJRT_Api *api, PJRT_Event_IsReady_Args* args);

// call_PJRT_Event_Error calls the corresponding PJRT API method.
// Should only be called if PJRT_Event_IsReady returns true.
// Returns `nullptr` if there is no error.
// The returned error should be freed with `PJRT_Error_Destroy`.
//
// If `PJRT_Event_Await` has been called, this will return a pointer to an
// identical error status as that call, as will subsequent calls to
// `PJRT_Event_Error`. However, each of these `PJRT_Error *` pointers are
// independent of `PJRT_Error *`s returned by other function calls, so they must
// each be freed separately using `PJRT_Error_Destroy`.
extern PJRT_Error* call_PJRT_Event_Error(const PJRT_Api *api, PJRT_Event_Error_Args* args);

// call_PJRT_Event_Await calls the corresponding PJRT API method.
// Blocks the calling thread until `event` is ready, then returns the error
// status (with `nullptr` indicating no error). The returned status should be
// freed with `PJRT_Error_Destroy`.
extern PJRT_Error* call_PJRT_Event_Await(const PJRT_Api *api, PJRT_Event_Await_Args* args);

// call_PJRT_Event_OnReady calls the corresponding PJRT API method.
// Registers `callback` to be called once `event` is ready, with `event`'s
// error status and a pointer to an object of the caller's choice as arguments.
extern PJRT_Error* call_PJRT_Event_OnReady(const PJRT_Api *api, PJRT_Event_OnReady_Args* args);

// call_PJRT_Client_Create calls the corresponding PJRT API method.
// Creates and initializes a new PJRT_Client and returns in `client`.
extern PJRT_Error* call_PJRT_Client_Create(const PJRT_Api *api, PJRT_Client_Create_Args* args);

// call_PJRT_Client_Destroy calls the corresponding PJRT API method.
// Shuts down and frees `client`. `client` can be nullptr.
extern PJRT_Error* call_PJRT_Client_Destroy(const PJRT_Api *api, PJRT_Client_Destroy_Args* args);

// call_PJRT_Client_PlatformName calls the corresponding PJRT API method.
// Returns a string that identifies the platform (e.g. "cpu", "gpu", "tpu").
extern PJRT_Error* call_PJRT_Client_PlatformName(const PJRT_Api *api, PJRT_Client_PlatformName_Args* args);

// call_PJRT_Client_ProcessIndex calls the corresponding PJRT API method.
// Return the process index of this client. Always 0 in single-process
// settings.
extern PJRT_Error* call_PJRT_Client_ProcessIndex(const PJRT_Api *api, PJRT_Client_ProcessIndex_Args* args);

// call_PJRT_Client_PlatformVersion calls the corresponding PJRT API method.
// Returns a string containing human-readable, platform-specific version info
// (e.g. the CUDA version on GPU or libtpu version on Cloud TPU).
extern PJRT_Error* call_PJRT_Client_PlatformVersion(const PJRT_Api *api, PJRT_Client_PlatformVersion_Args* args);

// call_PJRT_Client_TopologyDescription calls the corresponding PJRT API method.
// Returns the topology description of the runtime topology. The returned
// topology is owned by the client and should not be deleted by the caller.
extern PJRT_Error* call_PJRT_Client_TopologyDescription(const PJRT_Api *api, PJRT_Client_TopologyDescription_Args* args);

// call_PJRT_Client_Devices calls the corresponding PJRT API method.
// Returns a list of all devices visible to the runtime, including addressable
// and non-addressable devices.
extern PJRT_Error* call_PJRT_Client_Devices(const PJRT_Api *api, PJRT_Client_Devices_Args* args);

// call_PJRT_Client_AddressableDevices calls the corresponding PJRT API method.
// Returns a list of devices that are addressable from the client.
// Addressable devices are those that the client can issue commands to.
// All devices are addressable in a single-process environment.
extern PJRT_Error* call_PJRT_Client_AddressableDevices(const PJRT_Api *api, PJRT_Client_AddressableDevices_Args* args);

// call_PJRT_Client_LookupDevice calls the corresponding PJRT API method.
// Returns a PJRT_Device* with the specified ID as returned by
// PJRT_DeviceDescription_Id.
extern PJRT_Error* call_PJRT_Client_LookupDevice(const PJRT_Api *api, PJRT_Client_LookupDevice_Args* args);

// call_PJRT_Client_LookupAddressableDevice calls the corresponding PJRT API method.
// Returns an addressable PJRT_Device* with the specified ID as returned by
// PJRT_DeviceDescription_LocalHardwareId.
extern PJRT_Error* call_PJRT_Client_LookupAddressableDevice(const PJRT_Api *api, PJRT_Client_LookupAddressableDevice_Args* args);

// call_PJRT_Client_AddressableMemories calls the corresponding PJRT API method.
// Returns a list of memories that are addressable from the client. Addressable
// memories are those that the client can directly transfer data to and from.
// All memories are addressable in a single-process environment.
extern PJRT_Error* call_PJRT_Client_AddressableMemories(const PJRT_Api *api, PJRT_Client_AddressableMemories_Args* args);

// call_PJRT_Client_Compile calls the corresponding PJRT API method.
// Compiles a program in specified format (such as MLIR or HLO) with given
// `options`.
extern PJRT_Error* call_PJRT_Client_Compile(const PJRT_Api *api, PJRT_Client_Compile_Args* args);

// call_PJRT_Client_DefaultDeviceAssignment calls the corresponding PJRT API method.
extern PJRT_Error* call_PJRT_Client_DefaultDeviceAssignment(const PJRT_Api *api, PJRT_Client_DefaultDeviceAssignment_Args* args);

// call_PJRT_Client_BufferFromHostBuffer calls the corresponding PJRT API method.
// Asynchronously copies a buffer stored on host to device memory.
extern PJRT_Error* call_PJRT_Client_BufferFromHostBuffer(const PJRT_Api *api, PJRT_Client_BufferFromHostBuffer_Args* args);

// call_PJRT_Client_CreateViewOfDeviceBuffer calls the corresponding PJRT API method.
// Creates a PJRT buffer that is a non-owned view of an on-device buffer
// (typically allocated by another library). The buffer may be mutated,
// for example, if the buffer is donated to an Execute operation. This method is
// not required on all hardware platforms.
extern PJRT_Error* call_PJRT_Client_CreateViewOfDeviceBuffer(const PJRT_Api *api, PJRT_Client_CreateViewOfDeviceBuffer_Args* args);

// call_PJRT_DeviceDescription_Id calls the corresponding PJRT API method.
// The ID of this device. IDs are unique among devices of this type
// (e.g. CPUs, GPUs). On multi-host platforms, this will be unique across all
// hosts' devices.
extern PJRT_Error* call_PJRT_DeviceDescription_Id(const PJRT_Api *api, PJRT_DeviceDescription_Id_Args* args);

// call_PJRT_DeviceDescription_ProcessIndex calls the corresponding PJRT API method.
// The index of the process that this device belongs to, i.e. is addressable
// from. This is not always identical to PJRT_Client_ProcessIndex in a
// multi-process setting, where each client can see devices from all
// processes, but only a subset of them are addressable and have the same
// process_index as the client.
extern PJRT_Error* call_PJRT_DeviceDescription_ProcessIndex(const PJRT_Api *api, PJRT_DeviceDescription_ProcessIndex_Args* args);

// call_PJRT_DeviceDescription_Attributes calls the corresponding PJRT API method.
// Returns an array of device specific attributes with attribute name, value
// and value type.
extern PJRT_Error* call_PJRT_DeviceDescription_Attributes(const PJRT_Api *api, PJRT_DeviceDescription_Attributes_Args* args);

// call_PJRT_DeviceDescription_Kind calls the corresponding PJRT API method.
// A vendor-dependent string that uniquely identifies the kind of device,
// e.g., "Tesla V100-SXM2-16GB".
extern PJRT_Error* call_PJRT_DeviceDescription_Kind(const PJRT_Api *api, PJRT_DeviceDescription_Kind_Args* args);

// call_PJRT_DeviceDescription_DebugString calls the corresponding PJRT API method.
// Debug string suitable for logging when errors occur. Should be verbose
// enough to describe the current device unambiguously.
extern PJRT_Error* call_PJRT_DeviceDescription_DebugString(const PJRT_Api *api, PJRT_DeviceDescription_DebugString_Args* args);

// call_PJRT_DeviceDescription_ToString calls the corresponding PJRT API method.
// Debug string suitable for reading by end users, should be reasonably terse,
// for example: "CpuDevice(id=0)".
extern PJRT_Error* call_PJRT_DeviceDescription_ToString(const PJRT_Api *api, PJRT_DeviceDescription_ToString_Args* args);

// call_PJRT_Device_GetDescription calls the corresponding PJRT API method.
// Fetch the DeviceDescription associated with this device.
extern PJRT_Error* call_PJRT_Device_GetDescription(const PJRT_Api *api, PJRT_Device_GetDescription_Args* args);

// call_PJRT_Device_IsAddressable calls the corresponding PJRT API method.
// Whether client can issue command to this device.
extern PJRT_Error* call_PJRT_Device_IsAddressable(const PJRT_Api *api, PJRT_Device_IsAddressable_Args* args);

// call_PJRT_Device_LocalHardwareId calls the corresponding PJRT API method.
// Opaque hardware ID, e.g., the CUDA device number. In general, not guaranteed
// to be dense, and -1 if undefined.
extern PJRT_Error* call_PJRT_Device_LocalHardwareId(const PJRT_Api *api, PJRT_Device_LocalHardwareId_Args* args);

// call_PJRT_Device_AddressableMemories calls the corresponding PJRT API method.
// Returns the memories that a device can address.
extern PJRT_Error* call_PJRT_Device_AddressableMemories(const PJRT_Api *api, PJRT_Device_AddressableMemories_Args* args);

// call_PJRT_Device_DefaultMemory calls the corresponding PJRT API method.
// Returns the default memory of a device, i.e. which memory data processed by
// this device should be stored in by default.
extern PJRT_Error* call_PJRT_Device_DefaultMemory(const PJRT_Api *api, PJRT_Device_DefaultMemory_Args* args);

// call_PJRT_Device_MemoryStats calls the corresponding PJRT API method.
// Device memory/allocator statistics. All returned stats except `bytes_in_use`
// are optional and may not be returned by all platforms. Implementations may
// also return PJRT_Error_Code_UNIMPLEMENTED. Intended for diagnostic purposes.
extern PJRT_Error* call_PJRT_Device_MemoryStats(const PJRT_Api *api, PJRT_Device_MemoryStats_Args* args);

// call_PJRT_Memory_Id calls the corresponding PJRT API method.
// The ID of this memory. IDs are unique among memories of this type.
extern PJRT_Error* call_PJRT_Memory_Id(const PJRT_Api *api, PJRT_Memory_Id_Args* args);

// call_PJRT_Memory_Kind calls the corresponding PJRT API method.
// A platform-dependent string that uniquely identifies the kind of the memory.
extern PJRT_Error* call_PJRT_Memory_Kind(const PJRT_Api *api, PJRT_Memory_Kind_Args* args);

// call_PJRT_Memory_Kind_Id calls the corresponding PJRT API method.
// A platform-dependent ID that uniquely identifies the kind of the memory.
extern PJRT_Error* call_PJRT_Memory_Kind_Id(const PJRT_Api *api, PJRT_Memory_Kind_Id_Args* args);

// call_PJRT_Memory_DebugString calls the corresponding PJRT API method.
// Debug string suitable for logging when errors occur. Should be verbose
// enough to describe the current memory unambiguously.
extern PJRT_Error* call_PJRT_Memory_DebugString(const PJRT_Api *api, PJRT_Memory_DebugString_Args* args);

// call_PJRT_Memory_ToString calls the corresponding PJRT API method.
// Debug string suitable for reading by end users, should be reasonably terse.
extern PJRT_Error* call_PJRT_Memory_ToString(const PJRT_Api *api, PJRT_Memory_ToString_Args* args);

// call_PJRT_Memory_AddressableByDevices calls the corresponding PJRT API method.
// Returns the devices that can address this memory.
extern PJRT_Error* call_PJRT_Memory_AddressableByDevices(const PJRT_Api *api, PJRT_Memory_AddressableByDevices_Args* args);

// call_PJRT_ExecuteContext_Create calls the corresponding PJRT API method.
// Creates an execute context.
extern PJRT_Error* call_PJRT_ExecuteContext_Create(const PJRT_Api *api, PJRT_ExecuteContext_Create_Args* args);

// call_PJRT_ExecuteContext_Destroy calls the corresponding PJRT API method.
// Frees an execute context. `context` can be nullptr.
extern PJRT_Error* call_PJRT_ExecuteContext_Destroy(const PJRT_Api *api, PJRT_ExecuteContext_Destroy_Args* args);

// call_PJRT_Executable_Destroy calls the corresponding PJRT API method.
// Frees `executable`. `executable` can be nullptr.
extern PJRT_Error* call_PJRT_Executable_Destroy(const PJRT_Api *api, PJRT_Executable_Destroy_Args* args);

// call_PJRT_LoadedExecutable_Destroy calls the corresponding PJRT API method.
// Frees `executable` and deletes the underlying runtime object as if
// `PJRT_LoadedExecutable_Delete` were called. `executable` can be nullptr.
extern PJRT_Error* call_PJRT_LoadedExecutable_Destroy(const PJRT_Api *api, PJRT_LoadedExecutable_Destroy_Args* args);

// call_PJRT_LoadedExecutable_GetExecutable calls the corresponding PJRT API method.
// Constructs a PJRT_Executable from a PJRT_LoadedExecutable. The returned
// executable should be freed by the caller with PJRT_Executable_Destroy.
extern PJRT_Error* call_PJRT_LoadedExecutable_GetExecutable(const PJRT_Api *api, PJRT_LoadedExecutable_GetExecutable_Args* args);

// call_PJRT_Executable_Name calls the corresponding PJRT API method.
// Returns a string that identifies the executable.
extern PJRT_Error* call_PJRT_Executable_Name(const PJRT_Api *api, PJRT_Executable_Name_Args* args);

// call_PJRT_Executable_NumReplicas calls the corresponding PJRT API method.
// Returns the number of replicas of the executable.
extern PJRT_Error* call_PJRT_Executable_NumReplicas(const PJRT_Api *api, PJRT_Executable_NumReplicas_Args* args);

// call_PJRT_Executable_NumPartitions calls the corresponding PJRT API method.
// Returns the number of partitions of the executable.
extern PJRT_Error* call_PJRT_Executable_NumPartitions(const PJRT_Api *api, PJRT_Executable_NumPartitions_Args* args);

// call_PJRT_LoadedExecutable_AddressableDevices calls the corresponding PJRT API method.
// Returns a list of devices this executable will run on.
extern PJRT_Error* call_PJRT_LoadedExecutable_AddressableDevices(const PJRT_Api *api, PJRT_LoadedExecutable_AddressableDevices_Args* args);

// call_PJRT_Executable_OptimizedProgram calls the corresponding PJRT API method.
// Retrieves the optimized program for a given PJRT_Executable (SPMD).
// The caller should populate `program->format` and `format_size`.
//
// The implementation will set `program->format` and `program->format_size`
// to inform callers of the format of the optimized program returned.
// These members are owned by the implementation.
//
// If called with nullptr as `program->code`, `PJRT_Executable_OptimizedProgram`
// will populate `program->code_size` as an output indicating the number of
// bytes the string `program->code` requires.
//
// If `program->code` is not null, `PJRT_Executable_OptimizedProgram` will fill
// the buffer pointed to by `program->code` with the serialization of the
// optimized HLO program. `program->code` must point to a client-owned buffer of
// size >= `program->code_size`, which must be at large enough to hold the
// serialization of the optimized program.
//
// Callers should generally call this function twice with the same `args`.
// In the first call, `program->code` must be nullptr. This call will populate
// `program->code_size`. Clients should then allocate a buffer `code_buff` of at
// least `code_size` bytes. Before the second call, callers should set
// `program->code = code_buff`. The second call will then write the serialized
// program to `code_buff`.
extern PJRT_Error* call_PJRT_Executable_OptimizedProgram(const PJRT_Api *api, PJRT_Executable_OptimizedProgram_Args* args);

// call_PJRT_LoadedExecutable_Delete calls the corresponding PJRT API method.
// Drops `executable`'s reference to the internal runtime object and
// associated resources, without freeing the `executable` object itself.
// `executable` can only be used with PJRT_LoadedExecutable_IsDeleted and
// PJRT_LoadedExecutable_Destroy after calling this method. The internal runtime
// executable will be freed after the last execution completes.
extern PJRT_Error* call_PJRT_LoadedExecutable_Delete(const PJRT_Api *api, PJRT_LoadedExecutable_Delete_Args* args);

// call_PJRT_LoadedExecutable_IsDeleted calls the corresponding PJRT API method.
// True if and only if PJRT_LoadedExecutable_Delete has previously been called.
extern PJRT_Error* call_PJRT_LoadedExecutable_IsDeleted(const PJRT_Api *api, PJRT_LoadedExecutable_IsDeleted_Args* args);

// call_PJRT_LoadedExecutable_Execute calls the corresponding PJRT API method.
// Executes on devices addressable by the client.
extern PJRT_Error* call_PJRT_LoadedExecutable_Execute(const PJRT_Api *api, PJRT_LoadedExecutable_Execute_Args* args);

// call_PJRT_Executable_NumOutputs calls the corresponding PJRT API method.
// Gets the number of outputs per device produced by `executable`.
extern PJRT_Error* call_PJRT_Executable_NumOutputs(const PJRT_Api *api, PJRT_Executable_NumOutputs_Args* args);

// call_PJRT_Executable_SizeOfGeneratedCodeInBytes calls the corresponding PJRT API method.
extern PJRT_Error* call_PJRT_Executable_SizeOfGeneratedCodeInBytes(const PJRT_Api *api, PJRT_Executable_SizeOfGeneratedCodeInBytes_Args* args);

// call_PJRT_Executable_Fingerprint calls the corresponding PJRT API method.
// A unique fingerprint for `executable`. Two executables that were produced by
// compiling with identical inputs (same program, compile options, compiler
// version, etc.) should have the same fingerprint. May not be implemented by
// all platforms.
extern PJRT_Error* call_PJRT_Executable_Fingerprint(const PJRT_Api *api, PJRT_Executable_Fingerprint_Args* args);

// call_PJRT_Executable_GetCostAnalysis calls the corresponding PJRT API method.
// Get the cost properties for the executable. Different platforms may return
// different properties; for example, some platforms may return the number of
// operations, or memory size of the input/output of the executable, based on
// program analysis.
extern PJRT_Error* call_PJRT_Executable_GetCostAnalysis(const PJRT_Api *api, PJRT_Executable_GetCostAnalysis_Args* args);

// call_PJRT_Executable_GetCompiledMemoryStats calls the corresponding PJRT API method.
// Return memory stats that allow callers to estimate memory usage when running
// this executable. The memory stats could contain usage info from different
// memory spaces, like default memory (e.g., HBM for GPU/TPU) and host memory.
extern PJRT_Error* call_PJRT_Executable_GetCompiledMemoryStats(const PJRT_Api *api, PJRT_Executable_GetCompiledMemoryStats_Args* args);

// call_PJRT_Executable_OutputElementTypes calls the corresponding PJRT API method.
// Returns a list of element types for outputs.
extern PJRT_Error* call_PJRT_Executable_OutputElementTypes(const PJRT_Api *api, PJRT_Executable_OutputElementTypes_Args* args);

// call_PJRT_Executable_OutputDimensions calls the corresponding PJRT API method.
// Returns a list of dimensions for outputs. Each output has an array shape,
// which is represented by a list of dimensions. The array shapes of all outputs
// are concatenated into a single list of dimensions.
extern PJRT_Error* call_PJRT_Executable_OutputDimensions(const PJRT_Api *api, PJRT_Executable_OutputDimensions_Args* args);

// call_PJRT_Executable_OutputMemoryKinds calls the corresponding PJRT API method.
// Returns a list of memory kind strings for outputs.
extern PJRT_Error* call_PJRT_Executable_OutputMemoryKinds(const PJRT_Api *api, PJRT_Executable_OutputMemoryKinds_Args* args);

// call_PJRT_Executable_Serialize calls the corresponding PJRT API method.
// Returns a platform-specific serialization of `executable`. The serialization
// is not guaranteed to be stable over time.
extern PJRT_Error* call_PJRT_Executable_Serialize(const PJRT_Api *api, PJRT_Executable_Serialize_Args* args);

// call_PJRT_Executable_DeserializeAndLoad calls the corresponding PJRT API method.
// Deserializes an executable serialized by `PJRT_Executable_Serialize`.
// `serialized_executable` must have been produced by the same platform and
// library version as this one.
extern PJRT_Error* call_PJRT_Executable_DeserializeAndLoad(const PJRT_Api *api, PJRT_Executable_DeserializeAndLoad_Args* args);

// call_PJRT_LoadedExecutable_Fingerprint calls the corresponding PJRT API method.
// DEPRECATED. Will be removed in PJRT version 2.0. Please use
// PJRT_Executable_Fingerprint instead. A unique fingerprint for `executable`.
// Two executables that were produced by compiling with identical inputs (same
// program, compile options, compiler version, etc.) should have the same
// fingerprint. May not be implemented by all platforms.
extern PJRT_Error* call_PJRT_LoadedExecutable_Fingerprint(const PJRT_Api *api, PJRT_LoadedExecutable_Fingerprint_Args* args);

// call_PJRT_Buffer_Destroy calls the corresponding PJRT API method.
// Deletes the underlying runtime objects as if 'PJRT_Buffer_Delete' were
// called and frees `buffer`. `buffer` can be nullptr.
extern PJRT_Error* call_PJRT_Buffer_Destroy(const PJRT_Api *api, PJRT_Buffer_Destroy_Args* args);

// call_PJRT_Buffer_ElementType calls the corresponding PJRT API method.
// Returns the type of the array elements of a buffer.
extern PJRT_Error* call_PJRT_Buffer_ElementType(const PJRT_Api *api, PJRT_Buffer_ElementType_Args* args);

// call_PJRT_Buffer_Dimensions calls the corresponding PJRT API method.
// Returns the array shape of `buffer`, i.e. the size of each dimension.
extern PJRT_Error* call_PJRT_Buffer_Dimensions(const PJRT_Api *api, PJRT_Buffer_Dimensions_Args* args);

// call_PJRT_Buffer_UnpaddedDimensions calls the corresponding PJRT API method.
// Returns the unpadded array shape of `buffer`. This usually is equivalent to
// PJRT_Buffer_Dimensions, but for implementations that support
// dynamically-sized dimensions via padding to a fixed size, any dynamic
// dimensions may have a smaller unpadded size than the padded size reported by
// PJRT_Buffer_Dimensions. ("Dynamic" dimensions are those whose length is
// only known at runtime, vs. "static" dimensions whose size is fixed at compile
// time.)
extern PJRT_Error* call_PJRT_Buffer_UnpaddedDimensions(const PJRT_Api *api, PJRT_Buffer_UnpaddedDimensions_Args* args);

// call_PJRT_Buffer_DynamicDimensionIndices calls the corresponding PJRT API method.
// Returns the indices of dynamically-sized dimensions, or an empty list if all
// dimensions are static. ("Dynamic" dimensions are those whose length is
// only known at runtime, vs. "static" dimensions whose size is fixed at compile
// time.)
extern PJRT_Error* call_PJRT_Buffer_DynamicDimensionIndices(const PJRT_Api *api, PJRT_Buffer_DynamicDimensionIndices_Args* args);

// call_PJRT_Buffer_GetMemoryLayout calls the corresponding PJRT API method.
// DEPRECATED. Please use layout extension instead.
// https://github.com/openxla/xla/blob/main/xla/pjrt/c/pjrt_c_api_layouts_extension.h
// Returns the memory layout of the data in this buffer.
extern PJRT_Error* call_PJRT_Buffer_GetMemoryLayout(const PJRT_Api *api, PJRT_Buffer_GetMemoryLayout_Args* args);

// call_PJRT_Buffer_ToHostBuffer calls the corresponding PJRT API method.
// Asynchronously copies the buffer's value into a preallocated host buffer.
extern PJRT_Error* call_PJRT_Buffer_ToHostBuffer(const PJRT_Api *api, PJRT_Buffer_ToHostBuffer_Args* args);

// call_PJRT_Buffer_OnDeviceSizeInBytes calls the corresponding PJRT API method.
// Gets the number of bytes of the buffer storage on the device
extern PJRT_Error* call_PJRT_Buffer_OnDeviceSizeInBytes(const PJRT_Api *api, PJRT_Buffer_OnDeviceSizeInBytes_Args* args);

// call_PJRT_Buffer_Delete calls the corresponding PJRT API method.
// Drop the buffer's reference to its associated device memory, without freeing
// the `buffer` object itself. `buffer` can only be used with
// PJRT_Buffer_IsDeleted and PJRT_Buffer_Destroy after calling this method. The
// device memory will be freed when all async operations using the buffer have
// completed, according to the allocation semantics of the underlying platform.
extern PJRT_Error* call_PJRT_Buffer_Delete(const PJRT_Api *api, PJRT_Buffer_Delete_Args* args);

// call_PJRT_Buffer_IsDeleted calls the corresponding PJRT API method.
// True if and only if PJRT_Buffer_Delete has previously been called.
extern PJRT_Error* call_PJRT_Buffer_IsDeleted(const PJRT_Api *api, PJRT_Buffer_IsDeleted_Args* args);

// call_PJRT_Buffer_CopyToDevice calls the corresponding PJRT API method.
// Copies the buffer to device `dst_device` within the same client. Caller is
// responsible for freeing returned `dst_buffer` with PJRT_Buffer_Destroy.
// Returns an error if the buffer is already on `dst_device`.
extern PJRT_Error* call_PJRT_Buffer_CopyToDevice(const PJRT_Api *api, PJRT_Buffer_CopyToDevice_Args* args);

// call_PJRT_Buffer_CopyToMemory calls the corresponding PJRT API method.
// Copies the buffer to memory `dst_memory` within the same client. Caller is
// responsible for freeing returned `dst_buffer` with PJRT_Buffer_Destroy.
// Returns an error if the buffer is already on `dst_memory`.
extern PJRT_Error* call_PJRT_Buffer_CopyToMemory(const PJRT_Api *api, PJRT_Buffer_CopyToMemory_Args* args);

// call_PJRT_Buffer_IsOnCpu calls the corresponding PJRT API method.
// Whether this buffer is on CPU and thus allows for certain optimizations.
extern PJRT_Error* call_PJRT_Buffer_IsOnCpu(const PJRT_Api *api, PJRT_Buffer_IsOnCpu_Args* args);

// call_PJRT_Buffer_Device calls the corresponding PJRT API method.
// Returns this buffer's storage device.
extern PJRT_Error* call_PJRT_Buffer_Device(const PJRT_Api *api, PJRT_Buffer_Device_Args* args);

// call_PJRT_Buffer_Memory calls the corresponding PJRT API method.
// Returns this buffer's storage memory.
extern PJRT_Error* call_PJRT_Buffer_Memory(const PJRT_Api *api, PJRT_Buffer_Memory_Args* args);

// call_PJRT_Buffer_ReadyEvent calls the corresponding PJRT API method.
// Returns an event that is triggered when either of the following happens:
// * the data in the PJRT_Buffer becomes ready, or
// * an error has occurred.
//
// TODO(b/241967811): change these weird semantics
// If the buffer has been deleted or donated, the returned event will
// immediately indicate an error. However, if PJRT_Buffer_ReadyEvent() is
// called on the buffer before PJRT_Buffer_Delete() is, the returned event will
// not transition to an error state after PJRT_Buffer_Delete() is called.
extern PJRT_Error* call_PJRT_Buffer_ReadyEvent(const PJRT_Api *api, PJRT_Buffer_ReadyEvent_Args* args);

// call_PJRT_Buffer_UnsafePointer calls the corresponding PJRT API method.
// Returns platform-dependent address for the given buffer that is often but
// not guaranteed to be the physical/device address.
extern PJRT_Error* call_PJRT_Buffer_UnsafePointer(const PJRT_Api *api, PJRT_Buffer_UnsafePointer_Args* args);

// call_PJRT_Buffer_IncreaseExternalReferenceCount calls the corresponding PJRT API method.
// Increments the reference count for the buffer. The reference count indicates
// the raw buffer data is being shared with another framework (e.g. NumPy,
// dlpack) and should not be deleted or moved by the PJRT implementation (e.g.
// for memory compaction). TODO(b/295230663): document more API contract
// details, e.g. does this block, can the buffer be modified in-place.
extern PJRT_Error* call_PJRT_Buffer_IncreaseExternalReferenceCount(const PJRT_Api *api, PJRT_Buffer_IncreaseExternalReferenceCount_Args* args);

// call_PJRT_Buffer_DecreaseExternalReferenceCount calls the corresponding PJRT API method.
// Decrements the reference count for the buffer. Returns an error if the
// reference count is zero (i.e. PJRT_Buffer_IncreaseExternalReferenceCount is
// not called beforehand).
extern PJRT_Error* call_PJRT_Buffer_DecreaseExternalReferenceCount(const PJRT_Api *api, PJRT_Buffer_DecreaseExternalReferenceCount_Args* args);

// call_PJRT_Buffer_OpaqueDeviceMemoryDataPointer calls the corresponding PJRT API method.
// Returns the opaque device memory data pointer of the buffer. The returned
// data pointer may become invalid at any point unless the external reference
// count is greater than 0 via PJRT_Buffer_IncreaseExternalReferenceCount.
extern PJRT_Error* call_PJRT_Buffer_OpaqueDeviceMemoryDataPointer(const PJRT_Api *api, PJRT_Buffer_OpaqueDeviceMemoryDataPointer_Args* args);

// call_PJRT_CopyToDeviceStream_Destroy calls the corresponding PJRT API method.
// Frees `stream`. `stream` can be nullptr.
extern PJRT_Error* call_PJRT_CopyToDeviceStream_Destroy(const PJRT_Api *api, PJRT_CopyToDeviceStream_Destroy_Args* args);

// call_PJRT_CopyToDeviceStream_AddChunk calls the corresponding PJRT API method.
// Emplaces a new chunk of data to copy to the device. The transfer is started
// immediately, and the returned event is triggered when the transfer completes
// or fails.
//
// The returned event will indicate an error if the chunk's size causes the
// amount of transferred data to exceed the total bytes, if the stream is
// already complete, or if the chunk is not a multiple of the granule size.
extern PJRT_Error* call_PJRT_CopyToDeviceStream_AddChunk(const PJRT_Api *api, PJRT_CopyToDeviceStream_AddChunk_Args* args);

// call_PJRT_CopyToDeviceStream_TotalBytes calls the corresponding PJRT API method.
// Returns the total amount of data the stream expects to be transferred.
extern PJRT_Error* call_PJRT_CopyToDeviceStream_TotalBytes(const PJRT_Api *api, PJRT_CopyToDeviceStream_TotalBytes_Args* args);

// call_PJRT_CopyToDeviceStream_GranuleSize calls the corresponding PJRT API method.
// Returns the granule size in bytes. The size of the chunk added to this stream
// must be a multiple of this number.
extern PJRT_Error* call_PJRT_CopyToDeviceStream_GranuleSize(const PJRT_Api *api, PJRT_CopyToDeviceStream_GranuleSize_Args* args);

// call_PJRT_CopyToDeviceStream_CurrentBytes calls the corresponding PJRT API method.
// Returns the amount of data the stream currently has either transferred or has
// buffered to transfer.
extern PJRT_Error* call_PJRT_CopyToDeviceStream_CurrentBytes(const PJRT_Api *api, PJRT_CopyToDeviceStream_CurrentBytes_Args* args);

// call_PJRT_TopologyDescription_Create calls the corresponding PJRT API method.
// Creates and initializes a new PJRT_TopologyDescription and returns in
// `topology`.
extern PJRT_Error* call_PJRT_TopologyDescription_Create(const PJRT_Api *api, PJRT_TopologyDescription_Create_Args* args);

// call_PJRT_TopologyDescription_Destroy calls the corresponding PJRT API method.
// Frees `topology`. `topology` can be nullptr.
extern PJRT_Error* call_PJRT_TopologyDescription_Destroy(const PJRT_Api *api, PJRT_TopologyDescription_Destroy_Args* args);

// call_PJRT_TopologyDescription_PlatformVersion calls the corresponding PJRT API method.
// Returns a string containing human-readable, platform-specific version info
// (e.g. the CUDA version on GPU or libtpu version on Cloud TPU).
extern PJRT_Error* call_PJRT_TopologyDescription_PlatformVersion(const PJRT_Api *api, PJRT_TopologyDescription_PlatformVersion_Args* args);

// call_PJRT_TopologyDescription_PlatformName calls the corresponding PJRT API method.
// Returns a string that identifies the platform (e.g. "cpu", "gpu", "tpu").
extern PJRT_Error* call_PJRT_TopologyDescription_PlatformName(const PJRT_Api *api, PJRT_TopologyDescription_PlatformName_Args* args);

// call_PJRT_TopologyDescription_GetDeviceDescriptions calls the corresponding PJRT API method.
// Returns descriptions for all devices in this topology. The device
// descriptions can be returned in any order, but will be in the same order
// across calls within a process.
extern PJRT_Error* call_PJRT_TopologyDescription_GetDeviceDescriptions(const PJRT_Api *api, PJRT_TopologyDescription_GetDeviceDescriptions_Args* args);

// call_PJRT_TopologyDescription_Serialize calls the corresponding PJRT API method.
// Serializes the TopologyDescription to a string for use in cache keys.
extern PJRT_Error* call_PJRT_TopologyDescription_Serialize(const PJRT_Api *api, PJRT_TopologyDescription_Serialize_Args* args);

// call_PJRT_TopologyDescription_Attributes calls the corresponding PJRT API method.
// Returns platform-specific topology attributes.
extern PJRT_Error* call_PJRT_TopologyDescription_Attributes(const PJRT_Api *api, PJRT_TopologyDescription_Attributes_Args* args);

// call_PJRT_Compile calls the corresponding PJRT API method.
// Compiles a program in specified format (such as MLIR or HLO) with given
// `options`. The returned executable must be loaded by a compatible
// PJRT_Client before execution.
extern PJRT_Error* call_PJRT_Compile(const PJRT_Api *api, PJRT_Compile_Args* args);


#ifdef __cplusplus
}
#endif
#endif
