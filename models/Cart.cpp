#include "Cart.h"

void Cart::addProduct(Product* p, int qty) {
    CartItem* item = new CartItem(p, qty);
    items.push_back(item);
    originalTotal += item->itemTotal();
    currentTotal += item->itemTotal();
}

double Cart::getOriginalTotal() { return originalTotal; }
double Cart::getCurrentTotal() { return currentTotal; }

void Cart::applyDiscount(double d) {
    currentTotal -= d;
    if (currentTotal < 0) currentTotal = 0;
}

void Cart::setLoyaltyMember(bool val) { loyaltyMember = val; }
bool Cart::isLoyaltyMember() { return loyaltyMember; }

void Cart::setPaymentBank(std::string bank) { paymentBank = bank; }
std::string Cart::getPaymentBank() { return paymentBank; }

std::vector<CartItem*> Cart::getItems() { return items; }