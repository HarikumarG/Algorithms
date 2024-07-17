class TestSudoku

  def initialize
    @board = [
      [5, 3, 4, 6, 7, 8, 9, 1, 2],
      [6, 7, 2, 1, 9, 5, 3, 4, 8],
      [1, 9, 8, 3, 4, 2, 5, 6, 7],
      [8, 5, 9, 7, 6, 1, 4, 2, 3],
      [4, 2, 6, 8, 5, 3, 7, 9, 1],
      [7, 1, 3, 9, 2, 4, 8, 5, 6],
      [9, 6, 1, 5, 3, 7, 2, 8, 4],
      [2, 8, 7, 4, 1, 9, 6, 3, 5],
      [3, 4, 5, 2, 8, 6, 1, 7, 9]
    ]
    @rows = Array.new(9) { Set.new }
    @cols = Array.new(9) { Set.new }
    @box = Array.new(9) { Set.new }
  end

  def get_subgrid_index(row, col)
    return (row/3) * 3 + (col/3)
  end

  def condition_check(row, col, box_index)
    check_val = @board[row][col]
    return false if check_val == '.'
    return false if check_val > 9 || check_val < 1
    return false if @rows[row].include?(check_val) || @cols[col].include?(check_val) || @box[box_index].include?(check_val)
    return true
  end

  def test
    for row in 0...9
      for col in 0...9
        box_index = get_subgrid_index(row, col)
        return false unless condition_check(row, col, box_index)
        @rows[row] << @board[row][col]
        @cols[col] << @board[row][col]
        @box[box_index] << @board[row][col]
      end
    end

    return true
  end

end

puts TestSudoku.new.test
