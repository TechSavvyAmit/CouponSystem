#include "BankingCoupon.h"
#include "../utils/Logger.h"
#include "../utils/UIHelper.h"

BankingCoupon::BankingCoupon(const std::string& b,
                             double ms,
                             double pct,
                             double cap)
    : bank(b), minSpend(ms), percent(pct), offCap(cap) {

    strat = DiscountStrategyManager::getInstance()
                ->getStrategy(PERCENT_WITH_CAP, percent, offCap);
}

BankingCoupon::~BankingCoupon() {
    delete strat;
}

bool BankingCoupon::isApplicable(Cart* cart) {
    return cart->getPaymentBank() == bank &&
           cart->getOriginalTotal() >= minSpend;
}

double BankingCoupon::getDiscount(Cart* cart) {
    double discount = strat->calculate(cart->getCurrentTotal());

    UIHelper::printDiscount(name(), discount);
    
    return discount;
}

std::string BankingCoupon::name() {
    return bank + " Bank " +
           std::to_string((int)percent) +
           "% off upto Rs " +
           std::to_string((int)offCap);
}