#pragma once
#include"promotion.h"
#include <QWidget>
#include <QGroupBox>
#include <QChartView>
#include <QPieSeries>
#include <QGridLayout>

/**
 * @brief Class to manage the PieChart View
 * @author Adrien Peytavie
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

