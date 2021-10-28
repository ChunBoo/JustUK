//palindrome,回文数
#include<iostream>
#include<string>

class Solution
{
    public:
        bool isPalindrome(std::string& s)
        {
            int sz=s.size();
            if(sz==0||sz==1)
                return true;
            int left =0,right=sz-1;
            while(left<right)
            {
                if(s[left]!=s[right])
                    return false;
                left++;
                right--;
            }    
            return true;
                    
        }
};


int main()
{
    Solution s;
    std::string str{"racefcar"};
    std::cout<<str<<" is a palindrome? "<<(s.isPalindrome(str)?"Yes":"No")<<"\n";
    return 0;
}