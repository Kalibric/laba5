#include "func2.h"

#include <QCoreApplication>
int idxx = 0;
using namespace std;
class Base
{
public:
    Base()
    {
        _INDEX = idxx;
        printf("Base create #1 [%d]\n", _INDEX);
        idxx++;
    }
    Base(Base *obj)
    {
        x = obj->x;
        y = obj->y;
        _INDEX = idxx;
        printf("Base create #2 [%d]\n", _INDEX);
        idxx++;
    }
    Base(Base &obj)
    {
        x = obj.x;
        y = obj.y;
        _INDEX = idxx;
        printf("Base create #3 [%d]\n", _INDEX);
        idxx++;
    }
    virtual ~Base()
    {
        printf("Base delete #1 [%d]\n", _INDEX);
    }
    int _INDEX;
    int x = 0;
    int y = 5;
};

class Desc : public Base
{
public:
    Desc()
    {
        printf("Desc create #1 [%d]\n", _INDEX);
    }
    Desc(Desc *obj) : Base(obj)
    {
        number = obj->number;
        name = obj->name;
        printf("Desc create #2 [%d]\n", _INDEX);
    }
    Desc(Desc &obj) : Base(obj)
    {
        number = obj.number;
        name = obj.name;
        printf("Desc create #3 [%d]\n", _INDEX);
    }
    virtual ~Desc()
    {
        printf("Desc delete #1 [%d]\n", _INDEX);
    }
    int number = 0;
    string name = "circle";
};

Base func11()
{
    Base b;
    b.x = 100;
    return b;
}

Base* func22()
{
    Base b;
    b.x = 200;
    return &b;
}

Base& func33()
{
    Base b;
    b.x = 300;
    return b;
}

Base func44()
{
    Base *b = new Base();
    return *b;
}

Base* func55()
{
    Base *b = new Base();
    return b;
}

Base& func66()
{
    Base *b = new Base();
    return *b;
}

void func2()
{
    Base b1 = func11();
    Base* b2 = func22();
    Base& b3 = func33();
    Base b4 = func44();
    Base* b5 = func55();
    Base& b6 = func66();
}
