/**
 * You have a data structure of employee information, including the employee's unique ID, importance value, and direct subordinates' IDs.

You are given an array of employees employees where:

employees[i].id is the ID of the ith employee.
employees[i].importance is the importance value of the ith employee.
employees[i].subordinates is a list of the IDs of the direct subordinates of the ith employee.
Given an integer id that represents an employee's ID, return the total importance value of this employee and all their direct and indirect subordinates.

Input: employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]], id = 1
Output: 11
Explanation: Employee 1 has an importance value of 5 and has two direct subordinates: employee 2 and employee 3.
They both have an importance value of 3.
Thus, the total importance value of employee 1 is 5 + 3 + 3 = 11.
*/


/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {

public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int,Employee*> es;
        for(auto e:employees)
            es[e->id]=e;
        return dfs(id,es);
    }
private:
    int dfs(int id,map<int,Employee*> es)
    {
        const auto e=es.at(id);
        int sum=e->importance;
        for(int rid:e->subordinates)
            sum+=dfs(rid,es);
        return sum;
    }

};

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*> es;
        for(auto e:employees)
            es.emplace(e->id,e);

        queue<int> q{};
        q.push(id);
        int ans=0;
        while(!q.empty())
        {
            int curID=q.front();
            q.pop();
            auto e=es[curID];
            ans+=e->importance;
            for(auto s:e->subordinates)
                q.push(s);
        }
        return ans;
    }
};