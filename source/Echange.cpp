//==============================================================================
// Name        : Echange.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Echange class
//==============================================================================

#include "Echange.h"

Echange::Echange()
{
    this->clear();
}

Echange::Echange(const Devise& deviseSource, const Devise& deviseDestination,
        const MapIdCours& mapCours) :
        Echange()
{
    this->set(deviseSource, deviseDestination, mapCours);
}

Echange::Echange(const Echange& echange) :
        Echange()
{
    this->copy(echange);
}

Echange::~Echange()
{

}

const Devise& Echange::getDeviseSource() const
{
    return this->deviseSource;
}

const Devise& Echange::getDeviseDestination() const
{
    return this->deviseDestination;
}

const MapIdCours& Echange::getMapCours() const
{
    return this->mapCours;
}

void Echange::setDeviseSource(const Devise& deviseSource)
{
    this->deviseSource = deviseSource;
}

void Echange::setDeviseDestination(const Devise& deviseDestination)
{
    this->deviseDestination = deviseDestination;
}

void Echange::setMapCours(const MapIdCours& mapCours)
{
    this->mapCours = mapCours;
}

void Echange::clear()
{
    this->set(Devise(), Devise(), MapIdCours());
}

void Echange::set(const Devise& deviseSource, const Devise& deviseDestination,
        const MapIdCours& mapCours)
{
    this->setDeviseSource(deviseSource);
    this->setDeviseDestination(deviseDestination);
    this->setMapCours(mapCours);
}

void Echange::copy(const Echange& echange)
{
    this->set(echange.getDeviseSource(), echange.getDeviseDestination(), echange.getMapCours());
}

bool Echange::equals(const Echange& echange) const
{
    if (this->getDeviseSource() != echange.getDeviseSource())
        return false;
    if (this->getDeviseDestination() != echange.getDeviseDestination())
        return false;
    if (this->getMapCours() != echange.getMapCours())
        return false;
    return true;
}

void Echange::fromString(const std::string& fromString, const char& sep)
{
    // TODO void Echange::fromString(const std::string& fromString, const char& sep)
    // #warning "'void Echange::fromString(const std::string& fromString, const char& sep)' not implemented"
}

const std::string Echange::toString(const char& sep) const
{
    // TODO const std::string Echange::toString(const char& sep) const
    // #warning "'const std::string Echange::toString(const char& sep) const' not implemented"
    return std::string();
}

bool Echange::operator==(const Echange& echange) const
{
    return this->equals(echange);
}

bool Echange::operator!=(const Echange& echange) const
{
    return !(this->equals(echange));
}
