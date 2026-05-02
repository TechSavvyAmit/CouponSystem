#pragma once
#include "DiscountStrategy.h"

class PercentageWithCapStrategy : public DiscountStrategy {
    double percent, cap;

public:
    PercentageWithCapStrategy(double p, double c)
        : percent(p), cap(c) {}

    double calculate(double base) override {
        double d = base * percent / 100.0;
        return d > cap ? cap : d;
    }
};