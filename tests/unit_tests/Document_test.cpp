#include <gmock/gmock.h>
#include "document.cpp"

using namespace testing;

TEST(Document_Test, Document_Test_Factor_Test) {

    std::shared_ptr<Document> doc = docFactory::Create();
    ASSERT_EQ(doc->get_id(), 1);

    std::shared_ptr<Document> doc1 = docFactory::Create();
    ASSERT_EQ(doc1->get_id(), 2);

    std::shared_ptr<Document> doc2 = docFactory::Create();
    ASSERT_EQ(doc2->get_id(), 3);
}

TEST(Document_Test, Document_Test_Doc_Name_Test) {
    std::shared_ptr<Document> doc = std::make_shared<Document>();
    std::string str = "vector name.doc";
    doc->set_file_name(str);
    ASSERT_EQ(doc->get_file_name(), str);
}