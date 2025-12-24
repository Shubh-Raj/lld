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
    void getCarDetails(){
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Type: " << type << endl;
        cout << "License Plate No: " << licensePlateNo << endl;
        cout << "Year: " << year << endl;
        cout << "Rental Price Per Day: " << rentalPricePerDay << endl;
    }
};

int Car::carId = 0;

class SearchStrategy;

class CarManager{
    private:
    static CarManager* instance;
    vector<Car*> listOfCars;
    SearchStrategy* searchStrategy;
    CarManager(){}
    public:
    CarManager* getInstance(){
        if(instance==nullptr){
            instance = new CarManager();
        }
        return instance;
    }
    void setSearchStrategy(SearchStrategy* strategy){
        searchStrategy = strategy;
    }
    void addCar(Car* car){
        listOfCars.push_back(car);
    }
    void removeCar(Car* car){
        auto it = find(listOfCars.begin(), listOfCars.end(), car);
        if (it != listOfCars.end()) {
            listOfCars.erase(it);
        }
    }
    void getAllCarList(){
        for(Car* car: listOfCars){
            car->getCarDetails();
        }
    }
    // vector<Car*> performSearch(){
    //     return searchStrategy->findCars(listOfCars);
    // }
};