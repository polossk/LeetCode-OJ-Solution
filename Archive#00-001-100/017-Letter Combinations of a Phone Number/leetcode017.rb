# @param {String} digits
# @return {String[]}
def letter_combinations(digits)
  return Array.new() if digits.length == 0
  return dfs(digits)
end

def dfs(digits)
  if digits.length <= 1
    $mapping[digits]
  else
    cartProd($mapping[digits[0]], dfs(digits[1..digits.length]))
  end
end

def cartProd(a, b)
  a.product(b).map{ |a| a.join() }
end

$mapping = {
  '2' => ["a", "b", "c"],
  '3' => ["d", "e", "f"],
  '4' => ["g", "h", "i"],
  '5' => ["j", "k", "l"],
  '6' => ["m", "n", "o"],
  '7' => ["p", "q", "r", "s"],
  '8' => ["t", "u", "v"],
  '9' => ["w", "x", "y", "z"],
}
