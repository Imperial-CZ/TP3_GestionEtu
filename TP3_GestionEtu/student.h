#pragma once
#include <QString>

/**
 * @brief Student Regroupe tous les attribut relatif � un �tudiant, son ID, son nom, son pr�nom, son bac et son departement, cette classe poss�de des Getteurs afin de pouvoir r�cup�rer les informations d'un �tudiant
 * @author SUARD GaetanCLOSSON Jules
*/
class Student
{
private:
    QString Id;
    QString lastname;
    QString firstname;
    QString bac;
    QString departement;
public: 
    Student();
    Student(QString xId,QString xlastname,QString xfirstname,QString xbac,QString xdepartement);
    QString getId();
    QString getLastname();
    QString getFirstname();
    QString getBac();
    QString getDepartement();
};

