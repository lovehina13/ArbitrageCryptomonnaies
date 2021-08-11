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

    // Opérateurs
    Projet& operator=(const Projet& projet);
    bool operator==(const Projet& projet) const;
    bool operator!=(const Projet& projet) const;

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

typedef Projet* PtrProjet;
typedef const Projet* CPtrProjet;
typedef std::vector<Projet> ListeProjets;
typedef std::vector<PtrProjet> ListePtrProjets;
typedef std::vector<CPtrProjet> ListeCPtrProjets;
typedef std::map<int, Projet> MapIdProjets;
typedef std::map<int, PtrProjet> MapIdPtrProjets;
typedef std::map<int, CPtrProjet> MapIdCPtrProjets;
typedef std::map<std::string, Projet> MapNomsProjets;
typedef std::map<std::string, PtrProjet> MapNomsPtrProjets;
typedef std::map<std::string, CPtrProjet> MapNomsCPtrProjets;

#endif // PROJET_H
