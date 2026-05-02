#pragma once
#include "DiscountStrategy.h"

class PercentageDiscountStrategy : public DiscountStrategy {
    double percent;

public:
    PercentageDiscountStrategy(double p) : percent(p) {}
    double calculate(double base) override {
        return base * percent / 100.0;
    }
};