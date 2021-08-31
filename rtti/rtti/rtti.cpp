#include <iostream>
#include <cstdlib>
using namespace std;

struct B {
	virtual void f();
};

struct C :B
{
	void f() override;
	void f4C();
};


struct D :B
{
	void f() override;
	void f4D();
};

struct jeden:B
{
	void f() override;
	void fjeden() { cout << "klasa jeden" << endl; }
};

void choose(B* p) //ta funkcja kozysta z rtti
//p jest wskaznikiem typu klasy bazowej
{
	if (C* c = dynamic_cast<C*>(p)) //c,d,j sa wskaznikami typu odpowiednich klas pochodnych
		c->f4C();
	else if (D* d = dynamic_cast<D*>(p)) //dynamic_cast tworzy wskaznik typu klasy pochodnej ze wskaznika typu klasy bazowej
		d->f4D();
	else if (jeden* j = dynamic_cast<jeden*>(p))
		j->fjeden();
	else
		p->f();
}

void B::f() { };

void D::f4D()
{
	cout << "klasa D" << endl;
}
void jeden::f() { };
void D::f() { };

void C::f4C()
{
	cout << "klasa C" << endl;
}

void C::f() { };

////////////////////////////

class Grand
{
public:
	virtual void m() {}
};

class Superb :public Grand
{
public:
	void m(){}
};

class M :public Superb
{
public:
	void m(){}
};

////////////////
//moj przyklad:
//klasy 1,2,3,4 dziedzicza po klasie klasa

class klasa
{
public:
	virtual void a(){}
};

class klasa1:public klasa
{
public:
	void a(){}
	void wypisz() { cout << "1" << endl; }
};

class klasa2: public klasa
{
public:
	void a() {}
	void wypisz() { cout << "2" << endl; }
};

class klasa3: public klasa
{
public:
	void a() {}
	void wypisz() { cout << "3" << endl; }
};

class klasa4: public klasa
{
public:
	void a() {}
	void wypisz() { cout << "4" << endl; }
};

void wybierz(klasa* p)
{
		
		if (klasa1* x = dynamic_cast<klasa1*>(p)) //rzutowanie wskaznika typu klasy bazowej na wskaznik typu klasy pochodnej
		x->wypisz();
	else if (klasa2* x = dynamic_cast<klasa2*>(p))
		x->wypisz();
	else if (klasa3* x = dynamic_cast<klasa3*>(p))
			x->wypisz();
	else if (klasa4* x = dynamic_cast<klasa4*>(p))
			x->wypisz();
	else
		p->a();
}

int main()
{
	B* p = new C;
	dynamic_cast<C*>(p);
	choose(p);

	B* r = new jeden;
	dynamic_cast<jeden*>(r);
	choose(r);

	klasa* k = new klasa4;
	dynamic_cast<klasa4*>(k);
	wybierz(k);

	Grand* pg = new Grand;
	Grand* ps = new Superb;
	Grand* pm = new M;

	if (ps = dynamic_cast<Superb*>(pg))
	{
		ps->m();
	}
	
	//nie dziala
	//if (typeid(*pg)==typeid(Superb)) 
	//{
	//	(Superb * )pg->f();
	//}

	/* 6.2
	Static_cast uzywa sie do rzutowanie kompatybilnych typow, np. double->int.
	dynamic_cast uzywa sie do rzutowania, gdy kompatybilnosc nie jest pewna 
	- rzutowani wskaznikow bazowych na pochodne
	
	*/
}

