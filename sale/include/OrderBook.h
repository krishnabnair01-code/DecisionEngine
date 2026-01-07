#pragma once
#include <queue>
#include <unordered_map>
#include "Order.h"

struct BuyComparator {
    bool operator()(const Order& a, const Order& b) {
        if (a.price == b.price)
            return a.timestamp > b.timestamp;
        return a.price < b.price;
    }
};

struct SellComparator {
    bool operator()(const Order& a, const Order& b) {
        if (a.price == b.price)
            return a.timestamp > b.timestamp;
        return a.price > b.price;
    }
};

class OrderBook {
public:
    std::priority_queue<Order, std::vector<Order>, BuyComparator> buyOrders;
    std::priority_queue<Order, std::vector<Order>, SellComparator> sellOrders;

    std::unordered_map<int, Order> orderMap;
};
