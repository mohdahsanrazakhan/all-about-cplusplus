#include <bits/stdc++.h>
using namespace std;

int findModulo(const string& n) {
    int modulo = 0;
    for(char digit : n) {
        modulo = (modulo * 10 + (digit - '0')) % 11;
    }
    return modulo;
}

int main() {
    string number;
    getline(cin, number);
    cout << findModulo(number);
    return 0;
}
