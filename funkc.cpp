#include "strukt.h"
#include <string>

using namespace std;

unsigned int zodziai(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}

void fskaitymas (std::list<duom>& V, int* nd, int tempn)
{

    auto start = std::chrono::high_resolution_clock::now();

    int temp;
    int stud = 0;
    string buff;
    ifstream r;
    string failas = "Studentai" + to_string(tempn)+".txt";
    try{
        r.open(failas);
        if(!r)
            throw std::runtime_error("Nepavyko rasti failo");

            getline(r >> std::ws, buff);
            *nd = zodziai(buff) - 3;
            while(true)
            {
                V.resize(V.size()+1);
                r >> V.at(stud).vard;
                if(r.eof())
                {
                    V.pop_back();
                    break;
                }
                r >> V.at(stud).pav;
                for(int i=0; i<*nd; i++)
                {
                    r >> temp;
                    //V.at(stud).ndrez.push_back(temp);
                }
                r >> V.at(stud).egz;
                stud += 1;
            }
            r.close();
    }
    catch(int e){}
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
	std::cout << "Duomenu nuskaitymas uztruko: " << diff.count() << " s\n";
}

void ivedimas(std::list<duom>& V, int n)
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
double vidurkis(double ndsum, int n) // vidurkio funkcija
{
    double vid;
    vid = ndsum/n;
    if(n==0)
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
    double rez;
    rez = (0.4*a)+(0.6*b);
    return rez;
}
void isvedimas(std::list<duom> V, int n)
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
void fisvedimas(std::list<duom> V, int nd)
{
    auto start1 = std::chrono::high_resolution_clock::now();
    ofstream w1, w2;
    w1.open("vargsiukai.txt");
    w2.open("kietiakai.txt");
    w1 << left << setw(17) << "Vardas" << left << setw(17) << "Pavarde"
        << left << setw(22) << "Galutinis(vid.)/" << left << setw(22)
        << "Galutinis(med.)\n";

    w2 << left << setw(17) << "Vardas" << left << setw(17) << "Pavarde"
        << left << setw(22) << "Galutinis(vid.)/" << left << setw(22)
        << "Galutinis(med.)\n";

    for(int i=0; i<70; i++)
    {
        w1 << "_" ;
        w2 << "_" ;
    }
    w1 << endl;
    w2 << endl;

    auto start = std::chrono::high_resolution_clock::now();

    for(int i=0; i<V.size(); i++)
    {
        double sum; // vektoriaus elementu suma
        sum = accumulate(V[i].ndrez.begin(), V[i].ndrez.end(), 0);
        sort(V[i].ndrez.begin(), V[i].ndrez.end());

        if(rezultatas(vidurkis(sum, V[i].ndrez.size()),V[i].egz)<5)
           {
                w1 << left << setw(17) << V[i].vard << left << setw(17) << V[i].pav
                    <<left << setw(22) << fixed << setprecision(2) << rezultatas(vidurkis(sum, V[i].ndrez.size()), V[i].egz)
                    << left << setw(22) << fixed << setprecision(2) << rezultatas(mediana(V[i], V[i].ndrez.size()), V[i].egz) << endl;
           }
           else
            {
                w2 << left << setw(17) << V[i].vard << left << setw(17) << V[i].pav
                    <<left << setw(22) << fixed << setprecision(2) << rezultatas(vidurkis(sum, V[i].ndrez.size()), V[i].egz)
                    << left << setw(22) << fixed << setprecision(2) << rezultatas(mediana(V[i], V[i].ndrez.size()), V[i].egz) << endl;
            }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Duomenu rusiavimas i dvi grupes uztruko: " << diff.count() << " s\n";

    w1.close();
    w2.close();
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;
    std::cout << "Isvedimas i du failus uztruko: " << diff1.count() << " s\n";
}

int pazymiogen()
{
	return rand()%10+1;
}

void failogen(std::list<duom>& V, int tempn)
{
    auto start = std::chrono::high_resolution_clock::now();

    int randsk;
    randsk = rand()% 3 + 3;
    string failas = "Studentai" + to_string(tempn)+".txt";
    ofstream w1(failas);
    w1 << setw(16) << left << "Vardas"
		<< setw(16) << left << "Pavarde";
    for(int n=0; n<randsk; n++)
    {
        w1 << setw(5) << "ND" + to_string(n+1);
    }
    w1 << "Egz." << endl;
    for (int j=0; j<tempn; j++)
    {
        w1 << setw(16) << "Vardas" + to_string(j+1)
			<< setw(16) << "Pavarde" + to_string(j+1);
        for(int k=0; k<randsk; k++)
        {
            w1 << setw(5) << pazymiogen();
        }
        w1 << setw(5) << pazymiogen() << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
	std::cout << "Failo su " + std::to_string(tempn) + " studentais kurimas uztruko: " << diff.count() << " s\n";
}


