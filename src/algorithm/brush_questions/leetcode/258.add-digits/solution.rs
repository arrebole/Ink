
struct Solution;

impl Solution {
    pub fn add_digits(num: i32) -> i32 {
        let mut result = num;
        while result >= 10  {
            result = Solution::sum_dig(result)
        }
        return result;
    }

    fn sum_dig(mut num: i32) -> i32 {
        let mut result = 0;
        while num != 0 {
            result += num % 10;
            num = num / 10;
        }
        return result;
    }
}