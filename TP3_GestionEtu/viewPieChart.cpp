#include "viewPieChart.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>

ViewPieChart::ViewPieChart()
{
}

QWidget* ViewPieChart::getPieChartView(Promotion& promo) {
	int nbS = promo.compterS();
	int nbSTI = promo.compterSTI();
	int nbES = promo.compterES();

	QPieSeries* chartBac = new QPieSeries();
	chartBac->append("S", nbS);
	chartBac->append("ES", nbES);
	chartBac->append("STI", nbSTI);
	chartBac->setLabelsVisible(true);

	QPieSlice* slice1 = chartBac->slices().at(0);
	slice1->setLabel(QString("S %1%").arg(100 * slice1->percentage(), 0, 'f', 1));
	QPieSlice* slice2 = chartBac->slices().at(1);
	slice2->setLabel(QString("ES %1%").arg(100 * slice2->percentage(), 0, 'f', 1));
	QPieSlice* slice3 = chartBac->slices().at(2);
	slice3->setLabel(QString("STI %1%").arg(100 * slice2->percentage(), 0, 'f', 1));
	QChart* chart = new QChart();
	chart->addSeries(chartBac);
	chart->setTitle("REPARTITION GEOGRAPHIQUE");
	chart->setAnimationOptions(QChart::SeriesAnimations); // a nice animation!!
	chart->legend()->hide();

	QChartView* chartView = new QChartView(chart);
	return chartView;
}