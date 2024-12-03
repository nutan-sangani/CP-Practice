import java.util.*;

public class D_Very_Different_Array
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
            int m=sc.nextInt();
            int[] nums = new int[n];
            int[] nums2=new int[m];
            for(int i=0;i<n;i++)
                nums[i]=sc.nextInt();
            for(int i=0;i<m;i++)
                nums2[i]=sc.nextInt();
            s.helper(nums,nums2,n,m);
        }
        sc.close();
    }
}

class Solution {
    public void helper(int[] n,int[] m,int s1,int s2)
    {
        int[] ans = new int[s1];
        Arrays.sort(m);
        Arrays.sort(n);
        // Collections.reverse(n);
        int y,z;
        y=0;
        z=s1-1;
        while(y<z)
        {
            int temp = n[y];
            n[y]=n[z];
            n[z]=temp;
            y++;
            z--;
        }
        long maxi = 0;
        long[] leftDiffSum = new long[s1];
        long[] rightDiffSum = new long[s1];
        int mArrPointer=0;
        long sum=0;
        for(int i=0;i<s1;i++)
        {
            sum+=(Math.abs(n[i]-m[i])*1L);
            leftDiffSum[i]=sum;
        }
        sum=0;
        mArrPointer=s2-1;
        for(int i=s1-1;i>=0;i--)
        {
            sum+=(Math.abs(n[i]-m[mArrPointer])*1L);
            mArrPointer--;
            rightDiffSum[i]=sum;
        }
        for(int i=0;i<s1-1;i++)
        {
            long temp = leftDiffSum[i]+rightDiffSum[i+1];
            if(temp>maxi) maxi=temp;
        }
        long temp = leftDiffSum[s1-1];
        if(temp>maxi) maxi=temp;
        temp = rightDiffSum[0];
        if(temp>maxi) maxi=temp;
        System.out.println(maxi);
        return;
    }
}