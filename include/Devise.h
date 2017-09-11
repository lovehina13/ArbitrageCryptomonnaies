//==============================================================================
// Name        : Devise.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Header file of the Devise class
//==============================================================================

#ifndef DEVISE_H
#define DEVISE_H

#include <map>
#include <string>
#include <vector>

class Devise
{
public:
    // Constructeurs et destructeurs
    Devise();
    Devise(const std::string& nom);
    Devise(const Devise& devise);
    virtual ~Devise();

    // Getters
    const std::string& getNom() const;

    // Setters
    void setNom(const std::string& nom);

    // Méthodes génériques
    void clear();
    void set(const std::string& nom);
    void copy(const Devise& devise);
    bool equals(const Devise& devise) const;
    void fromString(const std::string& fromString, const char& sep);
    const std::string toString(const char& sep) const;

    // Méthodes spécifiques (opérateurs)
    bool operator==(const Devise& devise) const;
    bool operator!=(const Devise& devise) const;

private:
    // Membres de classe
    std::string m_nom;
};

typedef Devise* PtrDevise;
typedef std::vector<Devise> ListeDevises;
typedef std::vector<PtrDevise> ListePtrDevises;
typedef std::map<int, Devise> MapIdDevises;
typedef std::map<int, PtrDevise> MapIdPtrDevises;
typedef std::map<std::string, Devise> MapNomsDevises;
typedef std::map<std::string, PtrDevise> MapNomsPtrDevises;

#endif // DEVISE_H
