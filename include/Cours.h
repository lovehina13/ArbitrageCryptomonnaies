//==============================================================================
// Name        : Cours.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Header file of the Cours class
//==============================================================================

#ifndef COURS_H
#define COURS_H

#include <map>
#include <string>
#include <vector>

class Cours
{
public:
    // Constructeurs et destructeurs
    Cours() = default;
    Cours(const int& date, const double& valeurAchat, const double& valeurVente,
            const double& quantiteAchat, const double& quantiteVente);

    // Opérateurs
    bool operator==(const Cours& cours) const = default;
    bool operator!=(const Cours& cours) const = default;

    // Getters
    const int& getDate() const;
    const double& getValeurAchat() const;
    const double& getValeurVente() const;
    const double& getQuantiteAchat() const;
    const double& getQuantiteVente() const;

    // Setters
    void setDate(const int& date);
    void setValeurAchat(const double& valeurAchat);
    void setValeurVente(const double& valeurVente);
    void setQuantiteAchat(const double& quantiteAchat);
    void setQuantiteVente(const double& quantiteVente);

    // Méthodes génériques
    void clear();
    void set(const int& date, const double& valeurAchat, const double& valeurVente,
            const double& quantiteAchat, const double& quantiteVente);
    void fromString(const std::string& fromString, const char& sep);
    const std::string toString(const char& sep) const;

private:
    // Membres de classe
    int _date { 0 };
    double _valeurAchat { 0.0 };
    double _valeurVente { 0.0 };
    double _quantiteAchat { 0.0 };
    double _quantiteVente { 0.0 };
};

using PtrCours = Cours*;
using CPtrCours = const Cours*;
using ListeCours = std::vector<Cours>;
using ListePtrCours = std::vector<PtrCours>;
using ListeCPtrCours = std::vector<CPtrCours>;
using MapIdCours = std::map<int, Cours>;
using MapIdPtrCours = std::map<int, PtrCours>;
using MapIdCPtrCours = std::map<int, CPtrCours>;
using MapNomsCours = std::map<std::string, Cours>;
using MapNomsPtrCours = std::map<std::string, PtrCours>;
using MapNomsCPtrCours = std::map<std::string, CPtrCours>;

#endif // COURS_H
