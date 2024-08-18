class Linear
  
  def initialize
    @name_count = 0
    @one_to_n_count = 1
  end

  def print_name
    return if @name_count == 5
    puts "UH"
    @name_count += 1
    print_name
  end

  def one_to_n(one_to_n_cap)
    return if @one_to_n_count > one_to_n_cap
    puts @one_to_n_count
    @one_to_n_count += 1
    one_to_n(one_to_n_cap)
  end

  def n_to_one(n_to_one_cap)
    return if n_to_one_cap < 1
    puts n_to_one_cap
    n_to_one_cap -= 1
    n_to_one(n_to_one_cap)
  end

  def one_to_n_bt(cap)
    return if cap < 1
    one_to_n_bt(cap-1)
    puts cap
  end

  def n_to_one_bt(count, cap)
    return if count > cap
    n_to_one_bt(count+1, cap)
    puts count
  end
  
end



#main code starts
linear = Linear.new
puts "Print Name"
linear.print_name
puts "\n"
puts "Print 1 to N"
linear.one_to_n(5) #TC - O(N) ; SC - O(N)
puts "\n"
puts "Print N to 1"
linear.n_to_one(5) #TC - O(N) ; SC - O(N)
puts "\n"
puts "Print 1 to N - Backtracking" #TC - O(N) ; SC - O(N)
linear.one_to_n_bt(5)
puts "\n"
puts "Print N to 1 - Backtracking" #TC - O(N) ; SC - O(N)
linear.n_to_one_bt(1, 5)
#main code ends