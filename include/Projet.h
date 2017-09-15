//==============================================================================
// Name        : Projet.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Header file of the Projet class
//==============================================================================

#ifndef PROJET_H
#define PROJET_H

#include "Plateforme.h"
#include "Transaction.h"
#include <map>
#include <string>
#include <vector>

class Projet
{
public:
    // Constructeurs et destructeurs
    Projet();
    Projet(const MapNomsPlateformes& mapPlateformes);
    Projet(const Projet& projet);
    virtual ~Projet();

    // Getters
    const MapNomsPlateformes& getMapPlateformes() const;

    // Setters
    void setMapPlateformes(const MapNomsPlateformes& mapPlateformes);

    // Méthodes génériques
    void clear();
    void set(const MapNomsPlateformes& mapPlateformes);
    void copy(const Projet& projet);
    bool equals(const Projet& projet) const;
    void fromString(const std::string& fromString, const char& sep);
    const std::string toString(const char& sep) const;

    // Méthodes spécifiques (opérateurs)
    bool operator==(const Projet& projet) const;
    bool operator!=(const Projet& projet) const;

    // Méthodes spécifiques (m_mapPlateformes)
    bool hasPlateforme(const std::string& nom) const;
    PtrPlateforme getPlateforme(const std::string& nom) const;
    bool ajouterPlateforme(const std::string& nom, const MapNomsEchanges& mapEchanges,
            const Budget& budget);
    bool supprimerPlateforme(const std::string& nom);

    // Méthodes spécifiques (traitements)
    Transaction getTransactionOptimale(const int& date);
    void actualiserBudgets(const Transaction& transaction);
    void reequilibrerBudgets(const Transaction& transaction);

private:
    // Membres de classe
    MapNomsPlateformes m_mapPlateformes;
};

typedef Projet* PtrProjet;
typedef std::vector<Projet> ListeProjet_;
typedef std::vector<PtrProjet> ListePtrProjet_;
typedef std::map<int, Projet> MapIdProjet_;
typedef std::map<int, PtrProjet> MapIdPtrProjet_;
typedef std::map<std::string, Projet> MapNomsProjet_;
typedef std::map<std::string, PtrProjet> MapNomsPtrProjet_;

#endif // PROJET_H
