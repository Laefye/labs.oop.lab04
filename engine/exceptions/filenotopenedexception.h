#ifndef FILENOTOPENEDEXCEPTION_H
#define FILENOTOPENEDEXCEPTION_H
#include <exception>

class FileNotOpenedException : public std::exception
{
public:
    const char* what() const noexcept override {
        return "File not opened";
    }
};

#endif // FILENOTOPENEDEXCEPTION_H
