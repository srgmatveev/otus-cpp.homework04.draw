//
// Created by sergio on 09.08.18.
//

#pragma once

#include <exception>
#include <string>

#define Interface class

class msg_exception : public std::exception {
private:
    std::string message_;
public:
    explicit msg_exception(const std::string& message):message_(message){}
    virtual const char* what() const throw() {
        return message_.c_str();
    }
};

#include <iostream>
#include <string>

class Logger
{
public:
    static Logger& Instance() {
        static Logger instance;
        return instance;
    }

    void info(const std::string &message) {
        std::cout << "\tinfo: " << message << std::endl;
    }

    void warn(const std::string &message) {
        std::cerr << "warning: " << message << std::endl;
    }
private:
    Logger() = default;
    Logger(const Logger& root) = delete;
    Logger(Logger&& ths) = delete;
    Logger& operator=(const Logger&) = delete;
};
