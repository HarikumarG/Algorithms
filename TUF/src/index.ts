import LongestSubsequence from "./concept_wise/arrays_1/LongestSubsequence";
import SpiralOrder from "./concept_wise/arrays_1/SpiralOrder";

function main(): void {
   const object = new SpiralOrder([[1, 2, 3, 4, 5, 6], [7 ,8, 9, 10, 11, 12], [13, 14, 15, 16, 17, 18], [19, 20, 21, 22, 23, 24]]);
   const result = object.getSpiralOrder();
   console.log(result);
};

main();
