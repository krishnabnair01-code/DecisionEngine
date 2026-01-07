#pragma once
#include <iostream>
#include "OrderBook.h"

class MatchingEngine {
private:
    OrderBook orderBook;

    void cleanTop() {
        while (!orderBook.buyOrders.empty() &&
               !orderBook.buyOrders.top().isActive)
            orderBook.buyOrders.pop();

        while (!orderBook.sellOrders.empty() &&
               !orderBook.sellOrders.top().isActive)
            orderBook.sellOrders.pop();
    }

public:
    void addOrder(const Order& order) {
        orderBook.orderMap[order.id] = order;

        if (order.type == OrderType::BUY)
            orderBook.buyOrders.push(order);
        else
            orderBook.sellOrders.push(order);

        matchOrders();
    }

    void cancelOrder(int orderId) {
        if (orderBook.orderMap.count(orderId)) {
            orderBook.orderMap[orderId].isActive = false;
            std::cout << "CANCELLED Order ID: " << orderId << std::endl;
        }
    }

    void modifyOrder(int orderId, double newPrice, int newQty) {
        if (!orderBook.orderMap.count(orderId)) return;

        Order& oldOrder = orderBook.orderMap[orderId];
        oldOrder.isActive = false;

        Order newOrder(orderId,
                       oldOrder.type,
                       newPrice,
                       newQty,
                       oldOrder.timestamp + 1);

        addOrder(newOrder);

        std::cout << "MODIFIED Order ID: " << orderId << std::endl;
    }

    void matchOrders() {
        cleanTop();

        while (!orderBook.buyOrders.empty() &&
               !orderBook.sellOrders.empty()) {

            Order buy = orderBook.buyOrders.top();
            Order sell = orderBook.sellOrders.top();

            if (buy.price >= sell.price) {
                int tradedQty = std::min(buy.quantity, sell.quantity);

                std::cout << "TRADE | Price: " << sell.price
                          << " | Qty: " << tradedQty
                          << " | BuyID: " << buy.id
                          << " | SellID: " << sell.id
                          << std::endl;

                orderBook.buyOrders.pop();
                orderBook.sellOrders.pop();

                orderBook.orderMap[buy.id].quantity -= tradedQty;
                orderBook.orderMap[sell.id].quantity -= tradedQty;

                if (orderBook.orderMap[buy.id].quantity > 0)
                    orderBook.buyOrders.push(orderBook.orderMap[buy.id]);
                else
                    orderBook.orderMap[buy.id].isActive = false;

                if (orderBook.orderMap[sell.id].quantity > 0)
                    orderBook.sellOrders.push(orderBook.orderMap[sell.id]);
                else
                    orderBook.orderMap[sell.id].isActive = false;
            } else {
                break;
            }

            cleanTop();
        }
    }
};
