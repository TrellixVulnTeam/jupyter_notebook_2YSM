class Solution:
    def addBinary(self, a: str, b: str) -> str:
        lenA=len(a)
        lenB=len(b)
        maxLen = max(lenA,lenB)
        i = lenA-1
        j = lenB-1
        res = list()
        ret = 0

        for k in range(maxLen-1,-1,-1):
            if i>=0 and j>=0:
                remainder = (int(a[i])+int(b[j])+ret)%2
                ret = (int(a[i])+int(b[j])+ret)//2
                res.insert(0,str(remainder))
                i = i-1
                j = j-1
            elif i>=0:
                remainder = (int(a[i])+ret)%2
                ret = (int(a[i])+ret)//2
                res.insert(0,str(remainder))
                i = i-1
            elif j>=0:
                remainder = (int(b[j])+ret)%2
                ret = (int(b[j])+ret)//2
                res.insert(0,str(remainder))
                j = j-1
        if ret == 1:
            res.insert(0,'1')
        return ''.join(res)
