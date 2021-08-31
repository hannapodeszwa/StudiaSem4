#include <string>
#include <sstream>
#include <memory>
#include <iostream>
#include <memory>
#include <crtdbg.h>
#include <ctime>

//ZADANIE 2

class useless
{
	const std::string text;
public:
	useless(const std::string _text)
		: text(_text) {
		std::cout << " stworzono klase useless! " << text << std::endl;
	}
	~useless() {
		std::cout << " zniszczono klase useless! " << text << std::endl;
	}
	void print() const {
		std::cout << " tekst: " << text << std::endl;
	}
	useless& operator=(const useless& us) {
		*this = us;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& os, const useless& us) {
		os << "przeciazony operator '<<': " << us.text << "\n";
		return os;
	}
};

// popraw ponizszy kod.
// zaznacz miejsca w ktorych pojawiaja sie bledy,
// dopisz komentarz dlaczego sie pojawiaja.
void unique_ptr()
{
	auto unique = std::make_unique<useless>("unique");
	auto unique2 = std::make_unique<useless>("unique2");
	std::cout << "przypisywanie unique danych z unique2: ";

	//std::move()?
	// sprobuj poprawic kod
	unique = std::move(unique2);			//byl blad


	unique->print();
}

void shared_ptr()
{
	auto shared = std::make_shared<useless>("shared");
	auto shared2 = std::make_shared<useless>("shared2");

	// std::swap()? czy jest to konieczne?   //nie jest konieczne
	// sprobuj poprawic kod
	//auto const temp = shared;
	//shared = shared2;
	//shared2 = temp;

	std::swap(shared, shared2);

	// przeciazony operator, dlaczego tak sie dzieje?
	// shared->print()?
	// sprobuj poprawic kod
	//std::cout << shared << std::endl;
	shared->print();

	std::cout << "licznik referencji shared: ";
	std::cout << shared.use_count() << std::endl;
	auto shared3 = shared;
	// dlaczego licznik zostal inkrementowany?
	std::cout << "licznik referencji shared: "; //bo pojawilo sie odniesienie do danych, na ktore wskazuje shared
	std::cout << shared.use_count() << std::endl;
}

void weak_ptr()
{
	std::weak_ptr<useless> weak;
	// std::weak_ptr<> = weak; -  zamiast auto? 
	// sprobuj poprawic deklaracje
	//auto weak = std::make_weak<useless>("weak"); //byl blad

	std::cout << "licznik referencji weak: ";
	std::cout << weak.use_count() << std::endl;

	{
		auto weakshared = std::make_shared<useless>("weakshared");
		weak = weakshared;

		std::cout << "czy weak_ptr istnieje: ";
		if (!weak.expired())
			std::cout << "tak\n";
		else
			std::cout << "nie\n";

		std::cout << "licznik referencji weak: ";
		std::cout << weak.use_count() << std::endl;
	}

	std::cout << "czy weak_ptr istnieje: ";
	if (!weak.expired())
		std::cout << "tak\n";
	else
		std::cout << "nie\n";

	std::cout << "licznik referencji weak: ";
	std::cout << weak.use_count() << std::endl;
}



//ZADANIE 3

template<typename T>
class Lista
{
	struct List {
		T data;
		//List* pNext;	
		std::auto_ptr<List>pNext;// Zamien na inteligentny wskaznik 
	};
	//List* pHead;
	std::auto_ptr<List>pHead;// Zamien na inteligentny wskaznik
public:
	Lista() : pHead(nullptr) {};
	Lista(T data) { addElement(); };
	~Lista() = default;	// Destruktor musi pozostac pusty

	// Przeksztalc dodawanie na poczatek listy
	void addElement(T data)
	{
		//List* temp = new List;
		std::auto_ptr<List>temp(new List);
		temp->data = data;
		temp->pNext = pHead;
		pHead = temp;
	};
	// Przeksztalc wyswietlanie listy
	void printList()
	{
		//List* temp = pHead;
		std::auto_ptr<List>temp(pHead);
		int i = 1;
		while (temp.get()) {
			std::cout << i << ": " << temp->data << "\n";
			temp = temp->pNext;
			i++;
		}
	}
};

void foo()
{
	// Przeksztalc na inteligentny wskaznik
	std::auto_ptr<Lista<int>>lista(new Lista<int>());
	//Lista<int>* lista = new Lista<int>();
	for (int i = 0; i < 20; i++)
		lista->addElement(rand() % 100 + i);
	lista->printList();
}


//ZADANIE 4

// Stosując inteligentne wskazniki przeksztalc konstruktor,
// w taki sposob, aby nie bylo wyciekow pamieci.
class Matrix {
	//int** m_Matrix;
	std::unique_ptr<std::unique_ptr<int[]>[]> m_Matrix;	// Zamień na inteligentny wskaźnik
					// dwuwymiarowej tablicy dynamicznej.
	int m_SizeX;
	int m_SizeY;
public:
	Matrix(int sizeX = -1, int sizeY = -1)
		: m_SizeX(sizeX), m_SizeY(sizeY)
	{
		try {
			// Przeksztalc alokowanie pamieci
			//m_Matrix = new int* [m_SizeX];
		
			m_Matrix = std::make_unique<std::unique_ptr<int[]>[]>(m_SizeX);
			
			 
			for (int i = 0; i < m_SizeX; i++)
				m_Matrix[i] = std::make_unique< int[]>(m_SizeY);

			

			for (int i = 0; i < m_SizeX; i++)
				for (int j = 0; j < m_SizeY; j++)
					m_Matrix[i][j] = rand() % 100 + 1;
		}
		catch (std::bad_alloc& ba) {
			std::cout << ba.what() << std::endl;
		}
		catch (std::bad_array_new_length& bl) {
			std::cout << bl.what() << std::endl;
		}
	}
	~Matrix() = default;	// Destruktor musi pozostac pusty.

	void printMatrix()
	{
		for (int i = 0; i < m_SizeX; i++) {
			for (int j = 0; j < m_SizeY; j++) {
				std::cout << m_Matrix[i][j] << " ";
			}
			std::cout << "\n";
		}
	}
};



int main()
{
	//ZADANIE 1
	{std::shared_ptr<double> sharedPtr;
	double* commonPtr = new double;
	//std::shared_ptr<double> sharedptr2 = commonptr; //nie ma mozliwosci
							//automatycznego konwertowania wskaznika na obiekt inteligentnego wskaznika
	//sharedptr = commonptr; //ten sam blad
	sharedPtr = std::shared_ptr<double>(commonPtr); // konwersja commonptr na typ sharedptr2
	}

	unique_ptr();
	shared_ptr();
	weak_ptr();

	_CrtDumpMemoryLeaks();


	foo();
	_CrtDumpMemoryLeaks();

	// Zamnien na inteligentny wskaznik
	// Dzialania na inteligentnych wskaznikach w funkcji main()
	// powinny byc objete klamrami:
	// np. int main() { { auto shared = ...; } return 0;}
	//Matrix* mPtr = new Matrix(10, 3);
	{std::unique_ptr<Matrix> mPtr(new Matrix(10, 3));

	mPtr->printMatrix();
	}

	_CrtDumpMemoryLeaks();
	return 0;
}