class Water

  def initialize(arr)
    @water_levels = arr
    @length = @water_levels.length
  end

  def most_water

    left = 0
    right = @length-1

    area = 0

    while left < right

      curr_area = [@water_levels[left], @water_levels[right]].min * (right - left)
      area = [curr_area, area].max

      if @water_levels[left] < @water_levels[right]
        left += 1
      else
        right -= 1
      end
    end

    return area
  end
end

water = Water.new([3, 1, 2, 4, 5])
puts water.most_water
