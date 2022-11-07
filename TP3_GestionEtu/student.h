#pragma once
#include <QString>

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

