#pragma once
#include "DiscountStrategy.h"
#include "FlatDiscountStrategy.h"
#include "PercentageDiscountStrategy.h"
#include "PercentageWithCapStrategy.h"

enum StrategyType
{
    FLAT,
    PERCENT,
    PERCENT_WITH_CAP,
    SEASONAL
};

class DiscountStrategyManager
{
public:
    static DiscountStrategyManager *getInstance();

    DiscountStrategy *getStrategy(
        StrategyType type,
        double p1,
        double p2 = 0.0);
};