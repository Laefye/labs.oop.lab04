#ifndef FILEREADER_H
#define FILEREADER_H
#include "basefilereader.h"
#include "scene.h"
#include "normalizationparameters.h"
#include <vector>

class FileReader : public BaseFileReader
{
private:
    std::vector<double> parse(const std::string& line);
public:
    Scene read(const std::string& path, const NormalizationParameters& parameters) override;
};

#endif // FILEREADER_H
