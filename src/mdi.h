//
// Created by sergio on 09.08.18.
//

#pragma once
#include <mutex>
#include <memory>

#ifdef USE_X11
#include<X11/Xlib.h>
#include <X11/Xutil.h>
#endif

class mdi {
    friend class mdiFactory;
public:
    explicit mdi() = default;
#ifdef USE_X11
    void set_display(Display *d){ display = d;}
    Window create_simple_window(Display* display, int width, int height, int x, int y);
    void mdi_show_window();
#endif
private:
    mdi(const mdi &) = delete;
    mdi(mdi &&rhs) = delete;
    mdi &operator=(const mdi&) = delete;
#ifdef USE_X11
    Display* display;   /* pointer to X Display structure.*/
   int screen_num;  /* number of screen to place the window on.*/
   Window win; /* pointer to the newly created window.*/
   unsigned int display_width, display_height; /* height and width of the X display.*/
   unsigned int win_width,
   win_height;  /* height and width for the new window.*/

#endif
};


class mdiFactory{
public:
    static bool createMDI;
    static std::shared_ptr<mdi> Create(){
        std::mutex mutex;
        std::lock_guard<std::mutex> lock_guard(mutex);
        if(createMDI) return nullptr;
        createMDI = true;
        return std::make_shared<mdi>();
    }
};

bool mdiFactory::createMDI = false;


#ifdef USE_X11
/*
* function: create_simple_window. Creates a window with a white background
*
 in the given size.
* input:
 display, size of the window (in pixels), and location of the window
*
 (in pixels).
* output:
 the window's ID.
* notes:
 window is created with a black border, 2 pixels wide.
*
 the window is automatically mapped after its creation.
*/
Window mdi::create_simple_window(Display* display, int width, int height, int x, int y)
{
    int screen_num = DefaultScreen(display);
    int win_border_width = 2;
    Window win;
/* create a simple window, as a direct child of the screen's */
/* root window. Use the screen's black and white colors as
 */
/* the foreground and background colors of the window,
 */
/* respectively. Place the new window's top-left corner at
 */
/* the given 'x,y' coordinates.
 */
    win = XCreateSimpleWindow(display, RootWindow(display, screen_num),
                              x, y, width, height, win_border_width,
                              BlackPixel(display, screen_num),
                              WhitePixel(display, screen_num));
/* make the window actually appear on the screen. */
    XMapWindow(display, win);
/* flush all pending requests to the X server. */
    XFlush(display);
    return win;
}

void mdi::mdi_show_window() {
    /* get the geometry of the default screen for our display. */
    screen_num = DefaultScreen(display);
    display_width = DisplayWidth(display, screen_num);
    display_height = DisplayHeight(display, screen_num);
/* make the new window occupy 1/9 of the screen's size. */
    win_width = (display_width/2);
    win_height = (display_height/2);
    win = create_simple_window(display, win_width, win_height, 0, 0);

}
#endif