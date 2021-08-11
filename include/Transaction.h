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
    Transaction();
    Transaction(const int& date, const CPtrPlateforme plateformeAchat,
            const CPtrPlateforme plateformeVente, const CPtrEchange echangeAchat,
            const CPtrEchange echangeVente, const CPtrCours coursAchat, const CPtrCours coursVente);
    Transaction(const Transaction& transaction);
    virtual ~Transaction();

    // Opérateurs
    Transaction& operator=(const Transaction& transaction);
    bool operator==(const Transaction& transaction) const;
    bool operator!=(const Transaction& transaction) const;

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
    void copy(const Transaction& transaction);
    bool equals(const Transaction& transaction) const;
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
    int _date;
    PtrPlateforme _plateformeAchat;
    PtrPlateforme _plateformeVente;
    PtrEchange _echangeAchat;
    PtrEchange _echangeVente;
    PtrCours _coursAchat;
    PtrCours _coursVente;
};

typedef Transaction* PtrTransaction;
typedef const Transaction* CPtrTransaction;
typedef std::vector<Transaction> ListeTransactions;
typedef std::vector<PtrTransaction> ListePtrTransactions;
typedef std::vector<CPtrTransaction> ListeCPtrTransactions;
typedef std::map<int, Transaction> MapIdTransactions;
typedef std::map<int, PtrTransaction> MapIdPtrTransactions;
typedef std::map<int, CPtrTransaction> MapIdCPtrTransactions;
typedef std::map<std::string, Transaction> MapNomsTransactions;
typedef std::map<std::string, PtrTransaction> MapNomsPtrTransactions;
typedef std::map<std::string, CPtrTransaction> MapNomsCPtrTransactions;

#endif // TRANSACTION_H
