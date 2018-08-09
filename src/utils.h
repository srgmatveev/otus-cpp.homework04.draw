//
// Created by sergio on 09.08.18.
//

#pragma once

#include <exception>
#include <string>

class msg_exception : public std::exception {
private:
    std::string message_;
public:
    explicit msg_exception(const std::string& message):message_(message){}
    virtual const char* what() const throw() {
        return message_.c_str();
    }
};
