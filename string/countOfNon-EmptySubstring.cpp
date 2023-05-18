/*
Input : str = “abc” 
Output : 6 
Every substring of the given string : “a”, “b”, “c”, “ab”, “bc”, “abc”

Input : str = “abcd” 
Output : 10 
Every substring of the given string : “a”, “b”, “c”, “d”, “ab”, “bc”, “cd”, “abc”, “bcd” and “abcd”
*/

/*
Count of non-empty substrings is n*(n+1)/2
If we include empty string also as substring, the count becomes n*(n+1)/2 + 1

How does above formula work?  

Number of substrings of length one is n (We can choose any of the n characters)
Number of substrings of length two is n-1 (We can choose any of the n-1 pairs formed by adjacent)
Number of substrings of length three is n-2 
(We can choose any of the n-2 triplets formed by adjacent)
In general, number of substrings of length k is n-k+1 where 1 <= k <= n
Total number of substrings of all lengths from 1 to n = 
n + (n-1) + (n-2) + (n-3) + … 2 + 1 
= n * (n + 1)/2
*/

// CPP program to count number of substrings
// of a string
#include <bits/stdc++.h>
using namespace std;

int countNonEmptySubstr(string str)
{
int n = str.length();
return n*(n+1)/2;
}

// driver code
int main()
{
	string s = "abcde";
	cout << countNonEmptySubstr(s);
	return 0;
}
