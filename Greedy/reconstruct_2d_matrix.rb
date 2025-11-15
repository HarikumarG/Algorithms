class Matrix

  attr_reader :matrix
  
  def initialize(upper, lower, colsum)
    @upper = upper
    @lower = lower
    @colsum = colsum
    @col_len = colsum.length
    @matrix = Array.new(2) { Array.new(@col_len, 0) }
  end

  # def check_matrix
  #   upper_sum = 0
  #   lower_sum = 0
    
  #   for i in 0...@col_len

  #     upper_sum += @matrix[0][i]
  #     lower_sum += @matrix[1][i]

  #     return false if upper_sum > @upper || lower_sum > @lower
  #   end
  #   return true
  # end

  def construct(index, upper_sum, lower_sum)
    return false if upper_sum > @upper || lower_sum > @lower
    if index == @col_len
      return false if upper_sum != @upper || lower_sum != @lower
      return true
    end

    if @colsum[index] == 0
      @matrix[0][index] = 0
      @matrix[1][index] = 0
      return true if construct(index+1, upper_sum + 0, lower_sum + 0)
    elsif @colsum[index] == 2
      @matrix[0][index] = 1
      @matrix[1][index] = 1
      return true if construct(index+1, upper_sum + 1, lower_sum + 1)
    else
      if lower_sum > upper_sum
        @matrix[0][index] = 1
        @matrix[1][index] = 0
        return true if construct(index+1, upper_sum + 1, lower_sum + 0)
      else
        @matrix[0][index] = 0
        @matrix[1][index] = 1
        return true if construct(index+1, upper_sum + 0, lower_sum + 1)
      end
    end
    return false
  end

end

# m = Matrix.new(5, 5, [2,1,2,0,1,0,1,2,0,1])
# m = Matrix.new(2, 3, [2,2,1,1])
# m = Matrix.new(55, 54, [1,1,1,2,0,2,2,2,1,1,0,2,1,1,2,1,2,1,1,2,0,1,0,1,1,1,1,1,2,2,2,0,1,0,1,2,1,1,1,1,0,0,0,2,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,2,1,1,1,1,1,1,1,1,2,1,2,2,1,1,1,1,2,1,1,1,1,1,2,1,0,1,0,2,2,1,1,2,2,2,0,0,1,1,1,1])
m = Matrix.new(53, 82, [2,0,2,1,1,2,2,0,1,1,1,0,0,0,0,2,1,2,2,2,1,1,0,0,0,0,1,2,1,0,1,0,2,0,0,0,0,2,1,1,2,1,1,0,0,1,0,0,1,1,2,0,1,1,1,2,1,0,0,1,1,1,2,2,1,0,0,1,1,1,0,2,1,2,1,0,1,2,0,2,2,1,0,1,1,1,2,0,0,0,1,2,2,0,0,1,1,2,1,2])
if m.construct(0, 0, 0)
  puts m.matrix.inspect
else
  puts [].inspect
end