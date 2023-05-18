class Solution:
    def countSubstrings(self, s):
        '''
        Find number of palindromic strings in s. bruteForce method
        Args:
            s (str): String to analyze
        Returns:
            int: Count of palindromes
        '''
        palindromes = 0
        for i in range(len(s)):
            for j in range(i, len(s)):
                if s[i:j] == s[j:i:-1]:
                    palindromes += 1
        return palindromes
    
    def countSubstrings2(self,s):
        '''
        This solution builds up palindromes one character at a time on each end of the substring. 
        It has to run two while loops for each character in the string s:
               one for odd length palindromes and one for even length palindromes.
        '''
        ans=0
        for i in range(len(s)):
            left,right=i,i
            while(left>=0 and right<len(s) and s[left]==s[right]):
                ans+=1
                left-=1
                right+=1
            
            left,right=i,i+1
            while(left>=0 and right<len(s) and s[left]==s[right]):
                ans+=1
                left-=1
                right+=1
                
        return ans
    
s="aaa"
print(Solution().countSubstrings(s))
print(Solution().countSubstrings2(s))

    
    