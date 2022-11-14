#pragma once
#include "promotion.h"
#include "observer.h"
#include <QListWidget>


/**
 * @brief Class to manage the QListWidget
 * @author Adrien Peytavie
*/
class ViewList : public Observer
{
private:
	Promotion* promo;
	QListWidget* liste;
public:
	ViewList(Promotion* xpromo, QListWidget* xliste);
	void update() override;
	void remove();
};