#include "viewList.h"
#include <QVector>
#include <QListWidget>
//#include "controllers.h"


ViewList::ViewList(Promotion* xpromo, QListWidget* xliste) : promo(xpromo), liste(xliste)
{
	update();
	
}

void ViewList::update() {

	liste->clear();

	liste->addItems(promo->getStudentslist());
}

/*
void ViewList::remove() {
	Controller_DeleteList temp = Controller_DeleteList(promo);
	temp.control(liste->currentItem()->text());
}
*/
