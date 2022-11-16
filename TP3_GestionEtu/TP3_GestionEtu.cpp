#include "TP3_GestionEtu.h"
#include"viewPieChart.h"
#include "controllers.h"

TP3_GestionEtu::TP3_GestionEtu(Promotion* xpromo, QWidget* parent) : QMainWindow(parent)
{
    promo = xpromo;

    ui.setupUi(this);

    listView = new ViewList(promo, ui.listWidget);
    pieChartView = new ViewPieChart(promo, ui.groupBox_department);
    histogramView = new ViewHistogram(promo,ui.groupBox_bacs);

    promo->addObserver(listView); 
    promo->addObserver(pieChartView);
    promo->addObserver(histogramView);
    
    connect(ui.pushButton_delete_list, &QPushButton::pressed, this, &TP3_GestionEtu::launchDeleteList);
    connect(ui.pushButton_delete_number, &QPushButton::pressed, this, &TP3_GestionEtu::launchDeleteForm);
}

void TP3_GestionEtu::launchDeleteList() {
    Controller_DeleteList c = Controller_DeleteList(promo);
    QString selected = ui.listWidget->currentItem()->text();
    QStringList list;
    list.append(selected);
    c.control(list);
}

void TP3_GestionEtu::launchDeleteForm() {
    Controller_DeleteForm c = Controller_DeleteForm(promo);
    QString selected = ui.lineEdit_remove_number->text();
    QStringList list;
    list.append(selected);
    c.control(list);
    ui.lineEdit_remove_number->clear();
}