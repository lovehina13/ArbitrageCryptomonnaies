//==============================================================================
// Name        : Plateforme.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Header file of the Plateforme class
//==============================================================================

#ifndef PLATEFORME_H
#define PLATEFORME_H

#include "Budget.h"
#include "Client.h"
#include "Echange.h"
#include <map>
#include <memory>
#include <string>
#include <vector>

class Plateforme
{
public:
    // Constructeurs et destructeurs
    Plateforme() = default;
    Plateforme(const std::string& nom, const MapNomsEchanges& mapEchanges, const Budget& budget,
            const std::shared_ptr<Client>& client);

    // Opérateurs
    bool operator==(const Plateforme& plateforme) const = default;
    bool operator!=(const Plateforme& plateforme) const = default;

    // Getters
    const std::string& getNom() const;
    const MapNomsEchanges& getMapEchanges() const;
    const Budget& getBudget() const;
    const std::shared_ptr<Client>& getClient() const;

    // Setters
    void setNom(const std::string& nom);
    void setMapEchanges(const MapNomsEchanges& mapEchanges);
    void setBudget(const Budget& budget);
    void setClient(const std::shared_ptr<Client>& client);

    // Méthodes génériques
    void clear();
    void set(const std::string& nom, const MapNomsEchanges& mapEchanges, const Budget& budget,
            const std::shared_ptr<Client>& client);
    void fromString(const std::string& fromString, const char& sep);
    const std::string toString(const char& sep) const;

    // Méthodes spécifiques (m_mapEchanges)
    bool hasEchange(const std::string& nom) const;
    CPtrEchange getEchange(const std::string& nom) const;
    bool ajouterEchange(const std::string& nom, const Echange& echange);
    bool supprimerEchange(const std::string& nom);

private:
    // Membres de classe
    std::string _nom;
    MapNomsEchanges _mapEchanges;
    Budget _budget;
    std::shared_ptr<Client> _client { std::make_shared<Client>() };
};

using PtrPlateforme = Plateforme*;
using CPtrPlateforme = const Plateforme*;
using ListePlateformes = std::vector<Plateforme>;
using ListePtrPlateformes = std::vector<PtrPlateforme>;
using ListeCPtrPlateformes = std::vector<CPtrPlateforme>;
using MapIdPlateformes = std::map<int, Plateforme>;
using MapIdPtrPlateformes = std::map<int, PtrPlateforme>;
using MapIdCPtrPlateformes = std::map<int, CPtrPlateforme>;
using MapNomsPlateformes = std::map<std::string, Plateforme>;
using MapNomsPtrPlateformes = std::map<std::string, PtrPlateforme>;
using MapNomsCPtrPlateformes= std::map<std::string, CPtrPlateforme>;

#endif // PLATEFORME_H
