#include "StockPredictor.h"
#include <iostream>
#include <string>

int main() {
    StockPredictor predictor;
    predictor.loadData("historical_data.csv");
    predictor.train();

    double nextPrediction = predictor.predictNextPrice();
    std::cout << "Predicted next stock price: $" << nextPrediction << std::endl;

    return 0;
}
