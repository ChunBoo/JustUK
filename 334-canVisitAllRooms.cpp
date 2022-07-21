/*
There are N rooms and you start in room 0. Each room has a distinct number in 0, 1, 2, …, N-1, and each room may have some keys to access the next room.

Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an integer in [0, 1, …, N-1] where N = rooms.length. A key rooms[i][j] = v opens the room with number v.

Initially, all the rooms start locked (except for room 0).

You can walk back and forth between rooms freely.

Return true if and only if you can enter every room.

Example 1:
Input: [[1],[2],[3],[]]
Output: true
Explanation:
We start in room 0, and pick up key 1.
We then go to room 1, and pick up key 2.
We then go to room 2, and pick up key 3.
We then go to room 3. Since we were able to go to every room, we return true.

Example 2:
Input: [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can’t enter the room with number 2.
Note:
1 <= rooms.length <= 1000
0 <= rooms[i].length <= 1000
The number of keys in all rooms combined is at most 3000.
*/
//https://helloacm.com/depth-first-search-and-breadth-first-search-algorithm-to-open-the-doors-to-the-rooms-with-keys/
#include<vector>
#include<unordered_set>
#include<stack>
#include<queue>
#include<iostream>
using DT=std::vector<std::vector<int>>;
class Solution
{
    public:
        bool canVisitAllRooms_D(const DT& rooms)
        {
            dfs(0,rooms);
            return seen.size()==rooms.size();
        }
        bool canVisitAllRooms_Stack(const DT& rooms)
        {
            std::stack<int> s;
            s.push(0);
            while(!s.empty())
            {
                int room=s.top();
                s.pop();
                if(seen.count(room))
                    continue;
                seen.insert(room);
                for(auto &r:rooms[room])
                {
                    s.push(r);
                }
            }
            return seen.size()==rooms.size();
        }

        bool canVisitAllRooms_BFS(const DT& rooms)
        {
            std::queue<int> q;
            q.push(0);
            while(!q.empty())
            {
                int room=q.front();
                q.pop();
                if(seen.count(room))
                    continue;
                seen.insert(room);
                for(auto &r:rooms[room])
                    q.push(r);
            }
            return seen.size()==rooms.size();
        }

    private:
        std::unordered_set<int> seen{};  //operations: insert,count
        void dfs(int room,const DT& rooms)
        {
            if(seen.count(room))
                return;
            seen.insert(room);
            for(auto &r:rooms[room])
                dfs(r,rooms);
        }
};


int main()
{
    DT rooms{{1},{1,3},{3},{2}};
    Solution s;
    std::cout<<s.canVisitAllRooms_D(rooms)<<'\n';
    std::cout<<s.canVisitAllRooms_BFS(rooms)<<'\n';
    std::cout<<s.canVisitAllRooms_Stack(rooms)<<'\n';

    return 0;
}