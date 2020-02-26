//==============================================================================
// Name        : Client.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Client class
//==============================================================================

#include "Client.h"

Client::Client() :
        m_adresseSite(std::string()), m_adresseCarnetDeCommandes(std::string()),
                m_coursActuels(MapNomsCours())
{
    this->clear();
}

Client::Client(const std::string& adresseSite, const std::string& adresseCarnetDeCommandes,
        const MapNomsCours& coursActuels) :
        Client()
{
    this->set(adresseSite, adresseCarnetDeCommandes, coursActuels);
}

Client::Client(const Client& client) :
        Client()
{
    this->copy(client);
}

Client::~Client()
{

}

Client& Client::operator=(const Client& client)
{
    this->copy(client);
    return *this;
}

bool Client::operator==(const Client& client) const
{
    return this->equals(client);
}

bool Client::operator!=(const Client& client) const
{
    return !this->equals(client);
}

const std::string& Client::getAdresseSite() const
{
    return this->m_adresseSite;
}

const std::string& Client::getAdresseCarnetDeCommandes() const
{
    return this->m_adresseCarnetDeCommandes;
}

const MapNomsCours& Client::getCoursActuels() const
{
    return this->m_coursActuels;
}

void Client::setAdresseSite(const std::string& adresseSite)
{
    this->m_adresseSite = adresseSite;
}

void Client::setAdresseCarnetDeCommandes(const std::string& adresseCarnetDeCommandes)
{
    this->m_adresseCarnetDeCommandes = adresseCarnetDeCommandes;
}

void Client::setCoursActuels(const MapNomsCours& coursActuels)
{
    this->m_coursActuels = coursActuels;
}

void Client::clear()
{
    this->set(std::string(), std::string(), MapNomsCours());
}

void Client::set(const std::string& adresseSite, const std::string& adresseCarnetDeCommandes,
        const MapNomsCours& coursActuels)
{
    this->setAdresseSite(adresseSite);
    this->setAdresseCarnetDeCommandes(adresseCarnetDeCommandes);
    this->setCoursActuels(coursActuels);
}

void Client::copy(const Client& client)
{
    this->set(client.getAdresseSite(), client.getAdresseCarnetDeCommandes(),
            client.getCoursActuels());
}

bool Client::equals(const Client& client) const
{
    if (this->getAdresseSite() != client.getAdresseSite())
        return false;
    if (this->getAdresseCarnetDeCommandes() != client.getAdresseCarnetDeCommandes())
        return false;
    if (this->getCoursActuels() != client.getCoursActuels())
        return false;
    return true;
}

void Client::fromString(const std::string& fromString, const char& sep)
{
    // TODO void Client::fromString(const std::string& fromString, const char& sep)
    // #warning "'void Client::fromString(const std::string& fromString, const char& sep)' not implemented"
}

const std::string Client::toString(const char& sep) const
{
    // TODO const std::string Client::toString(const char& sep) const
    // #warning "'const std::string Client::toString(const char& sep) const' not implemented"
    return std::string();
}

void Client::recupererCoursActuel(const std::string& nomDeviseNumerique,
        const std::string& nomDeviseReelle) const
{
    // TODO void Client::recupererCoursActuel(const std::string& nomDeviseNumerique, const std::string& nomDeviseReelle) const
}

double Client::getValeurAchat(const std::string& nomDeviseNumerique,
        const std::string& nomDeviseReelle) const
{
    // TODO double Client::getValeurAchat(const std::string& nomDeviseNumerique, const std::string& nomDeviseReelle) const
    return 0.0;
}

double Client::getValeurVente(const std::string& nomDeviseNumerique,
        const std::string& nomDeviseReelle) const
{
    // TODO double Client::getValeurVente(const std::string& nomDeviseNumerique, const std::string& nomDeviseReelle) const
    return 0.0;
}

double Client::getQuantiteAchat(const std::string& nomDeviseNumerique,
        const std::string& nomDeviseReelle) const
{
    // TODO double Client::getQuantiteAchat(const std::string& nomDeviseNumerique, const std::string& nomDeviseReelle) const
    return 0.0;
}

double Client::getQuantiteVente(const std::string& nomDeviseNumerique,
        const std::string& nomDeviseReelle) const
{
    // TODO double Client::getQuantiteVente(const std::string& nomDeviseNumerique, const std::string& nomDeviseReelle) const
    return 0.0;
}
