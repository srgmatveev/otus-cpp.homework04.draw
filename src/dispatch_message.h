#pragma once

enum class Message{
    New_Document,
    Open_Document,
    Set_Active_Document,
    Close_Document,
    Close_All_Documents,
    Save_Document,
    Save_All_Documents,
    Import_From_File,
    Export_to_File,
    DrawLine,
    DrawCircle,
    DrawRectangle,
    DeleteSelected,
};