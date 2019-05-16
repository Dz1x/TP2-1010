#include "ObjetMagique.h"
#include <iostream>

ObjetMagique::ObjetMagique()
{
}

ObjetMagique::ObjetMagique(const string & nom, int bonus):
	nom_(nom), bonus_(bonus)
{
}


ObjetMagique::~ObjetMagique()
{
}

string ObjetMagique::obtenirNom() const
{
	return nom_;
}

int ObjetMagique::obtenirBonus() const
{
	return bonus_;
}

void ObjetMagique::modifierNom(const string& nom)
{
	nom_ = nom;
}

void ObjetMagique::modifierBonus(int bonus)
{
	bonus_ = bonus;
}

void ObjetMagique::affichage() const // A MODIFIER... (si necessaire)
{
	cout << "l'objet " << nom_ << "fournit un bonus de " << bonus_ << endl;
}
