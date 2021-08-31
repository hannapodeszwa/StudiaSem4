#include <iostream>
#include <thread>
#include <mutex>
#include <sstream>
#include <array>
#include <string>
#include <chrono>
#include <math.h>
#include <stdlib.h>

void funkcja1() {
	std::cout << "Wywolano funkcje nr 1" << std::endl;
}

void funkcja2(int value) {
	std::cout << "Wywolano funkcje nr 2, do ktorej przekazano argument typu 'int' o wartosci: " << value << std::endl;
}

void funkcja3(double& value) {
	std::cout << "Wywolano funkcje nr 3, do ktorej przekazano przez referencje argument typu 'double' o wartosci: " << value << ", po czym pomnozono go przez 2" << std::endl;
	value *= 2;
}

void oczekiwanie1() {
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "Zakonczono dzialanie funkcji wywolanej za pomoca join()" << std::endl;
}
void oczekiwanie2() {
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << std::endl << "Zakonczono dzialanie funkcji wywolanej za pomoca detach()" << std::endl << std::endl;
}

void dodawanie1(std::array<int, 5>& tab, std::mutex& m) {
	m.lock();
	for (int liczba_iteracji = 5000; liczba_iteracji > 0; liczba_iteracji--) {
		for (int i = 0; i < tab.size(); i++)
			tab[i] += 1;
	}
	m.unlock();
}

void dodawanie2(std::array<int, 5>& tab, std::mutex&m) {
	m.lock();
	for (int liczba_iteracji = 5000; liczba_iteracji > 0; liczba_iteracji--) {
		for (int i = 0; i < tab.size(); i++)
			tab[i] += 1;
	}
	m.unlock();
}


long double dzialanie(long double liczba,std::mutex &m1) {
	//m1.lock();
	long double wynik;
	for (int i = 0; i < 10000000; i++) {
		wynik = std::pow(liczba, 8);
		for (int j = 0; j < 3; j++)
			wynik = std::sqrt(wynik);
	}
	std::cout << "Pierwiastek liczby " << liczba << " wynosi " << std::sqrt(wynik) << std::endl;
	return wynik;
	//m1.unlock();
}

int main()
{
	/*****
		Zadanie 1
	*****/

	double x = 5;

	std::thread th1(&funkcja1);
	std::thread th2(&funkcja2,15);
	th1.join();
	th2.join();
	std::cout << "Wartosc zmiennej x przed wywolaniem funkcji nr 3: " << x << std::endl;
	std::thread th3(&funkcja3,std::ref (x));
	th3.join();
	std::cout << "Wartosc zmiennej x po wywolaniu funkcji nr 3: " << x << std::endl << std::endl;

	/*****
	Polecenie:

	Przekształć treść programu, aby podane powyżej funkcje były wykonywane w osobnych wątkach
	*****/



	///*****
	//	Zadanie 2
	//*****/

	//std::thread t1(oczekiwanie1);
	//std::thread t2(oczekiwanie2);
	//t1.join(); //watek nadrzedny czeka, az podrzedny zostanie wykonany
	//t2.detach(); //niezalezne funkcjonowanie watku nadrzednego i podrzednego

	///*****
	//Polecenie:
	//Wywołaj wątek t1 za pomocą metody join(), a wątek t2 za pomocą metody detach(). Jaka jest różnica w działaniu obu metod? Co się stanie, gdy nie użyjemy żadnej z nich?
	//*****/




	///*****
	//	Zadanie 3
	//*****/
	//std::array<int, 5> tablica = { 0,0,0,0,0 };
	//std::thread wtk_jeden;
	//std::thread wtk_drugi;
	//std::mutex m;
	//
	//wtk_jeden = std::thread(dodawanie1, std::ref(tablica),std::ref(m));
	//
	//wtk_drugi = std::thread(dodawanie2, std::ref(tablica), std::ref(m));
	//
	//wtk_jeden.join();
	//wtk_drugi.join();

	///*****
	//Polecenie:

	//Funkcje dodawanie1() i dodawanie2() naprzemiennie inkrementują wartości podanej tablicy.
	//Przekaż mutex przez referencję i użyj lock() oraz unlock(), aby przekształcić funkcje dodawanie1() i dodawanie2()
	//na "wątkowo-bezpieczne" (ang. thread-safe) i spraw, by ich wykonanie zwróciło poprawny wynik działania.
	//*****/

	//std::cout << std::endl << "Wynikiem dzialania 5000 + 5000 jest:" << std::endl;
	//for (int i = 0; i < tablica.size(); i++)
	//	std::cout << "Proba nr " << i + 1 << ": " << tablica[i] << std::endl;



	///*****
	//	Zadanie 4
	//*****/
	//std::mutex m1;
	//std::thread wtk[8]; // Osiem wątków, które program dostaje do dyspozycji
	//std::array<double, 8> liczba; // Program powinien przyjąć maksymalnie 8 liczb

	//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	//std::cout << std::endl << "Podaj od 1 do 8 liczb, na ktorych zostana wykonane skomplikowane dzialania matematyczne:" << std::endl;
	//std::string input;
	//std::getline(std::cin, input);
	//std::istringstream strumien(input);

	//double d;
	//int i = 0;
	//while (strumien >> d && i < 8) {
	//	liczba[i] = d;
	//	
	//	wtk[i] = std::thread(dzialanie, liczba[i],std::ref(m1));
	//	i++;
	//}

	//for (int a = 0;wtk[a].joinable();a++)
	//{
	//	wtk[a].join();
	//}
	//

	//

	/*****
	Polecenie:
	Podzielić pracę wykonywaną przez program, aby działanie na każdej z liczb było wykonywane w osobnym wątku.
	*****/

	std::cout << std::endl;


//
//#ifdef _WIN32
//	system("pause");
//#endif
//#ifdef unix
//	system("read");
//#endif

	return 0;
}