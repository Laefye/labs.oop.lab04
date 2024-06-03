#ifndef INCORRECTINDEXEXCEPTION_H
#define INCORRECTINDEXEXCEPTION_H
#include <exception>

class IncorrectIndexException : public std::exception
{
public:
    const char* what() const noexcept override {
        return "Incorrect Index";
    }
};

#endif // INCORRECTINDEXEXCEPTION_H
