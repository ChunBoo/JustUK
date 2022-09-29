/*
Implement a data structure with the following methods:

add(String word) which adds a lowercase alphabet string word to the search engine.
exists(String word) which checks if word is in the engine. word may contain “.” ,
which means to match any character.
Constraints
k ≤ 1,000 where k is the length of word
n ≤ 100,000 where n is the number of calls to add and exists
Example 1
Input
methods = [“constructor”, “add”, “add”, “exists”, “exists”, “exists”]
arguments = [[], [“dog”], [“document”], [“dog”], [“do.”], [“….”]]`
Output
[None, None, None, True, True, False]
*/