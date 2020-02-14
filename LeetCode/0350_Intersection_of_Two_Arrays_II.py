class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        result = []
        i = 0
        for val in nums1:
            while i < len(nums2) and val >= nums2[i]:
                if not result or result[-1] != nums2[i]:
                    result.append(nums2[i])
                i += 1
            if not result or result[-1] != val:
                result.append(val)
        return result
