# v1.0
## Naudojimosi instrukcija

Skirtingos versijos:

1. Duomenu vedimas ranka (v0.1)
2. Duomenu skaitymas is failo(v0.2)
3. Failu generavimas(v0.3)
4. std::vector ir std::list spartos palyginimas(v0.4)

Paleidus programą vartotojas gaus sąrašą įmanomų funkcijų:
- Vartotojui pateikiami pasirinkimai: (F/G/P) - čia "F" arba "f" - duomenis skaityti iš failo, "G" arba "g" - duomenis sugeneruoti, "P" arba "p" - duomenis ivesite patys.
- Pasirinkus duomenis įvesti rankiniu būdu, galima rinktis, ar pažymius generuoti atsitiktinai, ar vesti ranka, bei ar galutinį balą išvesti pagal vidurkį, ar pagal medianą.
- Pasirinkus duomenis skaityti iš failo, rezultatai bus pateikiami rezultatų faile
- Pasirinkus generuoti failus, reikia įvesti norimą duomenų skaičių.

## v0.1

Šioje programoje vartotojas įrašo studentų duomenis: vardą, pavardę, pažymių skaičių, pačius pažymius ir egzamino rezultatą. Vartotojas taip pat gali pasirinkti pažymius generuoti atsitiktinai, įvesdamas, kiek pažymių nori, kad programa sugeneruotų. Toliau vartorojui pateikiamas pasirinkimas, ar jis nori įvesti daugiau studentų duomenų, ar ne. Paskui vartotojui pateikiamas pasirinkimas, kaip skaičiuoti galutinį rezultatą - naudojant vidurkį ar medianą. Vartotojui pasirinkus, programa apskaičiuoja galutinį rezultatą ir išveda jį į ekraną su atitinkamų studentų vardais ir pavardėmis. Programa realizuota naudojant du skirtingus konteinerių tipus: vektorius ir dinaminius masyvus.

Pastaba: masyvo kode nėra taisyklingai panaudoti dinaminiai masyvai

## v0.2

Toliau programą kuriame naudojant tik vektoriaus tipo konteinerį. Šioje versijoje v0.1 papildome galimybe studentų duomenis nuskaityti iš failo. Toliau atliekami veiksmai - studentų galutinio rezultato suskaičiavimas naudojant vidurkį ir medianą. Gauti rezultatai tuomet yra išrašomi į naują failą.

Programos pakeitimai: funkcijų ir main failai iškelti į atskirus .cpp failus, o struktūra - į .h failą.

## v0.3

Šioje versijoje papildome v0.2 versiją galimybe studentų duomenų failą generuoti atsitiktinai. Generuojami 1000, 10000, 100000, 1000000, 10000000 įrašų failai, priklausomai nuo vartotojo pasirinkimo. Suskaičiavus galutinį rezultatą, studentai yra išskirstomi į dvi grupes: moksliukai(galutinis >= 5) ir vargšiukai (galutinis < 5). Galiausiai, šios dvi grupės yra įrašomos į du naujus failus.

Programa taip pat atlieka laiko matavimą failų generavimui, nuskaitymui, išskirstymui bei įrašymui į failus. Žemiau pateikti laiko matavimo rezultatai kiekvienam duomenų kiekiui.

![image](https://user-images.githubusercontent.com/113659762/211027105-93744cfd-7591-49f1-abbf-0c27d74371f1.png)


![image](https://user-images.githubusercontent.com/113659762/211027125-b293a86a-b7f2-45d8-9102-ccf904ecda97.png)


![image](https://user-images.githubusercontent.com/113659762/211027194-4c23421d-45be-478f-bc56-26a6cb2e3c65.png)


![image](https://user-images.githubusercontent.com/113659762/211027223-2bdec387-2d15-49ca-9c79-7c4d8190d7c6.png)


![image](https://user-images.githubusercontent.com/113659762/211027263-262cba21-34ba-486a-9eac-8eea2e9d25ce.png)



## v0.4

v0.3 versiją papildome funkcijomis naudojant list konteinerį bei išmatuojame jo veikimo spartą ir vartotojui pateikiame std::vector ir std::list funkciju veikimo greičius.

Intel(R) Core(TM) i5-1035GZ CPU @ 1.20GHz, 1498Mhz; RAM 8.00 GB; HDD 236 GB;

Su 1000 eilučių: Duomenų nuskaitymas su vektorium užtruko: 0.015618 s Duomenų nuskaitymas su list'u užtruko: 0.0003683 s Duomenų išvedimas į du skirtingus failus su vektoriumi užtruko: 0.0156333 s Duomenų išvedimas į du skirtingus failus su list'u užtruko: 0.0022476 s

Su 10000 eilučių: Duomenų nuskaitymas su vektorium užtruko: 0.0312051 s Duomenų nuskaitymas su list'u užtruko: 0.0161727 s Duomenų išvedimas į du skirtingus failus su vektoriumi užtruko: 0.0625792 s Duomenų išvedimas į du skirtingus failus su list'u užtruko: 0.0638511 s

Su 100000 eilučių: Duomenų nuskaitymas su vektorium užtruko: 0.210861 s Duomenų nuskaitymas su list'u užtruko: 0.22001 s Duomenų išvedimas į du skirtingus failus su vektoriumi užtruko: 0.549691 s Duomenų išvedimas į du skirtingus failus su list'u užtruko: 0.616607 s

Su 1000000 eilučių: Duomenų nuskaitymas su vektorium užtruko: 2.45574 s Duomenų nuskaitymas su list'u užtruko: 2.57127 s Duomenų išvedimas į du skirtingus failus su vektoriumi užtruko: 5.33869 s Duomenų išvedimas į du skirtingus failus su list'u užtruko: 5.54181 s

Su 10000000 eilučių: Duomenų nuskaitymas su vektorium užtruko: 24.7279 s Duomenų nuskaitymas su list'u užtruko: 24.3002 s Duomenų išvedimas į du skirtingus failus su vektoriumi užtruko: 58.0161 s Duomenų išvedimas į du skirtingus failus su list'u užtruko: 57.9788 s
