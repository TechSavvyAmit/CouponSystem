#pragma once

#include "Coupon.h"
#include "../strategies/DiscountStrategyManager.h"
#include <string>

class BankingCoupon : public Coupon {
private:
    std::string bank;
    double minSpend;
    double percent;
    double offCap;
    DiscountStrategy* strat;

public:
    BankingCoupon(const std::string& b, double ms, double pct, double cap);
    ~BankingCoupon();

    bool isApplicable(Cart* cart) override;
    double getDiscount(Cart* cart) override;
    std::string name() override;
};