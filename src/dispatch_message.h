/**
 * @file dispatch_message.h
 * @brief Класс содержит перечисление типов событий очереди обработчика событий.
 */
#pragma once
/**
 * @brief Типы событий
 */
enum class Message{
    /// Создать новый документ
    New_Document,
    /// Открыть существующий документ
    Open_Document,
    /// Сделать документ активным (с которым идет работа)
    Set_Active_Document,
    /// Закрыть активный документ
    Close_Document,
    /// Закрыть все документы
    Close_All_Documents,
    /// Сохранить активный документ
    Save_Document,
    /// Сохранить все документы
    Save_All_Documents,
    /// Импоритровать из формата другого редактора в новый документ
    Import_From_File,
    /// Экспортировать в формат другого редактора
    Export_to_File,
    /// Нарисовать линию
    DrawLine,
    /// Нарисовать окружность.
    DrawCircle,
    /// Нарисовать прямоугольник
    DrawRectangle,
    /// Удалить выделенный графический элемент
    DeleteSelected,
};