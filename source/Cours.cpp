//==============================================================================
// Name        : Cours.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Cours class
//==============================================================================

#include "Cours.h"

Cours::Cours() :
        date(0), valeurAchat(0.0), valeurVente(0.0), quantiteAchat(0.0), quantiteVente(0.0)
{
    this->clear();
}

Cours::Cours(const int& date, const double& valeurAchat, const double& valeurVente,
        const double& quantiteAchat, const double& quantiteVente) :
        Cours()
{
    this->set(date, valeurAchat, valeurVente, quantiteAchat, quantiteVente);
}

Cours::Cours(const Cours& cours) :
        Cours()
{
    this->copy(cours);
}

Cours::~Cours()
{

}

const int& Cours::getDate() const
{
    return this->date;
}

const double& Cours::getValeurAchat() const
{
    return this->valeurAchat;
}

const double& Cours::getValeurVente() const
{
    return this->valeurVente;
}

const double& Cours::getQuantiteAchat() const
{
    return this->quantiteAchat;
}

const double& Cours::getQuantiteVente() const
{
    return this->quantiteVente;
}

void Cours::setDate(const int& date)
{
    this->date = date;
}

void Cours::setValeurAchat(const double& valeurAchat)
{
    this->valeurAchat = valeurAchat;
}

void Cours::setValeurVente(const double& valeurVente)
{
    this->valeurVente = valeurVente;
}

void Cours::setQuantiteAchat(const double& quantiteAchat)
{
    this->quantiteAchat = quantiteAchat;
}

void Cours::setQuantiteVente(const double& quantiteVente)
{
    this->quantiteVente = quantiteVente;
}

void Cours::clear()
{
    this->set(0, 0.0, 0.0, 0.0, 0.0);
}

void Cours::set(const int& date, const double& valeurAchat, const double& valeurVente,
        const double& quantiteAchat, const double& quantiteVente)
{
    this->setDate(date);
    this->setValeurAchat(valeurAchat);
    this->setValeurVente(valeurVente);
    this->setQuantiteAchat(quantiteAchat);
    this->setQuantiteVente(quantiteVente);
}

void Cours::copy(const Cours& cours)
{
    this->set(cours.getDate(), cours.getValeurAchat(), cours.getValeurVente(),
            cours.getQuantiteAchat(), cours.getQuantiteVente());
}

bool Cours::equals(const Cours& cours) const
{
    if (this->getDate() != cours.getDate())
        return false;
    if (this->getValeurAchat() != cours.getValeurAchat())
        return false;
    if (this->getValeurVente() != cours.getValeurVente())
        return false;
    if (this->getQuantiteAchat() != cours.getQuantiteAchat())
        return false;
    if (this->getQuantiteVente() != cours.getQuantiteVente())
        return false;
    return true;
}

void Cours::fromString(const std::string& fromString, const char& sep)
{
    // TODO void Cours::fromString(const std::string& fromString, const char& sep)
    // #warning "'void Cours::fromString(const std::string& fromString, const char& sep)' not implemented"
}

const std::string Cours::toString(const char& sep) const
{
    // TODO const std::string Cours::toString(const char& sep) const
    // #warning "'const std::string Cours::toString(const char& sep) const' not implemented"
    return std::string();
}

bool Cours::operator==(const Cours& cours) const
{
    return this->equals(cours);
}

bool Cours::operator!=(const Cours& cours) const
{
    return !(this->equals(cours));
}
