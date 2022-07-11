#include <bits/stdc++.h>

using namespace std;

void print()
{
    cout << "Mark" << endl;
}

int sum(int a, int b)
{
    return a + b;
}

int main()
{
    print();
    cout << sum(23, 2);
    return 0;
}

/*
STL:
Algorithms
Containers
Functions
Iterators
*/

/*
Containers:
Pairs
Vectors
*/

// Pairs
void explainPair()
{
    // Declare and initialize
    pair<int, int> p = {1, 3};
    // Access first and second pair
    cout << p.first << " " << p.second;
    // Nested pair
    pair<int, pair<int, int>> p = {1, {2, 3}};
    // Access nested pair
    cout << p.first << " " << p.second.second << " " << p.second.first;
    // Declare and initialize pair-array
    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
    // Access pair-array
    cout << arr[1].second;
}

// Vectors
void explainVector()
{
    // Declare a vector 'v' with 'int' datatype
    vector<int> v; // It creates empty container
    // push_back push the element inside the vector container
    v.push_back(1);
    v.emplace_back(2); // Same as push_back() but emplace_back() is faster.
    // Vector of a pair
    vector<pair<int, int>> vec;

    // push_back({1,2}) and emplace_back(1,2) both are syntactical different
    v.push_back({1, 2});
    v.emplace_back(1, 2);

    // Container contains 5 instances of 100 is already defined
    vector<int> v(5, 100); // {100,100,100,100,100}

    vector<int> v(5); // {0,0,0,0,0}

    vector<int> v1(5, 20); // {20,20,20,20,20}
    vector<int> v2(v1);    // v2 is another container, copy of v1

    // Accessing elements in vector. Different ways:
    // First Way: Using Iterator. Iterator means it points to the memory address not to the element
    vector<int>::iterator it = v.begin() // Iterator syntax

                               it++; // Shift by one position
    cout << *(it) << " ";            // Access the element from the memory we use dereferencing operator

    it = it + 2; // Shifted by two position
    cout << *(it) << " ";

    vector<int>::iterator it = v.end(); // .end() points to right after last element.

    vector<int>::iterator it = v.rend();

    vector<int>::iterator it = v.rbegin();

    // Second Way: Accessing like an array
    cout << v[0] << " " << v.at(0);

    cout << v.back() << " "; // .back() means the element which is at last

    // There are some ways to print entire elements
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }

    // 'auto' is automatically defined 'vector<int>::iterator'
    // auto a = 5; 'a' is automatically defined 'int'
    // auto a = "Hello"; 'a' is automatically defined 'string'
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }
    // Using for each loop.
    for (auto it : v)
    { // 'it' can access every element of 'v'
        cout << it << " ";
    }

    // {10, 20, 12, 23} begin()+1 means '20' {10,12,23}
    v.erase(begin() + 1); // .erase() function can delete the element

    // {10,20,12,23,35} delete [index(2), index(4)) {10,20,35}
    v.erase(v.begin() + 2, v.begin() + 4) // for deleting more than one elements .erase(include first element, exclude last element)

        // Insert function
        vector<int>(2, 100);        // {100,100}
    v.insert(v.begin(), 300);       // {300, 100, 100}
    v.insert(v.begin() + 1, 2, 10); // {300, 10, 10, 100, 100}

    vector<int> copy(2, 50);                       // {50, 50}
    v.insert(v.begin(), copy.begin(), copy.end()); // {50, 50, 300, 10, 10, 100, 100}

    // Size of the vector {10, 20}
    cout << v.size(); // 2

    // {10, 20}
    v.pop_back(); // {10}

    // v1 -> {10, 20}
    // v2 -> {30, 40}
    v1.swap(v2); // v1 -> {30, 40}, v2 -> {10, 20}

    v.clear(); // erase the entire vector

    cout << v.empty(); // true
}

// List: It is as similar as vector but one difference is, list has push_front() function for pushing an element directly at first position.
void explainList()
{
    list<int> ls;

    ls.push_back(2);    // {2}
    ls.emplace_back(4); // {2,4}

    ls.push_front(5);   // {5,2,4}
    ls.emplace_front(); // {2,4}

    // rest of the function are same as vector. Like begin(), end(), rbegin(), rend(), clear(), insert(), size(), swap()
}

// Deque:
void explainDeque()
{
    deque<int> dq;
    dq.push_back(1);     // {1}
    dq.emplace_back(2);  // {1,2}
    dq.push_front(4);    // {4,1,2}
    dq.emplace_front(3); // {3,4,1,2}

    dq.pop_back();  // {3,4,1}
    dq.pop_front(); // {4,1}

    dq.back();
    dq.front();

    // rest of the function are same as vector. Like begin(), end(), rbegin(), rend(), clear(), insert(), size(), swap()
}

// Stack: All the operations are happening in constant time O(1)
void explainStack()
{
    stack<int> st;
    st.push(1);    // {1}
    st.push(2);    // {2, 1}
    st.push(3);    // {3, 2, 1}
    st.push(3);    // {3, 3, 2, 1}
    st.emplace(5); // {5, 3, 3, 2, 1}

    cout << st.top(); // print '5'

    st.pop(); // pop out '5' and remaining values in stack {3,3,2,1}

    cout << st.top(); // 3

    cout << st.size(); // 4

    cout << st.empty();

    stack<int> st1, st2;
    st1.swap(st2);
}

// Queue: All the operations are happening in constant time O(1)
void explainQueue()
{
    queue<int> q;
    q.push(1);   // {1}
    q.push(2);   // {1,2}
    q.emplace(4) // {1,2,4}

        q.back() += 5; // means '4' is at last. 4+5 = 9
    cout << q.back();  // print 9

    cout << q.front(); // print 1

    q.pop(); // {2,9}

    cout << q.front(); // print 2

    // size(), swap(), empty() are same as stack
}

// Priority Queue:
void explainPQ()
{
    // Maximum heap: Maximum element is at root node
    priority_queue<int> pq;

    pq.push(5);     // {5}
    pq.push(2);     // {5, 2}
    pq.push(8);     // {8, 5, 2}
    pq.emplace(10); // {10, 8, 5, 2}

    cout << pq.top(); // print 10

    pq.pop(); // {8,5,2}

    // size(), swap(), empty() function same as others

    // Minimum heap: Minimum element is at root node
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5);     // {5}
    pq.push(2);     // {2, 5}
    pq.push(8);     // {2, 5, 8}
    pq.emplace(10); // {2, 5, 8, 10}

    cout << pq.top(); // print 2

    // Time complexity:
    // push() -> O(logn)
    // pop() -> O(logn)
    // top() -> O(1)
}

// Set: It stores every distinct elements in sorted order.
void explainSet()
{
    set<int> st;
    st.insert(1);  // {1}
    st.emplace(2); // {1,2}
    st.insert(2);  // {1,2}
    st.insert(4);  // {1,2,4}
    st.insert(3);  // {1,2,3,4}

    // Functionality of insert in vector can be used also, that only increases efficiency.
    // begin(), end(), rbegin(), rend(), size(), empty(), and swap() functions are same as others

    // {1,2,3,4,5}
    auto it = st.find(3);
    auto it = st.find(6);

    st.erase(5); // erase() function takes logarithmic time. It delete '5'

    int cnt = st.count(1); // all are distinct. So, if present print 1 otherwise print 0

    auto it = st.find(3);
    st.erase(it); // 'it' takes constant time

    // {1,2,3,4,5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2); // after erase {1,4,5} | include first and exclude last [first, last)

    // lower_vound() and upper_bound() function works in the same way at in vector it does.

    // This is the syntax
    auto it = st.lower_bound(2);
    auto it = st.upper_bound(3);

    // In set everything happen in O(logN) time complextiy.
}

// MultiSet: Everything is same as set but it stores duplicate elements also
void explainMultiSet()
{

    multiset<int> ms;
    ms.insert(1); // {1}
    ms.insert(1); // {1,1}
    ms.insert(1); // {1,1,1}

    int cnt = ms.count(1); // print 3

    ms.erase(1); // all 1's erased

    ms.erase(ms.find(1)); // only a single one erased

    ms.erase(ms.find(1), ms.find(1) + 2); // erase(start,last) erased every elements from start to last. Here 2 elements are erased.

    // rest of all function are same as set
}

// Unordered Set: Everything is same as set but it cannot stores in sorted order.
void explainUSet()
{
    unordered set<int> st;
    // lower_bound() and upper_bound() function does not works, rest all functions are same as above, it does not stores in any particular order it has a better complexity than set in most of the cases TC is O(1), except when some collision happens. In worst case TC goes O(n)
}

// Map: Keys are unique and values may or may not same.
// Node that map stores unique keys in sorted order
void explainMap()
{
    map<int, int> mpp;
    map<int, pair<int, int>> mpp;
    map<pair<int, int>, int> mpp;

    mpp[1] = 2;
    mpp.emplace({3, 1});
    mpp.insert({2, 4});
    /* {
            {1, 2}
            {2, 4}
            {3, 1}
        }
    */
    mpp[{2, 3}] = 10; // {{2, 3}, 10}

    for (auto it : mpp)
    {
        cout << it.first << " " << it.second << endl;
    }
    /*
        Print:
        1 2
        2 4
        3 1
    */

    cout << mpp[1]; // print 2
    cout << mpp[5]; // print NULL/0

    auto it = mpp.find(3); // finding the position of {3, 1}
    cout << *(it).second;  // Accessing the element at {3, 1}. print '1'

    auto it = mpp.find(5); // '5' is not exist so it points mpp.end() means after the map.

    auto it = mpp.lower_bound(2);
    auto it = mpp.upper_bound(3);

    // erase(), swap(), size(), empty(), are same as above
}

// Multimap
void explainMultimap()
{
    /*
    * Multi-map: everything same as map, only it can store multiple keys only mpp[key] cannot be used here.
    * It can store duplicate keys but stores in sorted order
    {1, 2}
    {1, 3}
    {2, 4}
    */
}

// Unordered Map
void explainUMap()
{
    /*
     * same as set and unordered set
     * It has unique keys
     * It is not store in sorted order
     * In most of the cases the TC is O(1)
     * At the worst case the TC is O(n)
     */
}

// Comparator function
bool comp(pair<int, int> p1, pair<int, int> p2)
{
    // Condition 1
    if (p1.second < p2.second)
        return true;
    // Condition 2
    if (p1.second > p2.second)
        return false;
    // Condition 3: Both p1 and p2 are same
    if (p1.first > p2.first)
        return true;
    return false;
}

// Important Algorithms
void explainExtra()
{
    // Sorted in ascending order
    sort(a, a + n);
    sort(a + m, a + n); // where m, n are integer.
    sort(v.begin(), v.end());

    // Sorted in decreasing order
    sort(a, a + n, greater<int>);

    pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};
    /*
    * Sort it according to second element, if second element is same, then sort it according to first element but in descending order.
    {{2,1},{4,1},{1,2}} -> {{4,1},{2,1},{1,2}}
    */

    sort(a, a + n, comp); // where a is first iterator, a+n is last iterator and comp is comparator and the comparator is nothing but a boolean function.
    // {{4,1},{2,1},{1,2}}

    int num = 7;                    // 1 1 1
    int cnt = __buildin_popcount(); // __buildin_popcount() tells how many number of 1's are there or how many set bits are there.
    /*
    num = 7 means 1 1 1 bits
    cnt prints 3
    num = 6 means 1 1 0 bits
    cnt prints 2
    */

    // If the variable's datatype is long long or a number is long long then we use:
    long long num = 165786578687;
    int cnt = __buildin_popcountll();

    string s = "123"; // Note: Start by sorting the variable.
    sort(s.begin(), s.end());
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    /*
        above code will print all the permutation of string "123":
        123
        132
        213
        231
        312
        321
        NULL
    */

    int maxi = *max_element(a, a + n);
    int mini = *min_element(a, a + n);
}