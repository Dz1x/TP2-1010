#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include "Creature.h"
#include <vector>
#define MAX_NOMBRE_CREATURES 2

class Dresseur
{
public:
	// ___TP1____
	Dresseur(); // A MODIFIER... (si necessaire)
	Dresseur(const string& nom,const string&equipe); // A MODIFIER... (si necessaire)
	~Dresseur(); // A MODIFIER... (si necessaire)

	string obtenirNom() const;
	Creature* obtenirUneCreature(const string&nom) const;
	ObjetMagique obtenirObjetMagique() const;
	unsigned int obtenirNombreCreatures() const; // A MODIFIER... (si necessaire)

	void modifierNom(const string& nom);
	void modifierCreature(vector<Creature*> creatures); // A MODIFIER... (si necessaire)
	void modifierObjetMagique(const ObjetMagique& objetMagique);
	
	bool ajouterCreature( Creature& creature); // A MODIFIER... (si necessaire)
	bool enleverCreature(const string& nom); // A MODIFIER... (si necessaire)
	
	void utiliserObjetMagique(Creature* creature);

	// ___TP2____
	vector<Creature*> obtenirCreatures() const; // A MODIFIER... (si necessaire)
	string obtenirNomEquipe() const;
	
	bool operator==(const Dresseur&dresseur) const;
	bool operator==(const string&nom)const;
	friend bool operator==(const string&nom,const Dresseur&dresseur);
	
	friend ostream&operator<<(ostream&os,const Dresseur&dresseur); // A COMPLETER... (si necessaire)

private:
	// ___TP1____
	string nom_;
	ObjetMagique objetMagique_;

	// ___TP2____
	vector<Creature*> creatures_;
	string equipe_;
};

#endif
