//==============================================================================
// Name        : Monnaie.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Header file of the Monnaie class
//==============================================================================

#ifndef MONNAIE_H
#define MONNAIE_H

#include "Devise.h"
#include <map>
#include <string>
#include <vector>

class Monnaie
{
public:
    // Constructeurs et destructeurs
    Monnaie();
    Monnaie(const Devise& devise, const double& quantite);
    Monnaie(const Monnaie& monnaie);
    virtual ~Monnaie();

    // Opérateurs
    Monnaie& operator=(const Monnaie& monnaie);
    bool operator==(const Monnaie& monnaie) const;
    bool operator!=(const Monnaie& monnaie) const;

    // Getters
    const Devise& getDevise() const;
    const double& getQuantite() const;

    // Setters
    void setDevise(const Devise& devise);
    void setQuantite(const double& quantite);

    // Méthodes génériques
    void clear();
    void set(const Devise& devise, const double& quantite);
    void copy(const Monnaie& monnaie);
    bool equals(const Monnaie& monnaie) const;
    void fromString(const std::string& fromString, const char& sep);
    const std::string toString(const char& sep) const;

private:
    // Membres de classe
    Devise m_devise;
    double m_quantite;
};

typedef Monnaie* PtrMonnaie;
typedef std::vector<Monnaie> ListeMonnaies;
typedef std::vector<PtrMonnaie> ListePtrMonnaies;
typedef std::map<int, Monnaie> MapIdMonnaies;
typedef std::map<int, PtrMonnaie> MapIdPtrMonnaies;
typedef std::map<std::string, Monnaie> MapNomsMonnaies;
typedef std::map<std::string, PtrMonnaie> MapNomsPtrMonnaies;

#endif // MONNAIE_H
