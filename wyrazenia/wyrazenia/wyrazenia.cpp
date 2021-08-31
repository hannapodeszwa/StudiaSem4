#include <iostream>
#include <regex>
#include <conio.h>

using namespace std;

int main()
{
    //zadanie 1

    const string examples[] = { "kura","k4ra" };
    const regex r1("k[A-z|0-9]+a");                 //a

    for (const auto& string : examples)
    {
        cout << string << ": " << regex_match(string, r1) << endl;
    }

    const string examples2[] = { "3424AR_","1999.ANI" };
    const regex r2("^([0-9]{4})[^a-z|^0-9]*");                 //b

    for (const auto& string : examples2)
    {
        cout << string << ": " << regex_match(string, r2) << endl;
    }

    const string examples3[] = { "hg34234AR_","1933399.ANI" };
    const regex r3(".*[0-9]{5,}.*");                 //c

    for (const auto& string : examples3)
    {
        cout << string << ": " << regex_match(string, r3) << endl;
    }

    //zadanie 2

    const string examples4[] = { "Andrzej_Bulka@polsl.pl",
"Bozena_Kajzerka@polsl.pl",
"Adam_Chlebek@.pl",
"Jerzy_Bagieta@polslpl",
"12Andrzej_Bulka@polsl.pl",
"_Bozena_Kajzerka@polsl.pl",
"bogudar@student.polsl.pl",
"kacpkik@student.polsl.pl",
"janekow@student.polsl.pl",
"adamkup@student.pl",
"sandind@student",
"..bogudar@student.polsl.pl",
"211kacpkik@student.polsl.pl",
"()janekow@student.polsl.pl",
"@student.polsl.pl",
"@studentpl",
"@.pl",
"@pl",
"pl",
"gutenberg@.pl",
"krzysztof.JERZYNAgmail.com",
"bozenka@gmail.com",
"boleslaw@polsl.pl",
"mieszko1@gmail.com",
"boleslaw1_chrobry@o2.pl",
"kazimierz.odnowiciel@wp.pl",
"boleslaw-szczodry@onet.pl",
"wladyslawHeHerman@gmail.com",
"boleslaWkrzywousty@gmail",
"wladyslaw_wygnaniec.pl",
"boleslaw.kedzierzawy@pl",
"mieszkoIIIstary@student",
"kazimierz2sprawiedliwy@buziaczki.eu",
"LESZEKbialy@tlen.eu",
"HenryKBrodatY@gmail.com" };

    cout << "Zadanie 2 a:" << endl;
    cout << endl;
    const regex r4("^([A-Z|a-z])(.*)@(.+)(\\.[a-z]{2,})$");                

    for (const auto& string : examples4)        //a
    {
        if((regex_match(string, r4))==1)
        cout << string  << endl;
    }


    cout << endl;
    cout << "Zadanie 2 b:" << endl;
    cout << endl;
    const regex r5("^([A-Z|a-z])(.*)@(student.polsl|polsl)(\\.[a-z]{2,})$");

    for (const auto& string : examples4)        //b
    {
        if ((regex_match(string, r5)) == 1)
            cout << string << endl;
    }


    cout << endl;
    cout << "Zadanie 2 c:" << endl;
    cout << endl;
    const regex r6("^([A-Z|a-z])(.*)@(.*)(\\.pl)$");

    for (const auto& string : examples4)        //c
    {
        if ((regex_match(string, r6)) == 1)
            cout << string << endl;
    }

    //zadanie 3

    const regex r7("(?=.*[A-Z])(?=.*[a-z])(?=.*[\\.|\\-|\\_|\\!|\\%|\\?]).{8,}");
  
    string s;
   
   do
    {
        cout << "Podaj haslo: (wpisz abc zeby przejsc dalej)" << endl;
        cin >> s;

        if ((regex_match(s, r7)) == 1)
            cout << "Haslo poprawne." << endl;
        else
            cout << "Haslo nie poprawne." << endl;
   } while (s != "abc");

   //zadanie 4

    string tekst= {"Zycie studenta to nieustanna walka o przetrwanie. Tu kolokwium, tam egzamin, co tu\nrobic? Kolokwia sa jak te podchody, niewinnie zwiastuja nadciagajacy kataklizm jakim jest\nsesja egzaminacyjna. Cztery egzaminy w przeciagu czterech dni? To nie problem.\nPrawdziwy problem rodzi sie wtedy, gdy po kilku podejsciach do tego samego egzaminu\nwracamy na tarczy. W tym momencie mozna rzec tak jak mawial pewien wielki czlowiek z\ndlugim patykiem: Zarty sie skonczyly, zaczynaja sie schody!\n\n"};

   regex zmien("egzamin|kolokwi|Kolokwi|Egzamin");

   cout << endl;
   cout << regex_replace(tekst, zmien, "*******") << endl;
}
