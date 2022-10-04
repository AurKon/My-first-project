#include "strukt.h"
using namespace std;

unsigned int zodziai(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}

void skaitymas (vector<duom>& V, int* nd)
{

    int temp;
    int stud = 0;
    string buff;
    ifstream fr;
    try
    {
        fr.open("kursiokai.txt");
        if(!fr)
            throw std::runtime_error("FAILAS NERASTAS!");
            getline(fr >> std::ws, buff);
            *nd = zodziai(buff) - 3;
            while(true)
            {
                V.resize(V.size()+1);
                fr >> V.at(stud).vard;
                if(fr.eof())
                {
                    V.pop_back();
                    break;
                }
                fr >> V.at(stud).pav;
                for(int i=0; i<*nd; i++)
                {
                    fr >> temp;
                    V.at(stud).ndrez.push_back(temp);
                }
                fr >> V.at(stud).egz;
                stud += 1;
            }
            fr.close();
    }
    catch(int e){}
}

void ivedimas(vector<duom>& V, int n)
{
    int temp; //vieno namu darbo rezultatas
    for(int i=0; i<n; i++)
    {
        V.resize(V.size()+1);
        cout << "Iveskite studento varda: ";
        cin >> V[i].vard;
        cout << "Iveskite studento pavarde: ";
        cin >> V[i].pav;
        char tipas;
        cout << "Ar pazymius irasysite patys ar juos parinkti atsitiktinai? P/A: " << endl;
        cin >> tipas;
        if(tipas=='P' || tipas=='p')
        {
            cout << "Iveskite studento egzamino rezultata: ";
            cin >> V[i].egz;
            while(true) // ivesti arba randominiai skaiciai sukeliami i vektoriaus pabaiga
            {
                cout << "Iveskite namu darbo pazymi, jeigu daugiau pazymiu nera, iveskite 0: " << endl;
                cin >> temp;
                if(temp == 0)
                {
                    break;
                }
                V[i].ndrez.push_back(temp);
            }
            if(V[i].ndrez.size()<1)
            {
                cout << "Studentas neturi nei vieno namu darbu pazymio" << endl;
            }
        }
        else if(tipas=='A' || tipas=='a')
        {
            int kiek;
            cout<<"Kiek sugeneruoti nd pazymiu?: ";
            cin>>kiek;
            cout<<"Sugeneruoti nd pazymiai: ";
            for(int z=0; z<kiek; z++)
            {
                V[i].ndrez.push_back(rand()%10+1);
                cout<<V[i].ndrez[z]<<" ";
            }
            cout<<endl;
            cout<<"Sugeneruotas egzamino pazymys: ";
            V[i].egz=1+std::rand()%10;
            cout<<V[i].egz<<endl;
        }
        else //programos stabdymas, jei ivesties formatas neteisingas
        {
            cout<<"KLAIDA IVEDIME!!!"<<endl;
            return;
        }
    }
}
double vidurkis(double ndsum, int m) // vidurkio funkcija
{
    double vid;
    vid = ndsum/m;
    if(m==0)
    {
        vid = 0;
    }
    return vid;
}
double mediana(duom V, int n){ // medianos funkcija
    double med;
    if(V.ndrez.size()==0)
    {
        med=0;
    }
    else
    {
        if(V.ndrez.size()%2==0)
        {
            int k = V.ndrez.size()/2;
            med=(V.ndrez[k]+V.ndrez[k-1])/2.0;
        }
        else
        {
            med = V.ndrez[V.ndrez.size()/2];
        }
    }
    return med;
}
double rezultatas(double a, double b)
{
    double gpaz;
    gpaz = (0.4*a)+(0.6*b);
    return gpaz;
}
void isvedimas(vector<duom> V, int n)
{
    cout << left << setw(15) << "Vardas" << left << setw(15) << "pavarde" << left
    << setw(15) <<"Galutinis (Vid.)" << " / " << setw(15) << "Galutinis (Med.)" << endl;
    for(int k=0; k<60; k++)
    {
        cout << "_";
    }
    cout << endl;
    for(int i=0; i<n; i++)
    {
        double sum; // vektoriaus elementu suma
        sum = accumulate(V[i].ndrez.begin(), V[i].ndrez.end(), 0);
        sort(V[i].ndrez.begin(), V[i].ndrez.end());
        cout << left << setw(15) << V[i].vard << left << setw(15) << V[i].pav
        << left << setw(15) << fixed << setprecision(2) << rezultatas(vidurkis(sum, V[i].ndrez.size()), V[i].egz)
        << left << setw(15) << rezultatas(mediana(V[i], V[i].ndrez.size()), V[i].egz) << endl;
    }
}
void fisvedimas(vector<duom> V, int nd)
{
    ofstream fd;
    fd.open("rezultatai.txt");
    fd << left << setw(17) << "Vardas" << left << setw(17) << "Pavarde"
        << left << setw(22) << "Galutinis(vid.)/" << left << setw(22)
        << "Galutinis(med.)\n" << endl;
    for(int k=0; k<70; k++)
    {
        fd << "_" ;
    }
    fd << endl;
    for(int i=0; i<V.size(); i++)
    {
        double sum; // vektoriaus elementu suma
        sum = accumulate(V[i].ndrez.begin(), V[i].ndrez.end(), 0);
        sort(V[i].ndrez.begin(), V[i].ndrez.end());
        fd << left << setw(17) << V[i].vard << left << setw(17) << V[i].pav
            <<left << setw(22) << fixed << setprecision(2) << rezultatas(vidurkis(sum, V[i].ndrez.size()), V[i].egz)
            << left << setw(22) << fixed << setprecision(2) << rezultatas(mediana(V[i], V[i].ndrez.size()), V[i].egz) << endl;
    }
    fd.close();
}
