//==============================================================================
// Name        : Monnaie.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Monnaie class
//==============================================================================

#include "Monnaie.h"

Monnaie::Monnaie(const Devise& devise, const double& quantite) :
        _devise(devise), _quantite(quantite)
{
}

const Devise& Monnaie::getDevise() const
{
    return _devise;
}

const double& Monnaie::getQuantite() const
{
    return _quantite;
}

void Monnaie::setDevise(const Devise& devise)
{
    _devise = devise;
}

void Monnaie::setQuantite(const double& quantite)
{
    _quantite = quantite;
}

void Monnaie::clear()
{
    *this = Monnaie();
}

void Monnaie::set(const Devise& devise, const double& quantite)
{
    setDevise(devise);
    setQuantite(quantite);
}

void Monnaie::fromString(const std::string& /*fromString*/, const char& /*sep*/)
{
    // TODO void Monnaie::fromString(const std::string& fromString, const char& sep)
    // #warning "'void Monnaie::fromString(const std::string& fromString, const char& sep)' not implemented"
}

const std::string Monnaie::toString(const char& /*sep*/) const
{
    // TODO const std::string Monnaie::toString(const char& sep) const
    // #warning "'const std::string Monnaie::toString(const char& sep) const' not implemented"
    return std::string();
}
