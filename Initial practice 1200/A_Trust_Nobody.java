import java.util.*;

public class A_Trust_Nobody
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
    public void helper(int[] nums,int n)
    {
        Arrays.sort(nums);
        TreeMap<Integer,Integer> map = new TreeMap<>();
        for(int i=0;i<n;i++){
            if(!map.containsKey(nums[i]))
                map.put(nums[i], i);
        }
        for(int liars = 0;liars<=n;liars++){
            Integer greaterKey = map.higherKey(liars);
            if(greaterKey==null){
                if(liars==0){
                    System.out.println(0);
                    return;
                }
            }
            else{
                int honests = map.get(greaterKey);
                int calculatedLiars = n - honests;
                if(calculatedLiars==liars){
                    System.out.println(liars);
                    return;
                }
            }
        }
        System.out.println(-1);
        return;
    }
}
//2 2
//0 1
