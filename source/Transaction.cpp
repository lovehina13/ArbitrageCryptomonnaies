//==============================================================================
// Name        : Transaction.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Transaction class
//==============================================================================

#include "Transaction.h"
#include "Budget.h"
#include "Devise.h"
#include "Monnaie.h"
#include <algorithm>
#include <sstream>

Transaction::Transaction() :
        m_date(0), m_plateformeAchat(nullptr), m_plateformeVente(nullptr), m_echangeAchat(nullptr),
                m_echangeVente(nullptr), m_coursAchat(nullptr), m_coursVente(nullptr)
{
    this->clear();
}

Transaction::Transaction(const int& date, const CPtrPlateforme plateformeAchat,
        const CPtrPlateforme plateformeVente, const CPtrEchange echangeAchat,
        const CPtrEchange echangeVente, const CPtrCours coursAchat, const CPtrCours coursVente) :
        Transaction()
{
    this->set(date, plateformeAchat, plateformeVente, echangeAchat, echangeVente, coursAchat,
            coursVente);
}

Transaction::Transaction(const Transaction& transaction) :
        Transaction()
{
    this->copy(transaction);
}

Transaction::~Transaction()
{

}

Transaction& Transaction::operator=(const Transaction& transaction)
{
    this->copy(transaction);
    return *this;
}

bool Transaction::operator==(const Transaction& transaction) const
{
    return this->equals(transaction);
}

bool Transaction::operator!=(const Transaction& transaction) const
{
    return !this->equals(transaction);
}

const int& Transaction::getDate() const
{
    return this->m_date;
}

CPtrPlateforme Transaction::getPlateformeAchat() const
{
    return this->m_plateformeAchat;
}

CPtrPlateforme Transaction::getPlateformeVente() const
{
    return this->m_plateformeVente;
}

CPtrEchange Transaction::getEchangeAchat() const
{
    return this->m_echangeAchat;
}

CPtrEchange Transaction::getEchangeVente() const
{
    return this->m_echangeVente;
}

CPtrCours Transaction::getCoursAchat() const
{
    return this->m_coursAchat;
}

CPtrCours Transaction::getCoursVente() const
{
    return this->m_coursVente;
}

void Transaction::setDate(const int& date)
{
    this->m_date = date;
}

void Transaction::setPlateformeAchat(const CPtrPlateforme plateformeAchat)
{
    this->m_plateformeAchat = const_cast<PtrPlateforme>(plateformeAchat);
}

void Transaction::setPlateformeVente(const CPtrPlateforme plateformeVente)
{
    this->m_plateformeVente = const_cast<PtrPlateforme>(plateformeVente);
}

void Transaction::setEchangeAchat(const CPtrEchange echangeAchat)
{
    this->m_echangeAchat = const_cast<PtrEchange>(echangeAchat);
}

void Transaction::setEchangeVente(const CPtrEchange echangeVente)
{
    this->m_echangeVente = const_cast<PtrEchange>(echangeVente);
}

void Transaction::setCoursAchat(const CPtrCours coursAchat)
{
    this->m_coursAchat = const_cast<PtrCours>(coursAchat);
}

void Transaction::setCoursVente(const CPtrCours coursVente)
{
    this->m_coursVente = const_cast<PtrCours>(coursVente);
}

void Transaction::clear()
{
    this->set(0, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
}

void Transaction::set(const int& date, const CPtrPlateforme plateformeAchat,
        const CPtrPlateforme plateformeVente, const CPtrEchange echangeAchat,
        const CPtrEchange echangeVente, const CPtrCours coursAchat, const CPtrCours coursVente)
{
    this->setDate(date);
    this->setPlateformeAchat(plateformeAchat);
    this->setPlateformeVente(plateformeVente);
    this->setEchangeAchat(echangeAchat);
    this->setEchangeVente(echangeVente);
    this->setCoursAchat(coursAchat);
    this->setCoursVente(coursVente);
}

void Transaction::copy(const Transaction& transaction)
{
    this->set(transaction.getDate(), transaction.getPlateformeAchat(),
            transaction.getPlateformeVente(), transaction.getEchangeAchat(),
            transaction.getEchangeVente(), transaction.getCoursAchat(),
            transaction.getCoursVente());
}

bool Transaction::equals(const Transaction& transaction) const
{
    if (this->getDate() != transaction.getDate())
        return false;
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
    return true;
}

void Transaction::fromString(const std::string& fromString, const char& sep)
{
    // TODO void Transaction::fromString(const std::string& fromString, const char& sep)
    // #warning "'void Transaction::fromString(const std::string& fromString, const char& sep)' not implemented"
}

const std::string Transaction::toString(const char& sep) const
{
    // TODO const std::string Transaction::toString(const char& sep) const
    // #warning "'const std::string Transaction::toString(const char& sep) const' not implemented"
    return std::string();
}

bool Transaction::isSet() const
{
    return (this->m_plateformeAchat && this->m_plateformeVente && this->m_echangeAchat
            && this->m_echangeVente && this->m_coursAchat && this->m_coursVente);
}

double Transaction::getQuantiteAchat() const
{
    const double quantiteMonnaie = this->m_plateformeAchat->getBudget().getMonnaie(
            this->m_echangeAchat->getDeviseReelle().getNom())->getQuantite();
    const double quantiteBudget = (quantiteMonnaie - this->m_echangeAchat->getFraisFixesAchat())
            / (this->m_coursAchat->getValeurVente() * this->m_echangeAchat->getFraisVariablesAchat()
                    + this->m_coursAchat->getValeurVente());
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
    const double quantiteMonnaie = this->m_plateformeVente->getBudget().getMonnaie(
            this->m_echangeVente->getDeviseNumerique().getNom())->getQuantite();
    const double quantiteBudget = quantiteMonnaie;
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
    const double fraisFixesAchat = this->m_echangeAchat->getFraisFixesAchat();
    const double fraisVariablesAchat = this->m_echangeAchat->getFraisVariablesAchat();
    const double coutNetAchat = coutBrutAchat + fraisFixesAchat
            + coutBrutAchat * fraisVariablesAchat;
    return coutNetAchat;
}

double Transaction::getCoutNetVente() const
{
    const double coutBrutVente = this->getCoutBrutVente();
    const double fraisFixesVente = this->m_echangeVente->getFraisFixesVente();
    const double fraisVariablesVente = this->m_echangeVente->getFraisVariablesVente();
    const double coutNetVente = coutBrutVente - fraisFixesVente
            - coutBrutVente * fraisVariablesVente;
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

double Transaction::getRatioBeneficeBrut() const
{
    const double coutBrutAchat = this->getCoutBrutAchat();
    const double coutBrutVente = this->getCoutBrutVente();
    const double ratioBeneficeBrut = coutBrutVente / coutBrutAchat;
    return ratioBeneficeBrut;
}

double Transaction::getRatioBeneficeNet() const
{
    const double coutNetAchat = this->getCoutNetAchat();
    const double coutNetVente = this->getCoutNetVente();
    const double ratioBeneficeNet = coutNetVente / coutNetAchat;
    return ratioBeneficeNet;
}

const std::string Transaction::getTexteSynthese() const
{
    std::stringstream stream;
    stream << "Plateforme achat: " << this->getPlateformeAchat()->getNom() << std::endl;
    stream << "Échange achat: " << this->getEchangeAchat()->getDeviseReelle().getNom() << " vers "
            << this->getEchangeAchat()->getDeviseNumerique().getNom() << std::endl;
    stream << "Cours achat: " << this->getCoursAchat()->getValeurVente() << std::endl;
    stream << "Quantité achat: " << this->getQuantiteTransaction() << std::endl;
    stream << "Coût net achat: " << this->getCoutNetAchat() << std::endl;
    stream << "Plateforme vente: " << this->getPlateformeVente()->getNom() << std::endl;
    stream << "Échange vente: " << this->getEchangeVente()->getDeviseNumerique().getNom()
            << " vers " << this->getEchangeVente()->getDeviseReelle().getNom() << std::endl;
    stream << "Cours vente: " << this->getCoursVente()->getValeurAchat() << std::endl;
    stream << "Quantité vente: " << this->getQuantiteTransaction() << std::endl;
    stream << "Coût net vente: " << this->getCoutNetVente() << std::endl;
    stream << "Bénéfice net: " << this->getBeneficeNet() << std::endl;
    stream << "Ratio bénéfice net: " << this->getRatioBeneficeNet() << std::endl;
    return stream.str();
}
