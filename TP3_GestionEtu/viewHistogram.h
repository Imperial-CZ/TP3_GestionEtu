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

