// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Comparator function to sort pairs
// according to second value
bool cmp(pair<int, int>& a,
		pair<int, int>& b)
{
	return a.first < b.first;
}

// Function to sort the map according
// to value in a (key-value) pairs
void sort(map<int, int>& M)
{

	// Declare vector of pairs
	vector<pair<int, int> > A;

	// Copy key-value pair from Map
	// to vector of pairs
	for (auto& it : M) {
		A.push_back(it);
	}

	// Sort using comparator function
	sort(A.begin(), A.end(), cmp);

	// Print the sorted value
	for (auto& it : A) {

		cout << it.first << ' '
			<< it.second << endl;
	}
}

// Driver Code
int main()
{

	// Declare Map
	map<int, int> M;

	// Given Map
	// M = { { "GfG", 3 },
	// 	{ "To", 2 },
	// 	{ "Welcome", 1 } };
    M={{1,2},{}}
	// Function Call
	sort(M);
	return 0;
}
