#ifndef STDOUT_STDERR_INTERCEPT_H
#define STDOUT_STDERR_INTERCEPT_H

#include "core/object.h"
#include "core/print_string.h"
#include "core/ustring.h"

class StdoutStderrIntercept : public Object {
	GDCLASS(StdoutStderrIntercept, Object);

private:
	PrintHandlerList print_handler;
	static void _print_handler(void *p_this, const String &p_text, bool p_is_error);

protected:
	static StdoutStderrIntercept *singleton;
	static void _bind_methods();

public:
	static StdoutStderrIntercept *get_singleton();

	static StdoutStderrIntercept *create();

	StdoutStderrIntercept();
	~StdoutStderrIntercept();
};

#endif STDOUT_STDERR_INTERCEPT_H
