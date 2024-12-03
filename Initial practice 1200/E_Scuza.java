import java.util.*;

public class E_Scuza
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
            int n,q;
            n=sc.nextInt();
            q=sc.nextInt();
            long[] nums=new long[n];
            long[] query = new long[q];
            for(int i=0;i<n;i++)
                nums[i]=sc.nextLong();
            for(int i=0;i<q;i++)
                query[i]=sc.nextLong();
            s.helper(nums,query,n,q);
        }
    }
}
//12:29 se chalu kiya

class Solution {
    public void helper(long[] nums,long[] query,int n,int q)
    {
        long max = -1;
        TreeMap<Long,Long> maxHeightOf = new TreeMap<>();
        long[] prefixSum = new long[n];
        long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prefixSum[i]=sum;
            if(nums[i]>max){
                max=nums[i];
                maxHeightOf.put(nums[i], (long)i);
            }
        }
        long[] ans = new long[q];
        for(int i=0;i<q;i++){
            if(maxHeightOf.higherKey(query[i])!=null){
                long upperBound = maxHeightOf.higherKey(query[i]);
                long higherIndex = maxHeightOf.get(upperBound);
                if(higherIndex>0){
                    ans[i]=prefixSum[(int)(higherIndex-1)];
                    System.out.print(ans[i]+" ");
                }
                else{
                    ans[i]=0;
                    System.out.print(ans[i]+" ");
                }
            }
            else{
                ans[i]=sum;
                System.out.print(ans[i]+" ");
            } 
        }
        // for(int i=0;i<q;i++)
        System.out.println();
        return;
    }
}