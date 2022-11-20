#pragma once
#include "promotion.h"
#include "observer.h"
#include <QVector>
#include <QListWidget>

/**
 * @brief ViewList La classe ViewList g�re l'affichage et la mise � jour de l'affichage de liste d'�tudiant
 * @author SUARD GaetanCLOSSON Jules
*/
class ViewList : public Observer
{
private:
	Promotion* promo;
	QListWidget* liste;
public:
	ViewList(Promotion* xpromo, QListWidget* xliste);
	void update() override;
};