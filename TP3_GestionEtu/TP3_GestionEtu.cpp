#include "TP3_GestionEtu.h"
//#include "controllers.h"

TP3_GestionEtu::TP3_GestionEtu(Promotion* xpromo,QWidget *parent) : QMainWindow(parent)
{
    promo = xpromo;

    ui.setupUi(this);

    listView = new ViewList(promo, ui.listWidget);
     
    //connect(ui.pushButton_delete_list, &QPushButton::pressed, this, &ViewList::remove);
}
