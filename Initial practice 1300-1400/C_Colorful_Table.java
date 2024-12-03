import java.util.*;

public class C_Colorful_Table
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
            int n,k;
            n=sc.nextInt();
            k=sc.nextInt();
            long[] nums = new long[n];
            for(int i=0;i<n;i++){
                nums[i]=sc.nextLong();
            }
            s.helper(n,k,nums);
        }
    }
}

class Solution {
    public void helper(int n,int k,long[] nums)
    {
        long[] ans = new long[k];
        for(int i=0;i<k;i++){
            ans[i]=-1;
        }
        TreeMap<Long,Integer> map = new TreeMap<>(); //problem of duplicates
        for(int i=0;i<n;i++){
            if(!map.containsKey(nums[i])) //only first occurence hi store ho rha.
                map.put(nums[i], i);
        }
        for(int i=n-1;i>=0;i--){
            long ithLastNo = nums[i];
            if(map.isEmpty()){
                break;
            }
            while(!map.isEmpty() && map.firstKey()<=ithLastNo){
                ans[(int)(map.firstKey()-1)]=i-map.get(map.firstKey())+1;
                map.remove(map.firstKey());
            }//2-1,2-1
        }
        for(int i=0;i<k;i++){
            if(ans[i]==-1){
                ans[i]=0;
            }
            System.out.print(2*ans[i]+" ");
        }
        System.out.println();
        return;
    }
}
//3,2,4
//2:1,3:0,4:2
//2*2=4
//3 2 3
//2 2 2
//3 2 4