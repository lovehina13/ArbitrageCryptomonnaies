//==============================================================================
// Name        : Budget.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Header file of the Budget class
//==============================================================================

#ifndef BUDGET_H
#define BUDGET_H

#include "Monnaie.h"
#include <map>
#include <string>
#include <vector>

class Budget
{
public:
    // Constructeurs et destructeurs
    Budget() = default;
    Budget(const MapNomsMonnaies& mapMonnaies);

    // Opérateurs
    bool operator==(const Budget& budget) const = default;
    bool operator!=(const Budget& budget) const = default;

    // Getters
    const MapNomsMonnaies& getMapMonnaies() const;

    // Setters
    void setMapMonnaies(const MapNomsMonnaies& mapMonnaies);

    // Méthodes génériques
    void clear();
    void set(const MapNomsMonnaies& mapMonnaies);
    void fromString(const std::string& fromString, const char& sep);
    const std::string toString(const char& sep) const;

    // Méthodes spécifiques (m_mapMonnaies)
    bool hasMonnaie(const std::string& nom) const;
    CPtrMonnaie getMonnaie(const std::string& nom) const;
    bool ajouterMonnaie(const std::string& nom, const Monnaie& monnaie);
    bool supprimerMonnaie(const std::string& nom);

private:
    // Membres de classe
    MapNomsMonnaies _mapMonnaies;
};

using PtrBudget = Budget*;
using CPtrBudget = const Budget*;
using ListeBudgets = std::vector<Budget>;
using ListePtrBudgets = std::vector<PtrBudget>;
using ListeCPtrBudgets = std::vector<CPtrBudget>;
using MapIdBudgets = std::map<int, Budget>;
using MapIdPtrBudgets = std::map<int, PtrBudget>;
using MapIdCPtrBudgets = std::map<int, CPtrBudget>;
using MapNomsBudgets = std::map<std::string, Budget>;
using MapNomsPtrBudgets = std::map<std::string, PtrBudget>;
using MapNomsCPtrBudgets = std::map<std::string, CPtrBudget>;

#endif // BUDGET_H
