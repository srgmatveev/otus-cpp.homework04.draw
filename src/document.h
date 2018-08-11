#pragma once

#include <memory>
#include <vector>
#include "Shapes.h"

class Document {
public:
    Document();

    static size_t set_id() { return ++Document::counter; }

    size_t get_id() { return _document_id; }

    void set_file_name(const std::string &name) { _file_name = name; }

    std::string &get_file_name() { return _file_name; }

    void Create_IShape(std::shared_ptr<IShape>);

    void Delete_Selected_IShape();

private:
    size_t _document_id{0};
    static size_t counter;
    std::string _file_name{};
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

class docFactory {
public:
    static std::shared_ptr<Document> Create() {
        return std::make_shared<Document>();
    }
};


