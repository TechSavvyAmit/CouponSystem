#pragma once
#include "Product.h"

class CartItem {
    Product* product;
    int quantity;

public:
    CartItem(Product* p, int q);
    double itemTotal();
    Product* getProduct();
};