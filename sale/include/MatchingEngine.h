#pragma once
#include <iostream>
#include "OrderBook.h"

class MatchingEngine {
private:
    OrderBook orderBook;

public:
    void addOrder(const Order& order) {
        if (order.type == OrderType::BUY) {
            orderBook.buyOrders.push(order);
        } else {
            orderBook.sellOrders.push(order);
        }

        matchOrders();
    }

    void matchOrders() {
        while (!orderBook.buyOrders.empty() &&
               !orderBook.sellOrders.empty()) {

            Order buy = orderBook.buyOrders.top();
            Order sell = orderBook.sellOrders.top();

            // Match condition
            if (buy.price >= sell.price) {
                int tradedQty = std::min(buy.quantity, sell.quantity);

                std::cout << "TRADE | Price: " << sell.price
                          << " | Qty: " << tradedQty
                          << " | BuyID: " << buy.id
                          << " | SellID: " << sell.id
                          << std::endl;

                orderBook.buyOrders.pop();
                orderBook.sellOrders.pop();

                buy.quantity -= tradedQty;
                sell.quantity -= tradedQty;

                if (buy.quantity > 0)
                    orderBook.buyOrders.push(buy);
                if (sell.quantity > 0)
                    orderBook.sellOrders.push(sell);
            } else {
                break; // No valid match
            }
        }
    }
};
