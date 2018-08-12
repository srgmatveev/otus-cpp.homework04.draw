
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
App::instance().App_Dispatcher(Message::DrawCircle);
App::instance().App_Dispatcher(Message::DrawRectangle);
App::instance().App_Dispatcher(Message::DeleteSelected);
App::instance().App_Dispatcher(Message::Import_From_File);
App::instance().App_Dispatcher(Message::Export_to_File);
App::instance().App_Dispatcher(Message::Open_Document);
App::instance().App_Dispatcher(Message::Save_Document);
App::instance().App_Dispatcher(Message::Save_All_Documents);
App::instance().App_Dispatcher(Message::Close_Document);
App::instance().App_Dispatcher(Message::Close_All_Documents);
return 0;
}