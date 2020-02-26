//==============================================================================
// Name        : Devise.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Devise class
//==============================================================================

#include "Devise.h"

Devise::Devise() :
        m_nom(std::string())
{
    this->clear();
}

Devise::Devise(const std::string& nom) :
        Devise()
{
    this->set(nom);
}

Devise::Devise(const Devise& devise) :
        Devise()
{
    this->copy(devise);
}

Devise::~Devise()
{

}

Devise& Devise::operator=(const Devise& devise)
{
    this->copy(devise);
    return *this;
}

bool Devise::operator==(const Devise& devise) const
{
    return this->equals(devise);
}

bool Devise::operator!=(const Devise& devise) const
{
    return !this->equals(devise);
}

const std::string& Devise::getNom() const
{
    return this->m_nom;
}

void Devise::setNom(const std::string& nom)
{
    this->m_nom = nom;
}

void Devise::clear()
{
    this->set(std::string());
}

void Devise::set(const std::string& nom)
{
    this->setNom(nom);
}

void Devise::copy(const Devise& devise)
{
    this->set(devise.getNom());
}

bool Devise::equals(const Devise& devise) const
{
    if (this->getNom() != devise.getNom())
        return false;
    return true;
}

void Devise::fromString(const std::string& fromString, const char& sep)
{
    // TODO void Devise::fromString(const std::string& fromString, const char& sep)
    // #warning "'void Devise::fromString(const std::string& fromString, const char& sep)' not implemented"
}

const std::string Devise::toString(const char& sep) const
{
    // TODO const std::string Devise::toString(const char& sep) const
    // #warning "'const std::string Devise::toString(const char& sep) const' not implemented"
    return std::string();
}
