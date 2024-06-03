#include "filereader.h"
#include <fstream>
#include "exceptions/incorrectfileexception.h"

Scene FileReader::read(const std::string& path, const NormalizationParameters& parameters) {
    std::ifstream in(path, std::ios_base::in);
    std::vector<std::vector<double>> rows;
    while (!in.eof()) {
        std::string line;
        in >> line;
        std::vector<double> row = parse(line);
        if (row.size() > 0 && (rows.size() == 0 || (rows.size() > 0 && rows[0].size() == row.size()))) {
            rows.push_back(row);
        }
    }
    in.close();
    if (rows.size() == 0) {
        throw IncorrectFileException();
    }
    return Scene();
}

std::vector<double> FileReader::parse(const std::string& originalLine) {
    std::string line = originalLine.substr(0, originalLine.find_first_of("\r\n"));
    size_t index = 0;
    size_t end = 0;
    std::vector<double> values;
    while (end < line.length() && (end = line.find(",", index) != std::string::npos ? line.find(",", index) : line.length())) {
        std::string cell = line.substr(index, (end - index));
        index = end + 1;
        values.push_back(std::stoi(cell));
    }
    return values;
}
