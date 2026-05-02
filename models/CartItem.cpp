#include "CartItem.h"

CartItem::CartItem(Product* p, int q) : product(p), quantity(q) {}

double CartItem::itemTotal() {
    return product->getPrice() * quantity;
}

Product* CartItem::getProduct() {
    return product;
}