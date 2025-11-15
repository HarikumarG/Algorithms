


def print_all_subsequences(arr, ind, len, s, sum, curr_sum)

  if ind >= len
    if curr_sum == sum
      puts s.inspect
    end
    return
  end

  # for i in ind...len
    
  # end
  s << arr[ind]
  print_all_subsequences(arr, ind+1, len, s, sum, curr_sum + arr[ind])
  s.pop
  print_all_subsequences(arr, ind+1, len, s, sum, curr_sum)
  # print_all_subsequences(arr, ind+3, len, s+arr[ind].to_s)

end

print_all_subsequences([1,2,1], 0, 3, [], 3, 0)