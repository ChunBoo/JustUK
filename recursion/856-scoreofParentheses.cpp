/**
 * Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 

Example 1:

Input: s = "()"
Output: 1
Example 2:

Input: s = "(())"
Output: 2
Example 3:

Input: s = "()()"
Output: 2

 * 
 * 
*/
#include <iostream>
#include <string>
using namespace std;

class Solution1 {
public:
    int scoreOfParentheses(string s) {
        return score(s,0,s.length()-1);
    }
private:
    int score(const string& s,int l,int r){
        if(r-l==1) return 1;
        int b=0;
        for(int i=l;i<r;++i){
            if(s[i]=='(') ++b;
            if(s[i]==')') --b;
            if(b==0)
                return score(s,l,i)+score(s,i+1,r);
        }
        return 2*score(s,l+1,r-1);
    }
};

class Solution2 {
public:
    int scoreOfParentheses(string s) {
        int ans=0;
        int d=-1;
        for (int i = 0; i < int(s.length()); ++i) {
          d += s[i] == '(' ? 1 : -1;
          if (s[i] == '(' && s[i + 1] == ')')
            ans += 1 << d;
        }
        return ans;
    }
};

int main() {
  string s = "(())";
  cout << Solution1().scoreOfParentheses(s);
}