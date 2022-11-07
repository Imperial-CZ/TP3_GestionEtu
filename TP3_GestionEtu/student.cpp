#include "student.h"

Student::Student()
{
}

Student::Student(QString xId, QString xlastname, QString xfirstname, QString xbac, QString xdepartement) : Id(xId), lastname(xlastname), firstname(xfirstname), bac(xbac), departement(xdepartement) {}

QString Student::getId()
{
	return Id;
}

QString Student::getLastname()
{
	return lastname;
}

QString Student::getFirstname()
{
	return firstname;
}

QString Student::getBac()
{
	return bac;
}

QString Student::getDepartement()
{
	return departement;
}
