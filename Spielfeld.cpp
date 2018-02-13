/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Spielfeld.cpp
 * Author: snbl
 * 
 * Created on February 13, 2018, 4:37 PM
 */

#include "Spielfeld.h"
#include <iostream>
#include <iomanip>

using namespace std;

void clear_int_stream() {
    if (cin.fail()) {
        cin.clear();
        for (char ch; cin >> ch;)
            if (isdigit(ch)) {
                cin.unget();
                return;
            }
    }
}

int get_int(int size) {
    int input;
    while (true) {

        if (cin >> input && input <= size && input >= 0) return input;
        clear_int_stream();
    }
}

Spielfeld::Spielfeld() {
    leinwand = new char*[10];
    for (int i = 0; i < 10; ++i) {
        leinwand[i] = new char[10];
        for (int j = 0; j < 10; ++j) {
            leinwand[i][j] = '.';
        }
    }

    schiffe.push_back(Schiff(0, 0, 4, SUED));
    schiffe.push_back(Schiff(9, 8, 3, WEST));
    schiffe.push_back(Schiff(9, 0, 4, NORD));
    schiffe.push_back(Schiff(4, 5, 2, OST));
    schiffe.push_back(Schiff(5, 4, 2, SUED));
    for (int i = 0; i < schiffe.size(); ++i) {
        schiffe[i].zeichne(leinwand);
    }
}

Spielfeld::~Spielfeld() {
    for (int i = 0; i < 0; ++i) {
        delete[] leinwand[i];
    }
    delete[] leinwand;
}

void Spielfeld::ausgeben() {
    cout << setw(2) << " ";
    for (int i = 0; i < 10; ++i)
        cout << setw(2) << i;
    cout << "\n";
    for (int i = 0; i < 10; ++i) {
        cout << setw(2) << i;
        for (int j = 0; j < 10; ++j) {
            cout << setw(2) << leinwand[i][j];
        }
        cout << "\n";
    }
}

void Spielfeld::spielen() {
    int reihe, spalte;

    while (true) {

        ausgeben();

        int count = 0;
        bool treffer = false;

        cout << "Welche Position soll beschossen werden?\n"
                << "Reihe?\n>";
        reihe = get_int(10);
        cout << "Spalte?\n>";
        spalte = get_int(10);

        for (int i = 0; i < schiffe.size(); ++i) {
            if (schiffe[i].belegt(reihe, spalte)) {
                if (schiffe[i].beschuss(reihe, spalte)) {
                    cout << "Schiff versenkt!\n";
                }
                leinwand[reihe][spalte] = '%';
                treffer = true;
            }
        }
        if (!treffer) leinwand[reihe][spalte] = 'X';

        for (int i = 0; i < schiffe.size(); ++i) {
            if (schiffe[i].getStatus() == VERSENKT) ++count;
        }
        if (count == schiffe.size()) break;
    }
}