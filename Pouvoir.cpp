#include "Pouvoir.h"
#include <iostream>


Pouvoir::Pouvoir()
{
}

Pouvoir::Pouvoir(const string& nom, 
	unsigned int nombreDeDegat,	unsigned int energieNecessaire):
	nom_(nom), nombreDeDegat_(nombreDeDegat), energieNecessaire_(energieNecessaire)
{
}

Pouvoir::Pouvoir(const Pouvoir&pouvoir) {
	nom_ = pouvoir.obtenirNom();
	nombreDeDegat_ = pouvoir.obtenirNombreDeDegat();
	energieNecessaire_ = pouvoir.obtenirEnergieNecessaire();
}

Pouvoir::~Pouvoir()
{
}

unsigned int Pouvoir::obtenirEnergieNecessaire() const
{
	return energieNecessaire_;
}

string Pouvoir::obtenirNom() const
{
	return nom_;
}

unsigned int Pouvoir::obtenirNombreDeDegat() const
{
	return nombreDeDegat_;
}

void Pouvoir::modifierNombreDeDegat(unsigned int nombreDegat)
{
	nombreDeDegat_ = nombreDegat;
}

void Pouvoir::modifierEnergieNecessarie(unsigned int energieNecessaire)
{
	energieNecessaire_ = energieNecessaire;
}

void Pouvoir::modifierNom(const string& nom)
{
	nom_ = nom;
}

 ostream&operator<<(ostream&o, const Pouvoir&pouvoir)// A MODIFIER... (si necessaire)
{
	o<< pouvoir.obtenirNom() << " necessite " << pouvoir.obtenirEnergieNecessaire() << " energie et inflige " << pouvoir.obtenirNombreDeDegat() << " degats" << endl;
	return o;
}

Pouvoir Pouvoir::operator=(const Pouvoir & pouvoir)
{
	if (this != &pouvoir) {
		nom_ = pouvoir.obtenirNom();
		nombreDeDegat_ = pouvoir.obtenirNombreDeDegat();
		energieNecessaire_ = pouvoir.obtenirEnergieNecessaire();
	}
	return *this;
}

bool Pouvoir::operator==(const Pouvoir & pouvoir)
{
	if (nom_ == pouvoir.obtenirNom()) {
		return true;
	}
	return false;
}
