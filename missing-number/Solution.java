class Main {
    public static void main(String[] args) {
        int[] nums = { 3, 0, 1 };
        Solution s = new Solution();
        System.out.println("Missing value: " + s.missingNumber(nums));
    }
}

class Solution {
    // isn't it a XOR problem?
    public int missingNumber(int[] nums) {
        int size = nums.length;
        int mask = 0;

        // use full range determined by array size
        for (int i = 0; i <= size; i++) {
            mask ^= i;
        }
        // use original array
        for (int i = 0; i < size; i++) {
            mask ^= nums[i];
        }

        return mask;
    }
}
