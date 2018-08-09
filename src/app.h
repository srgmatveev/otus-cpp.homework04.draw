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

#ifdef USE_X11
#include<X11/Xlib.h>
#include <X11/Xutil.h>
#endif

#include <mutex>


#include "utils.h"
#include "mdi.h"
class App {
    friend class Application;
    static std::shared_ptr<mdi> createMDI()
    {
        return mdiFactory::Create();
    }
public:
    App();
    std::shared_ptr<mdi> getMDI() {return _mdi;}
    virtual ~App();
#ifdef USE_X11
    Display* get_display() {return display;}
#endif
private:
    App(const App &) = delete;
    App(App &&rhs) = delete;
    App &operator=(const App &) = delete;

#ifdef USE_X11
    Display *display;
#endif
    std::shared_ptr<mdi> _mdi{nullptr};

};

class Application {
public:
    static bool alreadyCreated;

     static std::unique_ptr<App> run() {
        static std::mutex mutex;
        std::lock_guard<std::mutex> lock(mutex);
        if (alreadyCreated)
            throw msg_exception("Only one instance app can exist in program");
        alreadyCreated = true;
        return std::make_unique<App>();
    }

};

bool Application::alreadyCreated = false;

App::App() {
#ifdef USE_X11
    display = XOpenDisplay(NULL);
    if (!display) {
        std::string ss = std::string("Cannot connect to X server ") + std::string(getenv("DISPLAY"));
        std::cerr << ss <<std::endl;
        throw msg_exception(ss);
    }
#endif
_mdi = App::createMDI();

}

App::~App(){

#ifdef USE_X11
    if(display) {
        XCloseDisplay(display);
        display = nullptr;
    }
#endif
}