import Kadane from "./concept_wise/arrays_1/KadaneAlgo";
import LongestSubsequence from "./concept_wise/arrays_1/LongestSubsequence";
import SpiralOrder from "./concept_wise/arrays_1/SpiralOrder";
import MaxProductSubArray from "./concept_wise/arrays_4/MaxProductSubarray";

function main(): void {
   const object = new MaxProductSubArray();;
   const result = object.getLargestProduct([1, -2, 3, 4, -4, -3]);
   console.log(result);
};

main();
