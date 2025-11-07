#include <QCoreApplication>
#include <QDebug>
extern int INDEX;
class Building
{
public:
    Building()
    {
        _INDEX = INDEX++;
        printf("Building create #1[%d]\n", _INDEX);
    }
    Building(Building &iBuilding)
    {
        _INDEX = INDEX++;
        lenght = iBuilding.lenght;
        width = iBuilding.width;
        height = iBuilding.height;
        printf("Building create #2[%d]\n", _INDEX);
    }
public:
    virtual void v2_1()
    {
        v2_2();
    }
    void v2_2()
    {
        printf("Building v2_2\n");
    }
    virtual void v3_1()
    {
        v3_2();
    }
    virtual void v3_2()
    {
        printf("Building v3_2\n");
    }
    void v4()
    {
        printf("Building v4\n");
    }
    virtual void v5()
    {
        printf("Building v5\n");
    }
    void setLenght(float iLenght)
    {
        lenght = iLenght;
    }
    void setWidth(float iWidth)
    {
        width = iWidth;
    }
    void setHeight(float iHeight)
    {
        height = iHeight;
    }
    void printInfo()
    {
        printf("Здание размером: %.2fx%.2fx%.2f\n", lenght, width, height);
    }
    virtual ~Building()
    {
        printf("Building delete #1 [%d]\n", _INDEX);
    }
protected:
    float lenght = 0;
    float width = 0;
    float height = 0;
    int _INDEX;
};

class ResidentialBuilding: public Building
{
public:
    ResidentialBuilding()
    {
        printf("ResidentialBuilding create #1 [%d]\n", _INDEX);
    }
    ResidentialBuilding(ResidentialBuilding &iResidentialBuilding) : Building(iResidentialBuilding)
    {
        isCity = iResidentialBuilding.isCity;
        printf("ResidentialBuilding create #2 [%d]\n", _INDEX);
    }
    ~ResidentialBuilding() override
    {
        printf("ResidentialBuilding delete #1 [%d]\n", _INDEX);
    }
public:
    void v2_2()
    {
        printf("ResidentialBuilding v2_2\n");
    }
    void v3_2() override
    {
        printf("ResidentialBuilding v3_2\n");
    }
    void v4()
    {
        printf("ResidentialBuilding v4\n");
    }
    void v5() override
    {
        printf("ResidentialBuilding v5\n");
    }
    void printInfo()
    {
        printf("Жилое здание размером: %.2fx%.2fx%.2f. Находится в городе: %s\n", lenght, width, height, isCity ? "Да" : "Нет");
    }
protected:
    bool isCity = true;
};

void virtualView()
{
    Building *rb = new ResidentialBuilding();
    rb->v2_1();
    rb->v3_1();
    delete rb;
    printf("---------------\n");
    Building *r1 = new ResidentialBuilding();
    ResidentialBuilding *r2 = new ResidentialBuilding();
    r1->v4();
    r2->v4();
    r1->v5();
    r2->v5();
    delete r1;
    delete r2;
}
