#include "stdout_stderr_intercept.h"

void StdoutStderrIntercept::_print_handler(void *p_this, const String &p_text, bool p_is_error) {
	StdoutStderrIntercept *r = (StdoutStderrIntercept *)p_this;
	r->emit_signal("intercepted_message", p_text, p_is_error);
}

void StdoutStderrIntercept::_bind_methods() {
	ADD_SIGNAL(MethodInfo("intercepted_message", PropertyInfo(Variant::STRING, "text"), PropertyInfo(Variant::BOOL, "is_error")));
}

StdoutStderrIntercept *StdoutStderrIntercept::singleton = nullptr;

StdoutStderrIntercept *StdoutStderrIntercept::get_singleton() {
	return singleton;
}

StdoutStderrIntercept *StdoutStderrIntercept::create() {
	ERR_FAIL_COND_V_MSG(singleton, nullptr, "StdoutStderrIntercept singleton already exists.");
	return memnew(StdoutStderrIntercept);
}

StdoutStderrIntercept::StdoutStderrIntercept() {
	singleton = this;

	print_handler.printfunc = _print_handler;
	print_handler.userdata = this;
	add_print_handler(&print_handler);
}

StdoutStderrIntercept::~StdoutStderrIntercept() {
	remove_print_handler(&print_handler);
}
