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
 * @brief ViewHistogram La classe ViewHistogram gere l'affichage et la mise a jour de l'affichage de l'histogramme
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

