#pragma once

#include <memory>
#include <sstream>
#include "utils.h"


Interface IShape {
public:
    virtual void draw() = 0;
    virtual std::string string_info(bool) = 0;
    virtual ~IShape() {};
};

struct Point {
    int _x{0};
    int _y{0};

    Point(int x, int y) : _x(x), _y(y) {};

    Point() : _x(0), _y(0) {};
};


class Line : public IShape {
public:
    Line(const Point &begin, const Point &end) : _begin(begin), _end(end) {}

    void draw() override {
        Logger::Instance().info(string_info());
    }

    ~Line() override {string_info(true);}

    std::string string_info(bool del_flag = false) override {
        std::ostringstream stream;
        if (del_flag) stream << "Delete ";
        else stream << "Draw ";
        stream << "line from x = " << _begin._x << " y = " << _begin._y;
        stream << " to x = " << _end._x << " y = " << _end._y;
        return stream.str();
    }

private:
    Point _begin;
    Point _end;
};


class Rectangle : public IShape {
public:
    Rectangle(const Point &top, const size_t &height, const size_t &width, const __uint16_t &rotate = 0) :
            _top(top), _height(height), _width(width), _angle(rotate) {}

    void draw() override {
        Logger::Instance().info(string_info());
    }

    ~Rectangle() override {string_info(true);}

    std::string string_info(bool del_flag = false) override {
        std::ostringstream stream;
        if (del_flag) stream << "Delete ";
        else stream << "Draw ";
        stream << "rectangle from top {" << _top._x << ", " << _top._y << "} ";
        stream << " with height = " << _height << " width = " << _width;
        stream << " and rotate angle = " << _angle;
        return stream.str();
    }

private:
    Point _top{0, 0};
    ///  The height of the rectangle.
    size_t _height{0};
    /// The width of the rectangle.
    size_t _width{0};
    /// The rotate angle in degrees/
    __uint16_t _angle{0};
};

class Circle : public IShape {
public:
    Circle(const Point &center, const size_t &radius) : _center(center), _radius(radius) {}

    void draw() override {
        Logger::Instance().info(string_info());
    }

    ~Circle() override {string_info(true);}

    std::string string_info(bool del_flag = false) override {
        std::ostringstream stream;
        if (del_flag) stream << "Delete ";
        else stream << "Draw ";
        stream << "circle with center at  x = " << _center._x << " y = " << _center._y;
        stream << " with radius = " << _radius;
        return stream.str();
    }

private:
    Point _center;
    size_t _radius;
};

