import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Main {
    public static void main(String[] args) {
        int[] nums = { -1, 0, 1, 2, -1, -4 };

        Solution s = new Solution();
        System.out.println(s.threeSum(nums));
    }
}

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {

        Set<List<Integer>> allTriplets = new HashSet<>();

        // find all triplets
        for (int a = 0; a < nums.length - 2; a++) {
            for (int b = a + 1; b < nums.length - 1; b++) {
                for (int c = b + 1; c < nums.length; c++) {
                    // check 3sum condition
                    if (nums[a] + nums[b] + nums[c] == 0) {
                        // create ArrayList
                        ArrayList<Integer> arr = new ArrayList<>();
                        arr.add(nums[a]);
                        arr.add(nums[b]);
                        arr.add(nums[c]);
                        // sorted values can be compared by Set to prevent unwanted duplicates
                        arr.sort(null);
                        // update final Set
                        allTriplets.add(arr);
                    }
                }
            }
        }

        // convert Set to List
        ArrayList<List<Integer>> solution = new ArrayList<>();
        for (List<Integer> l : allTriplets) {
            solution.add(l);
        }

        return solution;
    }
}
