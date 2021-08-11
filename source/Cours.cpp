//==============================================================================
// Name        : Cours.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Cours class
//==============================================================================

#include "Cours.h"

Cours::Cours() :
        _date(0), _valeurAchat(0.0), _valeurVente(0.0), _quantiteAchat(0.0), _quantiteVente(0.0)
{
    clear();
}

Cours::Cours(const int& date, const double& valeurAchat, const double& valeurVente,
        const double& quantiteAchat, const double& quantiteVente) :
        Cours()
{
    set(date, valeurAchat, valeurVente, quantiteAchat, quantiteVente);
}

Cours::Cours(const Cours& cours) :
        Cours()
{
    copy(cours);
}

Cours::~Cours()
{

}

Cours& Cours::operator=(const Cours& cours)
{
    copy(cours);
    return *this;
}

bool Cours::operator==(const Cours& cours) const
{
    return equals(cours);
}

bool Cours::operator!=(const Cours& cours) const
{
    return !equals(cours);
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
    set(0, 0.0, 0.0, 0.0, 0.0);
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

void Cours::copy(const Cours& cours)
{
    set(cours.getDate(), cours.getValeurAchat(), cours.getValeurVente(), cours.getQuantiteAchat(),
            cours.getQuantiteVente());
}

bool Cours::equals(const Cours& cours) const
{
    if (getDate() != cours.getDate())
        return false;
    if (getValeurAchat() != cours.getValeurAchat())
        return false;
    if (getValeurVente() != cours.getValeurVente())
        return false;
    if (getQuantiteAchat() != cours.getQuantiteAchat())
        return false;
    if (getQuantiteVente() != cours.getQuantiteVente())
        return false;
    return true;
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
