#include "DiscountStrategyManager.h"

static DiscountStrategyManager* instance = nullptr;

DiscountStrategyManager* DiscountStrategyManager::getInstance() {
    if (!instance) instance = new DiscountStrategyManager();
    return instance;
}

DiscountStrategy* DiscountStrategyManager::getStrategy(
    StrategyType type, double p1, double p2) {

    if (type == FLAT) return new FlatDiscountStrategy(p1);
    if (type == PERCENT) return new PercentageDiscountStrategy(p1);
    if (type == PERCENT_WITH_CAP)
        return new PercentageWithCapStrategy(p1, p2);
    if (type == SEASONAL)
    return new PercentageDiscountStrategy(p1);

    return nullptr;
}