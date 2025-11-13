#include "myunique.h"
#include <QCoreApplication>
int idxxx = 0;
using namespace std;
class Base
{
public:
    Base()
    {
        _INDEX = idxxx;
        printf("Base create #1 [%d]\n", _INDEX);
        idxxx++;
    }
    Base(Base *obj)
    {
        x = obj->x;
        y = obj->y;
        _INDEX = idxxx;
        printf("Base create #2 [%d]\n", _INDEX);
        idxxx++;
    }
    Base(Base &obj)
    {
        x = obj.x;
        y = obj.y;
        _INDEX = idxxx;
        printf("Base create #3 [%d]\n", _INDEX);
        idxxx++;
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

void myunique()
{
    shared_ptr<Base> y;
    {
        shared_ptr<Base> s = make_shared<Base>();
        s->x = 5;
        y = s;
        printf("%d\n", s->x);
    }
    printf("%d\n", y->x);
    printf("-----\n");
    Base *x;
    {
        Base *b = new Base();
        b->y = 10;
        x = b;
    }
    printf("%d\n", x->y);
}
