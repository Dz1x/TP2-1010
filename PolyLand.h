#ifndef POLYLAND_H
#define POLYLAND_H

#include "Dresseur.h"
#include "Creature.h"
#define MAX_DRESSEURS 100
#define MAX_CREATURES 1000
#define MAX_OBJET_MAGIQUE 100
#define MAX_POUVOIRS 10

class PolyLand
{
public:
	PolyLand(); // A MODIFIER... (si necessaire)
	~PolyLand(); // A MODIFIER... (si necessaire)

	bool ajouterDresseur(const Dresseur& dresseur); // A MODIFIER... (si necessaire)
	bool operator==(const Dresseur& dresseur) const;
	PolyLand& operator+=(const Dresseur& dresseur) const;
	
	bool ajouterCreature(const Creature& creature); // A MODIFIER... (si necessaire)
	bool operator==(const Creature& creature) const;
	PolyLand& operator+=(const Creature& creature) const;

	bool retirerDresseur(const string& nom); // A MODIFIER... (si necessaire)
	PolyLand& operator-=(const Dresseur& dresseur) const;

	bool retirerCreature(const string& nom); // A MODIFIER... (si necessaire)
	PolyLand& operator-=(const Creature& creature) const;

	Dresseur* choisirDresseurAleatoire(); // A MODIFIER... (si necessaire)
	Creature* choisirCreatureAleatoire(); // A MODIFIER... (si necessaire)

	bool attraperCreature(Dresseur* dresseur, const Creature& creature); // A MODIFIER... (si necessaire)
	

	bool relacherCreature(Dresseur* dresseur, const string& nomCreature); // A MODIFIER... (si necessaire)
	

	
	friend ostream& operator<<(ostream& os, const PolyLand& polyLand); // A MODIFIER... (si necessaire)


	//________TP2_______

private:
	//________TP2_______
	vector<Dresseur*> dresseurs_;
	vector<Creature*> creatures_;

};
#endif
