#include "viewForms.h"

ViewForms::ViewForms(QComboBox* xbac, QComboBox* xdepartement)
{
	xbac->addItem("S");
	xbac->addItem("ES");
	xbac->addItem("STI");

	xdepartement->addItem("1");
	xdepartement->addItem("35");
	xdepartement->addItem("38");
	xdepartement->addItem("39");
	xdepartement->addItem("69");
	xdepartement->addItem("71");
	xdepartement->addItem("Autre");
}
