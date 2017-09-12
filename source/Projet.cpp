//==============================================================================
// Name        : Projet.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Projet class
//==============================================================================

#include "Projet.h"

Projet::Projet()
{
    this->clear();
}

Projet::Projet(const MapNomsPlateformes& mapPlateformes) :
        Projet()
{
    this->set(mapPlateformes);
}

Projet::Projet(const Projet& projet) :
        Projet()
{
    this->copy(projet);
}

Projet::~Projet()
{

}

const MapNomsPlateformes& Projet::getMapPlateformes() const
{
    return this->m_mapPlateformes;
}

void Projet::setMapPlateformes(const MapNomsPlateformes& mapPlateformes)
{
    this->m_mapPlateformes = mapPlateformes;
}

void Projet::clear()
{
    this->set(MapNomsPlateformes());
}

void Projet::set(const MapNomsPlateformes& mapPlateformes)
{
    this->setMapPlateformes(mapPlateformes);
}

void Projet::copy(const Projet& projet)
{
    this->set(projet.getMapPlateformes());
}

bool Projet::equals(const Projet& projet) const
{
    if (this->getMapPlateformes() != projet.getMapPlateformes())
        return false;
    return true;
}

void Projet::fromString(const std::string& fromString, const char& sep)
{
    // TODO void Projet::fromString(const std::string& fromString, const char& sep)
    // TODO #warning "'void Projet::fromString(const std::string& fromString, const char& sep)' not implemented"
}

const std::string Projet::toString(const char& sep) const
{
    // TODO const std::string Projet::toString(const char& sep) const
    // TODO #warning "'const std::string Projet::toString(const char& sep) const' not implemented"
    return std::string();
}

bool Projet::operator==(const Projet& projet) const
{
    return this->equals(projet);
}

bool Projet::operator!=(const Projet& projet) const
{
    return !(this->equals(projet));
}

bool Projet::hasPlateforme(const std::string& nom) const
{
    return (this->m_mapPlateformes.find(nom) != this->m_mapPlateformes.end());
}

PtrPlateforme Projet::getPlateforme(const std::string& nom) const
{
    return (this->hasPlateforme(nom) ? (PtrPlateforme) &(this->m_mapPlateformes.find(nom)->second) :
    NULL);
}

bool Projet::ajouterPlateforme(const std::string& nom, const MapNomsEchanges& mapEchanges,
        const Budget& budget)
{
    if (this->hasPlateforme(nom))
        return false;
    this->m_mapPlateformes.insert(
            std::pair<std::string, Plateforme>(nom, Plateforme(nom, mapEchanges, budget)));
    return true;
}

bool Projet::supprimerPlateforme(const std::string& nom)
{
    if (!this->hasPlateforme(nom))
        return false;
    this->m_mapPlateformes.erase(nom);
    return true;
}

Transaction Projet::getTransactionOptimale(const int& date)
{
    Transaction transactionOptimale;

    // Récupération de l'ensemble des plateformes de source et de destination
    const MapNomsPlateformes mapPlateformesSource = this->m_mapPlateformes;
    const MapNomsPlateformes mapPlateformesDestination = this->m_mapPlateformes;

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
                    const PtrCours coursSource = echangeSource.getCours(date);
                    const PtrCours coursDestination = echangeDestination.getCours(date);

                    // Considération des cours de source et de destination s'ils existent
                    if (coursSource == NULL || coursDestination == NULL)
                        continue;

                    // Définition de la transaction
                    Transaction transaction = Transaction((PtrPlateforme) &plateformeSource,
                            (PtrPlateforme) &plateformeDestination, (PtrEchange) &echangeSource,
                            (PtrEchange) &echangeDestination, (PtrCours) &coursSource,
                            (PtrCours) &coursDestination, date);

                    // Considération de la transaction comme optimale si le bénéfice net est plus élevé
                    if (transaction.getBeneficeNet() > transactionOptimale.getBeneficeNet())
                    {
                        transactionOptimale = transaction;
                    }
                }
            }
        }
    }

    return transactionOptimale;
}
