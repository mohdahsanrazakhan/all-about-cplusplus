#include<bits/stdc++.h>
using namespace std;

string chats_dectonbase(int n, int num) {
    // Define symbols for n-based notation
    string symbols = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    // Initialize an empty string to store the n-based result
    string n_base_result = "";
    
    while(num > 0) {
        // Calculate the remainder when num is divided by n
        int remainder = num % n;
        
        // Add the corresponding symbol to the result
        n_base_result = symbols[remainder] + n_base_result;
        
        // Update num to be the quotient of the division
        num = num / n;
    }
    
    return n_base_result;
}

int main() {
    int n, num;
    
    cout << "Enter the base (1 < base <= 36): ";
    cin >> n;
    
    cout << "Enter the number: ";
    cin >> num;
    
    if (n <= 1 || n > 36) {
        cout << "Invalid base entered!" << endl;
        return 1;
    }
    
    cout << "The number in base " << n << " is: " << chats_dectonbase(n, num) << endl;
    
    return 0;
}

