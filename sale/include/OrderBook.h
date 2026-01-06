#pragma once
#include <queue>
#include "Order.h"

/*
 BUY orders:
   - Higher price first
   - If price same → earlier time first

 SELL orders:
   - Lower price first
   - If price same → earlier time first
*/

struct BuyComparator {
    bool operator()(const Order& a, const Order& b) {
        if (a.price == b.price)
            return a.timestamp > b.timestamp; // earlier wins
        return a.price < b.price; // higher price wins
    }
};

struct SellComparator {
    bool operator()(const Order& a, const Order& b) {
        if (a.price == b.price)
            return a.timestamp > b.timestamp; // earlier wins
        return a.price > b.price; // lower price wins
    }
};

class OrderBook {
public:
    std::priority_queue<Order, std::vector<Order>, BuyComparator> buyOrders;
    std::priority_queue<Order, std::vector<Order>, SellComparator> sellOrders;
};
