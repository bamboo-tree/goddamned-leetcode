class Solution {
    private void printArray(int[] array) {
        if (array != null) {
            for (int i : array) {
                System.out.printf("%d ", i);
            }
            System.out.println();
        }
    }

    public int[] plusOne(int[] digits) {
        for (int i = digits.length - 1; i >= 0; i--) {
            int sum = (digits[i] + 1);
            digits[i] = sum % 10;
            if (sum <= 9) {
                return digits;
            } else {
                if (i == 0) { // add one
                    int[] temp = new int[digits.length + 1];
                    temp[0] = 1;
                    for (int j = 1; j < temp.length; j++) {
                        temp[j] = digits[j - 1];
                    }
                    return temp;
                }
            }
        }

        return null;
    }

    public static void main(String[] args) {
        int[] digits = { 1, 2, 9 };
        Solution s = new Solution();

        int[] answ = s.plusOne(digits);
        s.printArray(answ);
    }
}
