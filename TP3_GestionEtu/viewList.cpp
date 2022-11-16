#include "viewList.h"
#include <QVector>
#include <QListWidget>


ViewList::ViewList(Promotion* xpromo, QListWidget* xliste) : promo(xpromo), liste(xliste)
{
	update();
}

void ViewList::update() {

	liste->clear();
	liste->addItems(promo->getStudentslist());
}
