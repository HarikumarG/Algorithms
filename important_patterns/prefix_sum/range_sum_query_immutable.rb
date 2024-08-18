#Problem Statement: Given an array nums, answer multiple queries about the sum of elements within a specific range [i, j].

class RangeSum

  def initialize(nums)
    @nums = nums
    @len = nums.length
    @prefix = Array.new(@len)
    build_prefix_sum if @len > 0
  end

  def get_sum(i, j)
    return @prefix[j] if i == 0
    return @prefix[j] - @prefix[i-1]
  end

  private

  def build_prefix_sum
    @prefix[0] = @nums[0]
    for i in 1...@len
      @prefix[i] = @prefix[i-1] + @nums[i]
    end
  end
  
end

r = RangeSum.new([1, 2, 3, 4, 5, 6])
puts r.get_sum(1, 3)
