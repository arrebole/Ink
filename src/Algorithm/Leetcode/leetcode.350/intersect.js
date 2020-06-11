/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
function intersect(nums1, nums2) {
    if(nums1.length == 0) return nums1;
    if(nums2.length == 0) return nums2;

    const result = []
    nums1.forEach(i=>{
        if(nums2.includes(i)){
            nums2.splice(nums2.indexOf(i),1);
            result.push(i);
        }
    })
    return result;
};