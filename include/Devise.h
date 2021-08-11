//==============================================================================
// Name        : Devise.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Header file of the Devise class
//==============================================================================

#ifndef DEVISE_H
#define DEVISE_H

#include <map>
#include <string>
#include <vector>

class Devise
{
public:
    // Constructeurs et destructeurs
    Devise() = default;
    Devise(const std::string& nom);

    // Opérateurs
    bool operator==(const Devise& devise) const = default;
    bool operator!=(const Devise& devise) const = default;

    // Getters
    const std::string& getNom() const;

    // Setters
    void setNom(const std::string& nom);

    // Méthodes génériques
    void clear();
    void set(const std::string& nom);
    void fromString(const std::string& fromString, const char& sep);
    const std::string toString(const char& sep) const;

private:
    // Membres de classe
    std::string _nom;
};

using PtrDevise = Devise*;
using CPtrDevise = const Devise*;
using ListeDevises = std::vector<Devise>;
using ListePtrDevises = std::vector<PtrDevise>;
using ListeCPtrDevises = std::vector<CPtrDevise>;
using MapIdDevises = std::map<int, Devise>;
using MapIdPtrDevises = std::map<int, PtrDevise>;
using MapIdCPtrDevises = std::map<int, CPtrDevise>;
using MapNomsDevises = std::map<std::string, Devise>;
using MapNomsPtrDevises = std::map<std::string, PtrDevise>;
using MapNomsCPtrDevises = std::map<std::string, CPtrDevise>;

#endif // DEVISE_H
