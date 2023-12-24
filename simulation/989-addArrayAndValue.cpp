

/**
 * The array-form of an integer num is an array representing its digits in left to right order.

For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.

 

Example 1:

Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
Example 2:

Input: num = [2,7,4], k = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
Example 3:

Input: num = [2,1,5], k = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
 

Constraints:

1 <= num.length <= 104
0 <= num[i] <= 9
num does not contain any leading zeros except for the zero itself.
1 <= k <= 104
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {


        vector<int> kVal;
        vector<int> newNum,newK;
        convertToArray(k,kVal);
              if(k==0)
            return num;
        int m=num.size(),n=kVal.size();
        if(m==0)
            return kVal;
  
        cout<<"---"<<m<<"+++"<<n;
        int diff=m-n;
        if(diff<0)
        {
            for(int i=0;i<abs(diff);++i)
                newNum.push_back(0);
            for(int j=0;j<m;++j)
            {
                newNum.push_back(num[j]);
                cout<<j<<'-'<<num[j]<<'\n';
            }
        reverse(begin(num),end(num));

        }
        else
        {
            reverse(kVal.begin(),kVal.end());
            for(int i=0;i<abs(diff);++i)
               newK.push_back(0);
            for(int j=0;j<n;++j)
                newK.push_back(kVal[j]);
            newNum=num;
        }
        int carry=0;
         vector<int> ans;
         
        for(int i=0;i<max(m,n);++i)
        {
            int sum=newK[i]+newNum[i]+carry;
            cout<<newK[i]<<","<<newNum[i]<<","<<sum<<'\n';
            ans.push_back(sum%10);
            carry=sum/10;
            sum/=10;
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
private:
    void convertToArray(int k,vector<int>& array)
    {
        while(k)
        {
            int d=k%10;
            array.push_back(d);
            k/=10;
        }
    }
};

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        for(int i=num.size()-1;i>=0||k>0;--i){
            k+=(i>=0?num[i]:0);
            ans.push_back(k%10);
            k/=10;
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};
int main()
{
    vector<int> num{1,2,0,0};
    int k=34;
    vector<int> res=Solution().addToArrayForm(num,k);
    for(auto v:res)
        cout<<v<<',';
}