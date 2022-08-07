#include "register_types.h"

#include "core/engine.h"

#include "stdout_stderr_intercept.h"

static StdoutStderrIntercept *stdout_stderr_intercept = nullptr;

void register_stdout_stderr_intercept_types() {
	stdout_stderr_intercept = StdoutStderrIntercept::create();

	Engine::get_singleton()->add_singleton(Engine::Singleton("StdoutStderrIntercept", StdoutStderrIntercept::get_singleton()));
}

void unregister_stdout_stderr_intercept_types() {
	if (stdout_stderr_intercept) {
		memdelete(stdout_stderr_intercept);
	}
}
