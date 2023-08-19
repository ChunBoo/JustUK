#include<vector>
using namespace std;


class FenwickTree{
    private:
     vector<int> sums_;
     static inline int lowbit(int x){return x&(-x);}
    public:
        FenwickTree(int n):sums_(n+1,0){}
        void update(int i,int delta){
            while(i<sums_.size()){
                sums_[i]+=delta;
                i+=lowbit(i);
            }
        }

        int query(int i) const {
            int sum=0;
            while(i>0){
                sum+=sums_[i];
                i-=lowbit(i);
            }
            return sum;
        }

};