#pragma once

#include "../models/Cart.h"
#include "../utils/Logger.h"
#include <string>

class Coupon {
protected:
    Coupon* next = nullptr;

public:
    virtual ~Coupon() {
        delete next;  // recursive cleanup
    }

    // 🔗 Chain management
    void setNext(Coupon* n) { next = n; }
    Coupon* getNext() const { return next; }

    // ⚙️ Core execution
    void applyDiscount(Cart* cart) {
        if (isApplicable(cart)) {
            double discount = getDiscount(cart);
            cart->applyDiscount(discount);

            Logger::log(name() + " applied: " + std::to_string(discount));

            // Stop chain if not combinable
            if (!isCombinable()) {
                Logger::log(name() + " is non-combinable. Stopping further coupons.");
                return;
            }
        }

        // Move to next coupon in chain
        if (next) {
            next->applyDiscount(cart);
        }
    }

    // 🧩 Abstract methods
    virtual bool isApplicable(Cart* cart) = 0;
    virtual double getDiscount(Cart* cart) = 0;
    virtual bool isCombinable() { return true; }
    virtual std::string name() = 0;
};