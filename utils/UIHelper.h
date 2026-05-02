#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class UIHelper
{
public:
    static void printDiscount(string name, double amount)
    {
        cout << "[OK] " << left << setw(40) << name
             << " - Rs " << fixed << setprecision(0) << amount << endl;
    }
};