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

public:
	Promotion();
	void add(Student);
	void remove(QString);
	void find(QString);
	void readList(const QString&);
	QStringList getStudentslist();

	void addObserver(Observer* observer) override;
	void removeObserver(Observer* observer) override;
	void notifyObserver()const override;
};

