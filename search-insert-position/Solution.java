class Main {
    public static void main(String[] args) {
        int[] nums = { 1, 3, 5, 6 };
        int target = 7;

        Solution s = new Solution();
        System.out.println("Insert position: " + s.searchInsert(nums, target));
    }
}

class Solution {
    public int searchInsert(int[] nums, int target) {
        int min = 0;
        int max = nums.length - 1;
        int mid = (max - min) / 2;

        // edge cases
        if (target <= nums[min]) {
            return min;
        }
        if (target > nums[max]) {
            return max + 1;
        }

        // use funky binary search
        while (min < max) {
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target) {
                min = mid;
                mid += (max - min) / 2;
            } else {
                max = mid;
                mid -= (max - min) / 2;
            }

            if (max - min == 1) {
                return max;
            }
        }

        return -1;
    }
}
