//==============================================================================
// Name        : Plateforme.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Plateforme class
//==============================================================================

#include "Plateforme.h"
#include <utility>

Plateforme::Plateforme() :
        m_nom(std::string()), m_mapEchanges(MapNomsEchanges()), m_budget(Budget()),
                m_client(nullptr)
{
    this->clear();
}

Plateforme::Plateforme(const std::string& nom, const MapNomsEchanges& mapEchanges,
        const Budget& budget, const CPtrClient client) :
        Plateforme()
{
    this->set(nom, mapEchanges, budget, client);
}

Plateforme::Plateforme(const Plateforme& plateforme) :
        Plateforme()
{
    this->copy(plateforme);
}

Plateforme::~Plateforme()
{
    delete this->m_client;
}

Plateforme& Plateforme::operator=(const Plateforme& plateforme)
{
    this->copy(plateforme);
    return *this;
}

bool Plateforme::operator==(const Plateforme& plateforme) const
{
    return this->equals(plateforme);
}

bool Plateforme::operator!=(const Plateforme& plateforme) const
{
    return !this->equals(plateforme);
}

const std::string& Plateforme::getNom() const
{
    return this->m_nom;
}

const MapNomsEchanges& Plateforme::getMapEchanges() const
{
    return this->m_mapEchanges;
}

const Budget& Plateforme::getBudget() const
{
    return this->m_budget;
}

CPtrClient Plateforme::getClient() const
{
    return this->m_client;
}

void Plateforme::setNom(const std::string& nom)
{
    this->m_nom = nom;
}

void Plateforme::setMapEchanges(const MapNomsEchanges& mapEchanges)
{
    this->m_mapEchanges = mapEchanges;
}

void Plateforme::setBudget(const Budget& budget)
{
    this->m_budget = budget;
}

void Plateforme::setClient(const CPtrClient client)
{
    this->m_client = const_cast<PtrClient>(client);
}

void Plateforme::clear()
{
    this->set(std::string(), MapNomsEchanges(), Budget(), nullptr);
}

void Plateforme::set(const std::string& nom, const MapNomsEchanges& mapEchanges,
        const Budget& budget, const CPtrClient client)
{
    this->setNom(nom);
    this->setMapEchanges(mapEchanges);
    this->setBudget(budget);
    this->setClient(client);
}

void Plateforme::copy(const Plateforme& plateforme)
{
    this->set(plateforme.getNom(), plateforme.getMapEchanges(), plateforme.getBudget(),
            plateforme.getClient());
}

bool Plateforme::equals(const Plateforme& plateforme) const
{
    if (this->getNom() != plateforme.getNom())
        return false;
    if (this->getMapEchanges() != plateforme.getMapEchanges())
        return false;
    if (this->getBudget() != plateforme.getBudget())
        return false;
    if (this->getClient() != plateforme.getClient())
        return false;
    return true;
}

void Plateforme::fromString(const std::string& fromString, const char& sep)
{
    // TODO void Plateforme::fromString(const std::string& fromString, const char& sep)
    // #warning "'void Plateforme::fromString(const std::string& fromString, const char& sep)' not implemented"
}

const std::string Plateforme::toString(const char& sep) const
{
    // TODO const std::string Plateforme::toString(const char& sep) const
    // #warning "'const std::string Plateforme::toString(const char& sep) const' not implemented"
    return std::string();
}

bool Plateforme::hasEchange(const std::string& nom) const
{
    return (this->m_mapEchanges.find(nom) != this->m_mapEchanges.end());
}

CPtrEchange Plateforme::getEchange(const std::string& nom) const
{
    return (this->hasEchange(nom) ? &this->m_mapEchanges.find(nom)->second : nullptr);
}

bool Plateforme::ajouterEchange(const std::string& nom, const Echange& echange)
{
    return (this->m_mapEchanges.insert(std::pair<std::string, Echange>(nom, echange)).second);
}

bool Plateforme::supprimerEchange(const std::string& nom)
{
    return (this->m_mapEchanges.erase(nom) > 0);
}
