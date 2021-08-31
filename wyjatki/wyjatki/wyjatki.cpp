#include <iostream>
#include <math.h>

using namespace std;

class blad
{

};

class blad_mat
{

};

class pi_na_dwa : public blad_mat
{

};

class ujemna :public blad_mat
{

};

class zero :public blad_mat
{

};

struct LIFO
{
	int number;
	LIFO* next;
	LIFO(int number_) : number(number_), next(nullptr) {}
};

class Integers
{
	LIFO* head;
public:

	void usun(LIFO*&);
	Integers pushfront(int number)
	{
		if (!head)
		{
			LIFO* q = new LIFO(number);
		}
		else
		{
			LIFO* q = new LIFO(number);
			q->next = head;
			head = q;
		}
		return *this;
	}

	~Integers()
	{
		while (head)
		{
			LIFO* q = head;
			head = head->next;
			delete q;
		}
	}

};

int sprawdz(int i)
{
	if (i > 0)
		return i;
	else
	{
		blad b;
		throw b;
	}
}


int oblicz_obj(int a,int b,int c)
{
	try
	{
		a = sprawdz(a);
		b = sprawdz(b);
		c = sprawdz(c);
		return a * b * c;
	}

	catch (blad type)
	{
		cout << "Krawedz musi byc dodatnia" << endl;
		
	}
	return 0;
}

int oblicz_pol(int a , int b, int c)
{
	try
	{
		a = sprawdz(a);
		b = sprawdz(b);
		c = sprawdz(c);
		return 2 * (a * b) + 2 * (b * c) + 2 * (c * a);
	}
	catch (blad type)
	{
		cout << "Krawedz nie moze byc ujemna" << endl;
		
	}
	return 0;
}

LIFO* s(LIFO* phead)
{
	if (phead)
		return phead;
	else
	{
		blad b;
		throw b;
	}
}

void Integers::usun(LIFO*& phead)
{
	try
	{
		s(phead);

		LIFO* usuwany = phead;
		phead = phead->next;
		delete usuwany;
	}
	catch (blad b)
	{
		cout << "Lista jest pusta" << endl;
	}
}

int s2(int x)
{
	if (x != (3.14 / 2) && x != (-3.14 / 2))
		return x;
	else
	{
		pi_na_dwa b;
		throw b;
	}
}

int tangens(int x)
{
	try
	{
		s2(x);
		return tan(x);
	}

	catch (blad_mat b)
	{
		cout << "x nie moze byc pi/2" << endl;
	}
}

int s3(int x)
{
	if (x > 0)
		return x;
	else
	{
		ujemna u;
		throw u;
	}
}

int s4(int y)
{
	if (y)
		return y;
	else
	{
		zero z;
		throw z;
	}
}

void dzialanie(int x, int y)
{
	try
	{
		s3(x);
		s4(y);
	}

	catch (blad_mat b)
	{
		cout << "blad" << endl;
	}
}

int main()
{
	/*LABORATORIUM WYJĄTKI*/
/*  1. Napisz funkcję obliczającą objętość / pole całkowite graniastosłupa, funkcja ma wyrzucić wyjątek jeżeli któraś z krawędzi jest ujemna.
	2. Dla klasy Integers zdefiniować metodę usuwającą pierwszy element kolejki LIFO. Metoda ma wyrzucić wyjątek jeżeli w kolejce nie ma żadnych elementów.
	3. Korzystając z dziedziczenia klas wyjątków wyrzucić wyjątki dla następujących funkcji matematycznych(funkcje na prezentacji)
	tg(x);
	sqrt(x-3)/pow2 x+6x+9
	4*. Dodać treści komunikatów i wypisywać je na końcu programu
	5**. Wylapac wybrany wyjatek z biblioteki standardowej
*/
	int wynik = oblicz_obj(1, 2, -3);
	if(wynik)
	cout << wynik<<endl;
	wynik = oblicz_obj(0, 3, 4);
	if(wynik)
	cout << wynik<<endl;
	int x = 2;

	int a = 2 - 3;
	int b = x * x + 6 * x + 9;

	dzialanie(a, b);
}
