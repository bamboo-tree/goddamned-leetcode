import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Main {
    public static void main(String[] args) {
        int[] nums = { 34, 55, 79, 28, 46, 33, 2, 48, 31, -3, 84, 71, 52, -3, 93, 15, 21, -43, 57, -6, 86, 56, 94, 74,
                83, -14, 28, -66, 46, -49, 62, -11, 43, 65, 77, 12, 47, 61, 26, 1, 13, 29, 55, -82, 76, 26, 15, -29, 36,
                -29, 10, -70, 69, 17, 49 };

        Solution s = new Solution();
        System.out.println(s.threeSum(nums));
    }
}

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        // sort array
        Arrays.sort(nums);

        // use Set to prevent unwanted duplicates
        Set<List<Integer>> tSet = new HashSet<>();
        ArrayList<List<Integer>> answ = new ArrayList<>();

        // use 2 pointer approach
        for (int i = 0; i < nums.length; i++) {
            // reset pointers
            int min = i + 1;
            int max = nums.length - 1;
            while (min < max) {
                int sum = nums[max] + nums[min] + nums[i];
                // adjust pointers
                if (sum > 0) {
                    max--;
                } else if (sum < 0) {
                    min++;
                } else { // solution
                    ArrayList<Integer> s = new ArrayList<>();
                    s.add(nums[min]);
                    s.add(nums[i]);
                    s.add(nums[max]);
                    s.sort(null); // sorted List allows Set to prevent duplicates

                    if (tSet.contains(s)) { // continue if Set contains this solution
                        min++;
                        max--;
                        continue;
                    } else { // new solution add to Set
                        tSet.add(s);
                        answ.add(s);
                    }
                }
            }
        }
        return answ;
    }
}
