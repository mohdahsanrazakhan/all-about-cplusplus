#include<bits/stdc++.h>
using namespace std;

void findRoots(int a, int b, int c) {
    double D = b * b - 4 * a * c;
    cout << D << endl;

    if (D > 0) {
        double r1 = (-b + sqrt(D)) / (2.0 * a);
        double r2 = (-b - sqrt(D)) / (2.0 * a);
        cout << "Roots are real and different: {" << r1 << "," << r2 << "}" << endl;
    } else if (D == 0) {
        double r = -b / (2.0 * a);
        cout << "Roots are real and same: {" << r << "," << r << "}" << endl;
    } else {
        double realPart = -b / (2.0 * a);
        double imaginaryPart = sqrt(-D) / (2.0 * a);
        cout << "Roots are complex: {" << realPart << " + " << imaginaryPart << "i, " << realPart << " - " << imaginaryPart << "i}" << endl;
    }
}

int main() {
	int a,b,c;
	cin >> a >> b >> c; 
	
	findRoots(a,b,c);
}
