//==============================================================================
// Name        : Echange.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Header file of the Echange class
//==============================================================================

#ifndef ECHANGE_H
#define ECHANGE_H

#include "Cours.h"
#include "Devise.h"
#include <map>
#include <string>
#include <vector>

class Echange
{
public:
    // Constructeurs et destructeurs
    Echange();
    Echange(const Devise& deviseNumerique, const Devise& deviseReelle, const double& fraisFixes,
            const double& fraisVariables, const MapIdCours& mapCours);
    Echange(const Echange& echange);
    virtual ~Echange();

    // Getters
    const Devise& getDeviseNumerique() const;
    const Devise& getDeviseReelle() const;
    const double& getFraisFixes() const;
    const double& getFraisVariables() const;
    const MapIdCours& getMapCours() const;

    // Setters
    void setDeviseNumerique(const Devise& deviseNumerique);
    void setDeviseReelle(const Devise& deviseReelle);
    void setFraisFixes(const double& fraisFixes);
    void setFraisVariables(const double& fraisVariables);
    void setMapCours(const MapIdCours& mapCours);

    // Méthodes génériques
    void clear();
    void set(const Devise& deviseNumerique, const Devise& deviseReelle, const double& fraisFixes,
            const double& fraisVariables, const MapIdCours& mapCours);
    void copy(const Echange& echange);
    bool equals(const Echange& echange) const;
    void fromString(const std::string& fromString, const char& sep);
    const std::string toString(const char& sep) const;

    // Méthodes spécifiques (opérateurs)
    bool operator==(const Echange& echange) const;
    bool operator!=(const Echange& echange) const;

    // Méthodes spécifiques (m_mapCours)
    bool hasCours(const int& date) const;
    PtrCours getCours(const int& date) const;
    bool ajouterCours(const int& date, const double& valeurAchat, const double& valeurVente,
            const double& quantiteAchat, const double& quantiteVente);
    bool supprimerCours(const int& date);

private:
    // Membres de classe
    Devise m_deviseNumerique;
    Devise m_deviseReelle;
    double m_fraisFixes;
    double m_fraisVariables;
    MapIdCours m_mapCours;
};

typedef Echange* PtrEchange;
typedef std::vector<Echange> ListeEchanges;
typedef std::vector<PtrEchange> ListePtrEchanges;
typedef std::map<int, Echange> MapIdEchanges;
typedef std::map<int, PtrEchange> MapIdPtrEchanges;
typedef std::map<std::string, Echange> MapNomsEchanges;
typedef std::map<std::string, PtrEchange> MapNomsPtrEchanges;

#endif // ECHANGE_H
