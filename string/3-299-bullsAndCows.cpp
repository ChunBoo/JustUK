
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        const int n=secret.size();
        int bulles=0,cows=0;
        int cntG[10]{},cntS[10]{};
        for(int i=0;i<n;++i){
            if(secret[i]==guess[i])
                bulles++;
            else
            {
                cntS[secret[i]-'0']++;
                cntG[guess[i]-'0']++;
            }
        }

        for(int i=0;i<10;++i){
            cows += min(cntG[i],cntS[i]);
        }

        return to_string(bulles)+"A"+to_string(cows)+"B";
    }
};

int main(){
    string secret = "1807", guess = "7810";
    cout<<Solution().getHint(secret,guess);
}