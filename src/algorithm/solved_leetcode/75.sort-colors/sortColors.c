
inline void swap(int *xp, int *yp) { 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

// sortColors 排序颜色
// 🗡双指针技巧——左右指针
void sortColors(int* nums, int numsSize){
    int lo = 0, hi = numsSize - 1, i = 0;
    while(i <= hi) {
        if(nums[i] == 0) swap(&nums[i++], &nums[lo++]);
        else if(nums[i] == 2) swap(&nums[i], &nums[hi--]);
        else i++;    
    } 
}