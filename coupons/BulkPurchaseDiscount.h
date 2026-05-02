#pragma once

#include "Coupon.h"
#include "../strategies/DiscountStrategyManager.h"

class BulkPurchaseDiscount : public Coupon {
private:
    double threshold;
    double flatOff;
    DiscountStrategy* strat;

public:
    BulkPurchaseDiscount(double thr, double off);
    ~BulkPurchaseDiscount();

    bool isApplicable(Cart* cart) override;
    double getDiscount(Cart* cart) override;
    std::string name() override;
};