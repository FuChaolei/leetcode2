#include <bits/stdc++.h>
using namespace std;
class AbstractApple
{
public:
    virtual void ShowName() = 0;
};
class ChinaApple : public AbstractApple
{
public:
    virtual void ShowName()
    {
        cout << "i'm Chinaapple" << endl;
    }
};
class USAApple : public AbstractApple
{
public:
    virtual void ShowName()
    {
        cout << "i'm USAapple" << endl;
    }
};
class AbstractBanana
{
public:
    virtual void ShowName() = 0;
};
class ChinaBanana : public AbstractBanana
{
public:
    virtual void ShowName()
    {
        cout << "i'm ChinaBanana" << endl;
    }
};
class USABanana : public AbstractBanana
{
public:
    virtual void ShowName()
    {
        cout << "i'm USABanana" << endl;
    }
};
class AbstractFactory
{
public:
    virtual AbstractApple *CreateApple() = 0;
    virtual AbstractBanana *CreateBanan() = 0;
};
class ChinaFactory : public AbstractFactory
{
public:
    virtual AbstractApple *CreateApple()
    {
        return new ChinaApple;
    }
    virtual AbstractBanana *CreateBanan()
    {
        return new ChinaBanana;
    }
};
class USAFactory : public AbstractApple
{
public:
    virtual AbstractApple *CreateApple()
    {
        return new USAApple;
    }
    virtual AbstractBanana *CreateBanan()
    {
        return new USABanana;
    }
};
int main()
{
    AbstractFactory *factory = new ChinaFactory;
    AbstractApple *fruit = factory->CreateApple();
    fruit->ShowName();
    delete fruit;
    fruit = nullptr;
    delete factory;
    factory = nullptr;
    return 0;
}
