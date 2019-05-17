#include "Dresseur.h"
#include <iostream>

Dresseur::Dresseur() :nom_(""),equipe_(""),objetMagique_() {}; // A MODIFIER... (si necessaire)

Dresseur::Dresseur(const string& nom,const string&equipe) : nom_(nom), equipe_(equipe),objetMagique_()
{
	 // A MODIFIER... (si necessaire)
}




Dresseur::~Dresseur() // A MODIFIER... (si necessaire)
{
	for (Creature* i:creatures_)
	{
		delete i;
		i = nullptr;
	}
	
	
}

Creature * Dresseur::obtenirUneCreature(const string & nom) const
{
	for (Creature* i : creatures_) {
		if (i->operator==(nom)) {
			return i;
		}
	}
	return nullptr;
}

string Dresseur::obtenirNom() const
{
	return nom_;
}

string Dresseur::obtenirNomEquipe() const
{
	return equipe_;
}

void Dresseur::modifierNom(const string& nom)
{
	nom_ = nom;
}

unsigned int Dresseur::obtenirNombreCreatures() const
{
	return creatures_.size();
}

vector<Creature*> Dresseur::obtenirCreatures() const // A MODIFIER... (si necessaire)
{
	return creatures_;
}

void Dresseur::modifierCreature(vector<Creature*> creatures) // A MODIFIER... (si necessaire)
{
	creatures_ = creatures;
}

ObjetMagique Dresseur::obtenirObjetMagique() const
{
	return objetMagique_;
}

void Dresseur::modifierObjetMagique(const ObjetMagique & objetMagique)
{
	objetMagique_ = objetMagique;
}

void Dresseur::utiliserObjetMagique(Creature* creature)
{

	if ((creature->obtenirPointDeVieTotal() - creature->obtenirPointDeVie()) >= objetMagique_.obtenirBonus()) {
		creature->modifierPointDeVie(creature->obtenirPointDeVie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierPointDeVie(creature->obtenirPointDeVieTotal());
	}
	if ((creature->obtenirEnergieTotale() - creature->obtenirEnergie()) > objetMagique_.obtenirBonus()) {
		creature->modifierEnergie(creature->obtenirEnergie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierEnergie(creature->obtenirEnergieTotale());
	}
}

bool Dresseur::ajouterCreature(const Creature& creature) // A MODIFIER... (si necessaire)
{
	
		for (Creature* i:creatures_)
		{
			if (i->obtenirNom() == creature.obtenirNom())
				return false;
		}
		creatures_.push_back( new Creature(creature));
		return true;
	
	
		
	
}

bool Dresseur::enleverCreature(const string& nom) // A MODIFIER... (si necessaire)
{
	for (Creature* i:creatures_)
	{
		if (i->obtenirNom == nom)
		{
			
			i = creatures_[creatures_.size() - 1];
			creatures_.pop_back;
			

			return true;
		}
	}
	return false;
}

bool Dresseur::operator==(const Dresseur & dresseur) const
{
	bool test;
	if (creatures_.size() != dresseur.obtenirNombreCreatures()) {
		return false;
	}
	for(Creature* i:creatures_){
		test = false;
		for (Creature* k : dresseur.obtenirCreatures()) {
			if (i == k) {
				test = true;
			}
		}
		if (test == false) {
			return false;
		}
		
	}
	return true;

}
bool Dresseur::operator==(const string&nom)const {
	if (nom_ == nom) {
		return true;
	}
	return false;
}



// ___TP2___

bool operator==(const string & nom, const Dresseur & dresseur) 
{
	return dresseur == nom;
}

ostream & operator<<(ostream & os, const Dresseur & dresseur)
{
	// TODO: insérer une instruction return ici
	os << dresseur.obtenirNom() << " possede " << dresseur.obtenirNombreCreatures()
	   << " creatures et appartient a l'equipe de " << dresseur.obtenirNomEquipe() << endl;

	return os;
}
