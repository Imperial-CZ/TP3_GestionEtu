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

	QChart* chart = new QChart();
	chart->addSeries(chartBac);
	chart->setTitle("REPARTITION GEOGRAPHIQUE");
	chart->setAnimationOptions(QChart::SeriesAnimations); // a nice animation!!
	chart->legend()->setVisible(false);

	QChartView* newchartView = new QChartView(chart);

    if (chartView == nullptr) {
        groupBox->layout()->addWidget(newchartView);
    }
    else {
        groupBox->layout()->replaceWidget(chartView, newchartView);
    }
    chartView = newchartView;
}