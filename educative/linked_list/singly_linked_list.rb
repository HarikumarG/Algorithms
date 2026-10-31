class ListNode

  attr_accessor :next, :val

  def initialize(val)
    @next = nil
    @val = val
  end
end

class SinglyLinkedNode

  def initialize
    @head = nil
    @count = 0
  end

  def add(val)
    if @head.nil?
      @head = ListNode.new(val)
      @count += 1
      return true
    end

    new_node = ListNode.new(val)
    curr = @head
    while !curr.next.nil?
      curr = curr.next
    end
    curr.next = new_node
    @count += 1
    return true
  end

  def remove_nth_node(remove)
    if remove == 1
      @head = @head.next
      @count -= 1
      return true
    end

    previous_node = nil
    removal_node = @head

    while remove > 1
      previous_node = removal_node
      removal_node = removal_node.next
      remove -= 1
    end

    previous_node.next = removal_node&.next
    removal_node = nil
    @count -= 1
    return true
  end

  def remove_nth_node_from_last(remove)
    remove_nth_node(@count - remove + 1)
  end

  def print
    trav = @head
    display = []

    while !trav.nil?
      display << trav.val
      trav = trav.next
    end

    puts display.inspect
    return nil
  end
end
