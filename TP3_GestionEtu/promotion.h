#pragma once
#include "student.h"
#include "observer.h"
#include <QVector>
#include <QStringList>
#include <QString>

class Promotion : public Observable
{
private:
	QVector<Student> studentsList;
	Student selectedStudent;
	QVector<Observer*> observersList;

public:
	Promotion();
	void add(Student);
	void remove(Student);
	void remove(QString);
	Student find(QString);
	void readList(const QString&);
	QStringList getStudentslist();

	int compterS();
	int compterES();
	int compterSTI();
	void addObserver(Observer* observer) override;
	void removeObserver(Observer* observer) override;
	void notifyObserver()const override;
};

