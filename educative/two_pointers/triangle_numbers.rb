# Write a function to list the actual triplets from an array nums of non-negative integers that could form the sides of a triangle.
# For three sides to form a valid triangle, all three of these conditions must hold: (a + b > c), (a + c > b), and (b + c > a), where (a), (b), and (c) are the side lengths.
# In other words, the sum of every possible pair must exceed the third side.

class TriangleNumber

  def initialize(nums)
    @result = []
    @optimized_result = []
    @input = nums
    @input_length = nums.length
  end

  def triplets
    (0...@input_length-2).each do |i|
      (i+1...@input_length-1).each do |j|
        (j+1...@input_length).each do |k|
          if is_triangle?(@input[i], @input[j], @input[k])
            @result << [@input[i], @input[j], @input[k]].sort
          end
        end
      end
    end
    @result.sort
  end

  def optimized_triplets
    @sorted = @input.sort

    (@input_length-1).downto(2) do |k|
      left = 0
      right = k-1

      while left < right
        if is_triangle?(@sorted[left], @sorted[right], @sorted[k])
          # if its count only then we can do # No 3rd loop needed at all! total += (right - left)
          (left...right).each do |idx|
            @optimized_result << [@sorted[idx], @sorted[right], @sorted[k]]
          end
          right -= 1
        else
          left += 1
        end
      end
    end

    @optimized_result.sort
  end

  def count
    @result.length
  end

  private

  def is_triangle?(i, j, k)
    return false unless (i + j) > k
    return false unless (i + k) > j
    return false unless (j + k) > i
    return true
  end
end
# 4, 6, 9, 11, 15, 18
triangle = TriangleNumber.new([11,4,9,6,15,18])
puts triangle.triplets.inspect
puts triangle.optimized_triplets.inspect
