/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Schiff.h
 * Author: snbl
 *
 * Created on February 13, 2018, 3:56 PM
 */

#ifndef SCHIFF_H
#define SCHIFF_H
#include <vector>

enum Status {
    UNBESCHAEDIGT, GETROFFEN, VERSENKT
};

enum Ausrichtung {
    NORD, OST, SUED, WEST
};

class Schiffteil {
public:
    Schiffteil(int reihe, int spalte, Status status);
    ~Schiffteil();
    const int getReihe() const;
    const int getSpalte() const;
    const Status getStatus() const;
    void setStatus(Status);

private:
    int m_reihe;
    int m_spalte;
    Status m_status;
};

class Schiff {
public:
    Schiff(int reihe, int spalte, int laenge, Ausrichtung ausrichtung);
    ~Schiff();
    const Status getStatus() const;
    bool belegt(int reihe, int spalte);
    bool beschuss(int reihe, int spalte);
    void zeichne(char**);
private:
    int m_laenge;
    std::vector<Schiffteil> schiffteile;

};

#endif /* SCHIFF_H */

