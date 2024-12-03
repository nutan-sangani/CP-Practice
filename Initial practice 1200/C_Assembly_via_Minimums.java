import java.util.*;

public class C_Assembly_via_Minimums
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
            int terms = n*(n-1)/2;
            int[] nums = new int[terms];
            for(int i=0;i<terms;i++)
                nums[i]=sc.nextInt();
            s.helper(nums,n,terms);
        }
        sc.close();
    }
}

class Solution {

    public void helper(int[] nums,int n,int terms)
    {
        HashMap<Integer,Integer> map = new HashMap<>(); //value:count
        List<Integer> ans=new ArrayList<>();
        Arrays.sort(nums);
        for(int i=0;i<terms;i++)
        {
            if(map.containsKey(nums[i]))
            {
                int value = map.get(nums[i]);
                map.put(nums[i], value+1);
            }
            else{
                map.put(nums[i], 1);
            }
        }
        int i=0;
        while(i<terms)
        {
            int needed = n-ans.size()-1;
            int got = map.get(nums[i]);
            if(got==needed){
                ans.add(nums[i]);
                i+=got;
            }
            else if(got>needed){
                int diff = got - needed;
                map.put(nums[i], diff);
                ans.add(nums[i]);
                i+=needed;
            }
        }
        int ansLast=ans.get(ans.size()-1);
        ans.add(ansLast);
        for(i=0;i<n;i++){
            System.out.print(ans.get(i)+" ");
        }
        System.out.println();
        return;
    }
}