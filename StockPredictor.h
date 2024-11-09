#ifndef STOCKPREDICTOR_H
#define STOCKPREDICTOR_H

#include <vector>
#include <string>

class StockPredictor {
public:
    void loadData(const std::string& filename);
    void train();
    double predictNextPrice() const;

private:
    std::vector<double> prices;
    double slope = 0.0;
    double intercept = 0.0;
};

#endif
