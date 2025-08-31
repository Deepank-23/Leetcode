class Solution(object):
    def isPalindrome(self, x):
        if x<0:
            return False
        digits = []
        for i in str(x):
            digits.append(int(i)) 

        n = len(digits)
        y = []

        for i in range(n):
            y.append(digits[n - i - 1])

        return y == digits
        """
        :type x: int
        :rtype: bool
        """
        