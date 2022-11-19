#include "viewPieChart.h"

ViewPieChart::ViewPieChart(Promotion* _promo, QGroupBox* _groupBox) : promo(_promo), groupBox(_groupBox), chartView(nullptr)
{
	QGridLayout* grid = new QGridLayout();
	groupBox->setLayout(grid);
	update();
}

void ViewPieChart::update() {
	promo->initMapDept();
	QMap<QString, int> mapDept= *promo->getMapDept();
	
	QPieSeries* chartBac = new QPieSeries();
	QMapIterator<QString, int> iterator(mapDept);
	while (iterator.hasNext()) {
		iterator.next();
		chartBac->append(iterator.key(), iterator.value());
	}
	chartBac->setLabelsVisible(true);

	QPieSlice* slice1 = chartBac->slices().at(0);
	QPieSlice* slice2 = chartBac->slices().at(1);
	QPieSlice* slice3 = chartBac->slices().at(2);
	QChart* chart = new QChart();
	chart->addSeries(chartBac);
	chart->setTitle("REPARTITION GEOGRAPHIQUE");
	chart->setAnimationOptions(QChart::SeriesAnimations); // a nice animation!!
	chart->legend();

	QChartView* newchartView = new QChartView(chart);

    if (chartView == nullptr) {
        groupBox->layout()->addWidget(newchartView);
    }
    else {
        groupBox->layout()->replaceWidget(chartView, newchartView);
    }
    chartView = newchartView;
}