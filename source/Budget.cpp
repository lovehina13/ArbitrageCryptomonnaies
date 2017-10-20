//==============================================================================
// Name        : Budget.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Budget class
//==============================================================================

#include "Budget.h"

Budget::Budget()
{
    this->clear();
}

Budget::Budget(const MapNomsMonnaies& mapMonnaies) :
        Budget()
{
    this->set(mapMonnaies);
}

Budget::Budget(const Budget& budget) :
        Budget()
{
    this->copy(budget);
}

Budget::~Budget()
{

}

const MapNomsMonnaies& Budget::getMapMonnaies() const
{
    return this->m_mapMonnaies;
}

void Budget::setMapMonnaies(const MapNomsMonnaies& mapMonnaies)
{
    this->m_mapMonnaies = mapMonnaies;
}

void Budget::clear()
{
    this->set(MapNomsMonnaies());
}

void Budget::set(const MapNomsMonnaies& mapMonnaies)
{
    this->setMapMonnaies(mapMonnaies);
}

void Budget::copy(const Budget& budget)
{
    this->set(budget.getMapMonnaies());
}

bool Budget::equals(const Budget& budget) const
{
    if (this->getMapMonnaies() != budget.getMapMonnaies())
        return false;
    return true;
}

void Budget::fromString(const std::string& fromString, const char& sep)
{
    // TODO void Budget::fromString(const std::string& fromString, const char& sep)
    // #warning "'void Budget::fromString(const std::string& fromString, const char& sep)' not implemented"
}

const std::string Budget::toString(const char& sep) const
{
    // TODO const std::string Budget::toString(const char& sep) const
    // #warning "'const std::string Budget::toString(const char& sep) const' not implemented"
    return std::string();
}

bool Budget::operator==(const Budget& budget) const
{
    return this->equals(budget);
}

bool Budget::operator!=(const Budget& budget) const
{
    return !(this->equals(budget));
}

bool Budget::hasMonnaie(const std::string& nom) const
{
    return (this->m_mapMonnaies.find(nom) != this->m_mapMonnaies.end());
}

PtrMonnaie Budget::getMonnaie(const std::string& nom) const
{
    return (this->hasMonnaie(nom) ? (PtrMonnaie) &(this->m_mapMonnaies.find(nom)->second) : NULL);
}

bool Budget::ajouterMonnaie(const std::string& nom, const Monnaie& monnaie)
{
    return (this->m_mapMonnaies.insert(std::pair<std::string, Monnaie>(nom, monnaie)).second);
}

bool Budget::supprimerMonnaie(const std::string& nom)
{
    return (this->m_mapMonnaies.erase(nom) > 0);
}
