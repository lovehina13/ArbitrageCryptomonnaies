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
    Transaction(const int& date, const PtrPlateforme plateformeAchat,
            const PtrPlateforme plateformeVente, const PtrEchange echangeAchat,
            const PtrEchange echangeVente, const PtrCours coursAchat, const PtrCours coursVente);
    Transaction(const Transaction& transaction);
    virtual ~Transaction();

    // Getters
    const int& getDate() const;
    PtrPlateforme getPlateformeAchat() const;
    PtrPlateforme getPlateformeVente() const;
    PtrEchange getEchangeAchat() const;
    PtrEchange getEchangeVente() const;
    PtrCours getCoursAchat() const;
    PtrCours getCoursVente() const;

    // Setters
    void setDate(const int& date);
    void setPlateformeAchat(const PtrPlateforme plateformeAchat);
    void setPlateformeVente(const PtrPlateforme plateformeVente);
    void setEchangeAchat(const PtrEchange echangeAchat);
    void setEchangeVente(const PtrEchange echangeVente);
    void setCoursAchat(const PtrCours coursAchat);
    void setCoursVente(const PtrCours coursVente);

    // Méthodes génériques
    void clear();
    void set(const int& date, const PtrPlateforme plateformeAchat,
            const PtrPlateforme plateformeVente, const PtrEchange echangeAchat,
            const PtrEchange echangeVente, const PtrCours coursAchat, const PtrCours coursVente);
    void copy(const Transaction& transaction);
    bool equals(const Transaction& transaction) const;
    void fromString(const std::string& fromString, const char& sep);
    const std::string toString(const char& sep) const;

    // Méthodes spécifiques (opérateurs)
    Transaction& operator=(const Transaction& transaction);
    bool operator==(const Transaction& transaction) const;
    bool operator!=(const Transaction& transaction) const;

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
    int m_date;
    PtrPlateforme m_plateformeAchat;
    PtrPlateforme m_plateformeVente;
    PtrEchange m_echangeAchat;
    PtrEchange m_echangeVente;
    PtrCours m_coursAchat;
    PtrCours m_coursVente;
};

typedef Transaction* PtrTransaction;
typedef std::vector<Transaction> ListeTransactions;
typedef std::vector<PtrTransaction> ListePtrTransactions;
typedef std::map<int, Transaction> MapIdTransactions;
typedef std::map<int, PtrTransaction> MapIdPtrTransactions;
typedef std::map<std::string, Transaction> MapNomsTransactions;
typedef std::map<std::string, PtrTransaction> MapNomsPtrTransactions;

#endif // TRANSACTION_H
