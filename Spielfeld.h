/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Spielfeld.h
 * Author: snbl
 *
 * Created on February 13, 2018, 4:37 PM
 */

#ifndef SPIELFELD_H
#define SPIELFELD_H
#include "Schiff.h"
#include <vector>

class Spielfeld {
public:
    Spielfeld();
    ~Spielfeld();
    void ausgeben();
    void spielen();
private:
    char** leinwand;
    std::vector<Schiff> schiffe;
};

int get_int();
void clear_int_stream();

#endif /* SPIELFELD_H */

