#include <bits/stdc++.h>
using namespace std;

/* =======================
   Product Interface
   ======================= */
class Notification {
public:
    virtual void send(const string& message) = 0;
    virtual ~Notification() {}
};

/* =======================
   Concrete Products
   ======================= */
class EmailNotification : public Notification {
public:
    void send(const string& message) override {
        cout << "Sending EMAIL: " << message << endl;
    }
};

class SMSNotification : public Notification {
public:
    void send(const string& message) override {
        cout << "Sending SMS: " << message << endl;
    }
};

class PushNotification : public Notification {
public:
    void send(const string& message) override {
        cout << "Sending PUSH notification: " << message << endl;
    }
};

class SlackNotification : public Notification {
public:
    void send(const string& message) override {
        cout << "Sending SLACK message: " << message << endl;
    }
};

/* =======================
   Creator (Factory Method)
   ======================= */
class NotificationCreator {
public:
    virtual Notification* createNotification() = 0;

    void send(const string& message) {
        Notification* notification = createNotification();
        notification->send(message);
        delete notification;
    }

    virtual ~NotificationCreator() {}
};

/* =======================
   Concrete Creators
   ======================= */
class EmailNotificationCreator : public NotificationCreator {
public:
    Notification* createNotification() override {
        return new EmailNotification();
    }
};

class SMSNotificationCreator : public NotificationCreator {
public:
    Notification* createNotification() override {
        return new SMSNotification();
    }
};

class PushNotificationCreator : public NotificationCreator {
public:
    Notification* createNotification() override {
        return new PushNotification();
    }
};

class SlackNotificationCreator : public NotificationCreator {
public:
    Notification* createNotification() override {
        return new SlackNotification();
    }
};

/* =======================
   Client Code
   ======================= */
int main() {
    NotificationCreator* creator;

    creator = new EmailNotificationCreator();
    creator->send("Welcome to our platform!");
    delete creator;

    creator = new SMSNotificationCreator();
    creator->send("Your OTP is 123456");
    delete creator;

    creator = new PushNotificationCreator();
    creator->send("You have a new follower!");
    delete creator;

    creator = new SlackNotificationCreator();
    creator->send("Standup in 10 minutes!");
    delete creator;

    return 0;
}
