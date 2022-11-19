#pragma once

#include <QMainWindow>
#include "ui_TP3_GestionEtu.h"
#include "viewList.h"
#include "viewForms.h"
#include "viewPieChart.h"
#include "viewHistogram.h"
#include "promotion.h"

/**
 * @brief TP3_GestionEtu Permet la construction et la modification de l'affichage
 * @author Etu
*/
class TP3_GestionEtu : public QMainWindow
{
    Q_OBJECT

public:
    TP3_GestionEtu(Promotion* promo,QWidget *parent = nullptr);
    ~TP3_GestionEtu() {}
private:
    Ui::TP3_GestionEtuClass ui;

    Promotion* promo;
    ViewList* listView;
    ViewForms* listForm;
    ViewPieChart* pieChartView;
    ViewHistogram* histogramView;

private slots:
    void launchAddForm();
    void launchDeleteList();
    void launchDeleteForm();
};
