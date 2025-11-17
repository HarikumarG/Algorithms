import Kadane from "./concept_wise/arrays_1/KadaneAlgo";
import LongestSubsequence from "./concept_wise/arrays_1/LongestSubsequence";
import SpiralOrder from "./concept_wise/arrays_1/SpiralOrder";
import MaxProductSubArray from "./concept_wise/arrays_4/MaxProductSubarray";
import MergeTwoSorted from "./concept_wise/arrays_4/MergeTwoSorted";

function main(): void {
   const object = new MergeTwoSorted([0, 2, 7, 8, 0, 0, 0], 4, [-7, -3, -1] , 3);;
   const result = object.getMergedArray();
   console.log(result);
};

main();
