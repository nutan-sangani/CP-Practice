import java.util.*;

public class E_Binary_Deque
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
            int k=sc.nextInt();
            int[] nums = new int[n];
            for(int i=0;i<n;i++)
                nums[i]=sc.nextInt();
            s.helper(nums,n,k);
        }
        sc.close();
    }
}

class Solution {
    public void helper(int[] nums,int n,int k)
    {
        List<Integer> opsToRemoveK = new ArrayList<>();
        opsToRemoveK.add(0); //since for making 0 ones, we need 0 operations
        List<Integer> opsToRemoveKBackward = new ArrayList<>();
        opsToRemoveKBackward.add(0);
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                opsToRemoveK.add(i+1);
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]==1){
                opsToRemoveKBackward.add(n-i);
            }
        }
        // System.out.println(opsToRemoveK);
        // System.out.println(opsToRemoveKBackward);
        int noOfOnes = opsToRemoveK.size()-1;
        if(k>noOfOnes){
            System.out.println(-1);
            return;
        }
        if(k==noOfOnes){
            System.out.println(0);
            return;
        }
        int mini=Integer.MAX_VALUE;
        int extra = noOfOnes - k;
        for(int i=0;i<=extra;i++){
            int removedFromFront = i;
            int removedFromBack = extra - removedFromFront;
            int frontCost = opsToRemoveK.get(i);
            int backCost = opsToRemoveKBackward.get(removedFromBack);
            mini = Math.min(mini, (frontCost+backCost));
        }
        System.out.println(mini);
        return;
    }
}