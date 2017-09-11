//==============================================================================
// Name        : Plateforme.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Plateforme class
//==============================================================================

#include "Plateforme.h"

Plateforme::Plateforme()
{
    this->clear();
}

Plateforme::Plateforme(const std::string& nom, const MapNomsEchanges& mapEchanges,
        const Budget& budget) :
        Plateforme()
{
    this->set(nom, mapEchanges, budget);
}

Plateforme::Plateforme(const Plateforme& plateforme) :
        Plateforme()
{
    this->copy(plateforme);
}

Plateforme::~Plateforme()
{

}

const std::string& Plateforme::getNom() const
{
    return this->nom;
}

const MapNomsEchanges& Plateforme::getMapEchanges() const
{
    return this->mapEchanges;
}

const Budget& Plateforme::getBudget() const
{
    return this->budget;
}

void Plateforme::setNom(const std::string& nom)
{
    this->nom = nom;
}

void Plateforme::setMapEchanges(const MapNomsEchanges& mapEchanges)
{
    this->mapEchanges = mapEchanges;
}

void Plateforme::setBudget(const Budget& budget)
{
    this->budget = budget;
}

void Plateforme::clear()
{
    this->set(std::string(), MapNomsEchanges(), Budget());
}

void Plateforme::set(const std::string& nom, const MapNomsEchanges& mapEchanges,
        const Budget& budget)
{
    this->setNom(nom);
    this->setMapEchanges(mapEchanges);
    this->setBudget(budget);
}

void Plateforme::copy(const Plateforme& plateforme)
{
    this->set(plateforme.getNom(), plateforme.getMapEchanges(), plateforme.getBudget());
}

bool Plateforme::equals(const Plateforme& plateforme) const
{
    if (this->getNom() != plateforme.getNom())
        return false;
    if (this->getMapEchanges() != plateforme.getMapEchanges())
        return false;
    if (this->getBudget() != plateforme.getBudget())
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

bool Plateforme::operator==(const Plateforme& plateforme) const
{
    return this->equals(plateforme);
}

bool Plateforme::operator!=(const Plateforme& plateforme) const
{
    return !(this->equals(plateforme));
}
