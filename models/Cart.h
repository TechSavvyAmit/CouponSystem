#pragma once
#include <vector>
#include <string>
#include "CartItem.h"

class Cart {
    std::vector<CartItem*> items;
    double originalTotal = 0;
    double currentTotal = 0;
    bool loyaltyMember = false;
    std::string paymentBank;

public:
    void addProduct(Product* p, int qty);
    double getOriginalTotal();
    double getCurrentTotal();
    void applyDiscount(double d);

    void setLoyaltyMember(bool val);
    bool isLoyaltyMember();

    void setPaymentBank(std::string bank);
    std::string getPaymentBank();

    std::vector<CartItem*> getItems();
};