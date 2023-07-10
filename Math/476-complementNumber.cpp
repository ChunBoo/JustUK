class Solution {
public:
    int findComplement(int num) {
            unsigned  int mask=~0;
        while(num&mask) mask<<=1;
        return ~num^mask;
    }
};

class Solution {
public:
    int findComplement(int num) {
        int mask=1;
        while(num&mask) mask<<=1;
        return ~num^mask;
        // vector<int> tmp;
        // while(num)
        // {
        //     tmp.push_back(num%2);
        //     num/=2;
        // }
        // long long ans=0;
        // for(auto i:tmp)
        // {
        //     ans=ans*2+i^1;
        // }
        // return ans;
    }
};