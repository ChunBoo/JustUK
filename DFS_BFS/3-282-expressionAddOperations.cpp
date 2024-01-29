/**
 * Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples:

"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
*/

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        dfs(num,target,0,"",0,0,&ans);
        return ans;
    }
private:
    void dfs(const string& num,const int target,//input)
              int pos,const string& exp,long prev,long curr,//state
              vector<string>* ans){//output
              if(pos==num.length())
              {
                if(curr==target)
                    ans->push_back(exp);
                return;
              }
              for(int l=1;l<=num.size()-pos;++l)
              {
                  string t=num.substr(pos,l);
                  if(t[0]=='0'&&t.length()>1)
                    break;
                  long n=std::stol(t);
                  if(n>INT_MAX)
                    break;
                
                  if(pos==0)
                  {
                      dfs(num,target,l,t,n,n,ans);
                      continue;
                  }
                  dfs(num,target,pos+l,exp+'+'+t,n,curr+n,ans);
                  dfs(num,target,pos+l,exp+'-'+t,-n,curr-n,ans);
                  dfs(num,target,pos+l,exp+'*'+t,prev*n,curr-prev+prev*n,ans);
              }
              }
};