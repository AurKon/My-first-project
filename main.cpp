#include "strukt.h"

int main()
{
    int n; //studentu skaicius
    int nd; //namu darbu pazymys
    int tempn;
    char tipas;
    std::list<duom> D; // vektoriaus struktura
    std::cout << "Pasirinkite, ar duomenis skaityti is failo(F), ar ivedinesite patys(P), ar juos sugeneruoti automatiskai(G)? F/P/G: ";
    std::cin >> tipas;
    std::cout << std::endl;
    if(tipas=='F' || tipas=='f')
    {
        fskaitymas(D, &nd, tempn);
        fisvedimas(D, nd);
    }
    else if(tipas=='P' || tipas=='p')
    {
        std::cout << "Iveskite studentu skaiciu: ";
        std::cin >> n;
        ivedimas(D, n);
        isvedimas(D, n);
    }
    else if(tipas=='G' || tipas=='g')
    {
        std::cout << "Iveskite studentu skaiciu: ";
        std::cin >> tempn;
        failogen(D, tempn);
        fskaitymas(D, &nd, tempn);
        fisvedimas(D, nd);
    }
    else //programos stabdymas, jei ivesties formatas neteisingas
    {
        std::cout<<"KLAIDA IVEDIME!!!"<<std::endl;
        return(0);
    }
    return 0;
}
