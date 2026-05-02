#include "SeasonalOffer.h"
#include "../utils/Logger.h"
#include "../strategies/DiscountStrategyManager.h"
#include "../utils/UIHelper.h"

SeasonalOffer::SeasonalOffer(double pct, const std::string &cat)
{
    percent = pct;
    category = cat;

    DiscountStrategyManager manager;
    strat = manager.getStrategy(StrategyType::PERCENT, pct, 0);
}

SeasonalOffer::~SeasonalOffer()
{
}

bool SeasonalOffer::isApplicable(Cart *cart)
{
    const auto &items = cart->getItems();

    for (const auto &item : items)
    {
        if (item->getProduct()->getCategory() == category)
        {
            return true;
        }
    }
    return false;
}

double SeasonalOffer::getDiscount(Cart *cart)
{
    const auto &items = cart->getItems();
    double subtotal = 0;

    for (const auto &item : items)
    {
        if (item->getProduct()->getCategory() == category)
        {
            subtotal += item->itemTotal();
        }
    }

    double discount = (strat) ? strat->calculate(subtotal) : 0;

    UIHelper::printDiscount(name(), discount);

    return discount;
}

std::string SeasonalOffer::name()
{
    return "Seasonal Offer " + std::to_string((int)percent) +
           "% on " + category;
}