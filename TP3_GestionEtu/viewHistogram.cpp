#include "viewHistogram.h"

ViewHistogram::ViewHistogram(Promotion* _promo, QGroupBox* _groupBox) : promo(_promo), groupBox(_groupBox), chartView(nullptr)
{
    QGridLayout* grid = new QGridLayout();
    groupBox->setLayout(grid);
    update();
}

void ViewHistogram::update() {
    int nbS = promo->compterS();
    int nbSTI = promo->compterSTI();
    int nbES = promo->compterES();

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

    QChartView* newchartView = new QChartView(chart);
    newchartView->setRenderHint(QPainter::Antialiasing);

    if (chartView == nullptr) {
        groupBox->layout()->addWidget(newchartView);
    }
    else {
        groupBox->layout()->replaceWidget(chartView, newchartView);
    }
    chartView = newchartView;
}