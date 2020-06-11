/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
function merge(nums1, m, nums2, n) {
    let cop_num1 = new Array(m);
    for(let i = 0; i < m; i++)cop_num1[i] = nums1[i];

    let c = 0, p = 0; q = 0
    while(  p != m &&  q != n){
        nums1[c++] = cop_num1[p] > nums2[q]? nums2[q++] : cop_num1[p++];
    }

    if(p != m){
        for(let i = p; i < m;i++){
            nums1[c++] = cop_num1[i];
        }
    }else if (q != n){
        for(let i = q; i < n;i++){
            nums1[c++] = nums2[i];
        }
    }

};


merge([4,0,0,0,0,0],1,[1,2,3,5,6],5);