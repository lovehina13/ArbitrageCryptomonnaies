//==============================================================================
// Name        : Projet.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Projet class
//==============================================================================

#include "Projet.h"
#include "Budget.h"
#include "Client.h"
#include "Cours.h"
#include "Devise.h"
#include "Echange.h"
#include "Monnaie.h"
#include <iterator>
#include <memory>
#include <utility>

Projet::Projet(const MapNomsPlateformes& mapPlateformes) :
        _mapPlateformes(mapPlateformes)
{
}

const MapNomsPlateformes& Projet::getMapPlateformes() const
{
    return _mapPlateformes;
}

void Projet::setMapPlateformes(const MapNomsPlateformes& mapPlateformes)
{
    _mapPlateformes = mapPlateformes;
}

void Projet::clear()
{
    *this = Projet();
}

void Projet::set(const MapNomsPlateformes& mapPlateformes)
{
    setMapPlateformes(mapPlateformes);
}

void Projet::fromString(const std::string& /*fromString*/, const char& /*sep*/)
{
    // TODO void Projet::fromString(const std::string& fromString, const char& sep)
    // #warning "'void Projet::fromString(const std::string& fromString, const char& sep)' not implemented"
}

const std::string Projet::toString(const char& /*sep*/) const
{
    // TODO const std::string Projet::toString(const char& sep) const
    // #warning "'const std::string Projet::toString(const char& sep) const' not implemented"
    return std::string();
}

bool Projet::hasPlateforme(const std::string& nom) const
{
    return (_mapPlateformes.find(nom) != _mapPlateformes.end());
}

CPtrPlateforme Projet::getPlateforme(const std::string& nom) const
{
    return (hasPlateforme(nom) ? &_mapPlateformes.find(nom)->second : nullptr);
}

bool Projet::ajouterPlateforme(const std::string& nom, const Plateforme& plateforme)
{
    return (_mapPlateformes.insert(std::pair<std::string, Plateforme>(nom, plateforme)).second);
}

bool Projet::supprimerPlateforme(const std::string& nom)
{
    return (_mapPlateformes.erase(nom) > 0);
}

void Projet::effacerNombreCours(const int& nombreCoursMaximal)
{
    // Récupération de l'ensemble des plateformes
    const MapNomsPlateformes& mapPlateformes = _mapPlateformes;

    // Boucle sur les plateformes
    for (MapNomsPlateformes::const_iterator itPlateforme = mapPlateformes.begin();
            itPlateforme != mapPlateformes.end(); itPlateforme++)
    {
        // Récupération de la plateforme
        const Plateforme& plateforme = itPlateforme->second;

        // Récupération de l'ensemble des échanges
        const MapNomsEchanges& mapEchanges = plateforme.getMapEchanges();

        // Boucle sur les échanges
        for (MapNomsEchanges::const_iterator itEchange = mapEchanges.begin();
                itEchange != mapEchanges.end(); itEchange++)
        {
            // Récupération de l'échange
            PtrEchange echange = const_cast<PtrEchange>(&itEchange->second);

            // Récupération de l'ensemble des cours
            const MapIdCours& mapCours = echange->getMapCours();

            // Actualisation de l'ensemble des cours
            const int nbCours = static_cast<int>(mapCours.size());
            if (nbCours > nombreCoursMaximal)
            {
                MapIdCours mapCoursNew = mapCours;
                mapCoursNew.erase(mapCoursNew.begin(),
                        std::next(mapCoursNew.begin(), nbCours - nombreCoursMaximal));
                echange->setMapCours(mapCoursNew);
            }
        }
    }
}

void Projet::recupererCours(const int& date)
{
    // Récupération de l'ensemble des plateformes
    const MapNomsPlateformes& mapPlateformes = _mapPlateformes;

    // Boucle sur les plateformes
    for (MapNomsPlateformes::const_iterator itPlateforme = mapPlateformes.begin();
            itPlateforme != mapPlateformes.end(); itPlateforme++)
    {
        // Récupération de la plateforme
        const Plateforme& plateforme = itPlateforme->second;

        // Récupération du client
        const std::shared_ptr<Client>& client = plateforme.getClient();

        // Récupération de l'ensemble des échanges
        const MapNomsEchanges& mapEchanges = plateforme.getMapEchanges();

        // Boucle sur les échanges
        for (MapNomsEchanges::const_iterator itEchange = mapEchanges.begin();
                itEchange != mapEchanges.end(); itEchange++)
        {
            // Récupération de l'échange
            PtrEchange echange = const_cast<PtrEchange>(&itEchange->second);

            // Récupération des devises numériques et réelles
            const Devise& deviseNumerique = echange->getDeviseNumerique();
            const Devise& deviseReelle = echange->getDeviseReelle();

            // Définition du cours
            const double valeurAchat = client->getValeurAchat(deviseNumerique.getNom(),
                    deviseReelle.getNom());
            const double valeurVente = client->getValeurVente(deviseNumerique.getNom(),
                    deviseReelle.getNom());
            const double quantiteAchat = client->getQuantiteAchat(deviseNumerique.getNom(),
                    deviseReelle.getNom());
            const double quantiteVente = client->getQuantiteVente(deviseNumerique.getNom(),
                    deviseReelle.getNom());
            const Cours cours = Cours(date, valeurAchat, valeurVente, quantiteAchat, quantiteVente);

            // Ajout du cours
            echange->ajouterCours(date, cours);
        }
    }
}

const Transaction Projet::getTransactionOptimale(const int& date, const double& beneficeMinimal,
        const double& ratioBeneficeMinimal) const
{
    // Définition de la transaction optimale
    Transaction transactionOptimale;

    // Récupération de l'ensemble des plateformes de source et de destination
    const MapNomsPlateformes& mapPlateformesSource = _mapPlateformes;
    const MapNomsPlateformes& mapPlateformesDestination = _mapPlateformes;

    // Boucle sur les plateformes de source
    for (MapNomsPlateformes::const_iterator itPlateformeSource = mapPlateformesSource.begin();
            itPlateformeSource != mapPlateformesSource.end(); itPlateformeSource++)
    {
        // Boucle sur les plateformes de destination
        for (MapNomsPlateformes::const_iterator itPlateformeDestination =
                mapPlateformesDestination.begin();
                itPlateformeDestination != mapPlateformesDestination.end();
                itPlateformeDestination++)
        {
            // Considération des plateformes de source et de destination si elles sont différentes
            const std::string& nomPlateformeSource = itPlateformeSource->first;
            const std::string& nomPlateformeDestination = itPlateformeDestination->first;
            if (nomPlateformeSource == nomPlateformeDestination)
                continue;

            // Récupération des plateformes de source et de destination
            const Plateforme& plateformeSource = itPlateformeSource->second;
            const Plateforme& plateformeDestination = itPlateformeDestination->second;

            // Récupération de l'ensemble des échanges de source et de destination
            const MapNomsEchanges& mapEchangesSource = plateformeSource.getMapEchanges();
            const MapNomsEchanges& mapEchangesDestination = plateformeDestination.getMapEchanges();

            // Boucle sur les échanges de source
            for (MapNomsEchanges::const_iterator itEchangeSource = mapEchangesSource.begin();
                    itEchangeSource != mapEchangesSource.end(); itEchangeSource++)
            {
                // Boucle sur les échanges de destination
                for (MapNomsEchanges::const_iterator itEchangeDestination =
                        mapEchangesDestination.begin();
                        itEchangeDestination != mapEchangesDestination.end();
                        itEchangeDestination++)
                {
                    // Considération des échanges de source et de destination s'ils sont identiques
                    const std::string& nomEchangeSource = itEchangeSource->first;
                    const std::string& nomEchangeDestination = itEchangeDestination->first;
                    if (nomEchangeSource != nomEchangeDestination)
                        continue;

                    // Récupération des échanges de source et de destination
                    const Echange& echangeSource = itEchangeSource->second;
                    const Echange& echangeDestination = itEchangeDestination->second;

                    // Récupération des cours de source et de destination
                    const CPtrCours coursSource = echangeSource.getCours(date);
                    const CPtrCours coursDestination = echangeDestination.getCours(date);

                    // Considération des cours de source et de destination s'ils existent
                    if (!coursSource || !coursDestination)
                        continue;

                    // Définition de la transaction
                    Transaction transaction = Transaction(date, &plateformeSource,
                            &plateformeDestination, &echangeSource, &echangeDestination,
                            coursSource, coursDestination);

                    // Récupération des bénéfices nets
                    const double beneficeNet = transaction.getBeneficeNet();
                    const double ratioBeneficeNet = transaction.getRatioBeneficeNet();
                    const double beneficeNetOptimal =
                            (transactionOptimale.isSet()) ?
                                    transactionOptimale.getBeneficeNet() : 0.0;

                    // Considération de la transaction comme optimale si le bénéfice net est supérieur au précédent
                    if (beneficeNet > beneficeNetOptimal && beneficeNet > beneficeMinimal
                            && ratioBeneficeNet > ratioBeneficeMinimal)
                    {
                        transactionOptimale = transaction;
                    }
                }
            }
        }
    }

    return transactionOptimale;
}

void Projet::actualiserBudgets(const Transaction& transaction)
{
    // Récupération des plateformes d'achat et de vente
    const CPtrPlateforme plateformeAchat = transaction.getPlateformeAchat();
    const CPtrPlateforme plateformeVente = transaction.getPlateformeVente();

    // Récupération des budgets d'achat et de vente
    const Budget& budgetAchat = plateformeAchat->getBudget();
    const Budget& budgetVente = plateformeVente->getBudget();

    // Récupération des monnaies numériques et réelles d'achat et de vente
    PtrMonnaie monnaieNumeriqueAchat = const_cast<PtrMonnaie>(budgetAchat.getMonnaie(
            transaction.getEchangeAchat()->getDeviseNumerique().getNom()));
    PtrMonnaie monnaieReelleAchat = const_cast<PtrMonnaie>(budgetAchat.getMonnaie(
            transaction.getEchangeAchat()->getDeviseReelle().getNom()));
    PtrMonnaie monnaieNumeriqueVente = const_cast<PtrMonnaie>(budgetVente.getMonnaie(
            transaction.getEchangeVente()->getDeviseNumerique().getNom()));
    PtrMonnaie monnaieReelleVente = const_cast<PtrMonnaie>(budgetVente.getMonnaie(
            transaction.getEchangeVente()->getDeviseReelle().getNom()));

    // Récupération des quantités des monnaies numériques et réelles d'achat et de vente
    const double quantiteMonnaieNumeriqueAchat = monnaieNumeriqueAchat->getQuantite()
            + transaction.getQuantiteTransaction();
    const double quantiteMonnaieReelleAchat = monnaieReelleAchat->getQuantite()
            - transaction.getCoutNetAchat();
    const double quantiteMonnaieNumeriqueVente = monnaieNumeriqueVente->getQuantite()
            - transaction.getQuantiteTransaction();
    const double quantiteMonnaieReelleVente = monnaieReelleVente->getQuantite()
            + transaction.getCoutNetVente();

    // Actualisation des quantités des monnaies numériques et réelles d'achat et de vente
    monnaieNumeriqueAchat->setQuantite(quantiteMonnaieNumeriqueAchat);
    monnaieReelleAchat->setQuantite(quantiteMonnaieReelleAchat);
    monnaieNumeriqueVente->setQuantite(quantiteMonnaieNumeriqueVente);
    monnaieReelleVente->setQuantite(quantiteMonnaieReelleVente);
}

void Projet::equilibrerBudgets(const Transaction& /*transaction*/)
{
    // Définition du budget total
    Budget budgetTotal;

    // Récupération de l'ensemble des plateformes
    const MapNomsPlateformes& mapPlateformes = _mapPlateformes;

    // Boucle sur les plateformes
    for (MapNomsPlateformes::const_iterator itPlateforme = mapPlateformes.begin();
            itPlateforme != mapPlateformes.end(); itPlateforme++)
    {
        // Récupération de la plateforme
        const Plateforme& plateforme = itPlateforme->second;

        // Récupération du budget
        const Budget& budget = plateforme.getBudget();

        // Récupération de l'ensemble des monnaies
        const MapNomsMonnaies& mapMonnaies = budget.getMapMonnaies();

        // Boucle sur les monnaies
        for (MapNomsMonnaies::const_iterator itMonnaie = mapMonnaies.begin();
                itMonnaie != mapMonnaies.end(); itMonnaie++)
        {
            // Récupération de la monnaie
            const Monnaie& monnaie = itMonnaie->second;

            // Considération de la monnaie et ajout au budget total
            const std::string& nomMonnaie = monnaie.getDevise().getNom();
            if (!budgetTotal.hasMonnaie(nomMonnaie))
            {
                budgetTotal.ajouterMonnaie(nomMonnaie, Monnaie(nomMonnaie, 0.0));
            }
            PtrMonnaie monnaieTotale = const_cast<PtrMonnaie>(budgetTotal.getMonnaie(nomMonnaie));
            monnaieTotale->setQuantite(monnaieTotale->getQuantite() + monnaie.getQuantite());
        }
    }

    // Récupération du nombre de plateformes
    const int nbPlateformes = static_cast<int>(mapPlateformes.size());

    // Récupération de l'ensemble des monnaies
    const MapNomsMonnaies& mapMonnaiesTotales = budgetTotal.getMapMonnaies();

    // Boucle sur les monnaies
    for (MapNomsMonnaies::const_iterator itMonnaieTotale = mapMonnaiesTotales.begin();
            itMonnaieTotale != mapMonnaiesTotales.end(); itMonnaieTotale++)
    {
        // Récupération de la monnaie
        PtrMonnaie monnaieTotale = const_cast<PtrMonnaie>(&itMonnaieTotale->second);

        // Considération de la monnaie et équilibrage selon le budget total et le nombre de plateformes
        monnaieTotale->setQuantite(monnaieTotale->getQuantite() / nbPlateformes);
    }

    // Boucle sur les plateformes
    for (MapNomsPlateformes::const_iterator itPlateforme = mapPlateformes.begin();
            itPlateforme != mapPlateformes.end(); itPlateforme++)
    {
        // Récupération de la plateforme
        PtrPlateforme plateforme = const_cast<PtrPlateforme>(&itPlateforme->second);

        // Actualisation du budget
        plateforme->setBudget(budgetTotal);
    }
}
