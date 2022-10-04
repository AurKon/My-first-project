#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <iterator>
#include <cstdio>

struct duom
{
    std::string vard; //studento vardas
    std::string pav; //studento pavarde
    int egz; // egzamino pazymys
    std::vector<int> ndrez;// namu darbu pazymiai
};
unsigned int zodziai(std::string const& str); //zodziu skaiciavimas
void skaitymas(std::vector<duom>& V, int* nd); //duomenu nuskaityvmas is failo
void ivedimas(std::vector<duom>& V, int n); //duomenu ivedimas ranka
double vidurkis(double ndsum, int m); //vidurkio radimas
double mediana(duom V, int n); //medianos radimas
double rezultatas(double a, double b); //galutinio rezultato radimas
void isvedimas(std::vector<duom> V, int n); //isvedimas i ekrana
void fisvedimas(std::vector<duom> V, int nd); //isvedimas i faila
