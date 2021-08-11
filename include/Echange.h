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
    Echange() = default;
    Echange(const Devise& deviseNumerique, const Devise& deviseReelle,
            const double& fraisFixesAchat, const double& fraisFixesVente,
            const double& fraisVariablesAchat, const double& fraisVariablesVente,
            const MapIdCours& mapCours);

    // Opérateurs
    bool operator==(const Echange& echange) const = default;
    bool operator!=(const Echange& echange) const = default;

    // Getters
    const Devise& getDeviseNumerique() const;
    const Devise& getDeviseReelle() const;
    const double& getFraisFixesAchat() const;
    const double& getFraisFixesVente() const;
    const double& getFraisVariablesAchat() const;
    const double& getFraisVariablesVente() const;
    const MapIdCours& getMapCours() const;

    // Setters
    void setDeviseNumerique(const Devise& deviseNumerique);
    void setDeviseReelle(const Devise& deviseReelle);
    void setFraisFixesAchat(const double& fraisFixesAchat);
    void setFraisFixesVente(const double& fraisFixesVente);
    void setFraisVariablesAchat(const double& fraisVariablesAchat);
    void setFraisVariablesVente(const double& fraisVariablesVente);
    void setMapCours(const MapIdCours& mapCours);

    // Méthodes génériques
    void clear();
    void set(const Devise& deviseNumerique, const Devise& deviseReelle,
            const double& fraisFixesAchat, const double& fraisFixesVente,
            const double& fraisVariablesAchat, const double& fraisVariablesVente,
            const MapIdCours& mapCours);
    void fromString(const std::string& fromString, const char& sep);
    const std::string toString(const char& sep) const;

    // Méthodes spécifiques (m_mapCours)
    bool hasCours(const int& date) const;
    CPtrCours getCours(const int& date) const;
    bool ajouterCours(const int& date, const Cours& cours);
    bool supprimerCours(const int& date);

private:
    // Membres de classe
    Devise _deviseNumerique;
    Devise _deviseReelle;
    double _fraisFixesAchat { 0.0 };
    double _fraisFixesVente { 0.0 };
    double _fraisVariablesAchat { 0.0 };
    double _fraisVariablesVente { 0.0 };
    MapIdCours _mapCours;
};

using PtrEchange = Echange*;
using CPtrEchange = const Echange*;
using ListeEchanges = std::vector<Echange>;
using ListePtrEchanges = std::vector<PtrEchange>;
using ListeCPtrEchanges = std::vector<CPtrEchange>;
using MapIdEchanges = std::map<int, Echange>;
using MapIdPtrEchanges = std::map<int, PtrEchange>;
using MapIdCPtrEchanges= std::map<int, CPtrEchange>;
using MapNomsEchanges = std::map<std::string, Echange>;
using MapNomsPtrEchanges = std::map<std::string, PtrEchange>;
using MapNomsCPtrEchanges = std::map<std::string, CPtrEchange>;

#endif // ECHANGE_H
