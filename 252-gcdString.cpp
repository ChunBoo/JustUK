/*
two strings s and t, we say “t divides s” if and only if s = t + … + t (t concatenated with itself 1 or more times) 
Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

Example 1:
Input: str1 = “ABCABC”, str2 = “ABC”
Output: “ABC”

Example 2:
Input: str1 = “ABABAB”, str2 = “ABAB”
Output: “AB”

Example 3:
Input: str1 = “LEET”, str2 = “CODE”
Output: “”

Example 4:
Input: str1 = “ABCDEF”, str2 = “ABC”
Output: “”

str1 and str2 consist of English uppercase letters.

The greatest common divisor must be a prefix of each string, so we can try all prefixes

*/
#include<cmath>
#include<string>
#include<iostream>
#include<numeric>

//If two strings have a non-empty GCD string/prefix, 
//it must satisfy that A+B is B+A. After passing the test, we then use the GCD function to get the length of the prefix.
std::string gcdString(std::string& s,std::string& t)
{
    if(s+t!=t+s)
        return "";
    int k=std::gcd(s.size(),t.size());
    return s.substr(k);
}

int main()
{
    std::string a{"abab"},b{"ababab"};
    std::cout<<gcdString(a,b);
    return 0;
}










