#pragma once
#include <string>

enum class OrderType {
    BUY,
    SELL
};

class Order {
public:
    int id;
    OrderType type;
    double price;
    int quantity;
    long long timestamp;

    Order(int id,
          OrderType type,
          double price,
          int quantity,
          long long timestamp)
        : id(id),
          type(type),
          price(price),
          quantity(quantity),
          timestamp(timestamp) {}
};
