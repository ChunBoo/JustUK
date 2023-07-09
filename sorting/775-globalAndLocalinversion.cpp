class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        const int n=nums.size();
        int local=0;
        for(int i=0;i<n-1;++i)
            if(nums[i]>nums[i+1]) ++local;
        tmp=vector<int>(n);
        long global=mergeSort(nums,0,n-1);
        return global==local;
    }
private:
    vector<int> tmp;
    int mergeSort(vector<int>& a,int l,int r)
    {
        if(l>=r)
            return 0;
        const int len=r-l+1;
        int m=(r-l)/2+l;
        long inv=mergeSort(a,l,m)+mergeSort(a,m+1,r);
        int i=l;
        int j=m+1;
        int k=0;
        while(i<=m &&j<=r)
        {
            if(a[i]<=a[j])
                tmp[k++]=a[i++];
            else
            {
                tmp[k++]=a[j++];
                inv+=m-i+1;
            }
        }
        while(i<=m) tmp[k++]=a[i++];
        while(j<=r) tmp[k++]=a[j++];
        std::copy(tmp.begin(),tmp.begin()+len,a.begin()+l);
        return inv;
    }
};