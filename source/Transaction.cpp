//==============================================================================
// Name        : Transaction.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Transaction class
//==============================================================================

#include "Transaction.h"

Transaction::Transaction() :
        m_plateformeAchat(NULL), m_plateformeVente(NULL), m_echangeAchat(NULL),
                m_echangeVente(NULL), m_coursAchat(NULL), m_coursVente(NULL), date(0)
{
    this->clear();
}

Transaction::Transaction(const PtrPlateforme plateformeAchat, const PtrPlateforme plateformeVente,
        const PtrEchange echangeAchat, const PtrEchange echangeVente, const PtrCours coursAchat,
        const PtrCours coursVente, const int& date) :
        Transaction()
{
    this->set(plateformeAchat, plateformeVente, echangeAchat, echangeVente, coursAchat, coursVente,
            date);
}

Transaction::Transaction(const Transaction& transaction) :
        Transaction()
{
    this->copy(transaction);
}

Transaction::~Transaction()
{

}

PtrPlateforme Transaction::getPlateformeAchat() const
{
    return this->m_plateformeAchat;
}

PtrPlateforme Transaction::getPlateformeVente() const
{
    return this->m_plateformeVente;
}

PtrEchange Transaction::getEchangeAchat() const
{
    return this->m_echangeAchat;
}

PtrEchange Transaction::getEchangeVente() const
{
    return this->m_echangeVente;
}

PtrCours Transaction::getCoursAchat() const
{
    return this->m_coursAchat;
}

PtrCours Transaction::getCoursVente() const
{
    return this->m_coursVente;
}

const int& Transaction::getDate() const
{
    return this->date;
}

void Transaction::setPlateformeAchat(const PtrPlateforme plateformeAchat)
{
    this->m_plateformeAchat = plateformeAchat;
}

void Transaction::setPlateformeVente(const PtrPlateforme plateformeVente)
{
    this->m_plateformeVente = plateformeVente;
}

void Transaction::setEchangeAchat(const PtrEchange echangeAchat)
{
    this->m_echangeAchat = echangeAchat;
}

void Transaction::setEchangeVente(const PtrEchange echangeVente)
{
    this->m_echangeVente = echangeVente;
}

void Transaction::setCoursAchat(const PtrCours coursAchat)
{
    this->m_coursAchat = coursAchat;
}

void Transaction::setCoursVente(const PtrCours coursVente)
{
    this->m_coursVente = coursVente;
}

void Transaction::setDate(const int& date)
{
    this->date = date;
}

void Transaction::clear()
{
    this->set(NULL, NULL, NULL, NULL, NULL, NULL, 0);
}

void Transaction::set(const PtrPlateforme plateformeAchat, const PtrPlateforme plateformeVente,
        const PtrEchange echangeAchat, const PtrEchange echangeVente, const PtrCours coursAchat,
        const PtrCours coursVente, const int& date)
{
    this->setPlateformeAchat(plateformeAchat);
    this->setPlateformeVente(plateformeVente);
    this->setEchangeAchat(echangeAchat);
    this->setEchangeVente(echangeVente);
    this->setCoursAchat(coursAchat);
    this->setCoursVente(coursVente);
    this->setDate(date);
}

void Transaction::copy(const Transaction& transaction)
{
    this->set(transaction.getPlateformeAchat(), transaction.getPlateformeVente(),
            transaction.getEchangeAchat(), transaction.getEchangeVente(),
            transaction.getCoursAchat(), transaction.getCoursVente(), transaction.getDate());
}

bool Transaction::equals(const Transaction& transaction) const
{
    if (this->getPlateformeAchat() != transaction.getPlateformeAchat())
        return false;
    if (this->getPlateformeVente() != transaction.getPlateformeVente())
        return false;
    if (this->getEchangeAchat() != transaction.getEchangeAchat())
        return false;
    if (this->getEchangeVente() != transaction.getEchangeVente())
        return false;
    if (this->getCoursAchat() != transaction.getCoursAchat())
        return false;
    if (this->getCoursVente() != transaction.getCoursVente())
        return false;
    if (this->getDate() != transaction.getDate())
        return false;
    return true;
}

void Transaction::fromString(const std::string& fromString, const char& sep)
{
    // TODO void Transaction::fromString(const std::string& fromString, const char& sep)
    // TODO #warning "'void Transaction::fromString(const std::string& fromString, const char& sep)' not implemented"
}

const std::string Transaction::toString(const char& sep) const
{
    // TODO const std::string Transaction::toString(const char& sep) const
    // TODO #warning "'const std::string Transaction::toString(const char& sep) const' not implemented"
    return std::string();
}

bool Transaction::operator==(const Transaction& transaction) const
{
    return this->equals(transaction);
}

bool Transaction::operator!=(const Transaction& transaction) const
{
    return !(this->equals(transaction));
}

bool Transaction::isSet() const
{
    return (this->m_plateformeAchat != NULL && this->m_plateformeVente != NULL
            && this->m_echangeAchat != NULL && this->m_echangeVente != NULL
            && this->m_coursAchat != NULL && this->m_coursVente != NULL);
}

double Transaction::getQuantiteAchat() const
{
    const double quantiteBudget = this->m_plateformeAchat->getBudget().getMonnaie(
            this->m_echangeAchat->getDeviseReelle().getNom())->getQuantite()
            / this->m_coursAchat->getValeurVente();
    const bool valeursAchatVenteIdentiques = (this->m_coursAchat->getValeurAchat()
            == this->m_coursAchat->getValeurVente());
    const double quantiteAchat =
            (valeursAchatVenteIdentiques) ?
                    std::min(quantiteBudget,
                            std::max(
                                    this->m_coursAchat->getQuantiteVente()
                                            - this->m_coursAchat->getQuantiteAchat(), 0.0)) :
                    std::min(quantiteBudget, this->m_coursAchat->getQuantiteVente());
    return quantiteAchat;
}

double Transaction::getQuantiteVente() const
{
    const double quantiteBudget = this->m_plateformeVente->getBudget().getMonnaie(
            this->m_echangeVente->getDeviseNumerique().getNom())->getQuantite();
    const bool valeursAchatVenteIdentiques = (this->m_coursVente->getValeurAchat()
            == this->m_coursVente->getValeurVente());
    const double quantiteVente =
            (valeursAchatVenteIdentiques) ?
                    std::min(quantiteBudget,
                            std::max(
                                    this->m_coursVente->getQuantiteAchat()
                                            - this->m_coursVente->getQuantiteVente(), 0.0)) :
                    std::min(quantiteBudget, this->m_coursVente->getQuantiteAchat());
    return quantiteVente;
}

double Transaction::getQuantiteTransaction() const
{
    const double quantiteAchat = this->getQuantiteAchat();
    const double quantiteVente = this->getQuantiteVente();
    const double quantiteTransaction = std::min(quantiteAchat, quantiteVente);
    return quantiteTransaction;
}

double Transaction::getCoutBrutAchat() const
{
    const double quantiteTransaction = this->getQuantiteTransaction();
    const double valeurAchat = this->m_coursAchat->getValeurVente();
    const double coutBrutAchat = quantiteTransaction * valeurAchat;
    return coutBrutAchat;
}

double Transaction::getCoutBrutVente() const
{
    const double quantiteTransaction = this->getQuantiteTransaction();
    const double valeurVente = this->m_coursVente->getValeurAchat();
    const double coutBrutVente = quantiteTransaction * valeurVente;
    return coutBrutVente;
}

double Transaction::getCoutNetAchat() const
{
    const double coutBrutAchat = this->getCoutBrutAchat();
    const double quantiteTransaction = this->getQuantiteTransaction();
    const double fraisFixes = this->m_echangeAchat->getFraisFixes();
    const double fraisVariables = this->m_echangeAchat->getFraisVariables();
    const double coutNetAchat = coutBrutAchat + fraisFixes + quantiteTransaction * fraisVariables;
    return coutNetAchat;
}

double Transaction::getCoutNetVente() const
{
    const double coutBrutVente = this->getCoutBrutVente();
    const double quantiteTransaction = this->getQuantiteTransaction();
    const double fraisFixes = this->m_echangeVente->getFraisFixes();
    const double fraisVariables = this->m_echangeVente->getFraisVariables();
    const double coutNetVente = coutBrutVente - fraisFixes - quantiteTransaction * fraisVariables;
    return coutNetVente;
}

double Transaction::getBeneficeBrut() const
{
    const double coutBrutAchat = this->getCoutBrutAchat();
    const double coutBrutVente = this->getCoutBrutVente();
    const double beneficeBrut = coutBrutVente - coutBrutAchat;
    return beneficeBrut;
}

double Transaction::getBeneficeNet() const
{
    const double coutNetAchat = this->getCoutNetAchat();
    const double coutNetVente = this->getCoutNetVente();
    const double beneficeNet = coutNetVente - coutNetAchat;
    return beneficeNet;
}
