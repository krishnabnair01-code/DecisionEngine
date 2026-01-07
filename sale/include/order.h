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
    bool isActive;

    // ✅ Default constructor (needed for unordered_map)
    Order()
        : id(0),
          type(OrderType::BUY),
          price(0.0),
          quantity(0),
          timestamp(0),
          isActive(false) {}

    // Normal constructor
    Order(int id,
          OrderType type,
          double price,
          int quantity,
          long long timestamp)
        : id(id),
          type(type),
          price(price),
          quantity(quantity),
          timestamp(timestamp),
          isActive(true) {}
};
