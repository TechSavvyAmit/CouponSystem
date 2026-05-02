#pragma once
#include <string>

class Product {
private:
    std::string name;
    std::string category;
    double price;

public:
    Product(std::string name, std::string category, double price);

    std::string getName();
    std::string getCategory() const;
    double getPrice();
};