import java.util.*;

public class B_250_Thousand_Tons_of_TNT
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
            int[] nums=new int[n];
            for(int i=0;i<n;i++)
            {
                nums[i]=sc.nextInt();
            }
            s.helper(nums,n);
		} //can be done with brute force, since n only has root(n) divisors.
	}
}
class Solution {
    public void helper(int[] nums,int n)
    {
        // Arrays.sort(nums);
        long[] prefix_sum=new long[n];
        long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=(0L+nums[i]);
            prefix_sum[i]=sum;
        }
        long ans=0L;
        for(int k=1;k<n;k++)
        {
            if(n%k==0)
            {
                long maxi,mini;
                maxi=Long.MIN_VALUE;
                mini=Long.MAX_VALUE;
                for(int i=0;i<=n-k;i+=k)
                {
                    int start = i-1;
                    int end = i+k-1;
                    long weight=0L;
                    if(start!=-1)
                        weight = prefix_sum[end] - prefix_sum[start]+0L;
                    else weight = prefix_sum[end];
                    if(weight>maxi) maxi=weight;
                    if(weight<mini) mini=weight;
                }
                long diff = Math.abs(maxi - mini +0L);
                if(ans<diff)
                {
                    ans=diff;
                }
            }
        }
        System.out.println(ans);
    }
}