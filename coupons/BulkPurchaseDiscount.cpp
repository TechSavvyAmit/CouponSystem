#include "BulkPurchaseDiscount.h"
#include "../utils/Logger.h"
#include "../utils/UIHelper.h"

BulkPurchaseDiscount::BulkPurchaseDiscount(double thr, double off)
    : threshold(thr), flatOff(off)
{

    strat = DiscountStrategyManager::getInstance()
                ->getStrategy(FLAT, flatOff);
}

BulkPurchaseDiscount::~BulkPurchaseDiscount()
{
    delete strat;
}

bool BulkPurchaseDiscount::isApplicable(Cart *cart)
{
    return cart->getOriginalTotal() >= threshold;
}

double BulkPurchaseDiscount::getDiscount(Cart *cart)
{
    double discount = strat->calculate(cart->getCurrentTotal());

    UIHelper::printDiscount(name(), discount);

    return discount;
}

std::string BulkPurchaseDiscount::name()
{
    return "Bulk Discount Rs " + std::to_string((int)flatOff) +
           " on min Rs " + std::to_string((int)threshold);
}