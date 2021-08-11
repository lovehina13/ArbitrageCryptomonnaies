//==============================================================================
// Name        : Monnaie.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Monnaie class
//==============================================================================

#include "Monnaie.h"

Monnaie::Monnaie() :
        _devise(Devise()), _quantite(0.0)
{
    clear();
}

Monnaie::Monnaie(const Devise& devise, const double& quantite) :
        Monnaie()
{
    set(devise, quantite);
}

Monnaie::Monnaie(const Monnaie& monnaie) :
        Monnaie()
{
    copy(monnaie);
}

Monnaie::~Monnaie()
{

}

Monnaie& Monnaie::operator=(const Monnaie& monnaie)
{
    copy(monnaie);
    return *this;
}

bool Monnaie::operator==(const Monnaie& monnaie) const
{
    return equals(monnaie);
}

bool Monnaie::operator!=(const Monnaie& monnaie) const
{
    return !equals(monnaie);
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
    set(Devise(), 0.0);
}

void Monnaie::set(const Devise& devise, const double& quantite)
{
    setDevise(devise);
    setQuantite(quantite);
}

void Monnaie::copy(const Monnaie& monnaie)
{
    set(monnaie.getDevise(), monnaie.getQuantite());
}

bool Monnaie::equals(const Monnaie& monnaie) const
{
    if (getDevise() != monnaie.getDevise())
        return false;
    if (getQuantite() != monnaie.getQuantite())
        return false;
    return true;
}

void Monnaie::fromString(const std::string& fromString, const char& sep)
{
    // TODO void Monnaie::fromString(const std::string& fromString, const char& sep)
    // #warning "'void Monnaie::fromString(const std::string& fromString, const char& sep)' not implemented"
}

const std::string Monnaie::toString(const char& sep) const
{
    // TODO const std::string Monnaie::toString(const char& sep) const
    // #warning "'const std::string Monnaie::toString(const char& sep) const' not implemented"
    return std::string();
}
