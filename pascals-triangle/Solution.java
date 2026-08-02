import java.util.ArrayList;
import java.util.List;

class Main {
    public static void main(String[] args) {
        int numRows = 5;

        Solution s = new Solution();
        System.out.println(s.generate(numRows));
    }
}

class Solution {
    public List<List<Integer>> generate(int numRows) {
        ArrayList<List<Integer>> answ = new ArrayList<>();
        for (int i = 0; i < numRows; i++) {
            ArrayList<Integer> arr = new ArrayList<>();
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i)
                    arr.add(1);
                else
                    arr.add(answ.get(i - 1).get(j - 1) + answ.get(i - 1).get(j));
            }
            answ.add(arr);
        }
        return answ;
    }
}
