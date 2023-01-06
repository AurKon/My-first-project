#include <iostream>
#include <iomanip>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::swap;
using std::setprecision;
using std::fixed;

struct duom
{
    string var; //Vardas
    string pav; //Pavarde
    double m[101]; //Masyvas pazymiams
    int ndnr; //Pazymiu skaicius
    int egz; //Egzamino pazymys
    double vid; //Pazymiu vidurkis
    double sum=0; //Pazymiu suma
    double med; //Pazymiu mediana
    char tip; //Pazymiu tipas (irasomas, atsitiktinis)
};
int main()
{
    int n=1; //pradinis zmoniu skaicius
    duom D[101]; //Struktura

    for(int i=0;i<n;i++) //Duomenu ivedimas
    {
        cout<<"Iveskite varda: "; //ivedamas vardas
        cin>>D[i].var;
        cout<<"Iveskite pavarde: "; //ivedama pavarde
        cin>>D[i].pav;
        cout<<"Ar pazymius irasysite patys ar juos parinkti atsitiktinai? P/A: ";
        cin>>D[i].tip;
        if(D[i].tip=='P' || D[i].tip=='p') //rankinis pazymiu ivedimas
        {
            cout<<"Iveskite savo namu darbu pazymius (ivedus visus iveskite 0): "<<endl; //ivedami visi reikalingi pazymiai, rasymas nutraukiams irasius '0'
            D[i].ndnr=1;
            for(int j=0;j<D[i].ndnr;j++) //ciklas pazymiu irasymui
            {
                cin>>D[i].m[j];
                if(D[i].m[j]>0 && D[i].m[j]<11) //tikrinimas, ar pazymio formatas teisingas
                {
                    D[i].ndnr++;
                }
                else if(D[i].m[j]==0) //ciklo baigimas, jei ivedamas 0
                {
                    D[i].m[j]=D[i].m[j];
                }
                else //programos stabdymas, jei pazymio formatas neteisingas
                {
                    cout<<"KLAIDA IVEDIME!!!"<<endl;
                    return(0);
                }
            }
            D[i].ndnr=D[i].ndnr-1; //pakoreguojami kintamieji, kad ivestas '0 nesiskaitytu kaip pazymys'
            cout<<"Iveskite egzamino pazymi: "<<endl; //egzamino pazymio irasymas
            cin>>D[i].egz;
            if(D[i].egz>=0 && D[i].egz<11) //tikrinimas, ar pazymio formatas teisingas
            {
                D[i].egz=D[i].egz;
            }
            else //programos stabdymas, jei pazymio formatas neteisingas
            {
                cout<<"KLAIDA IVEDIME!!!"<<endl;
                return(0);
            }
        }
        else if(D[i].tip=='A' || D[i].tip=='a') //atsitiktiniu pazymiu generavimas
        {
            cout<<"Atsitiktiniu pazymiu skaicius: ";
            cin>>D[i].ndnr;
            std::srand(time(0));
            cout<<"Sugeneruoti namu darbu pazymiai: ";
            for(int j=0;j<D[i].ndnr;j++)
            {
                D[i].m[j]=1+std::rand()%10;
                cout<<D[i].m[j]<<" ";
            }
            cout<<endl;
            cout<<"Sugeneruotas egzamino pazymys: ";
            D[i].egz=1+std::rand()%10;
            cout<<D[i].egz<<endl;
        }
        else //programos stabdymas, jei ivesties formatas neteisingas
        {
            cout<<"KLAIDA IVEDIME!!!"<<endl;
            return(0);
        }
        char ats;
        cout<<"Ar norite ivesti daugiau zmoniu? T/N: "; //uzklausa, ar bus daugiau zmoniu duomenims
        cin>>ats;
        if(ats=='T' || ats=='t') //teigiamas atsakymas
        {
            n++;
        }
        else if(ats=='N' || ats=='n') //neigiamas atsakymas
        {
            n=n;
        }
        else //programos stabdymas, jei ivesties formatas neteisingas
        {
            cout<<"KLAIDA IVEDIME!!!"<<endl;
            return(0);
        }
    }

    char ats;
    cout<<"Ar galutini rezultata pateikti mediana ar vidurkiu? M/V: "; //uzklausa, ar rezultata pateikti mediana ar vidurkiu
    cin>>ats;
    cout<<endl;
    if(ats=='M' || ats=='m') //Galutinis rezultatas su mediana
        {
            for(int i=0;i<n;i++) //Rikiavimas
            {
                for(int j=0;j<D[i].ndnr-1;j++)
                {
                    for(int y=j+1;y<D[i].ndnr;y++)
                    {
                        if(D[i].m[j]>D[i].m[y]){swap(D[i].m[j],D[i].m[y]);} //einant per sarasa po viena skaiciu tikriname kur jo vieta
                    }
                }
            }
            for(int i=0;i<n;i++) //Medianos skaiciavimas
            {
                if(D[i].ndnr==0) //isimties radimas
                {
                    D[i].med==0;
                }
                else if(D[i].ndnr%2==0) //medianos skaiciavimas kai lyginis pazymiu skaicius
                {
                    D[i].med=(D[i].m[D[i].ndnr/2]+D[i].m[(D[i].ndnr/2)-1]);
                    D[i].med=D[i].med/2;
                }
                else //medianos skaiciavimas kai nelyginis pazymiu skaicius
                {
                    D[i].med=D[i].m[(D[i].ndnr-1)/2];
                }
            }
            for(int i=0;i<n;i++)
            {
                cout<<D[i].var<<" "<<D[i].pav<<" | mediana: "<<fixed<<setprecision(2)<<D[i].med*0.4+D[i].egz*0.6<<endl;
            }
        }
        else if(ats=='V' || ats=='v') //Galutinis rezultatas su vidurkiu
        {
            for(int i=0;i<n;i++) //Vidurkio skaiciavimas
            {
                if(D[i].ndnr==0) //isimties radimas
                {
                    D[i].med==0;
                }
                else
                {
                    for(int j=0;j<D[i].ndnr;j++)
                    {
                        D[i].sum+=D[i].m[j]; //randama visu pazymiu suma
                    }
                    D[i].vid=D[i].sum/(D[i].ndnr); //vidurkio radimas
                }

            }
            for(int i=0;i<n;i++)
            {
                cout<<D[i].var<<" "<<D[i].pav<<" | vidurkis: "<<fixed<<setprecision(2)<<D[i].vid*0.4+D[i].egz*0.6<<endl;
            }
        }
        else //programos stabdymas, jei ivesties formatas neteisingas
        {
            cout<<"KLAIDA IVEDIME!!!"<<endl;
            return(0);
        }
    return 0;
}
