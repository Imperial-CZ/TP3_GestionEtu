#pragma once
#include"promotion.h"
#include<QWidget>

/**
 * @brief Class to manage the PieChart View
 * @author Adrien Peytavie
*/
class ViewPieChart 
{
public:
	ViewPieChart();
	QWidget* getPieChartView(Promotion& promo);
};

