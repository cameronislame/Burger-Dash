#ifndef X11_WRAPPER_H
#define X11_WRAPPER_H

#include <X11/Xlib.h>
#include <GL/glx.h>

class X11_wrapper {
private:
    Display* dpy;
    Window win;
    GLXContext glc;

public:
    X11_wrapper();
    ~X11_wrapper();
    void set_title();
    bool getXPending();
    XEvent getXNextEvent();
    void swapBuffers();
    void reshape_window(int width, int height);
    void check_resize(XEvent* e);
    void check_mouse(XEvent* e);
    int check_keys(XEvent* e);
};

#endif
