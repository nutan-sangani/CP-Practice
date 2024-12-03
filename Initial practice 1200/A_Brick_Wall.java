import java.util.*;

public class A_Brick_Wall
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
            int a,b;
            a=sc.nextInt();
            b=sc.nextInt();
            s.helper(a,b);
        }
    }
}

class Solution {
    public void helper(int a,int b)
    {
        long ans=0;
        ans=a*1L;
        int div=b/2;
        ans=ans*div*1L;
        System.out.println(ans);
        return;
    }
}