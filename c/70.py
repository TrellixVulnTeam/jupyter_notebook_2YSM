class Solution:
    def climbStairs(self, n):
        res = [1, 2]
        if n < 3:
            return res[n-1]
        else:
            for i in range(2, n):
                res.append(res[i-1] + res[i-2]) 
            return res[-1]
