// Given an integer array nums. Find the subarray with the largest product, and return the product of the elements present in that subarray.
// A subarray is a contiguous non-empty sequence of elements within an array.
// Input: nums = [4, 5, 3, 7, 1, 2]
// Output: 840
// Explanation:
// The largest product is given by the whole array itself
// Input: nums = [-5, 0, -2]
// Output: 0
// Explanation:
// The largest product is achieved with the following subarrays [0], [-5, 0], [0, -2], [-5, 0, -2].

export default class MaxProductSubArray {
   
   // store members
   input: Array<number> = [];
   inputLength: number = 0;
   largestProduct: number = 0;

   // processing members
   prefixSum: number = 1;
   suffixSum: number = 1;
   

   constructor() {}

   private calculate(): void {

      if (this.inputLength === 0) {
         this.largestProduct = 0;
         return;
      };

      if (this.inputLength === 1) {
         this.largestProduct = this.input[0];
         return;
      }

      for (let i = 0; i < this.inputLength; i++) {
         this.prefixSum *= this.input[i];
         this.suffixSum *= this.input[this.inputLength-i-1];

         this.largestProduct = Math.max(this.largestProduct, this.prefixSum, this.suffixSum);

         if (this.prefixSum === 0) this.prefixSum = 1;
         if (this.suffixSum === 0) this.suffixSum = 1;
      }
      return;
   }

   getLargestProduct(nums: Array<number>) {
      this.input = nums.map((x) => x);
      this.inputLength = this.input.length;

      this.calculate();

      return this.largestProduct;
   }
}
