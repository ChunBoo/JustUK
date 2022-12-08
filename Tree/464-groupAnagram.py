#https://stackoverflow.com/questions/6754102/typeerror-unhashable-type
from collections import defaultdict
'''
an array of strings strs, group the anagrams together. You can return the answer in any order. An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: strs = [“eat”,”tea”,”tan”,”ate”,”nat”,”bat”]
Output: [[“bat”],[“nat”,”tan”],[“ate”,”eat”,”tea”]]

Example 2:
Input: strs = [“”]
Output: [[“”]]

Example 3:
Input: strs = [“a”]
Output: [[“a”]]
'''
def groupAnagrams(self, strs):
    """
    :type strs: List[str]
    :rtype: List[List[str]]
    """
    data=defaultdict(list)
    for w in strs:
        data[tuple(sorted(w))].append(w)
    return data.values()

def groupAnagrams2(strs):
    data=defaultdict(list)
    for s in strs:
        d=[0]*26
        for w in s:
            d[ord(w)-97]+=1
        data[tuple(d)].append(s)
    return data.values()