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
    Echange(const Devise& deviseNumerique, const Devise& deviseReelle,
            const double& fraisFixesAchat, const double& fraisFixesVente,
            const double& fraisVariablesAchat, const double& fraisVariablesVente,
            const MapIdCours& mapCours);
    Echange(const Echange& echange);
    virtual ~Echange();

    // Opérateurs
    Echange& operator=(const Echange& echange);
    bool operator==(const Echange& echange) const;
    bool operator!=(const Echange& echange) const;

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
    void copy(const Echange& echange);
    bool equals(const Echange& echange) const;
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
    double _fraisFixesAchat;
    double _fraisFixesVente;
    double _fraisVariablesAchat;
    double _fraisVariablesVente;
    MapIdCours _mapCours;
};

typedef Echange* PtrEchange;
typedef const Echange* CPtrEchange;
typedef std::vector<Echange> ListeEchanges;
typedef std::vector<PtrEchange> ListePtrEchanges;
typedef std::vector<CPtrEchange> ListeCPtrEchanges;
typedef std::map<int, Echange> MapIdEchanges;
typedef std::map<int, PtrEchange> MapIdPtrEchanges;
typedef std::map<int, CPtrEchange> MapIdCPtrEchanges;
typedef std::map<std::string, Echange> MapNomsEchanges;
typedef std::map<std::string, PtrEchange> MapNomsPtrEchanges;
typedef std::map<std::string, CPtrEchange> MapNomsCPtrEchanges;

#endif // ECHANGE_H
