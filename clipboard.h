#include "clipboard.c"

#ifndef clipboard
#define clipboard
char* PrintSelection(Display *display, Window window, const char *bufname, const char *fmtname);
char* clip();
#endif
