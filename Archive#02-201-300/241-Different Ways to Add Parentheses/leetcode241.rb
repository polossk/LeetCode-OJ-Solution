$op = { '+' => :+.to_proc, '-' => :-.to_proc, '*' => :*.to_proc }

# @param {String} input
# @return {Integer[]}
def diff_ways_to_compute(input)
  idx = (0...input.length).select { |i| input[i] == '+' || input[i] == '-' || input[i] == '*' }
  output = []
  idx.each { |i| 
    diff_ways_to_compute(input[0...i]).each { |a| 
      diff_ways_to_compute(input[(i+1)..-1]).each { |b|
        output << ($op[input[i]].call(a, b))
      }
    }
  }
  output.length == 0 ? [input.to_i] : output
end