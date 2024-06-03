/**
 * @brief We distribute some number of candies, to a row of n = num_people people in the following way:

We then give 1 candy to the first person, 2 candies to the second person, and so on until we give n candies to the last person.

Then, we go back to the start of the row, giving n + 1 candies to the first person, n + 2 candies to the second person, and so on until we give 2 * n candies to the last person.

This process repeats (with us giving one more candy each time, and moving to the start of the row after we reach the end) until we run out of candies.  The last person will receive all of our remaining candies (not necessarily one more than the previous gift).

Return an array (of length num_people and sum candies) that represents the final distribution of candies.

 

Example 1:

Input: candies = 7, num_people = 4
Output: [1,2,3,1]
Explanation:
On the first turn, ans[0] += 1, and the array is [1,0,0,0].
On the second turn, ans[1] += 2, and the array is [1,2,0,0].
On the third turn, ans[2] += 3, and the array is [1,2,3,0].
On the fourth turn, ans[3] += 1 (because there is only one candy left), and the final array is [1,2,3,1].
Example 2:

Input: candies = 10, num_people = 3
Output: [5,2,3]
Explanation: 
On the first turn, ans[0] += 1, and the array is [1,0,0].
On the second turn, ans[1] += 2, and the array is [1,2,0].
On the third turn, ans[2] += 3, and the array is [1,2,3].
On the fourth turn, ans[0] += 4, and the final array is [5,2,3].
 * 
 */

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people,0);

        // int round=1;
        // while(candies>0){
        //     for(int i=1;i<=num_people;i++){
        //         int nextCnt=((round-1)*num_people+i)>candies?candies:((round-1)*num_people+i);
        //         ans[i-1]+=nextCnt;
        //         candies-=nextCnt;
        //     }
        //     round+=1;
        // }   
        // return ans;

        // int cnt=0;
        // while(candies>0){
        //     ans[cnt%num_people] += min(candies,cnt+1);
        //     candies -= min(candies,cnt+1);
        //     ++cnt;
        // }
        // return ans;

        int p=(int)(sqrt(2*candies+0.25)-0.5);
        int remaining=(int)(candies-(p+1)*p*0.5);
        int rows=p/num_people,cols=p%num_people;

        for(int i=0;i<num_people;i++){
            //complete rows
            ans[i]=(i+1)*rows+(int)(rows*(rows-1)*0.5)*num_people;
            if(i<cols)
                ans[i]+=i+1+rows*num_people;
        }
        ans[cols]+=remaining;
        return ans;
    }
};