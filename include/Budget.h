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

    // Opérateurs
    Budget& operator=(const Budget& budget);
    bool operator==(const Budget& budget) const;
    bool operator!=(const Budget& budget) const;

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

    // Méthodes spécifiques (m_mapMonnaies)
    bool hasMonnaie(const std::string& nom) const;
    CPtrMonnaie getMonnaie(const std::string& nom) const;
    bool ajouterMonnaie(const std::string& nom, const Monnaie& monnaie);
    bool supprimerMonnaie(const std::string& nom);

private:
    // Membres de classe
    MapNomsMonnaies m_mapMonnaies;
};

typedef Budget* PtrBudget;
typedef const Budget* CPtrBudget;
typedef std::vector<Budget> ListeBudgets;
typedef std::vector<PtrBudget> ListePtrBudgets;
typedef std::vector<CPtrBudget> ListeCPtrBudgets;
typedef std::map<int, Budget> MapIdBudgets;
typedef std::map<int, PtrBudget> MapIdPtrBudgets;
typedef std::map<int, CPtrBudget> MapIdCPtrBudgets;
typedef std::map<std::string, Budget> MapNomsBudgets;
typedef std::map<std::string, PtrBudget> MapNomsPtrBudgets;
typedef std::map<std::string, CPtrBudget> MapNomsCPtrBudgets;

#endif // BUDGET_H
