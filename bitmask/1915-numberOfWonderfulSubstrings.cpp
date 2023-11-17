/**
 * A wonderful string is a string where at most one letter appears an odd number of times.

For example, "ccjjc" and "abab" are wonderful, but "ab" is not.
Given a string word that consists of the first ten lowercase English letters ('a' through 'j'), return the number of wonderful non-empty substrings in word. If the same substring appears multiple times in word, then count each occurrence separately.

A substring is a contiguous sequence of characters in a string.

Example 1:

Input: word = "aba"
Output: 4
Explanation: The four wonderful substrings are underlined below:
- "aba" -> "a"
- "aba" -> "b"
- "aba" -> "a"
- "aba" -> "aba"
Example 2:

Input: word = "aabb"
Output: 9
Explanation: The nine wonderful substrings are underlined below:
- "aabb" -> "a"
- "aabb" -> "aa"
- "aabb" -> "aab"
- "aabb" -> "aabb"
- "aabb" -> "a"
- "aabb" -> "abb"
- "aabb" -> "b"
- "aabb" -> "bb"
- "aabb" -> "b"
Example 3:

Input: word = "he"
Output: 2
Explanation: The two wonderful substrings are underlined below:
- "he" -> "h"
- "he" -> "e"
Constraints:

1 <= word.length <= 105
word consists of lowercase English letters from 'a' to 'j'.
*/
/*
we use a bitmask to represent the occurrence (odd or even) of each letter and use a hashtable to store the frequency of each bitmask seen so far.

1. “0000000000” means all letters occur even times.
2. “0000000101” means all letters occur even times expect letter ‘a’ and ‘c’ that occur odd times.

We scan the word from left to right and update the bitmask: bitmask ^= (1 << (c-‘a’)).
However, the bitmask only represents the state of the prefix, i.e. word[0:i], then how can we count substrings? The answer is hashtable. If the same bitmask occurs c times before, which means there are c indices that word[0~j1], word[0~j2], …, word[0~jc] have the same state as word[0~i] that means for word[j1+1~i], word[j2+1~i], …, word[jc+1~i], all letters occurred even times.
For the “at most one odd” case, we toggle each bit of the bitmask and check how many times it occurred before.

ans += freq[mask] + sum(freq[mask ^ (1 << i)] for i in range(k))

Time complexity: O(n*k)
Space complexity: O(2k)
where k = j – a + 1 = 10

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
*/
class Solution {
public:
  long long wonderfulSubstrings(string word) {
    constexpr int l = 'j' - 'a' + 1;
    vector<int> count(1 << l);
    count[0] = 1;
    int mask = 0;
    long long ans = 0;
    for (char c : word) {
      mask ^= 1 << (c - 'a'); 
      for (int i = 0; i < l; ++i)
        ans += count[mask ^ (1 << i)]; // one odd.
      ans += count[mask]++; // all even.
    }
    return ans;
  }
};