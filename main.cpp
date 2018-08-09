//
// Created by sergio on 09.08.18.
//

#include <iostream>
#include <bits/unique_ptr.h>
#include "app.h"
#include "mdi.h"

int main() {
#ifdef USE_X11
    std::cout << "use x 11" << std::endl;
#endif
    std::cout << "hello" << std::endl;

    std::unique_ptr<App> app = Application::run();

    std::shared_ptr<mdi> mdi = app->getMDI();

#ifdef USE_X11
    mdi->set_display(app->get_display());
    mdi->mdi_show_window();
    #endif
getchar();
    return 0;
}