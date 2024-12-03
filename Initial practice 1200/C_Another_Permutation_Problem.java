import java.util.*;

public class C_Another_Permutation_Problem
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
            long n=sc.nextLong();
            s.helper(n);
        }
        sc.close();
    }
}

class Solution {

    private long reverseCalculate(int start,long[] prefixSum,long n)
    {
        long ans=0;
        long temp = n;
        ans =start>0 ? prefixSum[start-1] : 0L;
        long max=0;
        for(long i=start+1;i<=n;i++)
        {
            max=Math.max(temp*i*1L, max);
            ans+=(temp*i*1L);
            temp--;
        }
        ans-=max;
        return ans;
    }

    public void helper(long n)
    {
        long maxi = Long.MIN_VALUE;
        long[] prefixSum = new long[(int)n];
        long sum = 0L;
        for(int i=0;i<n;i++)
        {
            sum+=(Math.pow(i+1,2)*1L);
            prefixSum[i]=sum;
        }
        for(int i=0;i<n;i++)
        {
            long value = reverseCalculate(i, prefixSum, n);
            maxi=Math.max(value, maxi);
        }
        System.out.println(maxi);
    }
}