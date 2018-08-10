#pragma once
#include <memory>
#include <sstream>
#include "utils.h"


Interface IShape {
public:
    virtual void draw()=0;
    virtual ~IShape(){};
};

struct Point{
    int _x{0};
    int _y{0};
    Point(int x, int y) :_x(x), _y(y){};
    Point() : _x(0), _y(0){};
};


class Line: public IShape{
public:
    Line(const Point& begin, const Point& end): _begin(begin), _end(end) {}
    void draw(){
        Logger::Instance().info(string_info());
    }

    ~Line() override {}
     std::string string_info(){
        std::ostringstream stream;
        stream << "Draw line from x = "<<_begin._x<<" y = "<<_begin._y;
        stream << " to x = "<<_end._x<<" y = "<<_end._y;
        return stream.str();
    }
private:
    Point _begin;
    Point _end;
};


