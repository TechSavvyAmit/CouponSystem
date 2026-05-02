#pragma once

#include "Coupon.h"
#include "../strategies/DiscountStrategyManager.h"
#include <string>

class SeasonalOffer : public Coupon {
private:
    double percent;
    std::string category;
    DiscountStrategy* strat;

public:
    SeasonalOffer(double pct, const std::string& cat);
    ~SeasonalOffer();

    bool isApplicable(Cart* cart) override;
    double getDiscount(Cart* cart) override;
    std::string name() override;
};