# Given an integer array nums, find all unique triplets [nums[i], nums[j], nums[k]] where i, j, and k are distinct indices, such that the three elements sum to zero.

# The result must not contain any duplicate triplets. The order of the output and the order of elements within each triplet does not matter.

# Note: The solution set must only include unique triplets. Two triplets are considered duplicates if they contain the same elements regardless of ordering.

class ThreeSum

  def initialize
    @result = []
  end
  
  def unique_triplets(nums, target = 0)
    @nums = nums
    @sorted = nums.sort
    @len = nums.length
    @target = target

    calculate

    @result
  end

  private

  def calculate
    (0...@len-2).each do |first_index|
      next if first_index > 0 && @sorted[first_index-1] == @sorted[first_index]

      left = first_index+1
      right = @len-1

      while left < right
        current_sum = @sorted[first_index] + @sorted[left] + @sorted[right]

        if current_sum == @target
          @result << [@sorted[first_index], @sorted[left], @sorted[right]]
          left += 1
          right -= 1

          # Skip duplicate values for left and right pointers
          left += 1 while left < right && @sorted[left] == @sorted[left - 1]
          right -= 1 while left < right && @sorted[right] == @sorted[right + 1]
        elsif current_sum < @target
          left += 1
        else
          right -= 1
        end
      end
    end
  end
end

object = ThreeSum.new
puts object.unique_triplets([-3,-1,0,1,2,3,-2,4]).inspect
