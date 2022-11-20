#pragma once
#include"promotion.h"
#include <QWidget>
#include <QChartView>
#include <QGroupBox>
#include <QPieSeries>
#include <QPieSeries>
#include <QBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QGridLayout>


/**
 * @brief ViewHistogram La classe ViewHistogram gère l'affichage et la mise à jour de l'affichage de l'histogramme
 * @author SUARD GaetanCLOSSON Jules
*/
class ViewHistogram : public Observer
{
private:
	QChartView* chartView;
	Promotion* promo;
	QGroupBox* groupBox;

public:
	ViewHistogram(Promotion*,QGroupBox*);
	void update() override;
};

