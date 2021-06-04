#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <X11/Xlib.h>

char* PrintSelection(Display *display, Window window, const char *bufname, const char *fmtname)
{
  char *result;
  unsigned long ressize, restail;
  int resbits;
  Atom bufid = XInternAtom(display, bufname, False),
       fmtid = XInternAtom(display, fmtname, False),
       propid = XInternAtom(display, "XSEL_DATA", False),
       incrid = XInternAtom(display, "INCR", False);
  XEvent event;

  XSelectInput (display, window, PropertyChangeMask);
  XConvertSelection(display, bufid, fmtid, propid, window, CurrentTime);
  do {
    XNextEvent(display, &event);
  } while (event.type != SelectionNotify || event.xselection.selection != bufid);

  if (event.xselection.property)
  {
    XGetWindowProperty(display, window, propid, 0, LONG_MAX/4, True, AnyPropertyType,
      &fmtid, &resbits, &ressize, &restail, (unsigned char**)&result);
    char *string;
    strcpy(string, result);
    XFree(result);
    return string;
  }
  else // request failed, e.g. owner can't convert to the target format
    return "";
}

char* clip()
{
  Display *display = XOpenDisplay(NULL);
  unsigned long color = BlackPixel(display, DefaultScreen(display));
  Window window = XCreateSimpleWindow(display, DefaultRootWindow(display), 0,0, 1,1, 0, color, color);
  char *result = PrintSelection(display, window, "CLIPBOARD", "UTF8_STRING");
/*              PrintSelection(display, window, "CLIPBOARD", "STRING");*/
  XDestroyWindow(display, window);
  XCloseDisplay(display); /*problem line*/
  return result;
}
