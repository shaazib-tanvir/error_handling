#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

void error_debug(char format[static 1], ...);
void panic(char format[static 1], ...);
void error_info_report(char format[static 1], ...);
void error_info_exit(char format[static 1], ...);

#endif
