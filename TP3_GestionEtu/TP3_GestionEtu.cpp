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
    connect(ui.listWidget, &QListWidget::doubleClicked, this, &TP3_GestionEtu::launchModifyForm);
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
    Controller_AddForm cAdd = Controller_AddForm(promo);
    QStringList list;
    list.append(ui.lineEdit_add_number->text());
    list.append(ui.lineEdit_add_lastname->text());
    list.append(ui.lineEdit_add_firstname->text());
    list.append(ui.lineEdit_add_BAC->currentText());
    list.append(ui.lineEdit_add_department->currentText());

    if (ui.pushButton_addStudent->text() == "Ajout") {
        
        
        cAdd.control(list);
        ui.lineEdit_add_number->clear();
        ui.lineEdit_add_firstname->clear();
        ui.lineEdit_add_lastname->clear();
    }
    else if (ui.pushButton_addStudent->text() == "Enregistrer") {
        Controller_DeleteForm cDelete = Controller_DeleteForm(promo);
        QString selected = promo->getSelectedStudent()->getId();
        QStringList listDelete;
        listDelete.append(selected);
        cDelete.control(listDelete);
        cAdd.control(list);
        Student found = promo->find(promo->getSelectedStudent()->getId());
        if (found.getId() == nullptr) {
            QStringList oldStudList;
            oldStudList.append(promo->getSelectedStudent()->getId());
            oldStudList.append(promo->getSelectedStudent()->getLastname());
            oldStudList.append(promo->getSelectedStudent()->getFirstname());
            oldStudList.append(promo->getSelectedStudent()->getBac());
            oldStudList.append(promo->getSelectedStudent()->getDepartement());
            cAdd.control(oldStudList);
        }
        ui.lineEdit_add_number->setEnabled(true);
        ui.lineEdit_add_number->clear();
        ui.lineEdit_add_firstname->clear();
        ui.lineEdit_add_lastname->clear();
        ui.lineEdit_add_BAC->setCurrentIndex(0);
        ui.lineEdit_add_department->setCurrentIndex(0);
        ui.pushButton_addStudent->setText("Ajout");
    }
}

void TP3_GestionEtu::launchModifyForm() {
    ui.pushButton_addStudent->setText("Enregistrer");
    QString selected= ui.listWidget->currentItem()->text();
    selected = selected.split(" ")[0];
    ui.lineEdit_add_number->setText(promo->find(selected).getId());
    ui.lineEdit_add_firstname->setText(promo->find(selected).getFirstname());
    ui.lineEdit_add_lastname->setText(promo->find(selected).getLastname());
    ui.lineEdit_add_BAC->setCurrentText(promo->find(selected).getBac());
    ui.lineEdit_add_department->setCurrentText(promo->find(selected).getDepartement());
    ui.lineEdit_add_number->setEnabled(false);
    Student selectedStudent = Student(promo->find(selected).getId(), promo->find(selected).getFirstname(), promo->find(selected).getLastname(), promo->find(selected).getBac(), promo->find(selected).getDepartement());
    promo->setSelectedStudent(selectedStudent);
}