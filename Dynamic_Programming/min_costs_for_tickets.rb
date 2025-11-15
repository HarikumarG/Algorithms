class Ticket

  def initialize(days, costs)
    @days = days
    @costs = costs
    @min_cost = 3650000
    @len = days.length
    @dp = Hash.new
  end

  def get_pass_again_index(day_index, pass_type)
    can_travel = @days[day_index] + pass_type - 1
    # puts "start #{day_index}, #{pass_type}, #{can_travel}"
    for i in day_index..@len
      if i == @len || @days[i] > can_travel
        new_day_index = i
        break
      end
    end
    # puts "end #{day_index}, #{pass_type}"
    return new_day_index
  end

  def calc_cost(day_index, curr_cost)
    if day_index >= @len
      # puts curr_cost
      @min_cost = [@min_cost, curr_cost].min
      return
    end

    calc_cost(get_pass_again_index(day_index, 1), curr_cost + @costs[0])
    calc_cost(get_pass_again_index(day_index, 7), curr_cost + @costs[1])
    calc_cost(get_pass_again_index(day_index, 30), curr_cost + @costs[2])
  end

  def get_cost(day_index, curr_cost)
    if day_index == @len
      # puts curr_cost
      return curr_cost
    end

    return @dp[day_index] if @dp.include?(day_index)

    @dp[day_index] = 3650000

    @dp[day_index] = [@dp[day_index], get_cost(get_pass_again_index(day_index, 1), curr_cost + @costs[0])].min
    # puts "1 - #{@dp[day_index]}, #{curr_cost}"
    @dp[day_index] = [@dp[day_index], get_cost(get_pass_again_index(day_index, 7), curr_cost + @costs[1])].min
    #puts "1 - #{@dp[day_index]}, #{curr_cost}"
    @dp[day_index] = [@dp[day_index], get_cost(get_pass_again_index(day_index, 30), curr_cost + @costs[2])].min
    #puts "1 - #{@dp[day_index]}, #{curr_cost}"
    return @dp[day_index]
  end

  def dfs(day_index)
    if day_index == @len
      # puts curr_cost
      # @min_cost = [@min_cost, curr_cost].min
      return 0
    end

    return @dp[day_index] if @dp.include?(day_index)

    @dp[day_index] = 3650000

    @dp[day_index] = [@dp[day_index], @costs[0] + dfs(get_pass_again_index(day_index, 1))].min
    puts "1 - #{@dp[day_index]}"
    @dp[day_index] = [@dp[day_index], @costs[1] + dfs(get_pass_again_index(day_index, 7))].min
    @dp[day_index] = [@dp[day_index], @costs[2] + dfs(get_pass_again_index(day_index, 30))].min
    return @dp[day_index]
  end
  

  def minimum_cost
    #calc_cost(0, 0) #brute force
    return get_cost(0, 0) #optimised better
    # return dfs(0) #optimised best
    #return @min_cost
  end
  
end

puts "Result 1: #{Ticket.new([1,4,6,7,8,20], [2,7,15]).minimum_cost}"
# puts "Result 2: #{Ticket.new([1,2,3,4,5,6,7,8,9,10,30,31], [2,7,15]).minimum_cost}"
# puts "Result 3: #{Ticket.new([1,2,3,4,5,6,7,100], [2,7,15]).minimum_cost}"
