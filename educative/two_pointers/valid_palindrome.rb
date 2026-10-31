# Given a string, s, return TRUE if it is a palindrome; otherwise, return FALSE.

# A phrase is considered a palindrome if it reads the same backward as forward after converting all uppercase letters to lowercase and removing any characters that are not letters or numbers. Only alphanumeric characters (letters and digits) are taken into account.

class Palindrome
  
  def is_valid?(str)
    
    left = 0
    right = str.length - 1

    while left <= right

      while left < right && !alphanumeric(str[left])
        left += 1
      end

      while left < right && !alphanumeric(str[right])
        right -= 1
      end

      return false if str[left].downcase != str[right].downcase

      left += 1
      right -= 1
    end

    return true

  end

  private 
  
  def alphanumeric(ch)
    return true if ch >= "0" && ch <= "9"
    return true if ch >= "a" && ch <= "z"
    return true if ch >= "A" && ch <= "Z"
    return false
  end

end


p = Palindrome.new
puts p.is_valid?("hari")
puts p.is_valid?("mom")
puts p.is_valid?("abracadabra")
puts p.is_valid?("racecar")
