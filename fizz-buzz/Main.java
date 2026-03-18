import java.util.ArrayList;
import java.util.List;

class Main{
  public static void main(String[] args) {
    int n = 15;
    List<String> result = new Solution().fizzBuzz(n);
    
    System.out.printf("n: %d\n", n);
    for (String s : result) {
      System.out.printf("%s ", s);
    }
    System.out.println();
  }
}

class Solution {
  public List<String> fizzBuzz(int n) {
    ArrayList<String> arr = new ArrayList<>();

    for(int i = 1; i < n; i++) {
      String temp = "";
      if(i % 3 == 0) temp += "Fizz";
      if(i % 5 == 0) temp += "Buzz";
      if(temp.isEmpty()) temp += String.valueOf(i);
    
      arr.add(temp);
    }
    
    return arr;
  }
}

