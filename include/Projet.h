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
    Projet() = default;
    Projet(const MapNomsPlateformes& mapPlateformes);

    // Opérateurs
    bool operator==(const Projet& projet) const = default;
    bool operator!=(const Projet& projet) const = default;

    // Getters
    const MapNomsPlateformes& getMapPlateformes() const;

    // Setters
    void setMapPlateformes(const MapNomsPlateformes& mapPlateformes);

    // Méthodes génériques
    void clear();
    void set(const MapNomsPlateformes& mapPlateformes);
    void fromString(const std::string& fromString, const char& sep);
    const std::string toString(const char& sep) const;

    // Méthodes spécifiques (m_mapPlateformes)
    bool hasPlateforme(const std::string& nom) const;
    CPtrPlateforme getPlateforme(const std::string& nom) const;
    bool ajouterPlateforme(const std::string& nom, const Plateforme& plateforme);
    bool supprimerPlateforme(const std::string& nom);

    // Méthodes spécifiques (traitements)
    void effacerNombreCours(const int& nombreCoursMaximal);
    void recupererCours(const int& date);
    const Transaction getTransactionOptimale(const int& date, const double& beneficeMinimal,
            const double& ratioBeneficeMinimal) const;
    void actualiserBudgets(const Transaction& transaction);
    void equilibrerBudgets(const Transaction& transaction);

private:
    // Membres de classe
    MapNomsPlateformes _mapPlateformes;
};

using PtrProjet = Projet*;
using CPtrProjet = const Projet*;
using ListeProjets = std::vector<Projet>;
using ListePtrProjets = std::vector<PtrProjet>;
using ListeCPtrProjets = std::vector<CPtrProjet>;
using MapIdProjets = std::map<int, Projet>;
using MapIdPtrProjets = std::map<int, PtrProjet>;
using MapIdCPtrProjets = std::map<int, CPtrProjet>;
using MapNomsProjets = std::map<std::string, Projet>;
using MapNomsPtrProjets = std::map<std::string, PtrProjet>;
using MapNomsCPtrProjets = std::map<std::string, CPtrProjet>;

#endif // PROJET_H
