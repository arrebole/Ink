
class Solution {
    private int[] nums;
    private int target;
    private int waysCount;

    public int findTargetSumWays(int[] nums, int target) {
        this.nums = nums;
        this.target = target;
        this.waysCount = 0;
        dfsFindWays(0, 0);
        return this.waysCount;
    }

    private void dfsFindWays(int sum, int level) {
        if (level >= nums.length) {
            if (sum == target) {
                waysCount++;
            }
            return;
        }
        dfsFindWays(sum + nums[level], level + 1);
        dfsFindWays(sum - nums[level], level + 1);
    }
}