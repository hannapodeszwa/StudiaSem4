#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

void copy(vector<double> v1, vector<double> &v2)
{
	for (int i = 0;i < v1.size();i++)
	{
		back_inserter(v2) = v1[i];
	}
}

bool f(int a, int b)
{
	return (a < b);
}

int main()
{
	//zadanie 1
	ifstream plik("liczby.txt");
	vector <double> v;
	vector<double> v2;
	double tmp;

	if (plik)
	{
		while (!plik.eof())
		{
			plik >> tmp;
			v.push_back(tmp);
		}

		plik.close();
	}
	copy(v, v2);

	for (int i=0;i<v2.size();i++)
	{
		cout << v2[i] << endl;
	}
	cout << endl;

	//zadanie 2
	vector<double>::iterator toRemove = remove_if(v2.begin(), //usuwanie ujemnych
	v2.end(), [](int elem) 
		{
		if (elem < 0)
			return true;
		else
			return false;
		});

	 v2.erase(toRemove, v2.end()); //usuwanie
	 sort(v2.begin(), v2.end()); //sortowanie

	for (auto element : v2) 
	{
		cout << element << endl; 
	}
	cout << endl;

	//zadanie 3
	for_each(v2.begin(), //pierwiastek
		v2.end(), [](double& element) 
		{element = sqrt(element); });

	vector<double>::reverse_iterator iterator = v2.rbegin(); //iterator odwrotny

	for (; iterator!=v2.rend();iterator++)
	{
		cout << *(iterator) << endl; 
	}
	cout << endl;

	//zadanie 4
	bool dodatnia = all_of(v2.begin(), v2.end(), [](double elem)
		{
			if (elem > 0)
				return true;
			else
				return false;

		});

	bool zero = any_of(v2.begin(), v2.end(), [](double elem)
		{
			if (elem ==0)
				return true;
			else
				return false;

		});

	cout << dodatnia << endl;
	cout << zero << endl;
	cout << endl;

	//zadanie 5
	if (binary_search(v2.begin(), v2.end(), 2, f))
		cout << "Jest 2" << endl;
	else
		cout << "Nie ma 2" << endl;
	if(binary_search(v2.begin(), v2.end(), 4, f))
		cout << "Jest 4" << endl;
	else
		cout << "Nie ma 4" << endl;
	cout << endl;

	//zadanie 6
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(v2.begin(), v2.end(), default_random_engine(seed));
	for (auto element : v2) 
	{
		cout << element << endl; 
	}
}
