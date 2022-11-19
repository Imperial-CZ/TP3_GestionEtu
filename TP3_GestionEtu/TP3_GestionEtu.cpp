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
    listForm = new ViewForms(ui.lineEdit_add_BAC, ui.lineEdit_add_department);

    promo->addObserver(listView); 
    promo->addObserver(pieChartView);
    promo->addObserver(histogramView);
    
    connect(ui.pushButton_delete_list, &QPushButton::pressed, this, &TP3_GestionEtu::launchDeleteList);
    connect(ui.pushButton_delete_number, &QPushButton::pressed, this, &TP3_GestionEtu::launchDeleteForm);
    connect(ui.pushButton_addStudent, &QPushButton::pressed, this, &TP3_GestionEtu::launchAddForm);
}

void TP3_GestionEtu::launchDeleteList() {
    Controller_DeleteList c = Controller_DeleteList(promo);
    QStringList list;
    for (QListWidgetItem* item : ui.listWidget->selectedItems()){
        list.append(item->text().split(" ")[0]);
    }
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

void TP3_GestionEtu::launchAddForm() {
    Controller_AddForm c = Controller_AddForm(promo);
    QStringList list;
    list.append(ui.lineEdit_add_number->text());
    list.append(ui.lineEdit_add_firstname->text());
    list.append(ui.lineEdit_add_lastname->text());
    list.append(ui.lineEdit_add_BAC->currentText());
    list.append(ui.lineEdit_add_department->currentText());

    c.control(list);
    ui.lineEdit_add_number->clear();
    ui.lineEdit_add_firstname->clear();
    ui.lineEdit_add_lastname->clear();
}