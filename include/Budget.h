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
    Budget();
    Budget(const MapNomsMonnaies& mapMonnaies);
    Budget(const Budget& budget);
    virtual ~Budget();

    // Getters
    const MapNomsMonnaies& getMapMonnaies() const;

    // Setters
    void setMapMonnaies(const MapNomsMonnaies& mapMonnaies);

    // Méthodes génériques
    void clear();
    void set(const MapNomsMonnaies& mapMonnaies);
    void copy(const Budget& budget);
    bool equals(const Budget& budget) const;
    void fromString(const std::string& fromString, const char& sep);
    const std::string toString(const char& sep) const;

    // Méthodes spécifiques (opérateurs)
    bool operator==(const Budget& budget) const;
    bool operator!=(const Budget& budget) const;

    // Méthodes spécifiques (m_mapMonnaies)
    bool hasMonnaie(const std::string& nom) const;
    PtrMonnaie getMonnaie(const std::string& nom) const;
    bool ajouterMonnaie(const std::string& nom, const double& quantite);
    bool supprimerMonnaie(const std::string& nom);

private:
    // Membres de classe
    MapNomsMonnaies m_mapMonnaies;
};

typedef Budget* PtrBudget;
typedef std::vector<Budget> ListeBudgets;
typedef std::vector<PtrBudget> ListePtrBudgets;
typedef std::map<int, Budget> MapIdBudgets;
typedef std::map<int, PtrBudget> MapIdPtrBudgets;
typedef std::map<std::string, Budget> MapNomsBudgets;
typedef std::map<std::string, PtrBudget> MapNomsPtrBudgets;

#endif // BUDGET_H
