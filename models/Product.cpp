#include "Product.h"

Product::Product(std::string name, std::string category, double price)
    : name(name), category(category), price(price) {}

std::string Product::getName() { return name; }
std::string Product::getCategory() const { return category; }
double Product::getPrice() { return price; }