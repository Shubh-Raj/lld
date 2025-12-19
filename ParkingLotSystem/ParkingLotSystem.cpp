#include <bits/stdc++.h>
using namespace std;

enum VehicleSize
{
    SMALL,
    MEDIUM,
    LARGE
};

class Vehicle
{
private:
    VehicleSize vehiclesize;
    string licenseNumber;

public:
    Vehicle(VehicleSize vs, string license)
    {
        vehiclesize = vs;
        licenseNumber = license;
    }
    VehicleSize getSize()
    {
        return vehiclesize;
    }
    string getLicenseNumber()
    {
        return licenseNumber;
    }
};

class Truck : public Vehicle
{
public:
    Truck(string license) : Vehicle(LARGE, license) {}
};

class Car : public Vehicle
{
public:
    Car(string license) : Vehicle(MEDIUM, license) {}
};

class Bike : public Vehicle
{
public:
    Bike(string license) : Vehicle(SMALL, license){}
};


