#include <gtest/gtest.h>
#include "../include/DocumentSignature.h"
#include "../include/FullName.h"  // Предполагаем, что этот класс существует

class DocumentSignatureTest : public ::testing::Test {
protected:
    FullName* fullName1;
    FullName* fullName2;
    DocumentSignature* docSig1;
    DocumentSignature* docSig2;

    DocumentSignatureTest() {
        // Создаем полные имена
        fullName1 = new FullName("John", "Middle", "Doe");
        fullName2 = new FullName("Jane", "Middle", "Doe");

        // Создаем подписи документов
        docSig1 = new DocumentSignature("ID123", *fullName1);
        docSig2 = new DocumentSignature("ID124", *fullName2);
    }

    ~DocumentSignatureTest() {
        delete fullName1;
        delete fullName2;
        delete docSig1;
        delete docSig2;
    }
};

TEST_F(DocumentSignatureTest, ConstructorTest) {
// Проверяем, что конструктор правильно присваивает идентификатор и имя создателя
ASSERT_EQ(docSig1->retrieveIdentifier(), "ID123");
ASSERT_EQ(docSig1->retrieveFirstName(), "John");
ASSERT_EQ(docSig1->retrieveMiddleName(), "Middle");
ASSERT_EQ(docSig1->retrieveFamilyName(), "Doe");
}

TEST_F(DocumentSignatureTest, AssignIdentifierTest) {
// Проверяем метод assignIdentifier
docSig1->assignIdentifier("NewID");
ASSERT_EQ(docSig1->retrieveIdentifier(), "NewID");
}

TEST_F(DocumentSignatureTest, AssignCreatorNameTest) {
// Проверяем метод assignCreatorName
docSig1->assignCreatorName(*fullName2);
ASSERT_EQ(docSig1->retrieveFirstName(), "Jane");
ASSERT_EQ(docSig1->retrieveMiddleName(), "Middle");
ASSERT_EQ(docSig1->retrieveFamilyName(), "Doe");
}

TEST_F(DocumentSignatureTest, IsIdenticalToTest) {
// Проверяем метод isIdenticalTo
DocumentSignature docSig3("ID123", *fullName1);
ASSERT_TRUE(docSig1->isIdenticalTo(docSig3)); // Идентичны по идентификатору и имени создателя

DocumentSignature docSig4("ID124", *fullName2);
ASSERT_FALSE(docSig1->isIdenticalTo(docSig4)); // Различаются по идентификатору и имени
}

TEST_F(DocumentSignatureTest, CopyFromTest) {
// Проверяем метод copyFrom
docSig2->copyFrom(*docSig1);
ASSERT_EQ(docSig2->retrieveIdentifier(), "ID123");
ASSERT_EQ(docSig2->retrieveFirstName(), "John");
ASSERT_EQ(docSig2->retrieveMiddleName(), "Middle");
ASSERT_EQ(docSig2->retrieveFamilyName(), "Doe");
}

TEST_F(DocumentSignatureTest, CloneFromFullNameTest) {
// Проверяем метод cloneFromFullName
FullName newFullName("Alice", "M", "Smith");
docSig1->cloneFromFullName(newFullName);
ASSERT_EQ(docSig1->retrieveFirstName(), "Alice");
ASSERT_EQ(docSig1->retrieveMiddleName(), "M");
ASSERT_EQ(docSig1->retrieveFamilyName(), "Smith");
}

TEST_F(DocumentSignatureTest, AssignFirstNameTest) {
// Проверяем метод assignFirstName
docSig1->assignFirstName("Michael");
ASSERT_EQ(docSig1->retrieveFirstName(), "Michael");
}

TEST_F(DocumentSignatureTest, AssignMiddleNameTest) {
// Проверяем метод assignMiddleName
docSig1->assignMiddleName("James");
ASSERT_EQ(docSig1->retrieveMiddleName(), "James");
}

TEST_F(DocumentSignatureTest, AssignFamilyNameTest) {
// Проверяем метод assignFamilyName
docSig1->assignFamilyName("Smith");
ASSERT_EQ(docSig1->retrieveFamilyName(), "Smith");
}

TEST_F(DocumentSignatureTest, IsCreatorNameEqualToTest) {
// Проверяем метод isCreatorNameEqualTo
DocumentSignature docSig5("ID123", *fullName1);
ASSERT_TRUE(docSig1->isCreatorNameEqualTo(docSig5));

DocumentSignature docSig6("ID125", *fullName2);
ASSERT_FALSE(docSig1->isCreatorNameEqualTo(docSig6));
}
