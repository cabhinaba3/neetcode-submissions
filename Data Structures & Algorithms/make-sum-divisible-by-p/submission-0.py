class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        total = sum(nums)
        target = total % p
        if target == 0:
            return 0
        prefix = 0
        seen = {0:-1}
        ans = len(nums)
        for i, num in enumerate(nums):
            prefix = (prefix + num) % p
            need = (prefix -target) % p
            if need in seen:
                ans = min(ans, i-seen[need])
            seen[prefix] = i

        return ans if ans < len(nums) else -1