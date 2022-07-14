/*
 * Lower Triangular Matrix
 *
 * M = [[a11, 0, 0],
 *      [a21, a22, 0],
 *      [a31, a32, a33]]
 *
 * M[i,j] = 0   if i < j
 * M[i,j] = non-zero    if i >=  j
 * non-zero = 1 + 2 + 3 +...+ n = (n(n+1))/2
 *
 * ----------------------------------------------- *
 *
 * zero = n^2 - (n(n+1))/2 = (n(n-1))/2 
 * where total elements in the matrix is n^2
 *
 * ----------------------------------------------- *
 *
 * Representation of LTM: Using Row-major (Row by Row)
 * Formula for accessing non-zero elements in a single dimension array: 
 * Index(A[i][j]) = [(i(i-1))/2]+j-1
 *
 * ----------------------------------------------- *
 *
 * Representation of LTM: Using Column-major (Column by Column)
 * Formula for accessing non-zero elements in a single dimension array:
 * Index(A[i][j]) = [n(j-1)-((j-2)(j-1))/2]+(i-j)
 */

#include <iostream>
using namespace std;

class LowerTriangular
{
    int *A;
    int n;
public:
    LowerTriangular()
    {
        n = 2;
        A = new int[2*(2+1)/2];
    }
    LowerTriangular(int n)
    {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    ~LowerTriangular()
    {
        delete []A;
    }
    void Set(int i, int j, int k);
    int Get(int i, int j);
    void Display();
    int GetDimension() { return n; }
};

void LowerTriangular::Set(int i, int j, int k)
{
    if(i >= j) {
        // Row-major
        // A[i*(i-1)/2+j-1] = k;
        // Column-major
        A[n*(j-1)-(j-2)*(j-1)/2+i-j] = k;
    }
}

int LowerTriangular::Get(int i, int j)
{
    if(j >= j) {
        // Row-major
        // return A[i*(i-1)/2+j-1];
        // Column-major
        return A[n*(j-1)-(j-2)*(j-1)/2+i-j];
    }
    return 0;
}

void LowerTriangular::Display()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i >= j) {
                // Row-major
                // cout << A[i*(i-1)/2+j-1] << " ";
                // Column-major
                cout << A[n*(j-1)-(j-2)*(j-1)/2+i-j] << " ";
            }
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main()
{
    int d; // dimension of a metrix
    cout << "Enter Dimensions ";
    cin >> d;
    
    LowerTriangular ltm(d);
    
    int x;
    cout << "Enter All Elements ";
    for(int i = 1; i <= d; i++)
    {
        for(int j = 1; j <= d; j++)
        {
            cin >> x;
            ltm.Set(i, j, x);
        }
    }
    ltm.Display();
    return 0;
}
