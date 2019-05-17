#ifndef OBJETMAGIQUE_H
#define OBJETMAGIQUE_H

#include <string>

using namespace std;

class ObjetMagique
{
public:
	ObjetMagique();
	ObjetMagique(const string &nom, int bonus);
	~ObjetMagique();

	string obtenirNom() const;
	int obtenirBonus() const;

	void modifierNom(const string& nom);
	void modifierBonus(int bonus);

	friend ostream&operator<<(ostream&o,const ObjetMagique&objet); // A MODIFIER... (si necessaire)

private:
	string nom_;
	int bonus_;
};

#endif
