#include <bits/stdc++.h>
using namespace std;
 
class IPosition{
    protected:
    int days;
    IPosition* next;
    public:
    IPosition(int d){
        next=nullptr;
        days = d;
    }
    void setNextHandler(IPosition* ps){
        next=ps;
    }
    virtual void handleReq() = 0;
};

class HeadPos : public IPosition{
    public:
    HeadPos(int d) : IPosition(d) {} //point
    void handleReq() override {
        if(days<=2){
            cout<<"Approved by the team head\n";
        }
        else{
            next->handleReq();
        }
    }
};

class ManagerPos : public IPosition{
    public:
    ManagerPos(int d) : IPosition(d) {} //point
    void handleReq() override {
        if(days<=7){
            cout<<"Approved by the team Manager\n";
        }
        else{
            next->handleReq();
        }
    }
};

class DirectorPos : public IPosition{
    public:
    DirectorPos(int d) : IPosition(d) {} //point
    void handleReq() override {
        if(days<=10){
            cout<<"Approved by the team director\n";
        }
        else{
            cout<<"Cannot be approved\n";
        }
    }
};

int main(){
    int days;
    cout<<"How many days of leave do you want: ";
    cin >> days;
    if(days<=0){
        cout<<"Are you serious?\n";
        return 0;
    }
    IPosition* ps = new HeadPos(days);
    IPosition* ms = new ManagerPos(days);
    IPosition* ds = new DirectorPos(days);
    ps->setNextHandler(ms);
    ms->setNextHandler(ds);
    ps->handleReq();
}