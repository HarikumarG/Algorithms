import LongestSubsequence from "./concept_wise/arrays_1/LongestSubsequence";

function main(): void {
   const object = new LongestSubsequence();
   const result = object.getLongestSubsequence(
      [0, -1, 1, 2, -2, 3, -3, 4, 2, 1, -1, 5]
   );
   console.log(result);
};

main();
