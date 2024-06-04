#ifndef NORMALIZATIONPARAMETERS_H
#define NORMALIZATIONPARAMETERS_H
#include <vector>

class NormalizationParameters
{
private:
    double _min;
    double _max;
public:
    NormalizationParameters(double min, double max);

    double min() const;
    double max() const;
    void setMin(double min);
    void setMax(double max);
    void normilize(std::vector<std::vector<double>>& values) const;
};

#endif // NORMALIZATIONPARAMETERS_H
