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
 * @author SUARD GaetanCLOSSON Jules
*/
class TP3_GestionEtu : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief TP3_GestionEtu (Promotion *promo, QWidget *parent=nullptr) Constructeur de TP3_GestionEtu demandant une référence à une promotion et un QWidget qui attend une référence à un QWindows pour l'affichage
     * @author SUARD GaetanCLOSSON Jules
    */
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
