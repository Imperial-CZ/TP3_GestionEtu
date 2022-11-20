#pragma once
#include <QString>

/**
 * @brief Student Regroupe tous les attribut relatif à un étudiant, son ID, son nom, son prénom, son bac et son departement, cette classe possède des Getteurs afin de pouvoir récupérer les informations d'un étudiant
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

