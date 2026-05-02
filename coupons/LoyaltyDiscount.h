#pragma once

#include "Coupon.h"
#include "../strategies/DiscountStrategyManager.h"

class LoyaltyDiscount : public Coupon {
private:
    double percent;
    DiscountStrategy* strat;

public:
    LoyaltyDiscount(double pct);
    ~LoyaltyDiscount();

    bool isApplicable(Cart* cart) override;
    double getDiscount(Cart* cart) override;
    std::string name() override;
};