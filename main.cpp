//
// Created by sergio on 09.08.18.
//

#include <iostream>
#include <bits/unique_ptr.h>
#include "app.h"
#include "mdi.h"

#include "Shapes.h"
int main() {
App::instance().run();
App::instance().App_Dispatcher(Message::New_Document);
App::instance().App_Dispatcher(Message::New_Document);
App::instance().App_Dispatcher(Message::Set_Active_Document);
App::instance().App_Dispatcher(Message::DrawLine);

return 0;
}