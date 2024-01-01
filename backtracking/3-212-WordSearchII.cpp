/**
 * Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where “adjacent” cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

Example:

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.
Solution 1: DFS
Time complexity: O(sum(m*n*4^l))
Space complexity: O(l)
*/

// class Solution {
// public:
//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//         vector<string> ans;
//         h_=board.size();
//         w_=board[0].size();
//         for(const string& word: words)
//         {
//             if(exist(board,word))
//                 ans.push_back(word);
//         }
//         return ans;
//     }

// private:
//     int h_;
//     int w_;
//     bool exist(vector<vector<char>>& board,const string& word)
//     {
//         for(int r=0;r<h_;++r){
//             for(int c=0;c<w_;++c){
//                 if(search(board,0,r,c,word))
//                     return true;
//             }
//         }
//         return false;
//     }
//     bool search(vector<vector<char>>& board,int d,int r,int c,const string& word)
//     {
//         if(r<0||r>=h_||c<0||c>=w_||word[d]!=board[r][c])
//             return false;
//         if(d==word.size()-1)
//             return true;
//         char curr=board[r][c];
//         board[r][c]='#';
//         bool found= search(board,d+1,r+1,c,word)
//                   ||search(board,d+1,r-1,c,word)
//                   ||search(board,d+1,r,c+1,word)
//                   ||search(board,d+1,r,c-1,word);
//         board[r][c]=curr;
//         return found;

//     }
// };

class Solution {
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    unordered_set<string> unique_words(words.begin(), words.end());
    vector<string> ans;
    for (const string& word : unique_words)
      if (exist(board, word))
        ans.push_back(word);
    return ans;
  }
private:
  int w;
  int h;
  bool exist(vector<vector<char>> &board, string word) {
    if (board.size() == 0) return false;
    h = board.size();
    w = board[0].size();
    for (int i = 0 ; i < w; i++)
      for (int j = 0 ; j < h; j++)
        if (search(board, word, 0, i, j)) return true;
    return false;
  }
    
  bool search(vector<vector<char>> &board, 
           const string& word, int d, int x, int y) {
    if (x < 0 || x == w || y < 0 || y == h || word[d] != board[y][x]) 
      return false;
 
    // Found the last char of the word
    if (d == word.length() - 1)
      return true;
 
    char cur = board[y][x];
    board[y][x] = '#'; 
    bool found = search(board, word, d + 1, x + 1, y)
              || search(board, word, d + 1, x - 1, y)
              || search(board, word, d + 1, x, y + 1)
              || search(board, word, d + 1, x, y - 1);
    board[y][x] = cur;
    return found;
  }
};