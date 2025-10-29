class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i = 0
        for j in t:
            if i < len(s) and s[i] == j:
                i += 1
        
        if i == len(s):
            return True
        else: 
            return False    