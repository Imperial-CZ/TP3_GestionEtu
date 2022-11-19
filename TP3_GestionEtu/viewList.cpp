#include "viewList.h"



ViewList::ViewList(Promotion* xpromo, QListWidget* xliste) : promo(xpromo), liste(xliste)
{
	update();
	liste->setSelectionMode(QListWidget::ExtendedSelection);
}

void ViewList::update() {

	liste->clear();
	liste->addItems(promo->getStudentslist());
}
