#include <QCoreApplication>
#include <QDebug>
extern int INDEX;
class Building
{
public:
    Building()
    {
        _INDEX = INDEX++;
        printf("\nBuilding create #1[%d]\n", _INDEX);
    }
    Building(Building &iBuilding)
    {
        _INDEX = INDEX++;
        lenght = iBuilding.lenght;
        width = iBuilding.width;
        height = iBuilding.height;
        printf("\nBuilding create #2[%d]\n", _INDEX);
    }
public:
    virtual void v2_1()
    {
        v2_2();
    }
    void v2_2()
    {
        qDebug() << "Building v2_2";
    }
    virtual void v3_1()
    {
        v3_2();
    }
    virtual void v3_2()
    {
        qDebug() << "Building v3_2";
    }
    void v4()
    {
        qDebug() << "Building v4";
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
        printf("\nЗдание размером: %.2fx%.2fx%.2f\n", lenght, width, height);
    }
    virtual ~Building()
    {
        printf("\nBuilding delete #1 [%d]\n", _INDEX);
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
        printf("\nResidentialBuilding create #1 [%d]\n", _INDEX);
    }
    ResidentialBuilding(ResidentialBuilding &iResidentialBuilding) : Building(iResidentialBuilding)
    {
        isCity = iResidentialBuilding.isCity;
        printf("\nResidentialBuilding create #2 [%d]\n", _INDEX);
    }
    ~ResidentialBuilding() override
    {
        printf("\nResidentialBuilding delete #1 [%d]\n", _INDEX);
    }
public:
    void v2_2()
    {
        qDebug() << "ResidentialBuilding v2_2";
    }
    void v3_2() override
    {
        qDebug() << "ResidentialBuilding v3_2";
    }
    void v4()
    {
        qDebug() << "ResidentialBuilding v4";
    }
    void printInfo()
    {
        printf("\nЖилое здание размером: %.2fx%.2fx%.2f. Находится в городе: %s\n", lenght, width, height, isCity ? "Да" : "Нет");
    }
protected:
    bool isCity = true;
};

void virtualView()
{
    ResidentialBuilding *rb = new ResidentialBuilding();
    rb->v2_1();
    rb->v3_1();

}
