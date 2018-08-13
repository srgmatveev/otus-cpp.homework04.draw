/**
 * @file mdi.cpp
 * @brief Реализация Multi document interface методов
 */
#include "mdi.h"

/**
 * @brief MDI контроллер
 * @param[in] _message - тип сообщения
 */
void mdi::Dispatcher(Message _message) {
    switch (_message) {
        case Message::New_Document: {
            std::shared_ptr<Document> tmp_doc = docFactory::Create();
            mdi::instance().Active_Document = tmp_doc;
            mdi::instance().documents.emplace_back(tmp_doc);
            Logger::Instance().info("Create document id = " + std::to_string(Active_Document->get_id()));
        }
            break;
        case Message::Set_Active_Document: {
            size_t id = 1;
            auto item = find_document_by_id(id);
            if (item) {
                Active_Document = item;
                Logger::Instance().info("Active document id = " + std::to_string(Active_Document->get_id()));
            } else {
                Logger::Instance().warn("Can't active document with id = " + std::to_string(id));
            }
        }
            break;
        case Message::DrawLine: {
            std::shared_ptr<IShape> line = std::make_shared<Line>(Point(1, 1), Point(2, 3));
            Active_Document->Create_IShape(line);
        }
            break;
        case Message::DrawCircle: {
            std::shared_ptr<IShape> circle = std::make_shared<Circle>(Point(2, 1), 5);
            Active_Document->Create_IShape(circle);
        }
            break;
        case Message::DrawRectangle: {
            std::shared_ptr<IShape> rectangle = std::make_shared<Rectangle>(Point(3, 1), 3, 4, 15);
            Active_Document->Create_IShape(rectangle);
        }
            break;
        case Message::DrawSquare: {
            std::shared_ptr<IShape> square = std::make_shared<Square>(Point(15, 6), 4);
            Active_Document->Create_IShape(square);
        }
            break;
        case Message::DeleteSelected: {
            Active_Document->Delete_Selected_IShape();
        }
            break;
        case Message::Import_From_File: {
            Import_Document();
        }
            break;
        case Message::Export_to_File:
            Export_Active_Document();
            break;
        case Message::Close_Document:
            Close_Active_Document();
            break;
        case Message::Close_All_Documents:
            Close_All_Documents();
            break;
        case Message::Save_Document:
            if (Active_Document)
                Logger::Instance().info("Save document with id = " + std::to_string(Active_Document->get_id()));
            break;
        case Message::Save_All_Documents:
            Save_All_Documents();
            break;
        case Message::Open_Document:
            Open_Document();
            break;
        default:
            break;
    }
}

/**
    * @brief Найти документ по его id
    * @param[in] id - уникальный идентификатор документа
    * @return std::shared_ptr<Document> - указатель на документ
    */
std::shared_ptr<Document> mdi::find_document_by_id(const size_t &id) {
    auto it = std::find_if(documents.cbegin(), documents.cend(), [&](std::shared_ptr<Document> const &p) {
        return p->get_id() == id;
    });

    if (it != documents.cend()) return *it;
    else return nullptr;
}

/**
 * @brief Импорт документа другого формата
 */
void mdi::Import_Document() {
    Logger::Instance().info("Import document from Adobe Illustrator");
    std::shared_ptr<Document> tmp_doc = docFactory::Create();
    tmp_doc->set_file_name("Imported_from_Adobe_Illustrator.mdr");
    std::shared_ptr<IShape> circle = std::make_shared<Circle>(Point(12, 51), 8);
    tmp_doc->Create_IShape(circle);
    mdi::instance().Active_Document = tmp_doc;
    mdi::instance().documents.emplace_back(tmp_doc);
    Logger::Instance().info("Import ended and create document id = " + std::to_string(Active_Document->get_id()));
}

/**
 * @brief Экспорт в документ формат другого графического редактора
 */
void mdi::Export_Active_Document() {
    if (Active_Document)
        Logger::Instance().info("Export active document to Corel Draw format.");
}

/**
 * @brief Закрыть активный документ
 */
void mdi::Close_Active_Document() {
    if (!Active_Document) return;

    Logger::Instance().info("Active document with id=" + std::to_string(Active_Document->get_id()) + " is closed.");
    auto it = std::find_if(documents.cbegin(), documents.cend(), [&](std::shared_ptr<Document> const &p) {
        return p->get_id() == Active_Document->get_id();
    });

    if (it != documents.cend()) documents.erase(it);

    if (documents.size() > 0) Active_Document = documents.at(0);
}

/**
 * @brief Закрыть все документы
 */
void mdi::Close_All_Documents() {
    if (!documents.size()) return;
    Logger::Instance().info("Begin close all documents...");
    for ( auto it = documents.end() - 1; it != documents.begin() - 1; it-- ) {
        Logger::Instance().info("Close document wit id = " +
                                std::to_string(static_cast<std::shared_ptr<Document>>(*it)->get_id()));
    }
    Logger::Instance().info("End close all documents...");
}

/**
 * @brief Сохранить все документы
 */
void mdi::Save_All_Documents() {
    if (!documents.size()) return;
    Logger::Instance().info("Begin save all documents...");
    for ( auto it = documents.end() - 1; it != documents.begin() - 1; it-- ) {
        Logger::Instance().info("Save document wit id = " +
                                std::to_string(static_cast<std::shared_ptr<Document>>(*it)->get_id()));
    }
    Logger::Instance().info("End save all documents...");
}

/**
 * @brief Загрузить документ
 */
void mdi::Open_Document() {
    std::shared_ptr<Document> tmp_doc = docFactory::Create();
    tmp_doc->set_file_name("Vector graphic document.mdr");
    mdi::instance().Active_Document = tmp_doc;
    mdi::instance().documents.emplace_back(tmp_doc);
    Logger::Instance().info("Open Document named \"" + Active_Document->get_file_name()
                            + "\" and set document id=" + std::to_string(Active_Document->get_id()));
    std::shared_ptr<IShape> rectangle = std::make_shared<Rectangle>(Point(12, 51), 8, 20);
    Active_Document->Create_IShape(rectangle);
}

