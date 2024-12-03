import java.util.*;

public class C_Good_Subarrays
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
            String str = sc.next();
            s.helper(str,n);
        }
    }
}

class Solution {
    public void helper(String s,int n)
    {
        // int nums[] = new int[n];
        // for(int i=0;i<n;i++){
        //     nums[i]=(s.charAt(i)-'0'-1);
        // }
        // long count=0;
        // long runningSum=0;
        // // TreeMap<Long,Long> freqOf=new TreeMap<>();
        // for(int i=0;i<n;i++){
        //     runningSum+=nums[i];
        //     if(runningSum==0){
        //         count+=1L;
        //     }
        //     if(freqOf.get(runningSum)!=null){
        //         count+=freqOf.get(runningSum);
        //     }
        //     long val = freqOf.get(runningSum) == null ? 0 : freqOf.get(runningSum);
        //     freqOf.put(runningSum, val+1);
        // }
        // System.out.println(count);
        return;
    }
}
//0 1 -1
//0