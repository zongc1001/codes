/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function (nums1, m, nums2, n) {
	nums1.length = m;
	if(n === 0) return;
  let i = m - 1,
    j = n - 1
  while (j >= 0) {
    
      if ( i >= 0 && nums1[i] > nums2[j]) {
        nums1[i + j + 1] = nums1[i]
        i--
      } else {
        nums1[i + j + 1] = nums2[j]
        j--
			}
			if(i + j === -1) {
				if(i < j) {
					nums1[0] = nums2[0];
				}
				break;
			}
	}
	
}
