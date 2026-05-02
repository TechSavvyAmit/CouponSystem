#pragma once

class DiscountStrategy {
public:
    virtual ~DiscountStrategy() {}
    virtual double calculate(double base) = 0;
};