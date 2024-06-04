#include "incorrectindexexception.h"

IncorrectIndexException::IncorrectIndexException() {}

const char* what() noexcept {
    return "Incorrect index";
}
