#include "TP3_GestionEtu.h"
#include"viewPieChart.h"
#include "controllers.h"

TP3_GestionEtu::TP3_GestionEtu(Promotion* xpromo, QWidget* parent) : QMainWindow(parent)
{
    promo = xpromo;

    ui.setupUi(this);
    PieChart();
    BarChart();
    listView = new ViewList(promo, ui.listWidget);
    connect(ui.pushButton_delete_list, &QPushButton::pressed, this, &TP3_GestionEtu::launchControl);
}

void TP3_GestionEtu::PieChart() {
    pieChartView = new ViewPieChart();
    QGridLayout* grid = new QGridLayout;
    grid->addWidget(pieChartView->getPieChartView(*promo));
    ui.groupBox_department->setLayout(grid);   
}

void TP3_GestionEtu::BarChart() {
    histogramView = new ViewHistogram();
    QGridLayout* grid = new QGridLayout;
    grid->addWidget(histogramView->getBarChartView(*promo));
    ui.groupBox_bacs->setLayout(grid);
}

void TP3_GestionEtu::launchControl() {
    
    Controller_DeleteForm c = Controller_DeleteForm(promo);
    QString selected = ui.listWidget->currentItem()->text();
    QStringList list;
    list.append(selected.mid(0, 3));
    c.control(list);
}