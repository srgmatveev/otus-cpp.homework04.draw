/**
 * @file document.cpp
 * @brief Реализация функций документа
 */
#include "document.h"
/// Конструктор по умолчанию
Document::Document() {
    _document_id = Document::set_id();
    set_file_name("Default picture " + std::to_string(_document_id));
}
/// Статический счетчик документов
size_t Document::counter = 0;
/// Создать графический примитив
void Document::Create_IShape(std::shared_ptr<IShape> shape_ptr) {
    shape_ptr->draw();
    Elements.emplace_back(shape_ptr);
}
/// Удалить выделенный графический примитив
void Document::Delete_Selected_IShape() {

    if (Elements.size() > 0) {
        Logger::Instance().info(Elements.at(Elements.size() - 1)->string_info(true));
        Elements.pop_back();
    }
}

