class MinHeap
  def initialize
    @heap = []
  end

  def insert(val)
    @heap << val
    heapify_up(@heap.size-1)
  end

  def extract
    min_val = @heap.first
    @heap[0] = @heap.pop
    heapify_down(0)
    return min_val
  end

  def peek
    @heap.first
  end

  def empty?
    @heap.empty?
  end

  private

  def heapify_up(index)
    parent_index = (index-1)/2
    if index > 0 && @heap[index] < @heap[parent_index]
      @heap[index], @heap[parent_index] = @heap[parent_index], @heap[index]
      heapify_up(parent_index)
    end
  end

  def heapify_down(index)
    child_index = 2 * index + 1
    if child_index < @heap.size
      right_child_index = child_index+1
      if right_child_index < @heap.size && @heap[right_child_index] < @heap[child_index]
        child_index = right_child_index
      end
      if @heap[child_index] < @heap[index]
        @heap[index], @heap[child_index] = @heap[child_index], @heap[index]
        heapify_down(child_index)
      end
    end
  end
end

min_heap = MinHeap.new
min_heap.insert(10)
min_heap.insert(15)
min_heap.insert(20)
min_heap.insert(17)
min_heap.insert(8)

puts "Peek min: #{min_heap.extract}"
puts "Peek min: #{min_heap.extract}"
puts "Peek min: #{min_heap.extract}"
puts "Peek min: #{min_heap.extract}"
puts "Peek min: #{min_heap.extract}"
