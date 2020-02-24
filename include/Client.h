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
    Client();
    Client(const std::string& adresseSite, const std::string& adresseCarnetDeCommandes,
            const MapNomsCours& coursActuels);
    Client(const Client& client);
    virtual ~Client();

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
    void copy(const Client& client);
    bool equals(const Client& client) const;
    void fromString(const std::string& fromString, const char& sep);
    const std::string toString(const char& sep) const;

    // Méthodes spécifiques (opérateurs)
    Client& operator=(const Client& client);
    bool operator==(const Client& client) const;
    bool operator!=(const Client& client) const;

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
    std::string m_adresseSite;
    std::string m_adresseCarnetDeCommandes;
    MapNomsCours m_coursActuels;
};

typedef Client* PtrClient;
typedef std::vector<Client> ListeClients;
typedef std::vector<PtrClient> ListePtrClients;
typedef std::map<int, Client> MapIdClients;
typedef std::map<int, PtrClient> MapIdPtrClients;
typedef std::map<std::string, Client> MapNomsClients;
typedef std::map<std::string, PtrClient> MapNomsPtrClients;

#endif // CLIENT_H
