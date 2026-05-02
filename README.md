# 🛒 Coupon System Engine (C++ | Low-Level Design)

> A scalable and extensible coupon & discount engine built using modern C++ and industry-level design patterns.

---

## 🚀 Overview

This project simulates a real-world **e-commerce coupon system** where multiple discount strategies can be dynamically applied to a shopping cart.

The system is designed with clean architecture principles, making it easy to:
- Add new coupon types
- Modify discount logic
- Scale without breaking existing code

---

## ✨ Key Highlights

✔ Plug-and-play coupon system  
✔ Easily extendable discount strategies  
✔ Real-world LLD implementation  
✔ Clean modular architecture  
✔ Logging support for traceability  

---

## 🎯 Supported Coupon Types

- 🎉 Seasonal Discounts  
- 🏆 Loyalty-Based Discounts  
- 📦 Bulk Purchase Discounts  
- 💳 Banking Coupons  

---

## 🧠 Design Patterns Used

### 🔹 Strategy Pattern
Encapsulates different discount algorithms and allows dynamic selection at runtime.

### 🔹 Factory Pattern
Used via `DiscountStrategyManager` to decide which strategy to apply.

### 🔹 Singleton Pattern
Ensures a single instance of `CouponManager` across the system.

---

## 🏗️ Project Architecture

```
CouponSystem/
│
├── models/        # Core data structures (Cart, Product, CartItem)
├── coupons/       # Coupon definitions
├── strategies/    # Discount calculation logic
├── managers/      # Business logic controllers
├── utils/         # Logger & helper utilities
│
├── main.cpp       # Entry point
├── README.md
├── .gitignore
```

---

## ⚙️ How It Works (Flow)

1. User adds items to cart  
2. Coupons are applied  
3. System selects appropriate strategy  
4. Discount is calculated  
5. Final price is generated  
6. Logs are recorded  

---

## 🧪 Sample Output

```
Original Cart Total: 25000 Rs
[OK] Seasonal Offer 10% on Clothing           - Rs 300
[OK] Loyalty Discount 5%                      - Rs 1235
[OK] Bulk Discount Rs 100 on min Rs 1000      - Rs 100
[OK] ABC Bank 15% off upto Rs 500             - Rs 500
Final Cart Total: 22865 Rs
```

---

## 🛠️ Build & Run

### Compile:
```bash
g++ main.cpp models/*.cpp managers/*.cpp coupons/*.cpp strategies/*.cpp utils/*.cpp -o main
```

### Run:
```bash
./main.exe
```

## 👨‍💻 Author

Amit  
B.Tech ECE | NIT Kurukshetra  

---

## ⭐ If you like this project

Give it a star ⭐ and feel free to fork & improve!
