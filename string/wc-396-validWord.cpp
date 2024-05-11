
#include<iostream>
#include<string>

using namespace std;



class Solution {
public:
    bool isValid(string word) {
        int n=word.length();
        if(n<3)
            return false;
        
        bool foundVowel=false, foundConsonant=false;
        string vowels="aeiou";
        string invalid="@#$";
        for(char c:word){
            auto n_=vowels.find(tolower(c));
            auto  m_=invalid.find(c);
            if(m_!=string::npos)
            {
                return false;
            }
           
            if(n_!=string::npos)
                foundVowel=true;
            else if(isdigit(c))
                foundConsonant=true;
              
        }
        return foundVowel&&foundConsonant;//&&foundDigit;
    }
};


int main(){
    string word ="UuE6";
    cout<<Solution().isValid(word);
}