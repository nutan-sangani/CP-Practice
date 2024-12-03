import java.util.*;

public class C_Training_Before_the_Olympiad
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

    private void calculateEvenAndOddCount(int[] nums,int[] evenCountAt,int[] oddCountAt,int size)
    {
        for(int index=0;index<size;index++)
        {
            if(nums[index]%2==0)
            {
                if(index==0)
                {
                    evenCountAt[0]=1;
                    oddCountAt[0]=0;
                }
                else
                {
                    evenCountAt[index] = evenCountAt[index-1]+1;
                    oddCountAt[index]=oddCountAt[index-1];
                }
            }
            else
            {
                if(index==0)
                {
                    oddCountAt[0]=1;
                    evenCountAt[0]=0;
                }
                else
                {
                    oddCountAt[index] = oddCountAt[index-1]+1;
                    evenCountAt[index]=evenCountAt[index-1];
                }
            }
        }
        return;
    }

    public void helper(int[] nums,int n)
    {
        int[] oddCountAt = new int[n];
        int[] evenCountAt = new int[n];
        calculateEvenAndOddCount(nums, evenCountAt, oddCountAt, n);
        long[] prefixSum = new long[n];
        long sum=0L;
        long[] ans = new long[n];
        for(int index=0;index<n;index++)
        {
            sum+=(nums[index]+0L);
            prefixSum[index]=sum;
        }
        for(int index=0;index<n;index++)
        {
            int reduceBy=0;
            if(oddCountAt[index]==1)
            {
                if(evenCountAt[index]>0) reduceBy+=1;
            }
            else
            {
                int oddCount = oddCountAt[index];
                int quotient = oddCount/3;
                int remainder = oddCount%3;
                reduceBy+=quotient;
                if(remainder==1) reduceBy+=1;
            }
            ans[index]=(prefixSum[index]-(reduceBy+0L));
        }
        for(int index=0;index<n;index++)
            System.out.print(ans[index]+" ");
        System.out.println();
        return;
    }
}
// o = 
// e =