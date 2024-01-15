/**
 * Given a string containing only three types of characters: ‘(‘, ‘)’ and ‘*’, write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
*/


class Solution {
public:
    bool checkValidString(string ss) {
        const int l=ss.size();
        m_=vector<vector<int>>(l,vector<int>(l,-1));
        return dfs(ss,0,l-1);
    }
private:
   vector<vector<int>> m_;
   bool dfs(const string& ss,int s,int e)
   {
       if(s>e) return true;
       if(m_[s][e]>=0) return m_[s][e];
       if(s==e) return m_[s][e]=((ss[s]=='*')&&(ss[e]=='*'));
       if((ss[s]=='('||ss[s]=='*')&&(ss[e]==')'||ss[e]=='*'))
          if(dfs(ss,s+1,e-1))
            return m_[s][e]=1;
        
       for(int p=s;p<e;++p)
       {
           if(dfs(ss,s,p)&&dfs(ss,p+1,e))
             return m_[s][e]=1;
       }
       return m_[s][e]=0;
   }
};



class Solution {
public:
    bool checkValidString(string s) {
        int minOP=0;
        int maxOP=0;
        for(char c:s)
        {
            if(c=='(')
                minOP++;
            else
                minOP--;
            if(c!=')')
                ++maxOP;
            else
                --maxOP;
            if(maxOP<0)
                return false;
            minOP=max(0,minOP);
        }
        return minOP==0;
    }
};