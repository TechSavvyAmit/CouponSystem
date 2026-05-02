#include "CouponManager.h"
#include "../utils/Logger.h"

CouponManager *CouponManager::instance = nullptr;

// Constructor
CouponManager::CouponManager()
{
    head = nullptr;
}

// Singleton getter
CouponManager *CouponManager::getInstance()
{
    if (!instance)
    {
        instance = new CouponManager();
    }
    return instance;
}

// Register coupon (append to chain)
void CouponManager::registerCoupon(Coupon *coupon)
{
    std::lock_guard<std::mutex> lock(mtx);

    Logger::log("Registering coupon: " + coupon->name());

    if (!head)
    {
        head = coupon;
    }
    else
    {
        Coupon *cur = head;
        while (cur->getNext())
        {
            cur = cur->getNext();
        }
        cur->setNext(coupon);
    }
}

// Get list of applicable coupons (no mutation)
std::vector<std::string> CouponManager::getApplicable(Cart *cart) const
{
    std::lock_guard<std::mutex> lock(mtx);

    std::vector<std::string> result;

    Coupon *cur = head;
    while (cur)
    {
        if (cur->isApplicable(cart))
        {
            result.push_back(cur->name());
        }
        cur = cur->getNext();
    }

    return result;
}

// Apply all coupons (chain execution)
double CouponManager::applyAll(Cart *cart)
{
    std::lock_guard<std::mutex> lock(mtx);

    Logger::log("Starting coupon application");

    if (head)
    {
        head->applyDiscount(cart);
    }

    Logger::log("Finished coupon application. Final total: " +
                std::to_string(cart->getCurrentTotal()));

    return cart->getCurrentTotal();
}

// Destructor (cleanup chain)
CouponManager::~CouponManager()
{
    delete head;
}