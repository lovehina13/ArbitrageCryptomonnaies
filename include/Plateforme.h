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
#include <string>
#include <vector>

class Plateforme
{
public:
    // Constructeurs et destructeurs
    Plateforme();
    Plateforme(const std::string& nom, const MapNomsEchanges& mapEchanges, const Budget& budget,
            const CPtrClient client);
    Plateforme(const Plateforme& plateforme);
    virtual ~Plateforme();

    // Opérateurs
    Plateforme& operator=(const Plateforme& plateforme);
    bool operator==(const Plateforme& plateforme) const;
    bool operator!=(const Plateforme& plateforme) const;

    // Getters
    const std::string& getNom() const;
    const MapNomsEchanges& getMapEchanges() const;
    const Budget& getBudget() const;
    CPtrClient getClient() const;

    // Setters
    void setNom(const std::string& nom);
    void setMapEchanges(const MapNomsEchanges& mapEchanges);
    void setBudget(const Budget& budget);
    void setClient(const CPtrClient client);

    // Méthodes génériques
    void clear();
    void set(const std::string& nom, const MapNomsEchanges& mapEchanges, const Budget& budget,
            const CPtrClient client);
    void copy(const Plateforme& plateforme);
    bool equals(const Plateforme& plateforme) const;
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
    PtrClient _client;
};

typedef Plateforme* PtrPlateforme;
typedef const Plateforme* CPtrPlateforme;
typedef std::vector<Plateforme> ListePlateformes;
typedef std::vector<PtrPlateforme> ListePtrPlateformes;
typedef std::vector<CPtrPlateforme> ListeCPtrPlateformes;
typedef std::map<int, Plateforme> MapIdPlateformes;
typedef std::map<int, PtrPlateforme> MapIdPtrPlateformes;
typedef std::map<int, CPtrPlateforme> MapIdCPtrPlateformes;
typedef std::map<std::string, Plateforme> MapNomsPlateformes;
typedef std::map<std::string, PtrPlateforme> MapNomsPtrPlateformes;
typedef std::map<std::string, CPtrPlateforme> MapNomsCPtrPlateformes;

#endif // PLATEFORME_H
