import java.util.Arrays;

class Solution {

    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int closest = Integer.MAX_VALUE, answ = Integer.MAX_VALUE;
        int min, max, sum;
        for (int i = 0; i < nums.length - 1; i++) {
            // Two pointer approach
            min = i + 1;
            max = nums.length - 1;
            while (min < max) {
                sum = nums[i] + nums[min] + nums[max];
                // Update absolute differenece if needed
                int diff = Math.abs(target - sum);
                if (diff < closest) {
                    closest = diff;
                    answ = sum;
                }
                // Move pointers
                if (sum < target) {
                    min++;
                } else if (sum > target) {
                    max--;
                } else {
                    return sum;
                }
            }
        }
        return answ;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
        int target = 1;

        int answ = s.threeSumClosest(nums, target);
        System.out.println(answ);
    }
}
