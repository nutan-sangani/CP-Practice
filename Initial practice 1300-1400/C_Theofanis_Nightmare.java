import java.util.*;

public class C_Theofanis_Nightmare
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
            int[] nums = new int[n];
            for(int i=0;i<n;i++)
                nums[i]=sc.nextInt();
            s.helper(nums,n);
        }
        sc.close();
    }
}

class Solution {

    private long recurse(int i,long[][] dp,int n,long[] prefix){
        if(i>=n-1)
            return prefix[0];
        else if(dp[i][0]!=Long.MIN_VALUE && dp[i][1]!=Long.MIN_VALUE){
            return Math.max(dp[i][0],dp[i][1]);
        }
        else{
            long a,b;
            a=prefix[i]+recurse(i+1, dp, n, prefix);
            b=recurse(i+1, dp, n, prefix);
            dp[i][1]=a;
            dp[i][0]=b;
            return Math.max(a, b);
        }
    }

    public void helper(int[] nums,int n)
    {
        long[][] dp=new long[n][2];
        long[] prefix = new long[n];
        long sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            prefix[i]=sum;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                dp[i][j]=Long.MIN_VALUE;
            }
        }
        long ans = recurse(1, dp, n, prefix);
        System.out.println(ans);
    }
}