#include <bits/stdc++.h>
using namespace std;

class Product{
    int sku; 
    string name;
    double price;
    public:
    Product(int s, string n, double p){
        sku = s;
        name = n;
        price = p;
    }
    int getSku() {
        return this->sku;
    }
    string getName() {
        return this->name;
    }
    double getPrice() {
        return this->price;
    }
};

class ProductFactory {
public:
    static Product* createProduct(int sku) {
        // In reality product comes from DB
        string name;
        double price;

        if (sku == 101) {
            name  = "Apple";
            price = 20;
        }
        else if (sku == 102) {
            name  = "Banana";
            price = 10;
        }
        else if (sku == 103) {
            name  = "Chocolate";
            price = 50;
        }
        else if (sku == 201) {
            name  = "T-Shirt";
            price = 500;
        }
        else if (sku == 202) {
            name  = "Jeans";
            price = 1000;
        }
        else {
            name  = "Item" + to_string(sku);
            price = 100;
        }
        return new Product(sku, name, price);
    }
};
