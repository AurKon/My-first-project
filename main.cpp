#include "strukt.h"

int main()
{
    int n; //studentu skaicius
    int nd; //namu darbu pazymys
    char tipas;
    std::vector<duom> D; // vektoriaus struktura
    std::cout << "Pasirinkite, ar duomenis skaityti is failo, ar ivedinesite patys? F/P: ";
    std::cin >> tipas;
    std::cout << std::endl;
    if(tipas=='F' || tipas=='f')
    {
        skaitymas(D, &nd);
        fisvedimas(D, nd);
    }
    else if(tipas=='P' || tipas=='p')
    {
        std::cout << "Iveskite studentu skaiciu: ";
        std::cin >> n;
        ivedimas(D, n);
        isvedimas(D, n);
    }
    else //programos stabdymas, jei ivesties formatas neteisingas
    {
        std::cout<<"KLAIDA IVEDIME!!!"<<std::endl;
        return(0);
    }
    return 0;
}
