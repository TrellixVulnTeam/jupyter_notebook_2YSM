class Solution:
    def mySqrt(self, x: int) -> int:
        """
        :type x: int
        :rtype: int
        """
        if x==1:
            return 1
        start=0
        end=x//2
        while(start<=end):
            mid=(start+end)//2
            if mid*mid<=x and (mid+1)*(mid+1)>x:
                return int(mid)
            elif x<mid*mid:
                end = mid-1
            else:
                start=mid+1
