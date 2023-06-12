/*
Suppose we have a boolean expression, we have to find the result after evaluating that expression.

An expression can either be −

"t", evaluating to True;

"f", evaluating to False;

"!(expression)", evaluating to the logical NOT of the inner expression;

"&(expr1,expr2,...)", evaluating to the logical AND of 2 or more inner expressions;

"|(expr1,expr2,...)", evaluating to the logical OR of 2 or more inner expressions;

So, if the input is like "|(!(t),&(t,f,t))", then the output will be fasle, 
this is because !(t) is false, then &(t,f,t) is also false, so the OR of all false values will be false.
*/
#include<string>
#include<iostream>

using STR=std::string;
using std::cout;

class Solution{
    public:
        bool parseBoolExpr(STR expression)
        {
            int s=0;
            return parse(expression,s);
        }

    private:
        bool parse(const STR& exp,int& s){
            char ch=exp[s++];
            switch(ch){
                case 't':
                    return true;
                case 'f':
                    return false;
                case '!':
                    bool ans=!parse(exp,++s);
                    ++s;
                    return ans;
            }
            bool isAnd= (ch=='&');
            bool ans=isAnd;
            ++s;
            while(true)
            {
                if(isAnd)
                    ans&= parse(exp,s);
                else
                    ans|=parse(exp,s);
                if(exp[s++]==')')
                    break;
            }
            return ans;
        }
};

int main()
{
    STR s{"|(!(t),&(t,t,t))"};
    cout<<Solution().parseBoolExpr(s);
}