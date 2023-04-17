#include<random>
#include<iostream>
#include<vector>

using std::cout;
using VEC=std::vector<int>;
using std::vector;
/*
 void QuickSorting( VEC& nums)
{
    int n=nums.size();
    if(n<=1)
        return ;
    int randIndex=rand()%n;
    int pivot=nums[randIndex];
    VEC smaller{};
    VEC equal{};
    VEC greater{};

    for(auto &i:nums)
    {
        if(i<pivot)
            smaller.push_back(i);
        if(i==pivot)
            equal.push_back(i);
        if(i>pivot)
            greater.push_back(i);
    }
    //extend
    QuickSorting(smaller);
    QuickSorting(greater);
    smaller.reserve(smaller.size()+distance(equal.begin(),equal.end()));
    smaller.insert(smaller.end(),equal.begin(),equal.end());
    smaller.reserve(smaller.size()+distance(greater.begin(),greater.end()));
    smaller.insert(smaller.end(),greater.begin(),greater.end());
    // return smaller;
}
*/
    int partition(vector<int>& nums,int low,int high){
        int pivot = nums[low];
        while(low<high) {
            while(low<high && nums[high]>=pivot)--high;
            nums[low] = nums[high];
            while(low<high && nums[low]<=pivot) ++low;
            nums[high] = nums[low];
        }
        nums[low] = pivot;
        return low;
            
    }
    void QuickSort(vector<int>& nums,int low,int high,int n){
        
        if(low<high) {
            int pivotpos = partition(nums,low,high);
            QuickSort(nums,low,pivotpos-1,n);
            QuickSort(nums,pivotpos+1,high,n);
        }
    }


int main()
{
    VEC nums{5,2,1};
    //VEC res=
    QuickSort(nums,0,2,3);
    for(auto &v:nums)
        cout<<v<<',';
}