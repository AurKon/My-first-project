#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;
struct duom
{
    string var; //Vardas
    string pav; //Pavarde
    std::vector<int> v; //Vektorius pazymiams
    int ndnr; //Pazymiu skaicius
    int egz; //Egzamino pazymys
    double vid; //Pazymiu vidurkis
    double sum=0; //Pazymiu suma
    double med; //Pazymiu mediana
};
int main()
{
    int n=1; //zmoniu skaicius
    duom D[101]; //Struktura

    for(int i=0;i<n;i++) //Duomenu ivedimas
    {
        cout<<"Iveskite varda: "<<endl; //ivedamas vardas
        cin>>D[i].var;
        cout<<"Iveskite pavarde: "<<endl; //ivedama pavarde
        cin>>D[i].pav;
        cout<<"Iveskite savo namu darbu pazymius (ivedus visus iveskite 0): "<<endl; //ivedami visi reikalingi pazymiai, rasymas nutraukiams irasius '0'
        D[i].v.push_back(1);
        D[i].ndnr=1;
        for(int j=0;j<D[i].ndnr;j++) //ciklas pazymiu irasymui
        {
            D[i].v.push_back(n+1);
            cin>>D[i].v[j];
            if(D[i].v[j]>0 && D[i].v[j]<11) //tikrinimas, ar pazymio formatas teisingas
            {
                D[i].ndnr++;
            }
            else if(D[i].v[j]==0) //ciklo baigimas, jei ivedamas 0
            {
                D[i].v[j]=D[i].v[j];
            }
            else //programos stabdymas, jei pazymio formatas neteisingas
            {
                cout<<"KLAIDA IVEDIME!!!"<<endl;
                return(0);
            }
        }
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
        D[i].ndnr=D[i].ndnr-1; //pakoreguojami kintamieji, kad ivestas '0 nesiskaitytu kaip pazymys'
        D[i].v.resize(D[i].ndnr);
        char ats;
        cout<<"Ar norite ivesti daugiau zmoniu? T/N"<<endl; //uzklausa, ar bus daugiau zmoniu duomenims
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

    for(int i=0;i<n;i++) //Rikiavimas
    {
        for(int j=0;j<D[i].ndnr-1;j++)
        {
            for(int y=j+1;y<D[i].ndnr;y++)
            {
                if(D[i].v[j]>D[i].v[y]){swap(D[i].v[j],D[i].v[y]);} //einant per sarasa po viena skaiciu tikriname kur jo vieta
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
            D[i].med=(D[i].v[D[i].ndnr/2]+D[i].v[(D[i].ndnr/2)-1]);
            D[i].med=D[i].med/2;
        }
        else //medianos skaiciavimas kai nelyginis pazymiu skaicius
        {
            D[i].med=D[i].v[(D[i].ndnr-1)/2];
        }

    }

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
                D[i].sum+=D[i].v[j]; //randama visu pazymiu suma
            }
            D[i].vid=D[i].sum/(D[i].v.size()); //vidurkio radimas
        }

    }

    ofstream fr("rez.txt"); //isvedimas i faila
    char ats;
    cout<<"Ar galutini rezultata pateikti mediana ar vidurkiu? M/V"<<endl; //uzklausa, ar rezultata pateikti mediana ar vidurkiu
    cin>>ats;
    if(ats=='M' || ats=='m') //Galutinis rezultatas su mediana
        {
            for(int i=0;i<n;i++)
            {
                fr<<D[i].var<<" "<<D[i].pav<<" | mediana: "<<fixed<<setprecision(2)<<D[i].med<<endl;
            }
        }
        else if(ats=='V' || ats=='v') //Galutinis rezultatas su vidurkiu
        {
            for(int i=0;i<n;i++)
            {
                fr<<D[i].var<<" "<<D[i].pav<<" | vidurkis: "<<fixed<<setprecision(2)<<D[i].vid<<endl;
            }
        }
        else //programos stabdymas, jei ivesties formatas neteisingas
        {
            cout<<"KLAIDA IVEDIME!!!"<<endl;
            return(0);
        }
    return 0;
}
