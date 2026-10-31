# Given the head of a singly linked list, remove the nth node from the end of the list and return the head of the modified list.

# Note: Could you solve this in a single pass through the list?

require_relative '../linked_list/singly_linked_list'

class RemoveNodeList

  def initialize(values)
    @linked_list = SinglyLinkedNode.new
    build_list(values)
  end

  def remove_nth_node_from_last(remove)
    @linked_list.remove_nth_node_from_last(remove)
  end

  def display
    @linked_list.print
  end

  private

  def build_list(values)
    values.each do |val|
      @linked_list.add(val)
    end
  end
end

r = RemoveNodeList.new([4,11,23,56,78,90,15])
r.remove_nth_node_from_last(7)
r.display
