#pragma once
#include "promotion.h"
#include "observer.h"
#include <QVector>
#include <QListWidget>

/**
 * @brief ViewList La classe ViewList gère l'affichage et la mise à jour de l'affichage de liste d'étudiant
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