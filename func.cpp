#include "func.h"
#include <QCoreApplication>
int idx = 0;
using namespace std;
class Base
{
public:
    Base()
    {
        _INDEX = idx;
        printf("Base create #1 [%d]\n", _INDEX);
        idx++;
    }
    Base(Base *obj)
    {
        x = obj->x;
        y = obj->y;
        _INDEX = idx;
        printf("Base create #2 [%d]\n", _INDEX);
        idx++;
    }
    Base(Base &obj)
    {
        x = obj.x;
        y = obj.y;
        _INDEX = idx;
        printf("Base create #3 [%d]\n", _INDEX);
        idx++;
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

void func1(Base obj)
{
    printf("func1!\n");
}

void func2(Base *obj)
{
    printf("func2!\n");
}

void func3(Base &obj)
{
    printf("func3!\n");
}


void func()
{
    Desc d;
    Base b;
    d.x = 52;
    printf("-------\n");
    func1(d);
    func2(&d);
    func3(d);
    printf("-------\n");
    // func1(b);
    // func2(&b);
    // func3(b);
    printf("-------\n");

}
