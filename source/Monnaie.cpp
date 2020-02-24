//==============================================================================
// Name        : Monnaie.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Monnaie class
//==============================================================================

#include "Monnaie.h"

Monnaie::Monnaie() :
        m_quantite(0.0)
{
    this->clear();
}

Monnaie::Monnaie(const Devise& devise, const double& quantite) :
        Monnaie()
{
    this->set(devise, quantite);
}

Monnaie::Monnaie(const Monnaie& monnaie) :
        Monnaie()
{
    this->copy(monnaie);
}

Monnaie::~Monnaie()
{

}

const Devise& Monnaie::getDevise() const
{
    return this->m_devise;
}

const double& Monnaie::getQuantite() const
{
    return this->m_quantite;
}

void Monnaie::setDevise(const Devise& devise)
{
    this->m_devise = devise;
}

void Monnaie::setQuantite(const double& quantite)
{
    this->m_quantite = quantite;
}

void Monnaie::clear()
{
    this->set(Devise(), 0.0);
}

void Monnaie::set(const Devise& devise, const double& quantite)
{
    this->setDevise(devise);
    this->setQuantite(quantite);
}

void Monnaie::copy(const Monnaie& monnaie)
{
    this->set(monnaie.getDevise(), monnaie.getQuantite());
}

bool Monnaie::equals(const Monnaie& monnaie) const
{
    if (this->getDevise() != monnaie.getDevise())
        return false;
    if (this->getQuantite() != monnaie.getQuantite())
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

Monnaie& Monnaie::operator=(const Monnaie& monnaie)
{
    this->copy(monnaie);
    return *this;
}

bool Monnaie::operator==(const Monnaie& monnaie) const
{
    return this->equals(monnaie);
}

bool Monnaie::operator!=(const Monnaie& monnaie) const
{
    return !(this->equals(monnaie));
}
