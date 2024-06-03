#ifndef INCORRECTSIZE_H
#define INCORRECTSIZE_H
#include <exception>

class IncorrectSize : public std::exception
{
public:
    const char* what() const noexcept override {
        return "Incorrect Size";
    }
};


#endif // INCORRECTSIZE_H
