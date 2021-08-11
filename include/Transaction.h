//==============================================================================
// Name        : Transaction.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Header file of the Transaction class
//==============================================================================

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Cours.h"
#include "Echange.h"
#include "Plateforme.h"
#include <map>
#include <string>
#include <vector>

class Transaction
{
public:
    // Constructeurs et destructeurs
    Transaction() = default;
    Transaction(const int& date, const CPtrPlateforme plateformeAchat,
            const CPtrPlateforme plateformeVente, const CPtrEchange echangeAchat,
            const CPtrEchange echangeVente, const CPtrCours coursAchat, const CPtrCours coursVente);

    // Opérateurs
    bool operator==(const Transaction& transaction) const = default;
    bool operator!=(const Transaction& transaction) const = default;

    // Getters
    const int& getDate() const;
    CPtrPlateforme getPlateformeAchat() const;
    CPtrPlateforme getPlateformeVente() const;
    CPtrEchange getEchangeAchat() const;
    CPtrEchange getEchangeVente() const;
    CPtrCours getCoursAchat() const;
    CPtrCours getCoursVente() const;

    // Setters
    void setDate(const int& date);
    void setPlateformeAchat(const CPtrPlateforme plateformeAchat);
    void setPlateformeVente(const CPtrPlateforme plateformeVente);
    void setEchangeAchat(const CPtrEchange echangeAchat);
    void setEchangeVente(const CPtrEchange echangeVente);
    void setCoursAchat(const CPtrCours coursAchat);
    void setCoursVente(const CPtrCours coursVente);

    // Méthodes génériques
    void clear();
    void set(const int& date, const CPtrPlateforme plateformeAchat,
            const CPtrPlateforme plateformeVente, const CPtrEchange echangeAchat,
            const CPtrEchange echangeVente, const CPtrCours coursAchat, const CPtrCours coursVente);
    void fromString(const std::string& fromString, const char& sep);
    const std::string toString(const char& sep) const;

    // Méthodes spécifiques (traitements)
    bool isSet() const;
    double getQuantiteAchat() const;
    double getQuantiteVente() const;
    double getQuantiteTransaction() const;
    double getCoutBrutAchat() const;
    double getCoutBrutVente() const;
    double getCoutNetAchat() const;
    double getCoutNetVente() const;
    double getBeneficeBrut() const;
    double getBeneficeNet() const;
    double getRatioBeneficeBrut() const;
    double getRatioBeneficeNet() const;
    const std::string getTexteSynthese() const;

private:
    // Membres de classe
    int _date { 0 };
    PtrPlateforme _plateformeAchat { nullptr };
    PtrPlateforme _plateformeVente { nullptr };
    PtrEchange _echangeAchat { nullptr };
    PtrEchange _echangeVente { nullptr };
    PtrCours _coursAchat { nullptr };
    PtrCours _coursVente { nullptr };
};

using PtrTransaction = Transaction*;
using CPtrTransaction = const Transaction*;
using ListeTransactions = std::vector<Transaction>;
using ListePtrTransactions = std::vector<PtrTransaction>;
using ListeCPtrTransactions = std::vector<CPtrTransaction>;
using MapIdTransactions = std::map<int, Transaction>;
using MapIdPtrTransactions = std::map<int, PtrTransaction>;
using MapIdCPtrTransactions = std::map<int, CPtrTransaction>;
using MapNomsTransactions = std::map<std::string, Transaction>;
using MapNomsPtrTransactions = std::map<std::string, PtrTransaction>;
using MapNomsCPtrTransactions = std::map<std::string, CPtrTransaction>;

#endif // TRANSACTION_H
