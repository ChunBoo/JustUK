/***
 * A sentence is a string of single-space separated words 
 * where each word can contain digits, lowercase letters,
 *  and the dollar sign '$'. 
 * A word represents a price if it is a sequence of digits preceded by a dollar sign.

For example, "$100", "$23", and "$6" represent prices while "100", "$", and "$1e5" do not.
You are given a string sentence representing a sentence and an integer discount. 
For each word representing a price, 
apply a discount of discount% on the price and update the word in the sentence. 
All updated prices should be represented with exactly two decimal places.

Return a string representing the modified sentence.

Note that all prices will contain at most 10 digits.

 

Example 1:

Input: sentence = "there are $1 $2 and 5$ candies in the shop", discount = 50
Output: "there are $0.50 $1.00 and 5$ candies in the shop"
Explanation: 
The words which represent prices are "$1" and "$2". 
- A 50% discount on "$1" yields "$0.50", so "$1" is replaced by "$0.50".
- A 50% discount on "$2" yields "$1". 
Since we need to have exactly 2 decimal places after a price, we replace "$2" with "$1.00".
Example 2:

Input: sentence = "1 2 $3 4 $5 $6 7 8$ $9 $10$", discount = 100
Output: "1 2 $0.00 4 $0.00 $0.00 7 8$ $0.00 $10$"
Explanation: 
Applying a 100% discount on any price will result in 0.
The words representing prices are "$3", "$5", "$6", and "$9".
Each of them is replaced by "$0.00".
 

Constraints:

1 <= sentence.length <= 105
sentence consists of lowercase English letters, digits, ' ', and '$'.
sentence does not have leading or trailing spaces.
All words in sentence are separated by a single space.
All prices will be positive numbers without leading zeros.
All prices will have at most 10 digits.
0 <= discount <= 100
 */

#include<string>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<iomanip>
using namespace std;

class Solution2 {
public:
    string discountPrices(string sentence, int discount) {
        double d = 1 - discount / 100.0;
        stringstream ss(sentence);
        string ans, w;
        while (ss >> w) { 
            if (!ans.empty()) {
                ans += ' ';
            }
            if (w.length() > 1 && w[0] == '$' && all_of(w.begin() + 1, w.end(), ::isdigit)) {
                stringstream s;
                s << fixed << setprecision(2) << '$' << stoll(w.substr(1)) * d;
                ans += s.str();
            } else {
                ans += w;
            }
        }
        return ans;
    }
};

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        stringstream sin(sentence),sout;
        sout<<fixed<<setprecision(2);

        // vector<string> words;
        string word;
        while(sin>>word){
            if(word[0]=='$'&&word.size()>1&&all_of(word.begin()+1,word.end(),::isdigit)){
                double price=stoll(word.substr(1,word.size()-1))*(1.0-discount/100.0);
                sout<<'$'<<price;
            }
            else{
                sout<<word;
            }
        
        sout<<" ";
        }
    string ans=sout.str();
    ans.pop_back();
    return ans;
    }
};

int main(){
    string sentence = "1 2 $3 4 $5 $6 7 8$ $9 $10$";
    int discount = 100;
    cout<<Solution().discountPrices(sentence,discount);
}