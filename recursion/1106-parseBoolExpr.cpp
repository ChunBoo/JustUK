class Solution{
    public:
        bool parseBoolExpr(string expression)
        {
            int s=0;
            return parse(expression,s);
        }

    private:
        bool parse(const string& exp,int& s){
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