struct Solution;

impl Solution {
    pub fn truncate_sentence(s: String, k: i32) -> String {
        let mut result = Vec::<String>::new();
        for (i, v) in s.split(' ').enumerate() {
            if i as i32 >= k {
                break
            } 
            result.push(String::from(v));
        }
        return result.join(" ");
    }
}

fn main() {
    assert_eq!(
        Solution::truncate_sentence("aaa ss ww 672g sab".to_string(), 3), 
        "aaa ss ww".to_string(),
    );
}