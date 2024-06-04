#ifndef BASEFILEREADER_H
#define BASEFILEREADER_H
#include "scene/scene.h"
#include "normalizationparameters.h"
#include <string>

class BaseFileReader
{
public:
    virtual ~BaseFileReader() = default;

    virtual Scene read(const std::string& path) = 0;
    virtual Scene read(const std::string& path, const NormalizationParameters& parameters) = 0;
};

#endif // BASEFILEREADER_H
