// Given two integer arrays nums1 and nums2. Both arrays are sorted in non-decreasing order.
// Merge both the arrays into a single array sorted in non-decreasing order.
// The final sorted array should be stored inside the array nums1 and it should be done in-place.
// nums1 has a length of m + n, where the first m elements denote the elements of nums1 and rest are 0s.
// nums2 has a length of n.
// Examples:
// Input: nums1 = [-5, -2, 4, 5], nums2 = [-3, 1, 8]
// Output: [-5, -3, -2, 1, 4, 5, 8]
// Explanation:
// The merged array is: [-5, -3, -2, 1, 4, 5, 8], where [-5, -2, 4, 5] are from nums1 and [-3, 1, 8] are from nums2
// Input: nums1 = [0, 2, 7, 8], nums2 = [-7, -3, -1]
// Output: [-7, -3, -1, 0, 2, 7, 8]
// Explanation:
// The merged array is: [-7, -3, -1, 0, 2, 7, 8], where [0, 2, 7, 8] are from nums1 and [-7, -3, -1] are from nums2

export default class MergeTwoSorted {

   // store members
   input1: Array<number> = [];
   input1Length: number = 0;
   input2: Array<number> = [];
   input2Length: number = 0;

   constructor(input1: Array<number>, input1Length: number,  input2: Array<number>, input2Length: number) {
      this.input1 = input1;
      this.input1Length = input1Length;
      this.input2 = input2;
      this.input2Length = input2Length;
   }

   private build(): void {
      let updatePointer: number = this.input1Length + this.input2Length - 1;
      let i: number = this.input1Length - 1;
      let j: number = this.input2Length - 1;

      while (i >= 0 && j >= 0) {
         if (this.input1[i] >= this.input2[j]) {
            this.input1[updatePointer] = this.input1[i];
            i--;
         } else {
            this.input1[updatePointer] = this.input2[j];
            j--;
         }
         updatePointer--;
      }

      while (j >= 0)
         this.input1[updatePointer--] = this.input2[j--];

   }

   getMergedArray(): Array<number> {
      this.build();
      return this.input1;
   }
}
