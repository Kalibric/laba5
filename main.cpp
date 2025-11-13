#include <QCoreApplication>
#include <QDebug>
#include "virtualview.h"
#include "global.h"
#include "myclassname.h"
#include "myisa.h"
#include "func.h"
#include "func2.h"
#include "myunique.h"
extern int INDEX;
// class Building
// {
// public:
//     Building()
//     {
//         _INDEX = INDEX++;
//         printf("\nBuilding create #1[%d]\n", _INDEX);
//     }
//     Building(Building &iBuilding)
//     {
//         _INDEX = INDEX++;
//         lenght = iBuilding.lenght;
//         width = iBuilding.width;
//         height = iBuilding.height;
//         printf("\nBuilding create #2[%d]\n", _INDEX);
//     }
// public:
//     void setLenght(float iLenght)
//     {
//         lenght = iLenght;
//     }
//     void setWidth(float iWidth)
//     {
//         width = iWidth;
//     }
//     void setHeight(float iHeight)
//     {
//         height = iHeight;
//     }

//     void printInfo()
//     {
//         printf("\nЗдание размером: %.2fx%.2fx%.2f\n", lenght, width, height);
//     }
//     ~Building()
//     {
//         printf("\nBuilding delete #1[%d]\n", _INDEX);
//     }
//     int _INDEX;
// protected:
//     float lenght = 0;
//     float width = 0;
//     float height = 0;
// };

// class ResidentialBuilding: public Building
// {
// public:
//     ResidentialBuilding()
//     {
//         printf("\nResidentialBuilding create #1 [%d]\n", _INDEX);
//     }
//     ResidentialBuilding(ResidentialBuilding &iResidentialBuilding) : Building(iResidentialBuilding)
//     {
//         isCity = iResidentialBuilding.isCity;
//         printf("\nResidentialBuilding create #2 [%d]\n", _INDEX);
//     }
// public:
//     void printInfo()
//     {
//         printf("\nЖилое здание размером:%.2fx%.2fx%.2f. Находится в городе: %s\n", lenght, width, height, isCity ? "Да" : "Нет");
//     }
// protected:
//     bool isCity = true;
// };

// class House: public ResidentialBuilding
// {
// public:
//     House()
//     {
//         printf("\nHouse create #1 [%d]\n", _INDEX);
//     }
//     House(House &iHouse) : ResidentialBuilding(iHouse)
//     {
//         numberRooms = iHouse.numberRooms;
//         printf("\nHouse create #2 [%d]\n", _INDEX);
//     }
//     ~House()
//     {
//         printf("\nHouse delete #1\n");
//     }
// public:
//     void printInfo()
//     {
//         printf("\nДом размером: %.2fx%.2fx%.2f. Находится в городе: %s. Количество комнат: %d\n", lenght, width, height, isCity ? "Да" : "Нет", numberRooms);
//     }
// protected:
//     int numberRooms = 0;
// };

// class Flat: public ResidentialBuilding
// {
// public:
//     Flat()
//     {
//         printf("\nFlat create #1 [%d]\n", _INDEX);
//     }
//     Flat(Flat &iFlat) : ResidentialBuilding(iFlat)
//     {
//         printf("\nFlat create #2 [%d]\n", _INDEX);
//     }
// public:
//     void printInfo()
//     {
//         printf("\nКвартира размером: %.2fx%.2fx%.2f. Находится в городе: %s. Количество квартир: %d. Количетсво этажей: %d\n", lenght, width, height, isCity ? "Да" : "Нет", apartments, floors);
//     }
// protected:
//     int floors = 1;
//     int apartments = 1;
// };

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //virtualView();
    //myclassname();
    //myisa();
    //func();
    //func2();
    //myunique();
}
