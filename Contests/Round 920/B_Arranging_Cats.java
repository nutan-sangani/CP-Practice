import java.util.*;

public class B_Arranging_Cats
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
            int n=sc.nextInt();
            String start=sc.next();
            String end=sc.next();
            s.helper(start,end,n);
        }
        sc.close();
    }
}

class Solution {
    public void helper(String s,String t,int n)
    {
        long cost=0;
        long plusOne=0;
        long minusOne=0;
        for(int i=0;i<n;i++)
        {
            if(s.charAt(i)==t.charAt(i))
            {
                continue;
            }
            else if(s.charAt(i)=='1' && t.charAt(i)=='0')
            {
                minusOne+=1L;
            }
            else if(s.charAt(i)=='0' && t.charAt(i)=='1')
            {
                plusOne+=1L;
            }
        }
        long mini = Math.min(plusOne,minusOne);
        cost+=mini;
        long maxi = Math.max(plusOne, minusOne);
        cost += (maxi-mini);
        System.out.println(cost);
    }
}