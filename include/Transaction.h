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
    Transaction(const PtrPlateforme plateformeAchat, const PtrPlateforme plateformeVente,
            const PtrEchange echangeAchat, const PtrEchange echangeVente, const PtrCours coursAchat,
            const PtrCours coursVente, const int& date);
    Transaction(const Transaction& transaction);
    virtual ~Transaction();

    // Getters
    PtrPlateforme getPlateformeAchat() const;
    PtrPlateforme getPlateformeVente() const;
    PtrEchange getEchangeAchat() const;
    PtrEchange getEchangeVente() const;
    PtrCours getCoursAchat() const;
    PtrCours getCoursVente() const;
    const int& getDate() const;

    // Setters
    void setPlateformeAchat(const PtrPlateforme plateformeAchat);
    void setPlateformeVente(const PtrPlateforme plateformeVente);
    void setEchangeAchat(const PtrEchange echangeAchat);
    void setEchangeVente(const PtrEchange echangeVente);
    void setCoursAchat(const PtrCours coursAchat);
    void setCoursVente(const PtrCours coursVente);
    void setDate(const int& date);

    // Méthodes génériques
    void clear();
    void set(const PtrPlateforme plateformeAchat, const PtrPlateforme plateformeVente,
            const PtrEchange echangeAchat, const PtrEchange echangeVente, const PtrCours coursAchat,
            const PtrCours coursVente, const int& date);
    void copy(const Transaction& transaction);
    bool equals(const Transaction& transaction) const;
    void fromString(const std::string& fromString, const char& sep);
    const std::string toString(const char& sep) const;

    // Méthodes spécifiques (opérateurs)
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

private:
    // Membres de classe
    PtrPlateforme m_plateformeAchat;
    PtrPlateforme m_plateformeVente;
    PtrEchange m_echangeAchat;
    PtrEchange m_echangeVente;
    PtrCours m_coursAchat;
    PtrCours m_coursVente;
    int date;
};

typedef Transaction* PtrTransaction;
typedef std::vector<Transaction> ListeTransaction_;
typedef std::vector<PtrTransaction> ListePtrTransaction_;
typedef std::map<int, Transaction> MapIdTransaction_;
typedef std::map<int, PtrTransaction> MapIdPtrTransaction_;
typedef std::map<std::string, Transaction> MapNomsTransaction_;
typedef std::map<std::string, PtrTransaction> MapNomsPtrTransaction_;

#endif // TRANSACTION_H