/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function (nums, target) {
	
	let len = nums.length;
	if(len < 1) retunr -1;
  let low = 0,
		height = len - 1,
		mid = 0;
	let begin = nums[0];
	while (low < height) {
		mid = Math.ceil(low + (height - low) / 2 );
		
		if(nums[mid] < begin) {

			
			height = mid;

		} else if(nums[mid] > begin) {

			low = mid;
			

		}

	}
	
}
