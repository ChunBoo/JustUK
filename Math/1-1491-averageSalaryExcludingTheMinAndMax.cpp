/***
 * You are given an array of unique integers salary where salary[i] is the salary of the ith employee.

Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.

 

Example 1:

Input: salary = [4000,3000,1000,2000]
Output: 2500.00000
Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500
Example 2:

Input: salary = [1000,2000,3000]
Output: 2000.00000
Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
Average salary excluding minimum and maximum salary is (2000) / 1 = 2000
 

Constraints:

3 <= salary.length <= 100
1000 <= salary[i] <= 106
All the integers of salary are unique.
*/


class Solution {
public:
    double average(vector<int>& salary) {
        const int n=salary.size();
        // int maxSalary=0, minSalary=salary[0];

        // long sum=0;
        // for(auto &v:salary){
        //     sum+=v;
        //     maxSalary=max(maxSalary,v);
        //     minSalary=min(minSalary,v);
        // }
        // sum-=maxSalary;
        // sum-=minSalary;
        // cout<<sum;
        // return (double)sum/(n-2);
        //2nd method

        // sort(salary.begin(),salary.end());//sort array as descending order
        // long sum=accumulate(salary.begin(),salary.end(),0);
        // return double(sum-salary[0]-salary[n-1])/(n-2);

        /*3rd method*/
        double maxVal=*max_element(begin(salary),end(salary));
        double minVal=*min_element(begin(salary),end(salary));
        double sumVal=accumulate(begin(salary),end(salary),-maxVal-minVal);
        return sumVal/(n-2);
    }
};