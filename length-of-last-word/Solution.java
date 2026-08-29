class Solution {
    public int lengthOfLastWord(String s) {
        String reversed = new StringBuilder(s.trim()).reverse().toString();
        int firstSpaceIndex = reversed.indexOf(" ");

        if (firstSpaceIndex == -1) // one word
            return reversed.length();

        return firstSpaceIndex; // index of the first space
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        String txt = "   fly me   to   the moon  ";
        System.out.println(s.lengthOfLastWord(txt));
    }
}
