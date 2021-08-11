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
    Monnaie() = default;
    Monnaie(const Devise& devise, const double& quantite);

    // Opérateurs
    bool operator==(const Monnaie& monnaie) const = default;
    bool operator!=(const Monnaie& monnaie) const = default;

    // Getters
    const Devise& getDevise() const;
    const double& getQuantite() const;

    // Setters
    void setDevise(const Devise& devise);
    void setQuantite(const double& quantite);

    // Méthodes génériques
    void clear();
    void set(const Devise& devise, const double& quantite);
    void fromString(const std::string& fromString, const char& sep);
    const std::string toString(const char& sep) const;

private:
    // Membres de classe
    Devise _devise;
    double _quantite { 0.0 };
};

using PtrMonnaie = Monnaie*;
using CPtrMonnaie = const Monnaie*;
using ListeMonnaies = std::vector<Monnaie>;
using ListePtrMonnaies = std::vector<PtrMonnaie>;
using ListeCPtrMonnaies = std::vector<CPtrMonnaie>;
using MapIdMonnaies = std::map<int, Monnaie>;
using MapIdPtrMonnaies = std::map<int, PtrMonnaie>;
using MapIdCPtrMonnaies = std::map<int, CPtrMonnaie>;
using MapNomsMonnaies = std::map<std::string, Monnaie>;
using MapNomsPtrMonnaies = std::map<std::string, PtrMonnaie>;
using MapNomsCPtrMonnaies = std::map<std::string, CPtrMonnaie>;

#endif // MONNAIE_H
