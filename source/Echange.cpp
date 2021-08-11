//==============================================================================
// Name        : Echange.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Echange class
//==============================================================================

#include "Echange.h"
#include <utility>

Echange::Echange(const Devise& deviseNumerique, const Devise& deviseReelle,
        const double& fraisFixesAchat, const double& fraisFixesVente,
        const double& fraisVariablesAchat, const double& fraisVariablesVente,
        const MapIdCours& mapCours) :
        _deviseNumerique(deviseNumerique), _deviseReelle(deviseReelle),
                _fraisFixesAchat(fraisFixesAchat), _fraisFixesVente(fraisFixesVente),
                _fraisVariablesAchat(fraisVariablesAchat),
                _fraisVariablesVente(fraisVariablesVente), _mapCours(mapCours)
{
}

const Devise& Echange::getDeviseNumerique() const
{
    return _deviseNumerique;
}

const Devise& Echange::getDeviseReelle() const
{
    return _deviseReelle;
}

const double& Echange::getFraisFixesAchat() const
{
    return _fraisFixesAchat;
}

const double& Echange::getFraisFixesVente() const
{
    return _fraisFixesVente;
}

const double& Echange::getFraisVariablesAchat() const
{
    return _fraisVariablesAchat;
}

const double& Echange::getFraisVariablesVente() const
{
    return _fraisVariablesVente;
}

const MapIdCours& Echange::getMapCours() const
{
    return _mapCours;
}

void Echange::setDeviseNumerique(const Devise& deviseNumerique)
{
    _deviseNumerique = deviseNumerique;
}

void Echange::setDeviseReelle(const Devise& deviseReelle)
{
    _deviseReelle = deviseReelle;
}

void Echange::setFraisFixesAchat(const double& fraisFixesAchat)
{
    _fraisFixesAchat = fraisFixesAchat;
}

void Echange::setFraisFixesVente(const double& fraisFixesVente)
{
    _fraisFixesVente = fraisFixesVente;
}

void Echange::setFraisVariablesAchat(const double& fraisVariablesAchat)
{
    _fraisVariablesAchat = fraisVariablesAchat;
}

void Echange::setFraisVariablesVente(const double& fraisVariablesVente)
{
    _fraisVariablesVente = fraisVariablesVente;
}

void Echange::setMapCours(const MapIdCours& mapCours)
{
    _mapCours = mapCours;
}

void Echange::clear()
{
    *this = Echange();
}

void Echange::set(const Devise& deviseNumerique, const Devise& deviseReelle,
        const double& fraisFixesAchat, const double& fraisFixesVente,
        const double& fraisVariablesAchat, const double& fraisVariablesVente,
        const MapIdCours& mapCours)
{
    setDeviseNumerique(deviseNumerique);
    setDeviseReelle(deviseReelle);
    setFraisFixesAchat(fraisFixesAchat);
    setFraisFixesVente(fraisFixesVente);
    setFraisVariablesAchat(fraisVariablesAchat);
    setFraisVariablesVente(fraisVariablesVente);
    setMapCours(mapCours);
}

void Echange::fromString(const std::string& /*fromString*/, const char& /*sep*/)
{
    // TODO void Echange::fromString(const std::string& fromString, const char& sep)
    // #warning "'void Echange::fromString(const std::string& fromString, const char& sep)' not implemented"
}

const std::string Echange::toString(const char& /*sep*/) const
{
    // TODO const std::string Echange::toString(const char& sep) const
    // #warning "'const std::string Echange::toString(const char& sep) const' not implemented"
    return std::string();
}

bool Echange::hasCours(const int& date) const
{
    return (_mapCours.find(date) != _mapCours.end());
}

CPtrCours Echange::getCours(const int& date) const
{
    return (hasCours(date) ? &_mapCours.find(date)->second : nullptr);
}

bool Echange::ajouterCours(const int& date, const Cours& cours)
{
    return (_mapCours.insert(std::pair<int, Cours>(date, cours)).second);
}

bool Echange::supprimerCours(const int& date)
{
    return (_mapCours.erase(date) > 0);
}
