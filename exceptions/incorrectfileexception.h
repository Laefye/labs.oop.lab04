#ifndef INCORRECTFILEEXCEPTION_H
#define INCORRECTFILEEXCEPTION_H
#include <exception>

class IncorrectFileException : public std::exception
{
public:
    const char* what() const noexcept override {
        return "Incorrect File";
    }
};

#endif // INCORRECTFILEEXCEPTION_H
