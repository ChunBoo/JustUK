/**
 * n the "100 game" two players take turns adding, to a running total, any integer from 1 to 10. 
 The player who first causes the running total to reach or exceed 100 wins.

What if we change the game so that players cannot re-use integers?

For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without replacement until they reach a total >= 100.

Given two integers maxChoosableInteger and desiredTotal, 
return true if the first player to move can force a win, otherwise, return false. Assume both players play optimally.

 

Example 1:

Input: maxChoosableInteger = 10, desiredTotal = 11
Output: false
Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.
Example 2:

Input: maxChoosableInteger = 10, desiredTotal = 0
Output: true
Example 3:

Input: maxChoosableInteger = 10, desiredTotal = 1
Output: true
*/
#include<vector>
#include<iostream>

using namespace std;


class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        const  int sum=maxChoosableInteger*(maxChoosableInteger+1)/2;
        if(sum<desiredTotal) return false;
        if(desiredTotal<=0) return true;
        m_=vector<char>(1<<maxChoosableInteger,0);  //why we need this vector, and set the lenght is 2^M
        return canWin(maxChoosableInteger,desiredTotal,0);
    }
private:
    vector<char> m_;            //0:unknown,1:can win, -1:can not win
    bool canWin(int M,int T,int state){
        if(T<=0) return false;
        if(m_[state]) return m_[state]==1;
        for(int i=0;i<M;++i){
            if(state&(1<<i)) continue;  //number i has used
            if(!canWin(M,T-(i+1),state|(1<<i)))
                return (m_[state]=1);
        }
        m_[state]=-1;
        return false;
    }
};

int main()
{
    int T=3, M=2;
    cout << Solution().canIWin(M,T);
}