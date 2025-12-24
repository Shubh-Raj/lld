#include <bits/stdc++.h>
using namespace std;

class Car{
    private:
    static int carId;
    string make,model,type, licensePlateNo; 
    int year, rentalPricePerDay;
    public:
    Car(string& make, string& model,string& type, string& licensePlateNo, int year, int rentalPricePerDay){
        this->make = make;
        this->model = model;
        this->type = type;
        this->licensePlateNo = licensePlateNo;
        this->year = year;
        this->rentalPricePerDay = rentalPricePerDay;
        carId=++carId;
    }
    int getRentalPricePerDay(){
        return rentalPricePerDay;
    }
};