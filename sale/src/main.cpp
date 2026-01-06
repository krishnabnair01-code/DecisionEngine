#include <iostream>
#include "MatchingEngine.h"

int main() {
    MatchingEngine engine;

    engine.addOrder(Order(1, OrderType::BUY, 100, 10, 1));
    engine.addOrder(Order(2, OrderType::BUY, 101, 5, 2));
    engine.addOrder(Order(3, OrderType::SELL, 99, 7, 3));
    engine.addOrder(Order(4, OrderType::SELL, 100, 10, 4));

    return 0;
}
