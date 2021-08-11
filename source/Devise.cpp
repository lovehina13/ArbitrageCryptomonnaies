//==============================================================================
// Name        : Devise.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Devise class
//==============================================================================

#include "Devise.h"

Devise::Devise() :
        _nom(std::string())
{
    clear();
}

Devise::Devise(const std::string& nom) :
        Devise()
{
    set(nom);
}

Devise::Devise(const Devise& devise) :
        Devise()
{
    copy(devise);
}

Devise::~Devise()
{

}

Devise& Devise::operator=(const Devise& devise)
{
    copy(devise);
    return *this;
}

bool Devise::operator==(const Devise& devise) const
{
    return equals(devise);
}

bool Devise::operator!=(const Devise& devise) const
{
    return !equals(devise);
}

const std::string& Devise::getNom() const
{
    return _nom;
}

void Devise::setNom(const std::string& nom)
{
    _nom = nom;
}

void Devise::clear()
{
    set(std::string());
}

void Devise::set(const std::string& nom)
{
    setNom(nom);
}

void Devise::copy(const Devise& devise)
{
    set(devise.getNom());
}

bool Devise::equals(const Devise& devise) const
{
    if (getNom() != devise.getNom())
        return false;
    return true;
}

void Devise::fromString(const std::string& /*fromString*/, const char& /*sep*/)
{
    // TODO void Devise::fromString(const std::string& fromString, const char& sep)
    // #warning "'void Devise::fromString(const std::string& fromString, const char& sep)' not implemented"
}

const std::string Devise::toString(const char& /*sep*/) const
{
    // TODO const std::string Devise::toString(const char& sep) const
    // #warning "'const std::string Devise::toString(const char& sep) const' not implemented"
    return std::string();
}
