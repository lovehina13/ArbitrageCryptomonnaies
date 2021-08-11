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

Transaction::Transaction(const int& date, const CPtrPlateforme plateformeAchat,
        const CPtrPlateforme plateformeVente, const CPtrEchange echangeAchat,
        const CPtrEchange echangeVente, const CPtrCours coursAchat, const CPtrCours coursVente) :
        _date(date), _plateformeAchat(const_cast<PtrPlateforme>(plateformeAchat)),
                _plateformeVente(const_cast<PtrPlateforme>(plateformeVente)),
                _echangeAchat(const_cast<PtrEchange>(echangeAchat)),
                _echangeVente(const_cast<PtrEchange>(echangeVente)),
                _coursAchat(const_cast<PtrCours>(coursAchat)),
                _coursVente(const_cast<PtrCours>(coursVente))
{
}

const int& Transaction::getDate() const
{
    return _date;
}

CPtrPlateforme Transaction::getPlateformeAchat() const
{
    return _plateformeAchat;
}

CPtrPlateforme Transaction::getPlateformeVente() const
{
    return _plateformeVente;
}

CPtrEchange Transaction::getEchangeAchat() const
{
    return _echangeAchat;
}

CPtrEchange Transaction::getEchangeVente() const
{
    return _echangeVente;
}

CPtrCours Transaction::getCoursAchat() const
{
    return _coursAchat;
}

CPtrCours Transaction::getCoursVente() const
{
    return _coursVente;
}

void Transaction::setDate(const int& date)
{
    _date = date;
}

void Transaction::setPlateformeAchat(const CPtrPlateforme plateformeAchat)
{
    _plateformeAchat = const_cast<PtrPlateforme>(plateformeAchat);
}

void Transaction::setPlateformeVente(const CPtrPlateforme plateformeVente)
{
    _plateformeVente = const_cast<PtrPlateforme>(plateformeVente);
}

void Transaction::setEchangeAchat(const CPtrEchange echangeAchat)
{
    _echangeAchat = const_cast<PtrEchange>(echangeAchat);
}

void Transaction::setEchangeVente(const CPtrEchange echangeVente)
{
    _echangeVente = const_cast<PtrEchange>(echangeVente);
}

void Transaction::setCoursAchat(const CPtrCours coursAchat)
{
    _coursAchat = const_cast<PtrCours>(coursAchat);
}

void Transaction::setCoursVente(const CPtrCours coursVente)
{
    _coursVente = const_cast<PtrCours>(coursVente);
}

void Transaction::clear()
{
    *this = Transaction();
}

void Transaction::set(const int& date, const CPtrPlateforme plateformeAchat,
        const CPtrPlateforme plateformeVente, const CPtrEchange echangeAchat,
        const CPtrEchange echangeVente, const CPtrCours coursAchat, const CPtrCours coursVente)
{
    setDate(date);
    setPlateformeAchat(plateformeAchat);
    setPlateformeVente(plateformeVente);
    setEchangeAchat(echangeAchat);
    setEchangeVente(echangeVente);
    setCoursAchat(coursAchat);
    setCoursVente(coursVente);
}

void Transaction::fromString(const std::string& /*fromString*/, const char& /*sep*/)
{
    // TODO void Transaction::fromString(const std::string& fromString, const char& sep)
    // #warning "'void Transaction::fromString(const std::string& fromString, const char& sep)' not implemented"
}

const std::string Transaction::toString(const char& /*sep*/) const
{
    // TODO const std::string Transaction::toString(const char& sep) const
    // #warning "'const std::string Transaction::toString(const char& sep) const' not implemented"
    return std::string();
}

bool Transaction::isSet() const
{
    return (_plateformeAchat && _plateformeVente && _echangeAchat && _echangeVente && _coursAchat
            && _coursVente);
}

double Transaction::getQuantiteAchat() const
{
    const double quantiteMonnaie = _plateformeAchat->getBudget().getMonnaie(
            _echangeAchat->getDeviseReelle().getNom())->getQuantite();
    const double quantiteBudget = (quantiteMonnaie - _echangeAchat->getFraisFixesAchat())
            / (_coursAchat->getValeurVente() * _echangeAchat->getFraisVariablesAchat()
                    + _coursAchat->getValeurVente());
    const bool valeursAchatVenteIdentiques = (_coursAchat->getValeurAchat()
            == _coursAchat->getValeurVente());
    const double quantiteAchat =
            (valeursAchatVenteIdentiques) ?
                    std::min(quantiteBudget,
                            std::max(
                                    _coursAchat->getQuantiteVente()
                                            - _coursAchat->getQuantiteAchat(), 0.0)) :
                    std::min(quantiteBudget, _coursAchat->getQuantiteVente());
    return quantiteAchat;
}

double Transaction::getQuantiteVente() const
{
    const double quantiteMonnaie = _plateformeVente->getBudget().getMonnaie(
            _echangeVente->getDeviseNumerique().getNom())->getQuantite();
    const double quantiteBudget = quantiteMonnaie;
    const bool valeursAchatVenteIdentiques = (_coursVente->getValeurAchat()
            == _coursVente->getValeurVente());
    const double quantiteVente =
            (valeursAchatVenteIdentiques) ?
                    std::min(quantiteBudget,
                            std::max(
                                    _coursVente->getQuantiteAchat()
                                            - _coursVente->getQuantiteVente(), 0.0)) :
                    std::min(quantiteBudget, _coursVente->getQuantiteAchat());
    return quantiteVente;
}

double Transaction::getQuantiteTransaction() const
{
    const double quantiteAchat = getQuantiteAchat();
    const double quantiteVente = getQuantiteVente();
    const double quantiteTransaction = std::min(quantiteAchat, quantiteVente);
    return quantiteTransaction;
}

double Transaction::getCoutBrutAchat() const
{
    const double quantiteTransaction = getQuantiteTransaction();
    const double valeurAchat = _coursAchat->getValeurVente();
    const double coutBrutAchat = quantiteTransaction * valeurAchat;
    return coutBrutAchat;
}

double Transaction::getCoutBrutVente() const
{
    const double quantiteTransaction = getQuantiteTransaction();
    const double valeurVente = _coursVente->getValeurAchat();
    const double coutBrutVente = quantiteTransaction * valeurVente;
    return coutBrutVente;
}

double Transaction::getCoutNetAchat() const
{
    const double coutBrutAchat = getCoutBrutAchat();
    const double fraisFixesAchat = _echangeAchat->getFraisFixesAchat();
    const double fraisVariablesAchat = _echangeAchat->getFraisVariablesAchat();
    const double coutNetAchat = coutBrutAchat + fraisFixesAchat
            + coutBrutAchat * fraisVariablesAchat;
    return coutNetAchat;
}

double Transaction::getCoutNetVente() const
{
    const double coutBrutVente = getCoutBrutVente();
    const double fraisFixesVente = _echangeVente->getFraisFixesVente();
    const double fraisVariablesVente = _echangeVente->getFraisVariablesVente();
    const double coutNetVente = coutBrutVente - fraisFixesVente
            - coutBrutVente * fraisVariablesVente;
    return coutNetVente;
}

double Transaction::getBeneficeBrut() const
{
    const double coutBrutAchat = getCoutBrutAchat();
    const double coutBrutVente = getCoutBrutVente();
    const double beneficeBrut = coutBrutVente - coutBrutAchat;
    return beneficeBrut;
}

double Transaction::getBeneficeNet() const
{
    const double coutNetAchat = getCoutNetAchat();
    const double coutNetVente = getCoutNetVente();
    const double beneficeNet = coutNetVente - coutNetAchat;
    return beneficeNet;
}

double Transaction::getRatioBeneficeBrut() const
{
    const double coutBrutAchat = getCoutBrutAchat();
    const double coutBrutVente = getCoutBrutVente();
    const double ratioBeneficeBrut = coutBrutVente / coutBrutAchat;
    return ratioBeneficeBrut;
}

double Transaction::getRatioBeneficeNet() const
{
    const double coutNetAchat = getCoutNetAchat();
    const double coutNetVente = getCoutNetVente();
    const double ratioBeneficeNet = coutNetVente / coutNetAchat;
    return ratioBeneficeNet;
}

const std::string Transaction::getTexteSynthese() const
{
    std::stringstream stream;
    stream << "Plateforme achat: " << getPlateformeAchat()->getNom() << std::endl;
    stream << "Échange achat: " << getEchangeAchat()->getDeviseReelle().getNom() << " vers "
            << getEchangeAchat()->getDeviseNumerique().getNom() << std::endl;
    stream << "Cours achat: " << getCoursAchat()->getValeurVente() << std::endl;
    stream << "Quantité achat: " << getQuantiteTransaction() << std::endl;
    stream << "Coût net achat: " << getCoutNetAchat() << std::endl;
    stream << "Plateforme vente: " << getPlateformeVente()->getNom() << std::endl;
    stream << "Échange vente: " << getEchangeVente()->getDeviseNumerique().getNom() << " vers "
            << getEchangeVente()->getDeviseReelle().getNom() << std::endl;
    stream << "Cours vente: " << getCoursVente()->getValeurAchat() << std::endl;
    stream << "Quantité vente: " << getQuantiteTransaction() << std::endl;
    stream << "Coût net vente: " << getCoutNetVente() << std::endl;
    stream << "Bénéfice net: " << getBeneficeNet() << std::endl;
    stream << "Ratio bénéfice net: " << getRatioBeneficeNet() << std::endl;
    return stream.str();
}
