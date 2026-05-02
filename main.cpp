#include <iostream>

#include "models/Product.h"
#include "models/Cart.h"

#include "coupons/SeasonalOffer.h"
#include "coupons/LoyaltyDiscount.h"
#include "coupons/BulkPurchaseDiscount.h"
#include "coupons/BankingCoupon.h"

#include "managers/CouponManager.h"
#include "utils/Logger.h"

using namespace std;

void setupCoupons(CouponManager* mgr) {
    mgr->registerCoupon(new SeasonalOffer(10, "Clothing"));
    mgr->registerCoupon(new LoyaltyDiscount(5));
    mgr->registerCoupon(new BulkPurchaseDiscount(1000, 100));
    mgr->registerCoupon(new BankingCoupon("ABC", 2000, 15, 500));
}

int main() {

    Logger::log("==== Application Started ====");

    // Step 1: Setup Coupon Manager
    CouponManager* mgr = CouponManager::getInstance();
    setupCoupons(mgr);

    // Step 2: Create Products
    Product* p1 = new Product("Winter Jacket", "Clothing", 1000);
    Product* p2 = new Product("Smartphone", "Electronics", 20000);
    Product* p3 = new Product("Jeans", "Clothing", 1000);
    Product* p4 = new Product("Headphones", "Electronics", 2000);

    // Step 3: Create Cart
    Cart* cart = new Cart();

    cart->addProduct(p1, 1);
    cart->addProduct(p2, 1);
    cart->addProduct(p3, 2);
    cart->addProduct(p4, 1);

    cart->setLoyaltyMember(true);
    cart->setPaymentBank("ABC");

    cout << "Original Cart Total: " << cart->getOriginalTotal() << " Rs" << endl;

    Logger::log("Original Total: " + to_string(cart->getOriginalTotal()));

    // Step 4: Apply Coupons
    double finalTotal = mgr->applyAll(cart);

    cout << "Final Cart Total: " << finalTotal << " Rs" << endl;

    Logger::log("Final Total: " + to_string(finalTotal));

    Logger::log("==== Application Finished ====");

    // Step 5: Cleanup (important)
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete cart;

    return 0;
}