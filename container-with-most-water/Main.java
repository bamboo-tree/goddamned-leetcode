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
    int maxArea = 0;
    int startIndex = 0;
    int endIndex = height.length - 1;

    for(int i = 0; i < height.length; i++) {
      int startHeight = height[startIndex];
      int endHeight = height[endIndex];
      int validContainerHeight = 0; // smaller side of container
      int area = 0;
      
      if(startHeight > endHeight) {
        endIndex--;
        validContainerHeight = endHeight; 
      }
      else{
        startIndex++;
        validContainerHeight = startHeight;
      }
     
      area = validContainerHeight * (endIndex - startIndex + 1);
      maxArea = area > maxArea ? area : maxArea;
      System.out.printf("container borders: %d, %d\n", startHeight, endHeight);
      System.out.printf("area             : %d\n", area);
    }

    return maxArea;
  }
}
