#ifndef STRUKT_H_INCLUDED
#define STRUKT_H_INCLUDED
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <iterator>
#include <cstdio>
#include <iterator>
#include <chrono>

struct duom
{
    std::string vard; //studento vardas
    std::string pav; //studento pavarde
    int egz; // egzamino pazymys
    std::vector<int> ndrez;// namu darbu pazymiai
};
unsigned int zodziai(std::string const& str); //zodziu skaiciavimas
void fskaitymas(std::vector<duom>& V, int* nd, int tempn); //duomenu nuskaityvmas is failo
void ivedimas(std::vector<duom>& V, int n); //duomenu ivedimas ranka
double vidurkis(double ndsum, int n); //vidurkio radimas
double mediana(duom V, int n); //medianos radimas
double rezultatas(double a, double b); //galutinio rezultato radimas
void isvedimas(std::vector<duom> V, int n); //isvedimas i ekrana
void fisvedimas(std::vector<duom> V, int nd, int tempn); //isvedimas i faila

int pazymiogen(); //random pazymio generavimas
void failogen(std::vector<duom>& V, int tempn); //failo generavimas

#endif
