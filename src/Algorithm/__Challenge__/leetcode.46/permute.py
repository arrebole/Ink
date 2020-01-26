from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        
        result = [nums[:]]
        aux = [-1 for i in range(len(nums))]
        while True:
            moveIndex = self.getMaxMoveEl(nums, aux)
            moveVal = nums[moveIndex]
            if moveIndex == -1:
                break 
            # 箭头指向元素互换
            moveIndex2 = moveIndex + aux[moveIndex]
            nums[moveIndex], nums[moveIndex2] = nums[moveIndex2], nums[moveIndex]
            aux[moveIndex], aux[moveIndex2] = aux[moveIndex2], aux[moveIndex]
            self.changeDirection(aux, nums, moveVal)
            # 记录结果
            result.append(nums[:])
        return result

    def getMaxMoveEl(self, nums, aux):
        result, maxval = -1, float('-inf')
        for i, v in enumerate(aux):
            if (i+v) >= 0 and (i+v) < len(aux) and nums[i] > nums[i+v]:
                if nums[i] > maxval:
                    result, maxval = i, nums[i]
        return result
    
    def changeDirection(self, aux,nums, v):
        # 调转所有大于v的元素方向
        for i in range(len(aux)):
            if nums[i] > v:
                aux[i]*=-1

print(Solution().permute([1,2,3]))