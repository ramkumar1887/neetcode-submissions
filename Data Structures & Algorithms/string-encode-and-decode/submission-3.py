class Solution:

    def encode(self, strs: List[str]) -> str:
        out = "["
        for i,v in enumerate(strs):
            out += f'"{v}"'
            if i!=len(strs)-1:
                out+=","
        out += "]"
        return out
    def decode(self, s: str) -> List[str]:
        if len(s)==2:
            return []
        strs = []
        s = s[2:-2]
        strs = s.split('","')
        return strs
    