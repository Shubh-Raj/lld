#include <bits/stdc++.h>
using namespace std;

class DiscountStrategy{
    public:
    virtual double calculate(double baseAmount) = 0;
    virtual ~DiscountStrategy(){}
};

class FlatDiscountStrategy : public DiscountStrategy{
    double amount;
    public:
    FlatDiscountStrategy(double amt){
        amount = amt;
    }
    double calculate(double baseAmount){
        return min(amount, baseAmount);
    }
};

class PercentageDiscountStrategy : public DiscountStrategy {
private:
    double percent;
public:
    PercentageDiscountStrategy(double pct) {
        percent = pct;
    }
    double calculate(double baseAmount) override {
        return (percent / 100.0) * baseAmount;
    }
};

class PercentageWithCapStrategy : public DiscountStrategy {
private:
    double percent;
    double cap;
public:
    PercentageWithCapStrategy(double pct, double capVal) {
        percent = pct;
        cap = capVal;
    }
    double calculate(double baseAmount) override {
        double disc = (percent / 100.0) * baseAmount;
        if (disc > cap) {
            return cap;
        }
        return disc;
    }
};

