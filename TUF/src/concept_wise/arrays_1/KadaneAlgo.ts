// Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.
// A subarray is a contiguous non-empty sequence of elements within an array.

// Input: nums = [2, 3, 5, -2, 7, -4]
// Output: 15
// Explanation:
// The subarray from index 0 to index 4 has the largest sum = 15


export default class Kadane {

   // store members
   private input: Array<number> = [];

   // processing members
   private currentSum: number = 0;
   private maxSum: number = -Infinity;

   private calculate(): void {
      for (let i of this.input) {
         this.currentSum += i;
         this.maxSum = Math.max(this.currentSum, this.maxSum);
         if (this.currentSum < 0) {
            this.currentSum = 0;
         }  
      }
   }

   getLargestSum(nums: Array<number>) {
      this.input = nums.map((x) => x);
      this.calculate();
      return this.maxSum;
   }
}
