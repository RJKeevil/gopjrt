// Code generated by "stringer -type=errorCode errorcode.go"; DO NOT EDIT.

package xlabuilder

import "strconv"

func _() {
	// An "invalid array index" compiler error signifies that the constant values have changed.
	// Re-run the stringer command to generate them again.
	var x [1]struct{}
	_ = x[status_OK-0]
	_ = x[status_CANCELLED-1]
	_ = x[status_UNKNOWN-2]
	_ = x[status_INVALID_ARGUMENT-3]
	_ = x[status_DEADLINE_EXCEEDED-4]
	_ = x[status_NOT_FOUND-5]
	_ = x[status_ALREADY_EXISTS-6]
	_ = x[status_PERMISSION_DENIED-7]
	_ = x[status_UNAUTHENTICATED-16]
	_ = x[status_RESOURCE_EXHAUSTED-8]
	_ = x[status_FAILED_PRECONDITION-9]
	_ = x[status_ABORTED-10]
	_ = x[status_OUT_OF_RANGE-11]
}

const (
	_errorCode_name_0 = "status_OKstatus_CANCELLEDstatus_UNKNOWNstatus_INVALID_ARGUMENTstatus_DEADLINE_EXCEEDEDstatus_NOT_FOUNDstatus_ALREADY_EXISTSstatus_PERMISSION_DENIEDstatus_RESOURCE_EXHAUSTEDstatus_FAILED_PRECONDITIONstatus_ABORTEDstatus_OUT_OF_RANGE"
	_errorCode_name_1 = "status_UNAUTHENTICATED"
)

var (
	_errorCode_index_0 = [...]uint8{0, 9, 25, 39, 62, 86, 102, 123, 147, 172, 198, 212, 231}
)

func (i errorCode) String() string {
	switch {
	case 0 <= i && i <= 11:
		return _errorCode_name_0[_errorCode_index_0[i]:_errorCode_index_0[i+1]]
	case i == 16:
		return _errorCode_name_1
	default:
		return "errorCode(" + strconv.FormatInt(int64(i), 10) + ")"
	}
}
