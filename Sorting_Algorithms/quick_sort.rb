class Sort
  def initialize(list)
    @list = list
    @len = list.length
  end

  def quick_sort(low, high)
    if low < high
      partition_index = partition(low, high)
      quick_sort(low, partition_index-1)
      quick_sort(partition_index+1, high)
    end
  end

  def partition(low, high)
    pivot = @list[low]
    i = low
    j = high
    while i < j
      while i < high && @list[i] <= pivot
        i += 1
      end

      while j > low && @list[j] > pivot
        j -= 1
      end

      if i < j
        @list[i], @list[j] = @list[j], @list[i]
      end
    end
    @list[low], @list[j] = @list[j], @list[low]
    return j
  end

  def sort
    quick_sort(0, @len-1)
  end

  def get_sorted_list
    return @list
  end
end

qc = Sort.new([10, 15, 7, 2, 8, 12])
qc.sort
puts qc.get_sorted_list.inspect
