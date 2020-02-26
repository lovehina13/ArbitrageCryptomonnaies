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
    Cours();
    Cours(const int& date, const double& valeurAchat, const double& valeurVente,
            const double& quantiteAchat, const double& quantiteVente);
    Cours(const Cours& cours);
    virtual ~Cours();

    // Opérateurs
    Cours& operator=(const Cours& cours);
    bool operator==(const Cours& cours) const;
    bool operator!=(const Cours& cours) const;

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
    void copy(const Cours& cours);
    bool equals(const Cours& cours) const;
    void fromString(const std::string& fromString, const char& sep);
    const std::string toString(const char& sep) const;

private:
    // Membres de classe
    int m_date;
    double m_valeurAchat;
    double m_valeurVente;
    double m_quantiteAchat;
    double m_quantiteVente;
};

typedef Cours* PtrCours;
typedef std::vector<Cours> ListeCours;
typedef std::vector<PtrCours> ListePtrCours;
typedef std::map<int, Cours> MapIdCours;
typedef std::map<int, PtrCours> MapIdPtrCours;
typedef std::map<std::string, Cours> MapNomsCours;
typedef std::map<std::string, PtrCours> MapNomsPtrCours;

#endif // COURS_H
