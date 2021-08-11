//==============================================================================
// Name        : Cours.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Cours class
//==============================================================================

#include "Cours.h"

Cours::Cours(const int& date, const double& valeurAchat, const double& valeurVente,
        const double& quantiteAchat, const double& quantiteVente) :
        _date(date), _valeurAchat(valeurAchat), _valeurVente(valeurVente),
                _quantiteAchat(quantiteAchat), _quantiteVente(quantiteVente)
{
}

const int& Cours::getDate() const
{
    return _date;
}

const double& Cours::getValeurAchat() const
{
    return _valeurAchat;
}

const double& Cours::getValeurVente() const
{
    return _valeurVente;
}

const double& Cours::getQuantiteAchat() const
{
    return _quantiteAchat;
}

const double& Cours::getQuantiteVente() const
{
    return _quantiteVente;
}

void Cours::setDate(const int& date)
{
    _date = date;
}

void Cours::setValeurAchat(const double& valeurAchat)
{
    _valeurAchat = valeurAchat;
}

void Cours::setValeurVente(const double& valeurVente)
{
    _valeurVente = valeurVente;
}

void Cours::setQuantiteAchat(const double& quantiteAchat)
{
    _quantiteAchat = quantiteAchat;
}

void Cours::setQuantiteVente(const double& quantiteVente)
{
    _quantiteVente = quantiteVente;
}

void Cours::clear()
{
    *this = Cours();
}

void Cours::set(const int& date, const double& valeurAchat, const double& valeurVente,
        const double& quantiteAchat, const double& quantiteVente)
{
    setDate(date);
    setValeurAchat(valeurAchat);
    setValeurVente(valeurVente);
    setQuantiteAchat(quantiteAchat);
    setQuantiteVente(quantiteVente);
}

void Cours::fromString(const std::string& /*fromString*/, const char& /*sep*/)
{
    // TODO void Cours::fromString(const std::string& fromString, const char& sep)
    // #warning "'void Cours::fromString(const std::string& fromString, const char& sep)' not implemented"
}

const std::string Cours::toString(const char& /*sep*/) const
{
    // TODO const std::string Cours::toString(const char& sep) const
    // #warning "'const std::string Cours::toString(const char& sep) const' not implemented"
    return std::string();
}
