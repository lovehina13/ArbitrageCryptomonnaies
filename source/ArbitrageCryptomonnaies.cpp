//==============================================================================
// Name        : ArbitrageCryptomonnaies.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Main file of the ArbitrageCryptomonnaies project
//==============================================================================

#include "Budget.h"
#include "Client.h"
#include "Cours.h"
#include "Devise.h"
#include "Echange.h"
#include "Monnaie.h"
#include "Plateforme.h"
#include "Projet.h"
#include "Transaction.h"

int main(int argc, char* argv[])
{
    Projet projet;

    ListeDevises devisesReelles;
    devisesReelles.push_back(Devise("USDT"));

    ListeDevises devisesNumeriques;
    devisesNumeriques.push_back(Devise("BTC"));
    devisesNumeriques.push_back(Devise("ETH"));
    devisesNumeriques.push_back(Devise("LTC"));
    devisesNumeriques.push_back(Devise("XRP"));

    MapNomsEchanges mapEchanges;
    for (ListeDevises::const_iterator itDeviseReelle = devisesReelles.begin();
            itDeviseReelle != devisesReelles.end(); itDeviseReelle++)
    {
        for (ListeDevises::const_iterator itDeviseNumerique = devisesNumeriques.begin();
                itDeviseNumerique != devisesNumeriques.end(); itDeviseNumerique++)
        {
            const Devise& deviseReelle = (*itDeviseReelle);
            const Devise& deviseNumerique = (*itDeviseNumerique);
            const std::string nomEchange = deviseReelle.getNom() + "/" + deviseNumerique.getNom();
            const Echange echange = Echange(deviseNumerique, deviseReelle, 0.0, 0.0, 0.0025, 0.0025,
                    MapIdCours());
            mapEchanges.insert(std::pair<std::string, Echange>(nomEchange, echange));
        }
    }

    Budget budget;
    for (ListeDevises::const_iterator itDeviseReelle = devisesReelles.begin();
            itDeviseReelle != devisesReelles.end(); itDeviseReelle++)
    {
        const Devise& deviseReelle = (*itDeviseReelle);
        const Monnaie monnaieReelle = Monnaie(deviseReelle, 0.0);
        budget.ajouterMonnaie(deviseReelle.getNom(), monnaieReelle);
    }
    for (ListeDevises::const_iterator itDeviseNumerique = devisesNumeriques.begin();
            itDeviseNumerique != devisesNumeriques.end(); itDeviseNumerique++)
    {
        const Devise& deviseNumerique = (*itDeviseNumerique);
        const Monnaie monnaieNumerique = Monnaie(deviseNumerique, 0.0);
        budget.ajouterMonnaie(deviseNumerique.getNom(), monnaieNumerique);
    }

    Plateforme plateforme_1 = Plateforme("Plateforme_1", mapEchanges, budget, new Client());
    Plateforme plateforme_2 = Plateforme("Plateforme_2", mapEchanges, budget, new Client());
    projet.ajouterPlateforme(plateforme_1.getNom(), plateforme_1);
    projet.ajouterPlateforme(plateforme_2.getNom(), plateforme_2);

    const int nombreCoursMaximal = 60;
    const double beneficeNetMinimal = 0.0;
    const double ratioBeneficeNetMinimal = 0.0;
    for (int date = 0; date < 60; date++)
    {
        projet.effacerNombreCours(nombreCoursMaximal);
        projet.recupererCours(date);
        const Transaction transaction = projet.getTransactionOptimale(date, beneficeNetMinimal,
                ratioBeneficeNetMinimal);
        if (!transaction.isSet())
            continue;
        projet.actualiserBudgets(transaction);
        projet.equilibrerBudgets(transaction);
    }

    return 0;
}
