#include "TP3_GestionEtu.h"
#include "promotion.h"
#include "viewList.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create Promotion
    Promotion promo;
    promo.readList("promoDUT");
    promo.initMapDept();


    // Create Interface
    TP3_GestionEtu* w = new TP3_GestionEtu(&promo);
    w->show();


    return a.exec();
}
