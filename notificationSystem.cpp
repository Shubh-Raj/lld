#include <bits/stdc++.h>
using namespace std;

class INotification
{
public:
    virtual string getContent() const = 0;
    virtual ~INotification() {}
};

class SimpleNotification : public INotification
{
private:
    string text;

public:
    SimpleNotification(string &text)
    {
        this->text = text;
    }
    string getContent() const override
    {
        return text;
    }
};

class INotificationDecorator : public INotification
{
protected:
    INotification *notification;

public:
    INotificationDecorator(INotification *n)
    {
        notification = n;
    }
    virtual ~INotificationDecorator()
    {
        delete notification;
    }
};

class TimeStampDecorator : public INotificationDecorator
{
public:
    
    TimeStampDecorator(INotification *n) : INotificationDecorator(n) {}
    string getContent()
    {
        return "13th Dec" + notification->getContent();
    }
};

class SignatureDecorator : public INotificationDecorator
{
private:
    string signature;

public:
    SignatureDecorator(INotification *n, const string &sig) : INotificationDecorator(n)
    {
        signature = sig;
    }
    string getContent() const override
    {
        return notification->getContent() + "\n-- " + signature + "\n\n";
    }
};

int main(){
    cout<<"0";
}