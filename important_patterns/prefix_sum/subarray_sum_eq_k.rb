#Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
#A subarray is a contiguous non-empty sequence of elements within an array.
#https://leetcode.com/problems/subarray-sum-equals-k/description/

def subarray_sum(nums, k)

  result = 0
  prefix = Hash.new(0)
  prefix[0] = 1
  sum = 0

  nums.each do |val|
    sum += val
    result += prefix[sum-k]
    prefix[sum] += 1
  end

  return result;
    
end

puts subarray_sum([10, 2, -2, -20, 10], -10) #ans: 3
puts subarray_sum([9, 4, 20, 3, 10, 5], 33) #ans: 2
puts subarray_sum([1, 3, 5], 2) #ans: 0
