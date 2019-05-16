#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include "Creature.h"
#include <vector>
#define MAX_NOMBRE_CREATURES 2

class Dresseur
{
public:
	Dresseur(); // A MODIFIER... (si necessaire)
	Dresseur(const string& nom,const string&equipe); // A MODIFIER... (si necessaire)
	~Dresseur(); // A MODIFIER... (si necessaire)
	Creature* obtenirUneCreature(const string&nom) const;
	string obtenirNom() const;
	string obtenirNomEquipe() const;
	void modifierNom(const string& nom);
	
	unsigned int obtenirNombreCreatures() const; // A MODIFIER... (si necessaire)

	vector<Creature*> obtenirCreatures() const; // A MODIFIER... (si necessaire)
	void modifierCreature(vector<Creature*> creatures); // A MODIFIER... (si necessaire)
	
	ObjetMagique obtenirObjetMagique() const;
	void modifierObjetMagique(const ObjetMagique& objetMagique);

	void utiliserObjetMagique(Creature* creature);
	
	bool ajouterCreature(const Creature& creature); // A MODIFIER... (si necessaire)
	bool enleverCreature(const string& nom); // A MODIFIER... (si necessaire)
	bool operator==(const Dresseur&dresseur) const;
	bool operator==(const string&nom)const;
	friend operator==();
	friend ostream&operator<<(ostream&os,const Dresseur&dresseur); // A COMPLETER... (si necessaire)

private:
	string nom_;
	ObjetMagique objetMagique_;

	// ___TP2____
	vector<Creature*> creatures_;
	string equipe_;

};

#endif