
#pragma once

#include <mutex>
#include <memory>
#include <vector>
#include <algorithm>
#include "utils.h"
#include "document.h"
#include "dispatch_message.h"

class mdi {
public:
    static mdi &instance() {
        static mdi instance;
        return instance;
    }

    void init() {
        Logger::Instance().info("Initialization Multi Document Interface");
    }

    void Dispatcher(Message, size_t);

    std::shared_ptr<Document> find_document_by_id(const size_t &);

private:
    mdi() = default;

    mdi(const mdi &) = delete;

    mdi(mdi &&rhs) = delete;

    mdi &operator=(const mdi &) = delete;

    std::shared_ptr<Document> Active_Document{nullptr};
    std::vector<std::shared_ptr<Document>> documents;
};


void mdi::Dispatcher(Message _message, size_t= 0) {
    switch (_message) {
        case Message::New_Document: {
            std::shared_ptr<Document> tmp_doc = docFactory::Create();
            mdi::instance().Active_Document = tmp_doc;
            mdi::instance().documents.emplace_back(tmp_doc);
            Logger::Instance().info("Create document id=" + std::to_string(Active_Document->get_id()));
        }
            break;
        case Message::Set_Active_Document: {
            size_t id = 1;
            auto item = find_document_by_id(id);
            if (item) {
                Active_Document = item;
                Logger::Instance().info("Active document id=" + std::to_string(Active_Document->get_id()));
            } else {
                Logger::Instance().warn("Can't active document with id=" + std::to_string(id));
            }
        }
            break;
        case Message::DrawLine:
        {
            std::shared_ptr<IShape> line = std::make_shared<Line>(Point(1,1),Point(2,3));
            Active_Document->Create_IShape(line);
        }
        break;
        default:
            break;
    }
}

std::shared_ptr<Document> mdi::find_document_by_id(const size_t &id) {
    auto it = std::find_if(documents.cbegin(), documents.cend(), [&](std::shared_ptr<Document> const &p) {
        return p->get_id() == id;});

    if (it != documents.cend()) return *it;
    else return nullptr;
}