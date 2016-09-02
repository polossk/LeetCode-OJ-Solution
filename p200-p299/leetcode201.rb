# @param {Integer} m
# @param {Integer} n
# @return {Integer}
def range_bitwise_and(m, n)
	h, hoge, piyo = m ^ n, 0, 1
	while (piyo <= n && piyo >= 0)
		hoge = hoge + piyo if piyo > h
		piyo = piyo << 1
	end
	hoge & m
end

def range_bitwise_and(m, n)
	piyo = Enumerator.new do |y|
		fuga = 1
		loop do
			y << fuga
			fuga = fuga << 1
		end
	end
	m & piyo.take(32).select { |x| x > (m ^ n) && x <= n }.reduce(0, :+)
end