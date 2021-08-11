//==============================================================================
// Name        : Client.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Header file of the Client class
//==============================================================================

#ifndef CLIENT_H
#define CLIENT_H

#include "Cours.h"
#include <map>
#include <string>
#include <vector>

class Client
{
public:
    // Constructeurs et destructeurs
    Client() = default;
    Client(const std::string& adresseSite, const std::string& adresseCarnetDeCommandes,
            const MapNomsCours& coursActuels);
    virtual ~Client() = default;

    // Opérateurs
    bool operator==(const Client& client) const = default;
    bool operator!=(const Client& client) const = default;

    // Getters
    const std::string& getAdresseSite() const;
    const std::string& getAdresseCarnetDeCommandes() const;
    const MapNomsCours& getCoursActuels() const;

    // Setters
    void setAdresseSite(const std::string& adresseSite);
    void setAdresseCarnetDeCommandes(const std::string& adresseCarnetDeCommandes);
    void setCoursActuels(const MapNomsCours& coursActuels);

    // Méthodes génériques
    void clear();
    void set(const std::string& adresseSite, const std::string& adresseCarnetDeCommandes,
            const MapNomsCours& coursActuels);
    void fromString(const std::string& fromString, const char& sep);
    const std::string toString(const char& sep) const;

    // Méthodes spécifiques (traitements)
    virtual void recupererCoursActuel(const std::string& nomDeviseNumerique,
            const std::string& nomDeviseReelle) const;
    virtual double getValeurAchat(const std::string& nomDeviseNumerique,
            const std::string& nomDeviseReelle) const;
    virtual double getValeurVente(const std::string& nomDeviseNumerique,
            const std::string& nomDeviseReelle) const;
    virtual double getQuantiteAchat(const std::string& nomDeviseNumerique,
            const std::string& nomDeviseReelle) const;
    virtual double getQuantiteVente(const std::string& nomDeviseNumerique,
            const std::string& nomDeviseReelle) const;

private:
    // Membres de classe
    std::string _adresseSite;
    std::string _adresseCarnetDeCommandes;
    MapNomsCours _coursActuels;
};

using PtrClient = Client*;
using CPtrClient = const Client*;
using ListeClients = std::vector<Client>;
using ListePtrClients = std::vector<PtrClient>;
using ListeCPtrClients = std::vector<CPtrClient>;
using MapIdClients = std::map<int, Client>;
using MapIdPtrClients = std::map<int, PtrClient>;
using MapIdCPtrClients = std::map<int, CPtrClient>;
using MapNomsClients = std::map<std::string, Client>;
using MapNomsPtrClients = std::map<std::string, PtrClient>;
using MapNomsCPtrClients = std::map<std::string, CPtrClient>;

#endif // CLIENT_H
