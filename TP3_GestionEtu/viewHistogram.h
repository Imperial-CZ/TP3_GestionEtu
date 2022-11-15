#pragma once
#include"promotion.h"
#include<QWidget>

class ViewHistogram 
{
public:
	ViewHistogram();
	QWidget* getBarChartView(Promotion& promo);
};

