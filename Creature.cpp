#include "Creature.h"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

Creature::Creature():nom_(""), attaque_(0), defense_(0), pointDeVie_(0),
	energie_(0), experience_(0), niveau_(0),energieTotal_(0),experienceNecessaire_(0),pointDeVieTotal_(0) // A MODIFIER... (si necessaire)
{
}

Creature::Creature(const string& nom, unsigned int attaque,
	unsigned int defense, unsigned int pointDeVie, unsigned int energie):
	nom_(nom), attaque_(attaque), defense_(defense), pointDeVie_(pointDeVie),
	energie_(energie), experience_(0), niveau_(0),experienceNecessaire_(0) // A MODIFIER... (si necessaire)
{
	energieTotal_ = energie;
	
	pointDeVieTotal_ = pointDeVie;
}


Creature::~Creature() // A MODIFIER... (si necessaire)
{

}

Creature::Creature(const Creature & creature)
{
	
		nom_ = creature.obtenirNom();
		attaque_ = creature.obtenirAttaque();
		defense_ = creature.obtenirDefense();
		pointDeVie_ = creature.obtenirPointDeVie();
		pointDeVieTotal_ = creature.obtenirPointDeVieTotal();
		energie_ = creature.obtenirEnergie();
		energieTotal_ = creature.obtenirEnergieTotale();
		experience_ = creature.obtenirExperience();
		experienceNecessaire_ = creature.obtenirExperienceNecessaire;
		niveau_ = creature.obtenirNiveau();
		for (int i = 0; i < creature.obtenirPouvoirs().size(); i++) {
			pouvoirs_[i] = new Pouvoir(*creature.obtenirPouvoirs()[i]);
		}
	
	


}

string Creature::obtenirNom() const{
	return nom_;
}

unsigned int Creature::obtenirAttaque() const
{
	return attaque_;
}

unsigned int Creature::obtenirDefense() const
{
	return defense_;
}

unsigned int Creature::obtenirPointDeVie() const
{
	return pointDeVie_;
}

unsigned int Creature::obtenirPointDeVieTotal() const
{
	return pointDeVieTotal_;
}

unsigned int Creature::obtenirEnergie() const
{
	return energie_;
}

unsigned int Creature::obtenirEnergieTotale() const
{
	return energieTotal_;
}

unsigned int Creature::obtenirExperience() const
{
	return experience_;
}

unsigned int Creature::obtenirExperienceNecessaire() const
{
	return experienceNecessaire_;
}

unsigned int Creature::obtenirNiveau() const
{
	return niveau_;
}

bool Creature::operator==(const Creature & creature) const
{
	if (nom_ == creature.obtenirNom()&&attaque_ == creature.obtenirAttaque()&&defense_ == creature.obtenirDefense()&&pointDeVie_ == creature.obtenirPointDeVie()&&pointDeVieTotal_ == creature.obtenirPointDeVieTotal()&&energie_ == creature.obtenirEnergie()&&energieTotal_ == creature.obtenirEnergieTotale()&&experience_ == creature.obtenirExperience()&&experienceNecessaire_ == creature.obtenirExperienceNecessaire()&&niveau_ == creature.obtenirNiveau()) {
		return true;
	}
	else {
		return false;
	}
}

bool Creature::operator==(const string & nom) const
{
	if (nom_ == nom) {
		return true;
	}
	return false;
}

Creature Creature::operator=(const Creature & creature)
{
	if (this != &creature) {
		nom_ = creature.obtenirNom();
		attaque_ = creature.obtenirAttaque();
		defense_ = creature.obtenirDefense();
		pointDeVie_ = creature.obtenirPointDeVie();
		pointDeVieTotal_ = creature.obtenirPointDeVieTotal();
		energie_ = creature.obtenirEnergie();
		energieTotal_ = creature.obtenirEnergieTotale();
		experience_ = creature.obtenirExperience();
		experienceNecessaire_ = creature.obtenirExperienceNecessaire;
		niveau_ = creature.obtenirNiveau();
		for (int i = 0; i < creature.obtenirPouvoirs().size(); i++) {
			pouvoirs_[i] = new Pouvoir(*creature.obtenirPouvoirs()[i]);
		}
	}
	return *this;
}

void Creature::apprendrePouvoir( Pouvoir * pouvoir)
{   
	pouvoirs_.push_back(pouvoir);
}

bool Creature::oublierPouvoir(Pouvoir * pouvoir)
{
	for (Pouvoir* i : pouvoirs_) {
		if (*i == *pouvoir) {
			i = pouvoirs_[pouvoirs_.size() - 1];
			pouvoirs_.pop_back();
			return true;
		}
	}
	return false;
}

vector<Pouvoir*> Creature::obtenirPouvoirs() const
{
	return pouvoirs_;
}


void Creature::attaquer(Creature & creature,const Pouvoir&pouvoir)// A MODIFIER... (si necessaire)
{
	if (energie_ >= pouvoir.obtenirEnergieNecessaire()) 
    {
		if (creature.obtenirPointDeVie() >= 0) 
        {
			//Calcul du nombre de degat selon une formule 
			unsigned int degat = (pouvoir.obtenirNombreDeDegat())* (attaque_ / 2 - creature.defense_);
			int tentative = rand() % 6;
			//l'attaque rate une fois sur 6
			if (tentative != 3) {
				cout << nom_ << " lance " << pouvoir.obtenirNom() << " qui inflige " << degat << " degat a " << creature.obtenirNom() << endl;
				if (degat > creature.obtenirPointDeVie()) {
					creature.modifierPointDeVie(0);
					int xp = experienceGagnee(creature);
					cout << nom_ << " a gagné " << xp << " XP" << endl;
				}
				else
					creature.modifierPointDeVie(creature.obtenirPointDeVie() - degat);
				cout << creature.obtenirNom() << " a encore " << creature.obtenirPointDeVie() << " PV" << endl;
				energie_ -= pouvoir.obtenirEnergieNecessaire();
			}
			else {
				cout << "Attaque " << pouvoir.obtenirNom() << " a échouée" << endl;
			}
		}
		else
			cout << "Vous deja avez vaincu " << creature.obtenirNom() << endl;
	}

}

int Creature::experienceGagnee(const Creature& creature)
{
	if (creature.obtenirPointDeVie() <= 0) 
    {
		//Calcul de l'experience selon une formule mystérieuse
		int experience = (creature.obtenirNiveau() + 1 - niveau_) * ((creature.obtenirAttaque() + 5 - attaque_) * (creature.obtenirDefense() + 3 - defense_)) + (pointDeVie_ / 2);
		if (experience > (experienceNecessaire_ - experience_)) 
        {
			//Cas ou la creature va monter d'un niveau
			int experienceRestante = experience - (experienceNecessaire_ - experience_);
			niveau_++;
			attaque_ += 1;
			defense_ += 1;
			pointDeVie_ += 5;
			energie_ += 5;
			energieTotal_ += 5;
			pointDeVieTotal_ += 5;
			experience_ = experienceRestante;
			experienceNecessaire_ = experienceNecessaire_ * 15 / 10;
		}
		else 
        {
			//Sinon elle recupère juste de l'expérience
			experience_ += experience;
		}
		return experience;
	}
	return 0;
}

void Creature::modifierAttaque(unsigned int attaque)
{
	attaque_ = attaque;
}

void Creature::modifierDefense(unsigned int defense)
{
	defense_ = defense;
}

void Creature::modifierPointDeVie(unsigned int pointDeVie)
{
	pointDeVie_ = pointDeVie;
}

void Creature::modifierEnergie(unsigned int energie)
{
	energie_ = energie;
}

void Creature::modifierExperience(unsigned int experience)
{
	experience_ = experience;
}

void Creature::modifierNiveau(unsigned int niveau)
{
	niveau_ = niveau;
}

void Creature::modifierPouvoirs(const vector<Pouvoir*>&pouvoirs ) // A MODIFIER... (si necessaire)
{
	for (int i = 0; i < pouvoirs.size(); i++) {
		pouvoirs_[i] = pouvoirs[i];
	}
	
}



// _______TP2________

bool operator==(const Creature & creature, const string & nom)
{
	if(nom==creature.obtenirNom()){
		return true;
	}
	return false;
}

ostream & operator<<(ostream & o, const Creature & creature)
{
	o << creature.obtenirNom() << " a " << creature.obtenirAttaque() << " en attaque et " << creature.obtenirDefense() << " en defense, " << endl
		<< "Il a " << creature.obtenirPointDeVie() << "/" << creature.obtenirPointDeVieTotal() << " PV et " << creature.obtenirEnergie() << "/" << creature.obtenirEnergieTotale() << " Energie" << endl
		<< "Il est au niveau " << creature.obtenirNiveau() << " avec " << creature.obtenirExperience() << " d'XP" << endl
		<< "Il lui manque " << creature.obtenirExperienceNecessaire() - creature.obtenirExperience() << " jusqu'au prochain niveau " << endl
		<< "Pouvoir : " << endl;

	if (creature.obtenirPouvoirs().empty()) {
		o << creature.obtenirNom()  <<  " ne connait aucun pouvoir" << endl;
	 }
	else {
		for (int i = 0; i < creature.obtenirPouvoirs().size(); i++) {
			o << *creature.obtenirPouvoirs()[i] << endl;
		}
	}
	o << endl;
	return o;
}
