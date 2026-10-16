class Solution:

    def encode(self, strs: List[str]) -> str:
        # if len(strs) == 0:return ""
        return "\0".join(strs)

    def decode(self, s: str) -> List[str]:
        # if()
        return s.split("\0")