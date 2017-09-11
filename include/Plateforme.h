//==============================================================================
// Name        : Plateforme.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Header file of the Plateforme class
//==============================================================================

#ifndef PLATEFORME_H
#define PLATEFORME_H

#include "Budget.h"
#include "Echange.h"
#include <map>
#include <string>
#include <vector>

class Plateforme
{
public:
    // Constructeurs et destructeurs
    Plateforme();
    Plateforme(const std::string& nom, const MapNomsEchanges& mapEchanges, const Budget& budget);
    Plateforme(const Plateforme& plateforme);
    virtual ~Plateforme();

    // Getters
    const std::string& getNom() const;
    const MapNomsEchanges& getMapEchanges() const;
    const Budget& getBudget() const;

    // Setters
    void setNom(const std::string& nom);
    void setMapEchanges(const MapNomsEchanges& mapEchanges);
    void setBudget(const Budget& budget);

    // Méthodes génériques
    void clear();
    void set(const std::string& nom, const MapNomsEchanges& mapEchanges, const Budget& budget);
    void copy(const Plateforme& plateforme);
    bool equals(const Plateforme& plateforme) const;
    void fromString(const std::string& fromString, const char& sep);
    const std::string toString(const char& sep) const;

    // Méthodes spécifiques
    bool operator==(const Plateforme& plateforme) const;
    bool operator!=(const Plateforme& plateforme) const;

private:
    // Membres de classe
    std::string nom;
    MapNomsEchanges mapEchanges;
    Budget budget;
};

typedef Plateforme* PtrPlateforme;
typedef std::vector<Plateforme> ListePlateformes;
typedef std::vector<PtrPlateforme> ListePtrPlateformes;
typedef std::map<int, Plateforme> MapIdPlateformes;
typedef std::map<int, PtrPlateforme> MapIdPtrPlateformes;
typedef std::map<std::string, Plateforme> MapNomsPlateformes;
typedef std::map<std::string, PtrPlateforme> MapNomsPtrPlateformes;

#endif // PLATEFORME_H
