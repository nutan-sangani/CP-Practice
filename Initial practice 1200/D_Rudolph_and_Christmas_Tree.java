import java.util.*;

public class D_Rudolph_and_Christmas_Tree
{
    public static void main(String[] args) {
        int t=0;
        Scanner sc = new Scanner(System.in);
        Solution s = new Solution();
        t = sc.nextInt();
        sc.nextLine();
        while(t>0)
        {
            t--;
            double n=sc.nextInt();
            double h,b;
            b=sc.nextInt();
            h=sc.nextInt();
            double[] nums = new double[(int)n];
            for(int i=0;i<n;i++)
                nums[i]=sc.nextDouble();
            s.helper(nums,n,h,b);
        }
        sc.close();
    }
}

class Solution {
    public void helper(double[] nums,double n,double h,double b)
    {
        double side = Math.pow(Math.pow(h,2)+Math.pow(b/2,2),0.5);
        double ratio = side/h; 
        double areaOfTriangle = 0.5*h*b;
        double ans=areaOfTriangle;
        for(int i=0;i<n-1;i++){
            double diff = nums[i+1] - nums[i];
            if(diff<h){
                double smallerTriangleArea;
                double smallerTriangleSide = ratio*(h-diff);
                double smallerTriangleBase = Math.pow((Math.pow(smallerTriangleSide,2)-Math.pow((h-diff), 2)),0.5);
                smallerTriangleBase = smallerTriangleBase*2;
                smallerTriangleArea = 0.5*smallerTriangleBase*(h-diff);
                double temp = areaOfTriangle - smallerTriangleArea;
                ans+=temp;
            }
            else ans+=areaOfTriangle;
        }
        System.out.println(ans);
    }
}