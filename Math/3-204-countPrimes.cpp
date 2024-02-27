/**
 * @brief The statement "if \(y\) is a factor of \(x\), then the value of \(x/y\) is also a factor of \(x\)" is true by the definition of what it means for one number to be a factor of another.
Explanation:
Definition of a Factor: If \(y\) is a factor of \(x\), it means that \(x\) can be divided by \(y\) without leaving a remainder. In other words, there exists an integer \(k\) such that \(x = y \times k\).
Implication: Given \(x = y \times k\), dividing both sides of the equation by \(y\) gives \(x/y = k\). This means that \(k\) (which is \(x/y\)) is an integer.
Conclusion: Since \(x = y \times k\) and \(k\) is an integer, \(k\) (or \(x/y\)) is also a factor of \(x\), because by definition, a factor of a number is an integer that can multiply with another integer to yield the original number.
Example:
Consider \(x = 12\) and \(y = 3\):
\(y\) is a factor of \(x\) because \(12\) can be divided by \(3\) without leaving a remainder, yielding \(4\).
The value of \(x/y = 12/3 = 4\), which is also a factor of \(12\) because \(12\) can be divided by \(4\) without leaving a remainder.
This demonstrates that if \(y\) is a factor of \(x\), then \(x/y\) is also a factor of \(x\), following directly from the definition of what it means to be a factor.
 * 
 */
class Solution {
public:
    int countPrimes(int n) {
        int ans=0;
        m_=vector<bool>(n,true);
        for(int i=2;i<n;++i)
            if(m_[i])
            {
                ans+=1;
                if((long long)i*i<n){
                    for(int j=i*i;j<n;j+=i)
                        m_[j]=false;
                }
            }
        return ans;
    }
private:
    vector<bool> m_;
    // bool isPrime(int x){

    //     for(int i=2;i*i<=x;++i)
    //     {   
            
    //         if(x%i==0)
    //             return false;
    //     }
    //     return true;
    // }
};