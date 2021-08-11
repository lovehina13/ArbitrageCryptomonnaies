//==============================================================================
// Name        : Devise.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Devise class
//==============================================================================

#include "Devise.h"

Devise::Devise(const std::string& nom) :
        _nom(nom)
{
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
    *this = Devise();
}

void Devise::set(const std::string& nom)
{
    setNom(nom);
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
