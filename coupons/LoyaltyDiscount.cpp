#include "LoyaltyDiscount.h"
#include "../utils/Logger.h"
#include "../utils/UIHelper.h"

LoyaltyDiscount::LoyaltyDiscount(double pct) : percent(pct)
{
    strat = DiscountStrategyManager::getInstance()
                ->getStrategy(PERCENT, percent);
}

LoyaltyDiscount::~LoyaltyDiscount()
{
    delete strat;
}

bool LoyaltyDiscount::isApplicable(Cart *cart)
{
    return cart->isLoyaltyMember();
}

double LoyaltyDiscount::getDiscount(Cart *cart)
{
    double discount = strat->calculate(cart->getCurrentTotal());

    UIHelper::printDiscount(name(), discount);

    return discount;
}

std::string LoyaltyDiscount::name()
{
    return "Loyalty Discount " + std::to_string((int)percent) + "%";
}