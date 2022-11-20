#pragma once
#include "student.h"
#include "observer.h"
#include <QVector>
#include <QStringList>
#include <QString>
#include <QMap>

/**
 * @brief Promotion La classe Promotion gere un Vecteur d'Etudiant avec differente fonction lui permettant d'ajouter, supprimer, modifier, ... le vecteur d'etudiant
 * @author SUARD GaetanCLOSSON Jules
*/
class Promotion : public Observable
{
private:
	QVector<Student> studentsList;
	Student selectedStudent;
	QVector<Observer*> observersList;
	QMap<QString, int> mapDept;

public:
	Promotion();
	void initMapDept();
	void add(Student);
	void remove(Student);
	void remove(QString);
	void remove(QVector<Student> students);
	Student find(QString);
	void readList(const QString&);
	QStringList getStudentslist();
	QMap<QString, int>* getMapDept();
	int compterS();
	int compterES();
	int compterSTI();
	void setSelectedStudent(Student);
	Student* getSelectedStudent();
	void addObserver(Observer* observer) override;
	void removeObserver(Observer* observer) override;
	void notifyObserver()const override;
};

