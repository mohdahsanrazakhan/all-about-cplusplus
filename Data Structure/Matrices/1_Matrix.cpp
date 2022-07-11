/* DSA by Abdul Bari
 *
 * Special Matrices:
 * 1. Diagonal matrix
 * 2. Lower Triangular Matrix
 * 3. Upper Triangular Matrix
 * 4. Symmetric Matrix
 * 5. Tridiagonal Matrix
 * 6. Band Matrix
 * 7. Toeplitz Matrix
 * 8. Sparse Matrix
 */

/*
 * Diagonal Matrix:
 M = [[2,0,0],
      [0,4,0],
      [0,0,6]]

 M[i, j] = 0    if i != j

 Diagonal Matrix in a single diamention array:
 A = [2,4,6]

 M[i,j]
 if(i == j)
    A[i-1];

 */

#include <iostream>
using namespace std;

class Diagonal
{
private:
    int *A; // data member (pointer for dynamically create array)
    int n;  // data member (for a diamention)
public:
    Diagonal() // non-parameterized constructor
    {
        n = 2;          // minimum diamention is 2
        A = new int[2]; // array of size 2
    }
    Diagonal(int n) // parameterized constructor
    {
        this->n = n;    // fist 'n' is private and second 'n' is parameter of Diagonal
        A = new int[n]; // create an array of size 'n'
    }
    ~Diagonal() // destructor
    {
        delete[] A; // destructor can delete the array if it not use
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

void Diagonal::Set(int i, int j, int x)
{
    if (i == j)
        A[i - 1] = x;
}

int Diagonal::Get(int i, int j)
{
    if (i == j)
        return A[i - 1];
    return 0;
}

void Diagonal::Display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << A[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main()
{
    Diagonal d(4); // create an object of diagonal matrix 'd' of diamention '4'

    // calling set method
    d.Set(1, 1, 5);
    d.Set(2, 2, 8);
    d.Set(3, 3, 9);
    d.Set(4, 4, 12);
    // calling get method
    cout << d.Get(2, 2) << endl;
    // calling display method
    d.Display();

    return 0;
}
