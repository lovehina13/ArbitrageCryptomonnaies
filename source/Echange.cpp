//==============================================================================
// Name        : Echange.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Echange class
//==============================================================================

#include "Echange.h"

Echange::Echange() :
        m_fraisFixes(0.0), m_fraisVariables(0.0)
{
    this->clear();
}

Echange::Echange(const Devise& deviseSource, const Devise& deviseDestination,
        const double& fraisFixes, const double& fraisVariables, const MapIdCours& mapCours) :
        Echange()
{
    this->set(deviseSource, deviseDestination, fraisFixes, fraisVariables, mapCours);
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
    return this->m_deviseSource;
}

const Devise& Echange::getDeviseDestination() const
{
    return this->m_deviseDestination;
}

const double& Echange::getFraisFixes() const
{
    return this->m_fraisFixes;
}

const double& Echange::getFraisVariables() const
{
    return this->m_fraisVariables;
}

const MapIdCours& Echange::getMapCours() const
{
    return this->m_mapCours;
}

void Echange::setDeviseSource(const Devise& deviseSource)
{
    this->m_deviseSource = deviseSource;
}

void Echange::setDeviseDestination(const Devise& deviseDestination)
{
    this->m_deviseDestination = deviseDestination;
}

void Echange::setFraisFixes(const double& fraisFixes)
{
    this->m_fraisFixes = fraisFixes;
}

void Echange::setFraisVariables(const double& fraisVariables)
{
    this->m_fraisVariables = fraisVariables;
}

void Echange::setMapCours(const MapIdCours& mapCours)
{
    this->m_mapCours = mapCours;
}

void Echange::clear()
{
    this->set(Devise(), Devise(), 0.0, 0.0, MapIdCours());
}

void Echange::set(const Devise& deviseSource, const Devise& deviseDestination,
        const double& fraisFixes, const double& fraisVariables, const MapIdCours& mapCours)
{
    this->setDeviseSource(deviseSource);
    this->setDeviseDestination(deviseDestination);
    this->setFraisFixes(fraisFixes);
    this->setFraisVariables(fraisVariables);
    this->setMapCours(mapCours);
}

void Echange::copy(const Echange& echange)
{
    this->set(echange.getDeviseSource(), echange.getDeviseDestination(), echange.getFraisFixes(),
            echange.getFraisVariables(), echange.getMapCours());
}

bool Echange::equals(const Echange& echange) const
{
    if (this->getDeviseSource() != echange.getDeviseSource())
        return false;
    if (this->getDeviseDestination() != echange.getDeviseDestination())
        return false;
    if (this->getFraisFixes() != echange.getFraisFixes())
        return false;
    if (this->getFraisVariables() != echange.getFraisVariables())
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

bool Echange::hasCours(const int& date) const
{
    return (this->m_mapCours.find(date) != this->m_mapCours.end());
}

PtrCours Echange::getCours(const int& date) const
{
    return (this->hasCours(date) ? (PtrCours) &(this->m_mapCours.find(date)->second) : NULL);
}

bool Echange::ajouterCours(const int& date, const double& valeurAchat, const double& valeurVente,
        const double& quantiteAchat, const double& quantiteVente)
{
    if (this->hasCours(date))
        return false;
    this->m_mapCours.insert(
            std::pair<int, Cours>(date,
                    Cours(date, valeurAchat, valeurVente, quantiteAchat, quantiteVente)));
    return true;
}

bool Echange::supprimerCours(const int& date)
{
    if (!this->hasCours(date))
        return false;
    this->m_mapCours.erase(date);
    return true;
}
