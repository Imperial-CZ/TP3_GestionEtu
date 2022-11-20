#pragma once
#include <QString>

/**
 * @brief Student Regroupe tous les attribut relatif a un etudiant, son ID, son nom, son prenom, son bac et son departement, cette classe possede des Getters afin de pouvoir recuperer les informations d'un etudiant
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

