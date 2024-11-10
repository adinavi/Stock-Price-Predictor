#include "StockPredictor.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <numeric>

void StockPredictor::loadData(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        double price;
        ss >> price;
        prices.push_back(price);
    }
    file.close();
}

void StockPredictor::train() {
    size_t n = prices.size();
    if (n < 2) {
        std::cerr << "Not enough data to train." << std::endl;
        return;
    }

    // Calculate the mean of x and y
    double x_mean = (n - 1) / 2.0;
    double y_mean = std::accumulate(prices.begin(), prices.end(), 0.0) / n;

    // Calculate the slope (m) and intercept (b) for y = mx + b
    double num = 0.0, den = 0.0;
    for (size_t i = 0; i < n; ++i) {
        num += (i - x_mean) * (prices[i] - y_mean);
        den += (i - x_mean) * (i - x_mean);
    }
    slope = num / den;
    intercept = y_mean - slope * x_mean;
}

double StockPredictor::predictNextPrice() const {
    return slope * prices.size() + intercept;
}
