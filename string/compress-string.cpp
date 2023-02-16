/*
Write a program to do basic string compression. For a character which is consecutively repeated more than once, replace consecutive duplicate occurrences with the count of repetitions.
For e.g. if a String has 'x' repeated 5 times, replace this "xxxxx" with "x5".
Note : Consecutive count of every character in input string is less than equal to 9.
Input Format :

Input string S

Output Format :

Compressed string 

Sample Input:

aaabbccdsa

Sample Output:

a3b2c2dsa


*/

// input - given string
// You need to update in the given string itself i.e. in input. No need to return or print.
#include <bits/stdc++.h>
#include <iostream>
// #include "solution.h"
using namespace std;

using STR=std::string;

STR stringCompression(const STR& s)
{
    STR ans{};
    int n=s.size();
    for(int start=0;start<n;)
    {
        int e=start+1;
        while(s[e]==s[start])
            e+=1;
        int cnt=e-start;
        ans+=('0'+cnt);  //should use '0'+number to convert the integer as character,but char(int) will not work
        ans+=s[start];
        start=e;
    }
    return ans;
}


void stringCompression(char input[]) {
    string ans="";
    
    for(int i=0;input[i]!=0;){
        int j=i+1;
        while(input[i]==input[j]){
            j++;
        }
        int c=j-i;
        char cd='0'+c;
        if (c!=0 && c!=1){
            ans+=input[i];
            ans+=(char)(cd);
        }
        else
            ans+=input[i];
        i=j;
    }
    strcpy(input,ans.c_str());

}



int main() {
    // char input[1000];
    // cin.getline(input, 1000);
    // stringCompression(input);
    // cout << input << endl;

    STR ts{"11211"};
    cout<<stringCompression(ts);
}