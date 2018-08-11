//
// Created by sergio on 09.08.18.
//
#pragma #once

/**
 * @mainpage Макет простейшего графического векторного редактора.
 *  @section task Условие
 *  Спроектировать простейший графический векторный редактор.<br> Подготовить
 *макеты классов отражающих структуру будущего проекта.<br>
 *Функционал для макетирования следующй:<br>
 * @li создание нового документа
 * @li импорт документа из файла
 * @li экспорт документа в файл
 * @li создание графического примитива
 * @li удаление графического примитива
 * <br>Основной упор сделать на шаблон контроллера и полиморфизм.<br> Функции
 *являющиеся обработчками GUI собрать в одном файле с функцией main.
 *
 * @section tribe Требования к реализации
 * Внимание должен быть сосредоточено на декларациях, реализация только
 *в крайнем случае, для минимальной демонстрации необходимых вызовов.
 *Проект должен компилироваться, все заголовки должны пройти стадию
 *компиляции.<br>
 *Результатом работы должен быть каталог с диаграммами, опубликованный
 *на <i>github-pages</i>.
 *
 * @section check Проверка
 * Задание считается выполненным успешно, если все файлы прошли стадию
 *компиляции, все классы охвачены диаграммами, код успешно прошел
 *анализ.<br>
 *Будет отмечена скорость выполнения задания.
 *
 *
 */


#include <mutex>
#include "utils.h"
#include "mdi.h"
class App{
public:
    static App& instance() {
        static App instance;
        return instance;
    }
    void run(){
        Logger::Instance().info("Begin of showing Splash screen");
        Logger::Instance().info("Load plugins...");
        mdi::instance().init();
        Logger::Instance().info("End of showing Splash screen");
    }

    void App_Dispatcher(Message _message){
        mdi::instance().Dispatcher(_message);
    }

private:
    App() = default;
    App(const App &) = delete;
    App(App &&rhs) = delete;
    App &operator=(const App &) = delete;
 };

