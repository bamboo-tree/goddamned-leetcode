class Solution {
    private void printArray(int[] array) {
        for (int i : array) {
            System.out.printf("%d ", i);
        }
        System.out.println();
    }

    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int a = m - 1;
        int b = n - 1;
        int c = m + n - 1;

        while (b >= 0) {
            if (a >= 0 && nums1[a] > nums2[b]) {
                nums1[c] = nums1[a];
                a--;
            } else {
                nums1[c] = nums2[b];
                b--;
            }
            c--;
        }

        printArray(nums1);
    }

    public static void main(String[] args) {
        int[] nums1 = { 1, 2, 3, 0, 0, 0 };
        int m = 3;
        int[] nums2 = { 2, 5, 6 };
        int n = 3;

        Solution s = new Solution();
        s.merge(nums1, m, nums2, n);
    }
}
