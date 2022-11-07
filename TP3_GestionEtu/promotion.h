#pragma once
#include "student.h"
#include <QVector>

class Promotion
{
private:
	QVector<Student> studentsList;
	Student selectedStudent;

public:
	Promotion();
	void add(Student);
	void remove(Student);
	void find(QString);
	void readList(const QString&);
	QVector<Student> getStudentslist();
};

