#include "PolyLand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

PolyLand::PolyLand() // A MODIFIER... (si necessaire)
{

}

// Is done
PolyLand::~PolyLand() // A MODIFIER... (si necessaire)
{

	for (Creature* creature : creatures_)
	{
		delete creature;
		creature = nullptr;
	}
	for (Dresseur* dresseur : dresseurs_)
	{
		delete dresseur;
		dresseur = nullptr;
	}

}

// Is done
bool PolyLand::ajouterDresseur(const Dresseur& dresseur) // A MODIFIER... (si necessaire)
{
	for (Dresseur* dresseurDansVecteur : dresseurs_)
	{
		if (dresseurDansVecteur->obtenirNom() == dresseur.obtenirNom())
			return false;
	}
	dresseurs_.push_back(new Dresseur(dresseur));
	return true;
}

// is done
bool PolyLand::operator==(const Dresseur& dresseur) const{ // À faire

	for (Dresseur* dresseurDansVecteur : dresseurs_ ) {
		if (dresseurDansVecteur->obtenirNom() == dresseur.obtenirNom()) {
			return false;
		}
	}
	return true;
}

// À faire
PolyLand& PolyLand::operator+=(const Dresseur& dresseur) const {

}

// Is done
bool PolyLand::ajouterCreature(const Creature& creature) // A MODIFIER... (si necessaire)
{
	for (Creature* creatureDansVecteur : creatures_)
	{
		if (creatureDansVecteur->obtenirNom() == creature.obtenirNom())
			return false;
	}
	creatures_.push_back(new Creature(creature));
	return true;
}

// id done
bool PolyLand::operator==(const Creature& creature) const { // À faire
	for (Creature* creatureDansVecteur : creatures_) {
		if (creatureDansVecteur->obtenirNom() == creature.obtenirNom()) {
			return false;
		}
	}
	return true;
}

// À faire
PolyLand& PolyLand::operator+=(const Creature& creature) const {
	


}

// is done
bool PolyLand::retirerDresseur(const string& nom) // A MODIFIER... (si necessaire)
{
	for (Dresseur* dresseurDansVecteur : dresseurs_) {
		if (dresseurDansVecteur->obtenirNom == nom) {
			dresseurDansVecteur = dresseurs_[dresseurs_.size() - 1];
			dresseurs_.pop_back;
			return true;
		}
	}
	return false;
}

// À faire
PolyLand& PolyLand::operator-=(const Dresseur& dresseur) const {

}

// is done
bool PolyLand::retirerCreature(const string& nom) // A MODIFIER... (si necessaire)
{
	for (Creature* creatureDansVecteur : creatures_)
	{
		if (creatureDansVecteur->obtenirNom == nom){

			creatureDansVecteur = creatures_[creatures_.size() - 1];
			creatures_.pop_back;
			return true;
		}
	}
	return false;
}

// À faire
PolyLand& PolyLand::operator-=(const Creature& creature) const {

}

//  is done
Dresseur* PolyLand::choisirDresseurAleatoire() // A MODIFIER... (si necessaire)
{
	if (!dresseurs_.empty())
	{
		unsigned int indice = rand() % dresseurs_.size();
		return dresseurs_[indice];
	}
	else
	{
		return nullptr;
	}
}

// is done
Creature* PolyLand::choisirCreatureAleatoire() // A MODIFIER... (si necessaire)
{
	if (!creatures_.empty())
	{
		unsigned int indice = rand() % creatures_.size();
		return creatures_[indice];
	}
	else {
		return nullptr;
	}
}


bool PolyLand::attraperCreature(Dresseur* dresseur, const Creature& creature) // A MODIFIER... (si necessaire)
{
	return dresseur->ajouterCreature(creature);
}

bool PolyLand::relacherCreature(Dresseur* dresseur, const string& nomCreature)
{
	return dresseur->enleverCreature(nomCreature);
}


ostream& operator<<(ostream& os, const PolyLand& polyLand) // A MODIFIER... (si necessaire)
{
	// A finir de là
	cout << "INFORMATION SUR POLYLAND" << endl;
	for (Dresseur* dresseur: polyLand.dresseurs_) {
		cout << dresseur;
	}

	cout << endl;

	for (Creature* creature : polyLand.creatures_) {
		cout << creature;
	}

	// Le return est bon
	return os;
}
