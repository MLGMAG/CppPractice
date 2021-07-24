#include <iostream>
#include <string>

using namespace std;

class INotifier {
public:
    virtual void Notify(const string &message) = 0;
};

class SmsNotifier : public INotifier {
public:
    SmsNotifier(const string &phoneNumber) : phoneNumber_(phoneNumber) {
    }

    void Notify(const string &message) override {
        SendSms(phoneNumber_, message);
    }

private:
    const string phoneNumber_;
};

class EmailNotifier : public INotifier {
public:
    EmailNotifier(const string &emailAddress) : emailAddress_(emailAddress){
    }

    void Notify(const string &message) override {
        SendEmail(emailAddress_, message);
    }

private:
    const string emailAddress_;
};
