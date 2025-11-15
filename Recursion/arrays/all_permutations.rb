def permutations(arr, l, r)

    if l == r
      puts arr.inspect
      return
    end

    (l..r).each do |i|
      arr[i], arr[l] = arr[l], arr[i]
      permutations(arr, l+1, r)
      arr[i], arr[l] = arr[l], arr[i]
    end
end

permutations([1,2,3], 0, 2)