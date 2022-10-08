
function intersection(nums1: number[], nums2: number[]): number[] {
    const result = new Array();

    const seen = new Set(nums1);
    for (const i of nums2) {
        if (seen.has(i) && seen.delete(i)) result.push(i);
    }
    return result;
};