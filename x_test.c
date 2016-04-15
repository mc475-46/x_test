#include <X11/Xlib.h>

#define WIN_W 400
#define WIN_H 300
#define WIN_X 100
#define WIN_Y 100
#define BORDER 2

int main(void){
  Display* dpy;
  Window root;
  Window win;
  int screen;
  unsigned long black, white;
  XEvent evt;

  dpy = XOpenDisplay("");

  root = DefaultRootWindow(dpy);
  screen = DefaultScreen(dpy);

  white = WhitePixel(dpy, screen);
  black = BlackPixel(dpy, screen);

  win = XCreateSimpleWindow(dpy, root, WIN_X, WIN_Y, WIN_W, WIN_H, BORDER, black, white);

  XSelectInput(dpy, win, KeyPressMask);

  XMapWindow(dpy, win);

  while(1){
    XNextEvent(dpy, &evt);

    switch(evt.type){
      case KeyPress:
        XDestroyWindow(dpy, win);
        XCloseDisplay(dpy);
        return 0;
    }
  }
}
