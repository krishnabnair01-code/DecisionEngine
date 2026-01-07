#include "MatchingEngine.h"

int main() {
    MatchingEngine engine;

    engine.addOrder(Order(1, OrderType::BUY, 100, 10, 1));
    engine.addOrder(Order(2, OrderType::SELL, 99, 5, 2));

    engine.cancelOrder(1);

    engine.addOrder(Order(3, OrderType::BUY, 101, 7, 3));
    engine.modifyOrder(3, 102, 10);

    engine.addOrder(Order(4, OrderType::SELL, 100, 10, 4));

    return 0;
}
