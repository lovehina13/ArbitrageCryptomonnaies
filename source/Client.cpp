//==============================================================================
// Name        : Client.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Client class
//==============================================================================

#include "Client.h"

Client::Client() :
        _adresseSite(std::string()), _adresseCarnetDeCommandes(std::string()),
                _coursActuels(MapNomsCours())
{
    clear();
}

Client::Client(const std::string& adresseSite, const std::string& adresseCarnetDeCommandes,
        const MapNomsCours& coursActuels) :
        Client()
{
    set(adresseSite, adresseCarnetDeCommandes, coursActuels);
}

Client::Client(const Client& client) :
        Client()
{
    copy(client);
}

Client::~Client()
{

}

Client& Client::operator=(const Client& client)
{
    copy(client);
    return *this;
}

bool Client::operator==(const Client& client) const
{
    return equals(client);
}

bool Client::operator!=(const Client& client) const
{
    return !equals(client);
}

const std::string& Client::getAdresseSite() const
{
    return _adresseSite;
}

const std::string& Client::getAdresseCarnetDeCommandes() const
{
    return _adresseCarnetDeCommandes;
}

const MapNomsCours& Client::getCoursActuels() const
{
    return _coursActuels;
}

void Client::setAdresseSite(const std::string& adresseSite)
{
    _adresseSite = adresseSite;
}

void Client::setAdresseCarnetDeCommandes(const std::string& adresseCarnetDeCommandes)
{
    _adresseCarnetDeCommandes = adresseCarnetDeCommandes;
}

void Client::setCoursActuels(const MapNomsCours& coursActuels)
{
    _coursActuels = coursActuels;
}

void Client::clear()
{
    set(std::string(), std::string(), MapNomsCours());
}

void Client::set(const std::string& adresseSite, const std::string& adresseCarnetDeCommandes,
        const MapNomsCours& coursActuels)
{
    setAdresseSite(adresseSite);
    setAdresseCarnetDeCommandes(adresseCarnetDeCommandes);
    setCoursActuels(coursActuels);
}

void Client::copy(const Client& client)
{
    set(client.getAdresseSite(), client.getAdresseCarnetDeCommandes(), client.getCoursActuels());
}

bool Client::equals(const Client& client) const
{
    if (getAdresseSite() != client.getAdresseSite())
        return false;
    if (getAdresseCarnetDeCommandes() != client.getAdresseCarnetDeCommandes())
        return false;
    if (getCoursActuels() != client.getCoursActuels())
        return false;
    return true;
}

void Client::fromString(const std::string& /*fromString*/, const char& /*sep*/)
{
    // TODO void Client::fromString(const std::string& fromString, const char& sep)
    // #warning "'void Client::fromString(const std::string& fromString, const char& sep)' not implemented"
}

const std::string Client::toString(const char& /*sep*/) const
{
    // TODO const std::string Client::toString(const char& sep) const
    // #warning "'const std::string Client::toString(const char& sep) const' not implemented"
    return std::string();
}

void Client::recupererCoursActuel(const std::string& /*nomDeviseNumerique*/,
        const std::string& /*nomDeviseReelle*/) const
{
    // TODO void Client::recupererCoursActuel(const std::string& nomDeviseNumerique, const std::string& nomDeviseReelle) const
}

double Client::getValeurAchat(const std::string& /*nomDeviseNumerique*/,
        const std::string& /*nomDeviseReelle*/) const
{
    // TODO double Client::getValeurAchat(const std::string& nomDeviseNumerique, const std::string& nomDeviseReelle) const
    return 0.0;
}

double Client::getValeurVente(const std::string& /*nomDeviseNumerique*/,
        const std::string& /*nomDeviseReelle*/) const
{
    // TODO double Client::getValeurVente(const std::string& nomDeviseNumerique, const std::string& nomDeviseReelle) const
    return 0.0;
}

double Client::getQuantiteAchat(const std::string& /*nomDeviseNumerique*/,
        const std::string& /*nomDeviseReelle*/) const
{
    // TODO double Client::getQuantiteAchat(const std::string& nomDeviseNumerique, const std::string& nomDeviseReelle) const
    return 0.0;
}

double Client::getQuantiteVente(const std::string& /*nomDeviseNumerique*/,
        const std::string& /*nomDeviseReelle*/) const
{
    // TODO double Client::getQuantiteVente(const std::string& nomDeviseNumerique, const std::string& nomDeviseReelle) const
    return 0.0;
}
