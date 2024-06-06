#include <error_handling.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_LENGTH 1024

void error_debug(char format[static 1], ...) {
	char buffer[BUFFER_LENGTH];
	va_list arguments;
	va_start(arguments, format);
	vsnprintf(buffer, BUFFER_LENGTH, format, arguments);
	fputs(buffer, stderr);
	va_end(arguments);
}

void panic(char format[static 1], ...) {
	char buffer[BUFFER_LENGTH];
	va_list arguments;
	va_start(arguments, format);
	vsnprintf(buffer, BUFFER_LENGTH, format, arguments);
	fputs(buffer, stderr);
	va_end(arguments);

	exit(EXIT_FAILURE);
}

void error_info_report(char format[static 1], ...) {
	perror("Info");

	char buffer[BUFFER_LENGTH];
	va_list arguments;
	va_start(arguments, format);
	vsnprintf(buffer, BUFFER_LENGTH, format, arguments);
	fputs(buffer, stderr);
	va_end(arguments);
}

void error_info_exit(char format[static 1], ...) {
	perror("Info");

	char buffer[BUFFER_LENGTH];
	va_list arguments;
	va_start(arguments, format);
	vsnprintf(buffer, BUFFER_LENGTH, format, arguments);
	fputs(buffer, stderr);
	va_end(arguments);

	exit(EXIT_FAILURE);
}
