class Solution(object):
	def isNumber(self, s):
		"""
		:type s: str
		:rtype: bool
		"""
		hoge = re.compile("^[\ ]*[+-]?(\d+\.?\d*|\d*\.?\d+)(e[+-]?\d+)?[\ ]*$")
		return bool(hoge.match(s))
        