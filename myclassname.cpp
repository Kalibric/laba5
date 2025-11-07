#include "myclassname.h"
#include <QCoreApplication>
#include <random>
extern int INDEX;
using namespace std;
class Building
{
public:
    Building()
    {
        _INDEX = INDEX++;
        printf("Building create #1 [%d]\n", _INDEX);
    }
    Building(Building &iBuilding)
    {
        _INDEX = INDEX++;
        lenght = iBuilding.lenght;
        width = iBuilding.width;
        height = iBuilding.height;
        printf("Building create #2 [%d]\n", _INDEX);
    }
public:
    virtual string classname()
    {
        return "Building";
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

    virtual void printInfo()
    {
        printf("Здание размером: %.2fx%.2fx%.2f\n", lenght, width, height);
    }
    ~Building()
    {
        printf("Building delete #1 [%d]\n", _INDEX);
    }
    int _INDEX;
protected:
    float lenght = 0;
    float width = 0;
    float height = 0;
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
public:
    string classname() override
    {
        return "ResidentialBuilding";
    }
    void setCity(bool iIsCity)
    {
        isCity = iIsCity;
    }
    void printInfo() override
    {
        printf("Жилое здание размером:%.2fx%.2fx%.2f. Находится в городе: %s\n", lenght, width, height, isCity ? "Да" : "Нет");
    }
protected:
    bool isCity = true;
};

class House: public ResidentialBuilding
{
public:
    House()
    {
        printf("House create #1 [%d]\n", _INDEX);
    }
    House(House &iHouse) : ResidentialBuilding(iHouse)
    {
        numberRooms = iHouse.numberRooms;
        printf("House create #2 [%d]\n", _INDEX);
    }
    ~House()
    {
        printf("House delete #1\n");
    }
public:
    string classname() override
    {
        return "House";
    }
    void setNumbersRooms(int iNumberRooms)
    {
        numberRooms = iNumberRooms;
    }
    void printInfo() override
    {
        printf("Дом размером: %.2fx%.2fx%.2f. Находится в городе: %s. Количество комнат: %d\n", lenght, width, height, isCity ? "Да" : "Нет", numberRooms);
    }
protected:
    int numberRooms = 0;
};

class Flat: public ResidentialBuilding
{
public:
    Flat()
    {
        printf("Flat create #1 [%d]\n", _INDEX);
    }
    Flat(Flat &iFlat) : ResidentialBuilding(iFlat)
    {
        printf("Flat create #2 [%d]\n", _INDEX);
    }
public:
    string classname() override
    {
        return "Flat";
    }
    void setFloors(int iFloors)
    {
        floors = iFloors;
    }
    void printInfo() override
    {
        printf("Квартира размером: %.2fx%.2fx%.2f. Находится в городе: %s. Количество квартир: %d. Количетсво этажей: %d\n", lenght, width, height, isCity ? "Да" : "Нет", apartments, floors);
    }
protected:
    int floors = 1;
    int apartments = 1;
};

void myclassname()
{
    srand(time(0));
    vector<Building*> buildings;
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        if (rand() % 2 == 0)
            buildings.push_back(new Flat());
        else
            buildings.push_back(new House());
    }
    i = 0;
    for (Building *b : buildings)
    {
        if (b->classname() == "Flat")
        {
            Flat *f = static_cast<Flat*>(b);
            f->setFloors(i);
            f->printInfo();
        }
        else if (b->classname() == "House")
        {
            House *h = dynamic_cast<House*>(b);
            h->setNumbersRooms(i);
            h->printInfo();
        }
        i++;
    }

    // Проблема:

    if (buildings[0]->classname() == "ResidentialBuilding")
    {
        ((ResidentialBuilding*)buildings[0])->setCity(true);
    }
    ResidentialBuilding *hh = dynamic_cast<ResidentialBuilding*>(buildings[0]);
    if (hh)
    {
        printf("-----------------\n");
        hh->printInfo();
    }
}
