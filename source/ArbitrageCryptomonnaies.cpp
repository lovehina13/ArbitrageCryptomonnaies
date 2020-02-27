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
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main()
{
    Projet projet;

    ListeDevises devisesReelles;
    devisesReelles.push_back(Devise("USD"));

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
            const Devise& deviseReelle = *itDeviseReelle;
            const Devise& deviseNumerique = *itDeviseNumerique;
            const std::string nomEchange = deviseReelle.getNom() + "/" + deviseNumerique.getNom();
            const Echange echange = Echange(deviseNumerique, deviseReelle, 0.0, 0.0, 0.002, 0.002,
                    MapIdCours());
            mapEchanges.insert(std::pair<std::string, Echange>(nomEchange, echange));
        }
    }

    Budget budget;
    for (ListeDevises::const_iterator itDeviseReelle = devisesReelles.begin();
            itDeviseReelle != devisesReelles.end(); itDeviseReelle++)
    {
        const Devise& deviseReelle = *itDeviseReelle;
        const Monnaie monnaieReelle = Monnaie(deviseReelle, 0.0);
        budget.ajouterMonnaie(deviseReelle.getNom(), monnaieReelle);
    }
    for (ListeDevises::const_iterator itDeviseNumerique = devisesNumeriques.begin();
            itDeviseNumerique != devisesNumeriques.end(); itDeviseNumerique++)
    {
        const Devise& deviseNumerique = *itDeviseNumerique;
        const Monnaie monnaieNumerique = Monnaie(deviseNumerique, 0.0);
        budget.ajouterMonnaie(deviseNumerique.getNom(), monnaieNumerique);
    }

    CPtrClient client_1 = new Client();
    CPtrClient client_2 = new Client();
    Plateforme plateforme_1 = Plateforme("Plateforme_1", mapEchanges, budget, client_1);
    Plateforme plateforme_2 = Plateforme("Plateforme_2", mapEchanges, budget, client_2);
    projet.ajouterPlateforme(plateforme_1.getNom(), plateforme_1);
    projet.ajouterPlateforme(plateforme_2.getNom(), plateforme_2);

    double beneficeNetCumule = 0.0;
    const int nombreCoursMaximal = 60;
    const double beneficeNetMinimal = 0.0;
    const double ratioBeneficeNetMinimal = 0.0;
    for (int date = 1; date <= nombreCoursMaximal; date++)
    {
        std::cout << "==================== Date " << date << " ====================" << std::endl;
        const std::chrono::time_point<std::chrono::system_clock> start =
                std::chrono::system_clock::now();
        projet.effacerNombreCours(nombreCoursMaximal);
        projet.recupererCours(date);
        const Transaction transaction = projet.getTransactionOptimale(date, beneficeNetMinimal,
                ratioBeneficeNetMinimal);
        if (transaction.isSet())
        {
            beneficeNetCumule += transaction.getBeneficeNet();
            std::cout << transaction.getTexteSynthese();
            std::cout << "Bénéfice net cumulé: " << beneficeNetCumule << std::endl;
            projet.actualiserBudgets(transaction);
            projet.equilibrerBudgets(transaction);
        }
        const std::chrono::time_point<std::chrono::system_clock> stop =
                std::chrono::system_clock::now();
        const int elapsed = static_cast<int>(std::chrono::duration_cast<std::chrono::microseconds>(
                stop - start).count());
        std::cout << "Temps traitement: " << elapsed << " microsecondes" << std::endl;
    }

    delete client_1;
    delete client_2;

    return EXIT_SUCCESS;
}
