//==============================================================================
// Name        : Client.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Header file of the Client class
//==============================================================================

#ifndef CLIENT_H
#define CLIENT_H

#include <map>
#include <string>
#include <vector>

class Client
{
public:
    // Constructeurs et destructeurs
    Client();
    // Client();
    Client(const Client& client);
    virtual ~Client();

    // Getters

    // Setters

    // Méthodes génériques
    void clear();
    void set();
    void copy(const Client& client);
    bool equals(const Client& client) const;
    void fromString(const std::string& fromString, const char& sep);
    const std::string toString(const char& sep) const;

    // Méthodes spécifiques (opérateurs)
    bool operator==(const Client& client) const;
    bool operator!=(const Client& client) const;

private:
    // Membres de classe
};

typedef Client* PtrClient;
typedef std::vector<Client> ListeClients;
typedef std::vector<PtrClient> ListePtrClients;
typedef std::map<int, Client> MapIdClients;
typedef std::map<int, PtrClient> MapIdPtrClients;
typedef std::map<std::string, Client> MapNomsClients;
typedef std::map<std::string, PtrClient> MapNomsPtrClients;

#endif // CLIENT_H
