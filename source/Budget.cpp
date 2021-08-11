//==============================================================================
// Name        : Budget.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Budget class
//==============================================================================

#include "Budget.h"
#include <utility>

Budget::Budget() :
        _mapMonnaies(MapNomsMonnaies())
{
    clear();
}

Budget::Budget(const MapNomsMonnaies& mapMonnaies) :
        Budget()
{
    set(mapMonnaies);
}

Budget::Budget(const Budget& budget) :
        Budget()
{
    copy(budget);
}

Budget::~Budget()
{

}

Budget& Budget::operator=(const Budget& budget)
{
    copy(budget);
    return *this;
}

bool Budget::operator==(const Budget& budget) const
{
    return equals(budget);
}

bool Budget::operator!=(const Budget& budget) const
{
    return !equals(budget);
}

const MapNomsMonnaies& Budget::getMapMonnaies() const
{
    return _mapMonnaies;
}

void Budget::setMapMonnaies(const MapNomsMonnaies& mapMonnaies)
{
    _mapMonnaies = mapMonnaies;
}

void Budget::clear()
{
    set(MapNomsMonnaies());
}

void Budget::set(const MapNomsMonnaies& mapMonnaies)
{
    setMapMonnaies(mapMonnaies);
}

void Budget::copy(const Budget& budget)
{
    set(budget.getMapMonnaies());
}

bool Budget::equals(const Budget& budget) const
{
    if (getMapMonnaies() != budget.getMapMonnaies())
        return false;
    return true;
}

void Budget::fromString(const std::string& /*fromString*/, const char& /*sep*/)
{
    // TODO void Budget::fromString(const std::string& fromString, const char& sep)
    // #warning "'void Budget::fromString(const std::string& fromString, const char& sep)' not implemented"
}

const std::string Budget::toString(const char& /*sep*/) const
{
    // TODO const std::string Budget::toString(const char& sep) const
    // #warning "'const std::string Budget::toString(const char& sep) const' not implemented"
    return std::string();
}

bool Budget::hasMonnaie(const std::string& nom) const
{
    return (_mapMonnaies.find(nom) != _mapMonnaies.end());
}

CPtrMonnaie Budget::getMonnaie(const std::string& nom) const
{
    return (hasMonnaie(nom) ? &_mapMonnaies.find(nom)->second : nullptr);
}

bool Budget::ajouterMonnaie(const std::string& nom, const Monnaie& monnaie)
{
    return (_mapMonnaies.insert(std::pair<std::string, Monnaie>(nom, monnaie)).second);
}

bool Budget::supprimerMonnaie(const std::string& nom)
{
    return (_mapMonnaies.erase(nom) > 0);
}
