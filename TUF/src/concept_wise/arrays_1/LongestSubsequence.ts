// Given an array nums of n integers.
// Return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.
// eg. [0, -1, 1, 2, -2, 3, -3, 4, 2, 1, -1, 5] = 9

export default class LongestSubsequence {
   
   // store variables
   private longestSubsequence: number = 0;
   private store: Set<number> = new Set();

   // process variables
   private currentSubsequence: number = 0;
   private currElement: number = 0;
 
   constructor () {}

   private init(nums: Array<number>): void {
      nums.forEach((x) => {
         this.store.add(x);
      });
   }

   private calculate(): void {
      for (const i of this.store) {
         if (this.store.has(i-1)) continue;
         this.currentSubsequence = 1;
         this.currElement = i+1;
         while (this.store.has(this.currElement)) {
            this.currentSubsequence++;
            this.currElement++;
         }
         this.longestSubsequence = Math.max(this.longestSubsequence, this.currentSubsequence);
      }
   }
   
   public getLongestSubsequence(nums: Array<number>) {
      this.init(nums);
      this.calculate();
      return this.longestSubsequence;
   }
};
