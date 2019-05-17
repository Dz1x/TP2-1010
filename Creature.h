#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include "ObjetMagique.h"
#include "Pouvoir.h"
#include <vector>

class Creature
{
public:
	Creature(); // A MODIFIER... (si necessaire)
	Creature(const string& nom, unsigned int attaque, 
		unsigned int defense, unsigned int pointDeVie, unsigned int energie); // A COMPLETER... (si necessaire)
	~Creature(); // A MODIFIER... (si necessaire)
	Creature(const Creature&creature);
	string obtenirNom() const;
	unsigned int obtenirAttaque() const;
	unsigned int obtenirDefense() const;
	unsigned int obtenirPointDeVie() const;
	unsigned int obtenirPointDeVieTotal() const;
	unsigned int obtenirEnergie() const;
	unsigned int obtenirEnergieTotale() const;
	unsigned int obtenirExperience() const;
	unsigned int obtenirExperienceNecessaire() const;
	unsigned int obtenirNiveau() const;
	bool operator==(const Creature&creature) const;
	bool operator==(const string&nom) const;
	Creature operator=(const Creature&creature);
	
	void apprendrePouvoir( Pouvoir* pouvoir);
	bool oublierPouvoir(Pouvoir*pouvoir);
	vector<Pouvoir*> obtenirPouvoirs() const; // A MODIFIER... (si necessaire)

	void attaquer(Creature& creature,const Pouvoir&pouvoir);// A MODIFIER... (si necessaire)
	int experienceGagnee(const Creature& creature);
	
	void modifierAttaque(unsigned int attaque);
	void modifierDefense(unsigned int defense);
	void modifierPointDeVie(unsigned int pointDeVie);
	void modifierEnergie(unsigned int energie);
	void modifierExperience(unsigned int experience);
	void modifierNiveau(unsigned int niveau);
	void modifierPouvoirs(const vector<Pouvoir*>& pouvoirs); // A MODIFIER... (si necessaire)

	friend bool operator==(const Creature&creature, const std::string&nom);
	friend ostream&operator<<(ostream&o, const Creature&creature);
	// _________TP2___________

private:

	string nom_;
	unsigned int attaque_;
	unsigned int defense_;
	unsigned int pointDeVie_;
	unsigned int pointDeVieTotal_;
	unsigned int energie_;
	unsigned int energieTotal_;
	unsigned int experience_;
	unsigned int experienceNecessaire_;
	unsigned int niveau_;
	vector<Pouvoir*> pouvoirs_;
	// _________TP2___________
	
};

#endif
