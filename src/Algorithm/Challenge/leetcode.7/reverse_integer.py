
class Solution:
    def reverse(self, x: int) -> int:
        result = 0
        sign = self.sign(x)
        x*=sign

        while x != 0:
            result = (result*10) + x%10
            x= int(x/10)
        
        result*=sign
        if self.overflow(result):
            return 0
        return result

    def sign(self, x: int) -> int:
        if x < 0:
            return -1
        return 1
    
    def overflow(self, x: int)->bool:
        if x > 2147483647 - 1 or x < -2147483648:
            return True
        return False