#pragma once
#include "DiscountStrategy.h"

class FlatDiscountStrategy : public DiscountStrategy {
    double amount;

public:
    FlatDiscountStrategy(double amt) : amount(amt) {}
    double calculate(double base) override {
        return amount > base ? base : amount;
    }
};