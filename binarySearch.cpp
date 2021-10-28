#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
class solution
{
    public:
        int binarySearch( std::vector<int>& iValVector,int value)
        {
            std::vector<int> retVector;
            if(iValVector.empty())
                return 0;
            std::sort(iValVector.begin(),iValVector.end());
            int vectorSize=iValVector.size();

            int low=0,high=vectorSize;

            while(low<=high)
            {
                int middle=(low+high)/2;
                int tempValue=iValVector[middle];
                if(tempValue==value)
                    return middle;
                else if(tempValue<value)
                    low=middle+1;
                else
                    high=middle-1;
                
            }
            return 0;

        }
};

int main()
{
    std::vector<int> valVector{1,2,3,4,5,6};
    solution s;
    int position=s.binarySearch(valVector,5);
    if(position)
        std::cout<<"Found the value,at postion: "<<position+1<<'\n';
    else
        std::cout<<"Can not find the value.\n";
    return 0;
}