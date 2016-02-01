class Solution(object):
	def kth(self, nums1, nums2, idx1, idx2, k):
		"""
		:type nums1: List[int]
		:type nums2: List[int]
		:type idx1: int
		:type idx2: int
		:type k: int
		:rtype: int
		"""
		l1, l2 = len(nums1), len(nums2)
		if idx1 >= l1: return nums2[k - 1]
		if idx2 >= l2: return nums1[k - 1]
		if k == 1: return min(nums1[idx1], nums2[idx2])
		if l1 - idx1 > l2 - idx2:
			return self.kth(nums2, nums1, idx2, idx1, k)
		p1 = min(l1 - idx1, k / 2)
		p2 = k - p1
		if nums1[idx1 + p1 - 1] < nums2[idx2 + p2 - 1]:
			return self.kth(nums1, nums2, idx1 + p1, idx2, p2)
		else:
			return self.kth(nums1, nums2, idx1, idx2 + p2, p1)

	def findMedianSortedArrays(self, nums1, nums2):
		"""
		:type nums1: List[int]
		:type nums2: List[int]
		:rtype: float
		"""
		l = len(nums1) + len(nums2)
		hoge = self.kth(nums1, nums2, 0, 0, l / 2 + 1)
		if l % 2:
			return hoge
		else:
			hoge += self.kth(nums1, nums2, 0, 0, l / 2)
			return hoge / 2.0
