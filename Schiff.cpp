/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Schiff.cpp
 * Author: snbl
 * 
 * Created on February 13, 2018, 3:56 PM
 */

#include "Schiff.h"

Schiffteil::Schiffteil(int reihe, int spalte, Status status) : m_reihe{reihe}, m_spalte{spalte}, m_status{status}
{
}

Schiffteil::~Schiffteil() {
}

const int Schiffteil::getReihe() const {
    return m_reihe;
}

const int Schiffteil::getSpalte() const {
    return m_spalte;
}

const Status Schiffteil::getStatus() const {
    return m_status;
}

void Schiffteil::setStatus(Status status) {
    m_status = status;
}


Schiff::Schiff(int reihe, int spalte, int laenge, Ausrichtung ausrichtung) : m_laenge{laenge}
{
    switch (ausrichtung) {
        case SUED:
            for (int i = 0; i < m_laenge; ++i) {
                schiffteile.push_back(Schiffteil(reihe + i, spalte, UNBESCHAEDIGT));
            }
            break;
        case NORD:
            for (int i = 0; i < m_laenge; ++i) {
                schiffteile.push_back(Schiffteil(reihe - i, spalte, UNBESCHAEDIGT));
            }
            break;
        case OST:
            for (int i = 0; i < m_laenge; ++i) {
                schiffteile.push_back(Schiffteil(reihe, spalte + i, UNBESCHAEDIGT));
            }
            break;
        case WEST:
            for (int i = 0; i < m_laenge; ++i) {
                schiffteile.push_back(Schiffteil(reihe, spalte - i, UNBESCHAEDIGT));
            }
            break;
    }
}

Schiff::~Schiff() {
}

const Status Schiff::getStatus() const {
    int hitCount = 0;
    for (int i = 0; i < m_laenge; ++i) {
        if (schiffteile[i].getStatus() == GETROFFEN) ++hitCount;
    }
    if (hitCount == m_laenge) return VERSENKT;
    else if (hitCount > 0) return GETROFFEN;
    return UNBESCHAEDIGT;
}

bool Schiff::belegt(int reihe, int spalte) {
    for (int i = 0; i < m_laenge; ++i) {
        if (reihe == schiffteile[i].getReihe() && spalte == schiffteile[i].getSpalte()) return true;
    }
    return false;
}

bool Schiff::beschuss(int reihe, int spalte) {
    for (int i = 0; i < m_laenge; ++i) {
        if (schiffteile[i].getStatus() == UNBESCHAEDIGT && schiffteile[i].getReihe() == reihe && schiffteile[i].getSpalte() == spalte) {
            schiffteile[i].setStatus(GETROFFEN);
        }
    }
    if (getStatus() == VERSENKT) return true;
    return false;
}

void Schiff::zeichne(char** field) {
    for (int i = 0; i < m_laenge; ++i) {
        field[schiffteile[i].getReihe()][schiffteile[i].getSpalte()] = '#';
    }
}