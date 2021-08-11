//==============================================================================
// Name        : Plateforme.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Plateforme class
//==============================================================================

#include "Plateforme.h"
#include <utility>

Plateforme::Plateforme(const std::string& nom, const MapNomsEchanges& mapEchanges,
        const Budget& budget, const std::shared_ptr<Client>& client) :
        _nom(nom), _mapEchanges(mapEchanges), _budget(budget), _client(client)
{
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

const std::shared_ptr<Client>& Plateforme::getClient() const
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

void Plateforme::setClient(const std::shared_ptr<Client>& client)
{
    _client = client;
}

void Plateforme::clear()
{
    *this = Plateforme();
}

void Plateforme::set(const std::string& nom, const MapNomsEchanges& mapEchanges,
        const Budget& budget, const std::shared_ptr<Client>& client)
{
    setNom(nom);
    setMapEchanges(mapEchanges);
    setBudget(budget);
    setClient(client);
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
