#pragma once
#include"promotion.h"
#include <QWidget>
#include <QGroupBox>
#include <QChartView>
#include <QPieSeries>
#include <QGridLayout>

/**
 * @brief ViewPieChart La classe ViewPieChart gère l'affichage et la mise à jour de l'affichage du PieChart
 * @author SUARD GaetanCLOSSON Jules
*/
class ViewPieChart : public Observer
{
private:
	QChartView* chartView;
	Promotion* promo;
	QGroupBox* groupBox;

public:
	ViewPieChart(Promotion*, QGroupBox*);
	void update() override;
};

