import java.util.*;

public class C_Sending_Messages
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
            int n,f,a,b;
            n=sc.nextInt();
            f=sc.nextInt();
            a=sc.nextInt();
            b=sc.nextInt();
            int[] nums = new int[n];
            for(int i=0;i<n;i++)
                nums[i]=sc.nextInt();
            s.helper(nums,n,f,a,b);
        }
    }
}

class Solution {

    private long findJumpCost(long from,long to,long a)
    {
        return (to-from)*a;
    }

    public void helper(int[] nums,int n,int f,int a,int b)
    {
        int current=0;
        for(int i=0;i<n;i++)
        {
            long jumpCost = findJumpCost(current, nums[i], a);
            if(jumpCost<(long)b)
            {
                current=nums[i];
                f-=jumpCost;
                if(f<=0)
                {
                    System.out.println("NO");
                    return;
                }
                continue;
            }
            else
            {
                current=nums[i];
                f-=b;
                if(f<=0)
                {
                    System.out.println("NO");
                    return;
                }
                continue;
            }
        }
        System.out.println("YES");
        return;
    }
}