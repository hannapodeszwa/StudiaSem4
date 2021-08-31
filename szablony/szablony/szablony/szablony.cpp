#include <iostream>

using namespace std;

//zadanie 1
template <class T> class Lista 
{
private:
    T obiekt;
    Lista* pNast = nullptr;
public:
    Lista()
    {
        ilewliscie++;
    }

    template <class T> void dodaj(T a)//dodawanie na koniec
    {
        T* tmp = this;
        while (tmp->pNast)
            tmp = tmp->pNast;
        tmp->pNast = a
    }
};


template <class cos> class Matrix
{
private:
    template <class cos> doubleArray[MAXROWS][MAXCOLS]; //zadanie 2
    int rows;
    int cols;
public:
    Matrix();
    void printMatrix();
    void setElement(int row, int col, int value); //ustawienie wartości macierzy
    void addMatrix(int[][MAXCOLS]); //dodaje tablice do doubleArray 
    void addMatrix(int[][MAXCOLS], int[][MAXCOLS]);
};

template <typename M_type> 
void Matrix<M_type>::addMatrix(M_type otherArray[][MAXCOLS])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            doubleArray[i][j] += otherArray[i][j];
        }
    }
}

//zadanie 3
template <typename M_type>
void Matrix<M_type>::printMatrix()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << doubleArray[i][j] << " ";
        }
        cout << endl;
    }
}

template<class T> double pythag(T a, T b, T c) 
{
    return (-b + sqrt(double(b * b - 4 * a * c))) / 2 * a;
}

int main() 
{
    //zadanie 4
    pythag(1, 2, 3); // wszystkie typy to int
    pythag(1.0, 2.0, 3.0);  // wszystkie typy double
   // pythag(1, 2.0, 3.0); //bledne argumenty int, double,double
    pythag<double>(1, 2.0, 3.0); //dziala bo typ przyjety jest double
}


