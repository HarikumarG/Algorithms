import Kadane from "./concept_wise/arrays_1/KadaneAlgo";
import LongestSubsequence from "./concept_wise/arrays_1/LongestSubsequence";
import SpiralOrder from "./concept_wise/arrays_1/SpiralOrder";

function main(): void {
   const object = new Kadane();;
   const result = object.getLargestSum([-12, -3, -7, -2, -10, -4]);
   console.log(result);
};

main();
