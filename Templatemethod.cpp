#include <bits/stdc++.h>
using namespace std;

class TemplateClass
{
    TemplateClass *model;

public:
    TemplateClass(TemplateClass *str)
    {
        model = str;
    }
    virtual void step1() = 0;
    virtual void step2() = 0;
    virtual void step3() = 0;
    void TemplateMethod()
    {
        model->step1();
        model->step2();
        model->step3();
    }
};

class ConcreteClassA : public TemplateClass
{
public:
    ConcreteClassA() : TemplateClass(this) {}
    void step2() override
    {
        cout << "A step 2\n";
    }
    void step1() override
    {
        cout << "A step 1\n";
    }
    void step3() override
    {
        cout << "A step 3\n";
    }
};

class ConcreteClassB : public TemplateClass
{
public:
    ConcreteClassB() : TemplateClass(this) {}
    void step2() override
    {
        cout << "b step 2\n";
    }
    void step1() override
    {
        cout << "b step 1\n";
    }
    void step3() override
    {
        cout << "b step 3\n";
    }
};

class Client
{
    TemplateClass *tc;

public:
    Client(TemplateClass *str)
    {
        tc = str;
    }
    void method()
    {
        tc->TemplateMethod();
    }
};

int main()
{
    ConcreteClassA a;
    Client *c = new Client(&a);
    c->method();
}