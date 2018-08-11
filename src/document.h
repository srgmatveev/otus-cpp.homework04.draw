/**
 * @file document.h
 * @brief Файл для работы с содержимым документа
 *
 * Содержит функции для получения информации о документе, хранит графические объекты и т.д.
 */
#pragma once

#include <memory>
#include <vector>
#include "Shapes.h"
/**
 * @brief Класс, содержащий функции для работы с документом и хранящий графические объекты
 */
class Document {
public:
    /// Конструктор по умолчанию
    Document();
    /// Устанавливает номер документа в Multi_Document_Interface
    static size_t set_id() { return ++Document::counter; }
    ///  Получить номер документа в Multi_Document_Interface
    size_t get_id() { return _document_id; }
    /// Устанавливает имя документа
    void set_file_name(const std::string &name) { _file_name = name; }
    /// Получить имя документа
    std::string &get_file_name() { return _file_name; }
    /// Создать графический примитив
    void Create_IShape(std::shared_ptr<IShape>);
    /// Удалить выделенный графический примитив
    void Delete_Selected_IShape();
private:
    /// Номер документа
    size_t _document_id{0};
    /// Статияческий счетчик документов
    static size_t counter;
    /// Имя документа
    std::string _file_name{};
    /// Вектор указателей на графические примитивы
    std::vector<std::shared_ptr<IShape>> Elements;
};


Document::Document() {
    _document_id = Document::set_id();
    set_file_name("Default picture " + std::to_string(_document_id));
}

size_t Document::counter = 0;

void Document::Create_IShape(std::shared_ptr<IShape> shape_ptr) {
    shape_ptr->draw();
    Elements.emplace_back(shape_ptr);
}

void Document::Delete_Selected_IShape() {

    if (Elements.size() > 0) {
        Logger::Instance().info(Elements.at(Elements.size() - 1)->string_info(true));
        Elements.pop_back();
    }
}
/**
 * @brief Фабрика документов
 */
class docFactory {
public:
    /// Создать новый документ
    static std::shared_ptr<Document> Create() {
        return std::make_shared<Document>();
    }
};


