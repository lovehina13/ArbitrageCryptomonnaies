//==============================================================================
// Name        : Plateforme.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Plateforme class
//==============================================================================

#include "Plateforme.h"
#include <utility>

Plateforme::Plateforme() :
        _nom(std::string()), _mapEchanges(MapNomsEchanges()), _budget(Budget()), _client(nullptr)
{
    clear();
}

Plateforme::Plateforme(const std::string& nom, const MapNomsEchanges& mapEchanges,
        const Budget& budget, const CPtrClient client) :
        Plateforme()
{
    set(nom, mapEchanges, budget, client);
}

Plateforme::Plateforme(const Plateforme& plateforme) :
        Plateforme()
{
    copy(plateforme);
}

Plateforme::~Plateforme()
{
    // delete m_client;
}

Plateforme& Plateforme::operator=(const Plateforme& plateforme)
{
    copy(plateforme);
    return *this;
}

bool Plateforme::operator==(const Plateforme& plateforme) const
{
    return equals(plateforme);
}

bool Plateforme::operator!=(const Plateforme& plateforme) const
{
    return !equals(plateforme);
}

const std::string& Plateforme::getNom() const
{
    return _nom;
}

const MapNomsEchanges& Plateforme::getMapEchanges() const
{
    return _mapEchanges;
}

const Budget& Plateforme::getBudget() const
{
    return _budget;
}

CPtrClient Plateforme::getClient() const
{
    return _client;
}

void Plateforme::setNom(const std::string& nom)
{
    _nom = nom;
}

void Plateforme::setMapEchanges(const MapNomsEchanges& mapEchanges)
{
    _mapEchanges = mapEchanges;
}

void Plateforme::setBudget(const Budget& budget)
{
    _budget = budget;
}

void Plateforme::setClient(const CPtrClient client)
{
    _client = const_cast<PtrClient>(client);
}

void Plateforme::clear()
{
    set(std::string(), MapNomsEchanges(), Budget(), nullptr);
}

void Plateforme::set(const std::string& nom, const MapNomsEchanges& mapEchanges,
        const Budget& budget, const CPtrClient client)
{
    setNom(nom);
    setMapEchanges(mapEchanges);
    setBudget(budget);
    setClient(client);
}

void Plateforme::copy(const Plateforme& plateforme)
{
    set(plateforme.getNom(), plateforme.getMapEchanges(), plateforme.getBudget(),
            plateforme.getClient());
}

bool Plateforme::equals(const Plateforme& plateforme) const
{
    if (getNom() != plateforme.getNom())
        return false;
    if (getMapEchanges() != plateforme.getMapEchanges())
        return false;
    if (getBudget() != plateforme.getBudget())
        return false;
    if (getClient() != plateforme.getClient())
        return false;
    return true;
}

void Plateforme::fromString(const std::string& /*fromString*/, const char& /*sep*/)
{
    // TODO void Plateforme::fromString(const std::string& fromString, const char& sep)
    // #warning "'void Plateforme::fromString(const std::string& fromString, const char& sep)' not implemented"
}

const std::string Plateforme::toString(const char& /*sep*/) const
{
    // TODO const std::string Plateforme::toString(const char& sep) const
    // #warning "'const std::string Plateforme::toString(const char& sep) const' not implemented"
    return std::string();
}

bool Plateforme::hasEchange(const std::string& nom) const
{
    return (_mapEchanges.find(nom) != _mapEchanges.end());
}

CPtrEchange Plateforme::getEchange(const std::string& nom) const
{
    return (hasEchange(nom) ? &_mapEchanges.find(nom)->second : nullptr);
}

bool Plateforme::ajouterEchange(const std::string& nom, const Echange& echange)
{
    return (_mapEchanges.insert(std::pair<std::string, Echange>(nom, echange)).second);
}

bool Plateforme::supprimerEchange(const std::string& nom)
{
    return (_mapEchanges.erase(nom) > 0);
}
