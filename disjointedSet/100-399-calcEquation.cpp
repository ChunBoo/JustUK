
/*
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]

*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

class Union {
public: 
    vector<int> f;     //parents
    vector<double> d;  //distance

    Union(int n) {
        f = vector<int> (n);
        d = vector<double> (n , 1.0);
        for(int i = 0; i < n; i++) f[i] = i;
    }

    int find(int x) {
        if(f[x] == x) return x;
        int root = find(f[x]);
        d[x] *= d[f[x]];
        f[x] = root;
        return root;
    }

    void merge(int a , int b , double v) {
        int fa = find(a) , fb = find(b);
        if(fa == fb) return ;
        f[fa] = fb;
        // d[fa] * d[a] = d[b] * v
        d[fa] = d[b] * v / d[a];
    } 

    double getDistance(int a , int b) {
        int fa = find(a) , fb = find(b);
        if(fa != fb) return -1;
        return d[a] / d[b];
    }
};


class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string , int> mapper;
        vector<double> res;
        int idx = 0;

        for(size_t i = 0; i < equations.size(); i++) {
            if(!mapper.count(equations[i][0])) mapper[equations[i][0]] = idx++;
            if(!mapper.count(equations[i][1])) mapper[equations[i][1]] = idx++;
        }

        Union unions(equations.size() * 2);

        for(size_t i = 0; i < equations.size(); i++) {
            unions.merge(mapper[equations[i][0]] , mapper[equations[i][1]] , values[i]);
        }

        for(size_t i = 0; i < queries.size(); i++) {
            if(mapper.count(queries[i][0]) && mapper.count(queries[i][1])) {
                res.push_back(unions.getDistance(mapper[queries[i][0]] , mapper[queries[i][1]]));
            }else res.push_back(-1);
        }

        return res;
    }
};


int main()
{
    using VEC=vector<vector<string>>;
    using VAL=vector<double>;

    VEC equations = {{"a","b"},{"b","c"}},queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    VAL values = {2.0,3.0};
    VAL res=Solution().calcEquation(equations,values,queries);
    for(auto &f:res)
        cout<<f<<',';

}