#ifndef POUVOIR_H
#define POUVOIR_H

#include <string>

using namespace std;

class Pouvoir
{
public:
	Pouvoir();
	Pouvoir(const string& nom, 
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	Pouvoir(const Pouvoir&pouvoir);

	~Pouvoir();

	unsigned int obtenirNombreDeDegat() const;
	unsigned int obtenirEnergieNecessaire() const;
	string obtenirNom() const;

	void modifierNombreDeDegat(unsigned int nombreDegat);
	void modifierEnergieNecessarie(unsigned int energieNecessaire);
	void modifierNom(const string& nom);

	friend ostream&operator<<(ostream&o,const Pouvoir&pouvoir); // A MODIFIER... (si necessaire)

	//________TP2________
	Pouvoir operator=(const Pouvoir&pouvoir);
	bool operator==(const Pouvoir&pouvoir);

private:
	string nom_;
	unsigned int nombreDeDegat_ ;
	unsigned int energieNecessaire_;

};

#endif
