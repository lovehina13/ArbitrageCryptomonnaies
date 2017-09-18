//==============================================================================
// Name        : Echange.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Echange class
//==============================================================================

#include "Echange.h"

Echange::Echange() :
        m_fraisFixesAchat(0.0), m_fraisFixesVente(0.0), m_fraisVariablesAchat(0.0),
                m_fraisVariablesVente(0.0)
{
    this->clear();
}

Echange::Echange(const Devise& deviseNumerique, const Devise& deviseReelle,
        const double& fraisFixesAchat, const double& fraisFixesVente,
        const double& fraisVariablesAchat, const double& fraisVariablesVente,
        const MapIdCours& mapCours) :
        Echange()
{
    this->set(deviseNumerique, deviseReelle, fraisFixesAchat, fraisFixesVente, fraisVariablesAchat,
            fraisVariablesVente, mapCours);
}

Echange::Echange(const Echange& echange) :
        Echange()
{
    this->copy(echange);
}

Echange::~Echange()
{

}

const Devise& Echange::getDeviseNumerique() const
{
    return this->m_deviseNumerique;
}

const Devise& Echange::getDeviseReelle() const
{
    return this->m_deviseReelle;
}

const double& Echange::getFraisFixesAchat() const
{
    return this->m_fraisFixesAchat;
}

const double& Echange::getFraisFixesVente() const
{
    return this->m_fraisFixesVente;
}

const double& Echange::getFraisVariablesAchat() const
{
    return this->m_fraisVariablesAchat;
}

const double& Echange::getFraisVariablesVente() const
{
    return this->m_fraisVariablesVente;
}

const MapIdCours& Echange::getMapCours() const
{
    return this->m_mapCours;
}

void Echange::setDeviseNumerique(const Devise& deviseNumerique)
{
    this->m_deviseNumerique = deviseNumerique;
}

void Echange::setDeviseReelle(const Devise& deviseReelle)
{
    this->m_deviseReelle = deviseReelle;
}

void Echange::setFraisFixesAchat(const double& fraisFixesAchat)
{
    this->m_fraisFixesAchat = fraisFixesAchat;
}

void Echange::setFraisFixesVente(const double& fraisFixesVente)
{
    this->m_fraisFixesVente = fraisFixesVente;
}

void Echange::setFraisVariablesAchat(const double& fraisVariablesAchat)
{
    this->m_fraisVariablesAchat = fraisVariablesAchat;
}

void Echange::setFraisVariablesVente(const double& fraisVariablesVente)
{
    this->m_fraisVariablesVente = fraisVariablesVente;
}

void Echange::setMapCours(const MapIdCours& mapCours)
{
    this->m_mapCours = mapCours;
}

void Echange::clear()
{
    this->set(Devise(), Devise(), 0.0, 0.0, 0.0, 0.0, MapIdCours());
}

void Echange::set(const Devise& deviseNumerique, const Devise& deviseReelle,
        const double& fraisFixesAchat, const double& fraisFixesVente,
        const double& fraisVariablesAchat, const double& fraisVariablesVente,
        const MapIdCours& mapCours)
{
    this->setDeviseNumerique(deviseNumerique);
    this->setDeviseReelle(deviseReelle);
    this->setFraisFixesAchat(fraisFixesAchat);
    this->setFraisFixesVente(fraisFixesVente);
    this->setFraisVariablesAchat(fraisVariablesAchat);
    this->setFraisVariablesVente(fraisVariablesVente);
    this->setMapCours(mapCours);
}

void Echange::copy(const Echange& echange)
{
    this->set(echange.getDeviseNumerique(), echange.getDeviseReelle(), echange.getFraisFixesAchat(),
            echange.getFraisFixesVente(), echange.getFraisVariablesAchat(),
            echange.getFraisVariablesVente(), echange.getMapCours());
}

bool Echange::equals(const Echange& echange) const
{
    if (this->getDeviseNumerique() != echange.getDeviseNumerique())
        return false;
    if (this->getDeviseReelle() != echange.getDeviseReelle())
        return false;
    if (this->getFraisFixesAchat() != echange.getFraisFixesAchat())
        return false;
    if (this->getFraisFixesVente() != echange.getFraisFixesVente())
        return false;
    if (this->getFraisVariablesAchat() != echange.getFraisVariablesAchat())
        return false;
    if (this->getFraisVariablesVente() != echange.getFraisVariablesVente())
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
