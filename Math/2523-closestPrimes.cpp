class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
       vector<int>  primes(right+1,1);
       primes[0]=primes[1]=0;
       for(int i=2;i<=sqrt(right);++i){
           if(!primes[i]) continue;
           for(int x=i*i;x<=right;x+=i)
                primes[x]=0;
       }
       vector<int> ans;
       for(int i=left,last=-1,best=INT_MAX;i<=right;++i){
           if(!primes[i]) continue;
           if(last>0&&i-last<best){
               best=i-last;
               ans={last,i};
           }
           last=i;
       }
       return ans.empty()?vector<int>{-1,-1}:ans;
    }
};