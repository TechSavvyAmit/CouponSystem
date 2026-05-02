#pragma once

#include "../coupons/Coupon.h"
#include "../models/Cart.h"

#include <vector>
#include <string>
#include <mutex>

class CouponManager {
private:
    static CouponManager* instance;
    Coupon* head;
    mutable std::mutex mtx;

    // Private constructor (Singleton)
    CouponManager();

public:
    // Delete copy operations
    CouponManager(const CouponManager&) = delete;
    CouponManager& operator=(const CouponManager&) = delete;

    static CouponManager* getInstance();

    void registerCoupon(Coupon* coupon);

    std::vector<std::string> getApplicable(Cart* cart) const;

    double applyAll(Cart* cart);

    ~CouponManager();
};