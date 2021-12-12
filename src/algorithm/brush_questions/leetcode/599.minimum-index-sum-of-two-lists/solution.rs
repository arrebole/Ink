use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn find_restaurant(list1: Vec<String>, list2: Vec<String>) -> Vec<String>{
        let mut seen: HashMap<String, i32> = HashMap::new();
        
        for (i, item) in list1.iter().enumerate() {
            seen.insert(item.to_string(), 0-1-i as i32);
        }

        for (i, item) in list2.iter().enumerate() {
            let v = seen.get(item);
            match v {
                None => {}
                Some(v) => {
                    seen.insert(item.to_string(), (i as i32) - v + 1);
                }
            }
        }

        let mut index_sum = 999999;
        let mut result: Vec<String> = Vec::new();

        // 找出最小值
        for &value in seen.values() {
            if value > 0 && value < index_sum {
                index_sum = value;
            }
        }
        for (key, &value) in seen.iter() {
            if value == index_sum {
                result.push(key.to_string());
            }
        }
        return result;
    }
}                    

fn main(){
    Solution::find_restaurant(
        vec!["Shogun".to_string(), "Tapioca Express".to_string(), "Burger King".to_string(), "KFC".to_string()],
        vec!["Piatti".to_string(), "The Grill at Torrey Pines".to_string(), "Hungry Hunter Steakhouse".to_string(), "Shogun".to_string()]
    );
}