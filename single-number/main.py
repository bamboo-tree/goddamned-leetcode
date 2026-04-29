def main():
    print("Hello")
    nums = [4,1,2,1,2]
    s = Solution()
    print(s.singleNumber(nums))
    
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        single = 0
        for n in nums:
            single = single ^ n
        return single


if __name__ == "__main__":
    main()
