/**
 * Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1:

Input: "2-1-1".

1
2
((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]

Example 2:

Input: "2*3-4*5"

1
2
3
4
5
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]

Solution:

Running time: 3ms
*/

namespace operation{
    int add(int x,int y){return x+y;}
    int minus(int x,int y){return x-y;}
    int multiply(int x,int y){return x*y;}
}

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return ways(expression);
    }
private:
    unordered_map<string,vector<int>> m_;
    const vector<int>& ways(const string& input)
    {
        if(m_.count(input))
            return m_[input];
        vector<int> ans;

        for(int i=0;i<input.length();++i)
        {
            char op=input[i];
            if(op=='+'||op=='-'||op=='*')
            {
                const string left=input.substr(0,i);
                const string right=input.substr(i+1);
                const vector<int>& l=ways(left);
                const vector<int>& r=ways(right);
                std::function<int(int,int)> f;
                switch(op)
                {
                    case '+':f=operation::add;break;
                    case '-':f=operation::minus;break;
                    case '*':f=operation::multiply;break;
                }
                //combine
                for(int a:l)
                    for(int b:r)
                        ans.push_back(f(a,b));
            }
        }
        if(ans.empty())
            ans.push_back(std::stoi(input));
        
        //memorize the answer for input
        m_[input].swap(ans);
        return m_[input];
    }
};