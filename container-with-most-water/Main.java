class Main{
  public static void main(String[] args) {
    int[] height = {1,8,6,2,5,4,8,3,7};
    int result = new Solution().maxArea(height);

    for (int i : height) {
      System.out.printf("%d ", i);
    }
    System.out.println("---> " + result);

  }  
}

class Solution{
  public int maxArea(int[] height) {
    int maxArea = 0;              // absolute max area - aka solution
    int area = 0;                 // area calculatet in each loop run
    int start = 0;                // start index in height array - "left" border
    int end = height.length - 1;  // end index in height array - "right" border

    for(int i = 0; i < height.length; i++) {
      if(height[start] > height[end]) {
        area = height[end] * (end - start);
        end--;
      }
      else{
        area = height[start] * (end - start);
        start++;
      }
      maxArea = area > maxArea ? area : maxArea;
    }

    return maxArea;
  }
}
