#include "viewHistogram.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QBarCategoryAxis>
#include <QValueAxis>

ViewHistogram::ViewHistogram() 
{
}
QWidget* ViewHistogram::getBarChartView(Promotion& promo) {
	
	int nbS = promo.compterS();
	int nbSTI = promo.compterSTI();
	int nbES = promo.compterES();

    QBarSet* set0 = new QBarSet("");
    *set0 << nbS << nbES << nbSTI;

    QBarSeries* series = new QBarSeries();
    series->append(set0);

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("SERIES DE BAC");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "S" << "ES" << "STI";
    QBarCategoryAxis* axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);
    chart->legend()->setVisible(false);

    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}
