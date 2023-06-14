/**
 * 
 * Nearly everyone has used the Multiplication Table. 
   The multiplication table of size m x n is an integer matrix mat where mat[i][j] == i * j (1-indexed).
   Given three integers m, n, and k, return the kth smallest element in the m x n multiplication table.
*/
#include<iostream>
#include<cmath>
using std::cout;

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l=1, r=m*n+1;
        while(l<r){
            int x=l+(r-l)/2;
            if(LEX(m,n,x)>=k)
                r=x;
            else
                l=x+1;
        }
        return l;
    }
private:
    int LEX(int m,int n,int x){
        int count=0;
        for(int i=1;i<=m;++i)
            count+=std::min(n,x/i);
        return count;
    }
};

int main()
{
    int m=3,n=3,k=7;
    int res=Solution().findKthNumber(m,n,k);
    cout<<res<<'\n';
}