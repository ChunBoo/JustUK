/**
 * A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
 * 
*/
#include<iostream>
#include<unordered_set>
#include<vector>
#include<queue>
#include<string>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       unordered_set<string> dict{wordList.begin(),wordList.end()};
       if(!dict.count(endWord)) return 0;

       int l=beginWord.length();
       queue<string> q;
       q.push(beginWord);
       int step=0;
       int cnt=0;
       while(!q.empty()){
        ++step;
        cout<<"queue.size= "<<q.size()<<'\n';
        for(size_t size=0;size<q.size();++size)  //here can not go through from 0 to q.size()
        {
            cnt+=1;
            cout<<"count= "<<cnt<<'\n';
            string w=q.front();
            q.pop();
            for(int i=0;i<l;++i)
            {
                char ch=w[i];
                for(char c='a';c<='z';++c)
                {
                    w[i]=c;
                    if(w==endWord) return step+1;
                    if(!dict.count(w)) continue;
                    dict.erase(w);
                    q.push(w);
                }
                w[i]=ch;
            }
        }

       }
       return 0;
    }
};

int main()
{
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout<<Solution().ladderLength(beginWord,endWord,wordList);
}