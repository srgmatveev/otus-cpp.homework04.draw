/**
 * @file mdi.h
 * @brief Multi document interface класс
 */
#pragma once

#include <mutex>
#include <memory>
#include <vector>
#include <algorithm>
#include "utils.h"
#include "document.h"
#include "dispatch_message.h"

/**
 *  @brief Multi document interface класс синглтон
 */
class mdi {
public:
    /// Ссылка на единственный метод класса
    static mdi &instance() {
        static mdi instance;
        return instance;
    }

    /// Инициализация mdi
    void init() {
        Logger::Instance().info("Initialization Multi Document Interface");
    }

    /**
    * @brief MDI контроллер
    */
    void Dispatcher(Message);

/**
    * @brief Найти документ по его id
    */
    std::shared_ptr<Document> find_document_by_id(const size_t &);

/**
 * @brief Импорт документа другого формата
 */
    void Import_Document();

/**
 * @brief Экспорт в документ формат другого графического редактора
 */
    void Export_Active_Document();

/**
 * @brief Закрыть активный документ
 */
    void Close_Active_Document();

/**
 * @brief Закрыть все документы
 */
    void Close_All_Documents();

/**
 * @brief Сохранить все документы
 */
    void Save_All_Documents();

/**
 * @brief Загрузить документ
 */
    void Open_Document();

private:
    /// Пустой конструктор по умолчанию
    mdi() = default;

    mdi(const mdi &) = delete;

    mdi(mdi &&rhs) = delete;

    mdi &operator=(const mdi &) = delete;
    /// Уазатель на докумен, который находится в фокусе
    std::shared_ptr<Document> Active_Document{nullptr};
    /// Вектор доументов, открытых редакторе
    std::vector<std::shared_ptr<Document>> documents;
};
