# Coding Questions

## Sum of second largest of (Even/Odd):
```c++
#include<bits/stdc++.h>
using namespace std;

int secondLargest(int arr[], int sz) {
	int largest = INT_MIN, secLargest = INT_MIN;
	for(int i = 0; i < sz; i++) {
		if(arr[i] > largest) {
			largest = arr[i];
		}
	}
	
	for(int i = 0; i < sz; i++) {
		if(arr[i] > secLargest && arr[i] < largest) {
			secLargest = arr[i];
		}
	}
	
	return secLargest;
}

int solve(int matrix[], int sz) {
	int evenMatrix[sz] = {0}, oddMatrix[sz] = {0}, evenIndex = 0, oddIndex = 0;
	
	for(int i = 0; i < sz; i++) {
		if(i % 2 == 0)
			evenMatrix[evenIndex++] = matrix[i];
		else 
			oddMatrix[oddIndex++] = matrix[i];
	}
	
	int evenSize = sizeof(evenMatrix)/sizeof(evenMatrix[0]);
	int oddSize = sizeof(oddMatrix)/sizeof(oddMatrix[0]);
	
	sort((evenMatrix), evenMatrix+evenSize);
	sort((oddMatrix), oddMatrix+oddSize);
	
	for(int i = 0; i < evenSize; i++) {
		cout << evenMatrix[i] << ' ';
	}
	cout << endl;
	for(int i = 0; i < oddSize; i++) {
		cout << oddMatrix[i] << ' ';
	}
	cout << endl;
	
	int secLargestOfEven = secondLargest(evenMatrix, evenSize);
	int secLargestOfOdd = secondLargest(oddMatrix, oddSize);
	
	return secLargestOfEven + secLargestOfOdd;
		
}

int main() {
	int sizeOfArray = 0;
	cin >> sizeOfArray;
	int matrix[sizeOfArray];
	for(int i = 0; i < sizeOfArray; i++) {
		cin >> matrix[i];
	}
	cout << solve(matrix, sizeOfArray);
}
```

## Perform the function check password:
```c++
#include<bits/stdc++.h>
using namespace std;

int CheckPassword(char str[], int sz) {
	
	// If less then 4, return 0
	if(sz < 4) {
		return 0;
	}
	
	// if starting character is a number, return 0
	// str[0] - '0' -> Converts the character representation 
	// of a digit to its corresponding integer value.
	if(str[0] - '0' >= 0 && str[0] - '0' <= 9) {
		return 0;
	}
	
	int idx = 0, capitalCnt = 0, numberCnt = 0;
	
	while(idx < sz) {
		// if space or / is present, return 0
		if(str[idx] == ' ' || str[idx] == '/') {
			return 0;
		}
		if(str[idx] >= 65 && str[idx] <= 90) {
			capitalCnt++;
		}
		if(str[idx] - '0' >= 0 && str[idx] - '0' <= 9) {
			numberCnt++;
		}
		idx++;
	}
	
	return capitalCnt > 0 && numberCnt > 0;
}

int main() {
	string pwdStr;
	getline(cin, pwdStr);
	int sz = pwdStr.size();
	char *str = &pwdStr[0];
	
	cout << CheckPassword(str, sz);
	
	return 0;
}
```

## Rat Count House:
```c++
#include<bits/stdc++.h>
using namespace std;

int ratCountHouse(int r, int unit, int n, int arr[]) {
	
	if(n == 0) {
		return -1;
	}
	
	int totalUnitEat = r * unit;
	int foodUnit = 0, i = 0;
	
	for(i = 0; i < n; i++) {
		foodUnit += arr[i];
		if(foodUnit >= totalUnitEat) {
			break;
		}
	}
	
	if(foodUnit < totalUnitEat) {
		return 0;
	}
	return i + 1;
}

int main() {
	int r, unit, n;
	cin >> r;
	cin >> unit;
	cin >> n;
	int arr[n];
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	cout << ratCountHouse(r,unit,n,arr);
}
```

## The binary number system only uses two digits 1 and 0:
```c++
#include<bits/stdc++.h>
using namespace std;

int OperationsBinaryString(char* str) {
	
	if(str == NULL) {
		return -1;
	}
	
	int i = 1;
	// Dereference the pointer str and subtract 
	// the ASCII value of '0' from the obtained character. 
	// Converts the character representation 
	// of a digit to its corresponding integer value.
	// Store this value in the variable a.
	int a = *str - '0'; 
	str++;
	
	while(*str != '\0') {
		char p = *str;
		str++;
		
		if(p == 'A')
			a &= (*str - '0');
		else if(p == 'B')
			a |= (*str - '0');
		else
			a ^= (*str - '0');
		
		str++;
	}
	return a;
}

int main() {
	string expStr;
	getline(cin, expStr);
	
	char *str = &expStr[0];
	
	cout << OperationsBinaryString(str);	
}
```

## find and return the number of elements of `arr` having an absolute difference of less than or equal to `diff` with `num`:
```c++
#include<bits/stdc++.h>
using namespace std;

int findCount(int arr[], int length, int num, int diff) {
	
	int cnt = 0;
	
	for(int i = 0; i < length; i++) {
		if(abs(arr[i] - num) <= diff) 
			cnt++;
	}
	
	return cnt > 0 ? cnt : -1;
}

int main() {
	int length;
	cin >> length;
	
	int arr[length];
	for(int i = 0; i < length; i++) {
		cin >> arr[i];
	}
	int num, diff;
	cin >> num >> diff;
	
	cout << findCount(arr, length, num, diff);
}
```

## Find the sum of all numbers in range from 1 to `m` (both inclusive) that are not divisible by `n`:
```c++
#include<bits/stdc++.h>
using namespace std;

int differenceofSum(int n, int m) {
	
	int sumOfNotDivByM = 0;
	int sumOfDivByM = 0;
	
	for(int i = 0; i <= n; i++) {
		i % m == 0 ? sumOfDivByM += i : sumOfNotDivByM += i;
	}
	
	return sumOfNotDivByM - sumOfDivByM;
}

int main() {
	int m, n;
	cin >> m >> n;
	
	cout << differenceofSum(n,m);
}
```

## Find the sum of second largest element from the even positions and second smallest from the odd position of given `arr`:
```c++
#include<bits/stdc++.h>
using namespace std;

int LargeSmallSum(vector<int> arr) {
	
	int sz = arr.size();
	
	if(sz == 0 || sz <= 3) {
		return 0;
	}
	
	vector<int> evenArray;
	vector<int> oddArray;
	
	for(int i = 0; i < sz; i++) {
		if(i % 2 == 0) {
			evenArray.push_back(arr[i]);
		}
		else {
			oddArray.push_back(arr[i]);	
		}
	}
	
	int evenArraySize = evenArray.size();
	int oddArraySize = oddArray.size();
	
	sort(evenArray.begin(), evenArray.end());
	sort(oddArray.begin(), oddArray.end());
	
	return evenArray[evenArraySize-2] + oddArray[1];
}

int main() {
	int size, a = 0;
	cin >> size;
	vector<int> arr;
	
	for(int i = 0; i < size; i++) {
		cin >> a;
		arr.push_back(a);
	}
	
	cout << LargeSmallSum(arr);
}
```

## Write a function to validate if the provided two strings are anagrams or not. If the two strings are anagrams, then return `yes`. Otherwise, return `no`:
```c++
#include<bits/stdc++.h>
using namespace std;

bool validateAnagram(string str1, string str2) {
	
	int sz1 = str1.size();
	int sz2 = str2.size();
	
	if(sz1 != sz2) {
		return false;
	}
	
	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
	
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	
	cout << str1 << endl << str2 << endl;
	
	for(int i = 0; i < sz1; i++) {
		if(str1[i] != str2[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	string str1, str2;
	
	getline(cin, str1);
	getline(cin, str2);
	
	if(validateAnagram(str1, str2)) {
		cout << "Yes";
	} else {
		cout << "No";
	}
}
```

## Perform the following function. `productSmallPair(sum,arr)`:
```c++
#include<bits/stdc++.h>
using namespace std;

int ProductSmallestPair(int sum, vector<int> arr) {
	
	int smallest = INT_MAX, secSmallest = INT_MAX, n = arr.size();
	
	if(n < 2) {
		return -1;
	}
	
	for(int i = 0; i < n; i++) {
		if(arr[i] < smallest) {
			smallest = arr[i];
		}
	}
	
	for(int i = 0; i < n; i++) {
		if(arr[i] < secSmallest && arr[i] > smallest) {
			secSmallest = arr[i];
		}
	}
	
	if(smallest + secSmallest <= sum) {
		return smallest * secSmallest;
	} else {
		return 0;
	}
}

int main() {
	int sum, size, val;
	cin >> sum >> size;
	vector<int> arr;
	for(int i = 0; i < size; i++) {
		cin >> val;
		arr.push_back(val);
	}
	
	cout << ProductSmallestPair(sum, arr);
}
```

## Execute the function `numberOfCarry(int num1, int num2)`:
```c++
#include<bits/stdc++.h>
using namespace std;

int numberOfCarry(int n1, int n2) {
	
	int cntCarry = 0, cnt = 0;
	
	string s1 = to_string(n1), s2 = to_string(n2);
	
	int length1 = s1.length(), length2 = s2.length();
	
	while(length1 != 0 || length2 != 0) {
		
		int x = 0, y = 0;
		
		if(length1 > 0) {
			x = s1[length1 - 1] - '0';
			length1--;
		}
		if(length2 > 0) {
			y = s2[length2 - 1] - '0';
			length2--;
		}
		
		int add = x + y + cntCarry;
		
		if(add >= 10) {
			cntCarry = 1;
			cnt++;
		}
		else {
			cntCarry = 0;
		}
	}
	
	return cnt;	
}

int main() {
	int num1, num2;
	
	cin >> num1 >> num2;
	
	cout << numberOfCarry(num1, num2);
}
```

## Execute this function `maxInArray(int arr[], int length)`
```c++
#include<bits/stdc++.h>
using namespace std;

int maximumFrequencyCount(vector<int> arr, int n) {
	
	int maxi = 0, maxiVal = 0;
	map<int, int> mp;
	
	sort(arr.begin(), arr.end());
	
	for(int i = 0; i < n; i++) {
		if(mp.find(arr[i]) == mp.end()) {
			mp[arr[i]] = 1;
		}
		else {
			mp[arr[i]]++;
		}
	}
	
	for(auto it : mp) {
		if(it.second > maxi) {
			maxi = it.second;
			maxiVal = it.first;
		}
	}
	
	return maxiVal;
	
}

int main() {
	int n, num;
	cin >> n;
	vector<int> arr;
	
	for(int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}
	
	cout << maximumFrequencyCount(arr, n);
}
```

## Perform the function: `chats_dectonbase(int n, int num)`:
```c++
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
```

## Perform the function: `replaceCharacter(char str1, char ch1, int l, char ch2)`:
```c++
#include<bits/stdc++.h>
using namespace std;

void replaceCharacter(char *s1, int len, char ch1, char ch2) {
	
	for(int i = 0; i < len; i++) {
		if(s1[i] == ch1) {
			s1[i] = ch2;
		}
		else if(s1[i] == ch2) {
			s1[i] = ch1;
		}
	}
	

	cout << s1;
}

int main () {
	string str;
	getline(cin, str);
	int length = str.length();
	char ch1, ch2;
	cin >> ch1 >> ch2;
	
	char* s = new char[length + 1];
	
	strcpy(s, str.c_str());
	
	replaceCharacter(s, length, ch1, ch2);
	
	// Free memory allocated for character array
	delete[] s;
	
	return 0;
}
```

## Perform the function: `operationChoices(int c, int n, int a, int b)`:
```c++
#include<bits/stdc++.h>
using namespace std;

int operationChoices(int a, int b, int c) {
	
	int result = 0;
	
	switch(c) {
		case 1:
			result = (a+b);
			break;
		case 2:
			result = (a-b);
			break;
		case 3:
			result = (a*b);
			break;
		case 4:
			result = (a/b);
			break;
		default:
			cout << "Invalid Operator (value of c is between 1 to 4 inclusive)";
			break;
	}
	
	return result;
}

int main() {
	int a,b,c;
	cin >> a >> b >> c;
	
	cout << operationChoices(a, b, c);
	
	return 0;
}
```

## Perform the function: `calculate(int m, int n)`:
```c++
#include<bits/stdc++.h>
using namespace std;

int calculate(int m, int n) {
    int sum = 0;

    if (m > n) {
        swap(m, n);
    }
    
    for (int i = m; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            sum += i;
        }
    }
    
    return sum;
}

int main() {
	int m, n;
	cin >> m >> n;
	
	cout << calculate(m, n);
	
	return 0;
}
```

## Execute this function: `maxInArray(int arr[], int length)`:
```c++
#include<bits/stdc++.h>
using namespace std;

void maxInArray(int arr[], int n) {
	
	int maxVal = 0, idx = 0;
	
	for(int i = 0; i < n; i++) {
		
		if(arr[i] > maxVal) {
			maxVal = arr[i];
			idx = i;
		}
	}
	
	cout << maxVal << endl << idx;
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	maxInArray(arr, n);
	
	return 0;
}
```

## Execute the function: `changeFrequentCharacter(char str, char x)`:
```c++
#include<bits/stdc++.h>
using namespace std;

void changeFrequentCharacter(char* str, char x) {
	
	map<char, int> mp;
	int length = strlen(str);
	
	for(int i = 0; i < length; i++) {
		if(str[i] == '\0') {
			continue;
		}
		if(mp.find(str[i]) == mp.end()) {
			mp[str[i]] = 1;
		} else {
			mp[str[i]]++;
		}
	}
	
	int maxFreq = 0;
	char maxFreqChar;
	
	for(auto it : mp) {
		if(it.second > maxFreq || (it.second == maxFreq && it.first < maxFreqChar)) {
			maxFreq = it.second;
			maxFreqChar = it.first;
		}
	}
	
	for(int i = 0; i < length; i++) {
		if(str[i] == maxFreqChar) {
			str[i] = x;
		}
	}
	
	cout << str;
	
}

int main() {
	string str;
	getline(cin, str);
	int length = str.length();
	char* s = new char[length+1];
	strcpy(s, str.c_str());
	char x; 
	cin >> x;
	
	changeFrequentCharacter(s, x);
	
	// Free memory allocated for character array
	delete[] s;
	return 0;
}
```

## Find the number that has the highest frequency:
```c++
#include<bits/stdc++.h>
using namespace std;

int mostFrequentNumber(int arr[], int n) {
	
	map<int, int> mp;
	int mostFreq = 0, freq = 0;
	
	for(int i = 0; i < n; i++) {
		if(mp.find(arr[i]) == mp.end()) {
			mp[arr[i]] = 1;
		} else {
			mp[arr[i]]++;
		}
	}
	
	for(auto it : mp) {
		if(it.second > freq || (it.second == freq && it.first < mostFreq)) {
			freq = it.second;
			mostFreq = it.first;
		}
	}
	
	return mostFreq;
}


int main() {
	int tc, n;
	
	cin >> tc;
	
	for(int i = 0; i < tc; i++) {
		cin >> n;
		int arr[n];
		
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		cout << mostFrequentNumber(arr, n) << endl;
	}
}
```

## Execute the function: `mergeArray(int a[], int b[], int aSize, int bSize)`:
```c++
#include<bits/stdc++.h>
using namespace std;

vector<int> mergeArray(int a[], int b[], int aSize, int bSize) {
	
	vector<int> mergedArr;
	
	for(int i = 0; i < aSize; i++) {
		mergedArr.push_back(a[i]);
	}
	
	for(int i = 0; i < bSize; i++) {
		mergedArr.push_back(b[i]);
	}
	
	sort(mergedArr.begin(), mergedArr.end());

	return mergedArr;
}

int main() {
	int m, n;
	cin >> m;
	int arr[m];
	for(int i = 0; i < m; i++) {
		cin >> arr[i];
	}
	cin >> n;
	int brr[n];
	for(int i = 0; i < n; i++) {
		cin >> brr[i];
	}
	
	vector<int> merged = mergeArray(arr, brr, m, n);
	
	for(auto it : merged) {
		cout << it << " ";
	}
	return 0;
}
```

## Execute the function: `kthLargestNumber(int arr[], int n, int k)`:
```c++
#include<bits/stdc++.h>
using namespace std;

int kthLargestNumber(int arr[], int n, int k) {
	
	if(k < 0 || k >= n) {
		return -1;
	}
	
	sort(arr, arr + n);
	
	return arr[n-k-1];
}

int main() {
	int n, k;
	cout << "Size of an array: ";
	cin >> n;
	int arr[n];
	cout << "Enter array elements: ";
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << "Value of k: ";
	cin >> k;
	
	cout << kthLargestNumber(arr,n,k);
	
	return 0;
}
```

## Execute the function `autoCount(n)`:
```c++
#include<bits/stdc++.h>
using namespace std;

int findAutoCount(char *n) {
	int valueCount[10]={0},freq[10]={0};
	int count=0;
	
	for(int i=0;n[i]!='\0';i++) {
		valueCount[n[i]-'0']++;
	}
		
	for(int i=0;i<10;i++) {
		if(valueCount[i]>0)
			count++;
	}
			
	for(int i=0;n[i]!='\0';i++) {
		valueCount[i]=valueCount[i]-(n[i]-'0');
	}
		
	for(int i=0;i<10;i++)
	{
		if(valueCount[i]!=0)
			return 0;
	}
	return count;
}

int main()
{
	char str[11];
	scanf("%s",str);
	cout << findAutoCount(str);
}
```

## Find if the given string is a palindrome or not:
```c++
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str) {
	
	string reverseStr;
	
	reverse_copy(str.begin(), str.end(), back_inserter(reverseStr));
	
	for(int i = 0; i < str.size(); i++) {
		if(str[i] != reverseStr[i]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	string str;
	getline(cin, str);
	
	cout << isPalindrome(str);
}
```

## Program to print Collatz Sequence:
```c++
#include<bits/stdc++.h>
using namespace std;

void collatzSequence(int n) {
	
	while(n != 1) {
		
		cout << n << " ";	
			
		if(n % 2 == 0) {
			n /= 2;
		}
		else {
			n = 3*n+1;
		}
	}
	cout << n; // print 1
}

int main() {
	int n;
	cin >> n;
	collatzSequence(n);
}
```

## Print a given matrix in spiral form:
```c++
#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix) {
	int rows = matrix.size(), cols = matrix[0].size();
	vector<int> result;
	
	if(rows == 0) return result;
	
	vector<vector<bool>> tracked(rows, vector<bool>(cols, false));
	int dr[] = { 0, 1, 0, -1};
	int dc[] = { 1, 0, -1, 0};
	
	int x = 0, y = 0, di = 0;
	
	// Iterate from 0 to rows*cols-1
	for(int i = 0; i < rows*cols; i++) {
		result.push_back(matrix[x][y]);
		
		tracked[x][y] = true;
		int newX = x + dr[di];
		int newY = y + dc[di];
		
		if(0 <= newX && newX < rows && 0 <= newY && newY < cols && !tracked[newX][newY]) {
			x = newX;
			y = newY;
		}
		else {
			di = (di + 1) % 4;
			x += dr[di];
			y += dc[di];
		}
	}
	return result;
}

int main() {
	vector<vector<int>> mtx{ { 1, 2, 3, 4 },
                           { 5, 6, 7, 8 },
                           { 9, 10, 11, 12 },
                           { 13, 14, 15, 16 } };
                           
	for(int it : spiralOrder(mtx)) {
		cout << it  << " ";
	}
	return 0;
}
```