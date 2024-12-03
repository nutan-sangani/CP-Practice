import java.util.*;

public class D_Shocking_Arrangement
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
		    int n = sc.nextInt();
            List<Integer> nums = new ArrayList<>();
            for(int i=0;i<n;i++){
                nums.add(sc.nextInt());
            }
            s.helper(nums,n);
		}
        sc.close();
	}
}

class Solution {
    public void helper(List<Integer> nums,int n)
    {
        TreeMap<Integer,Integer> pos = new TreeMap<>();
        TreeMap<Integer,Integer> neg = new TreeMap<>();
        int zeroCount=0;
        for(int i=0;i<n;i++){
            if(nums.get(i)<0){
                int val = neg.get(nums.get(i))==null ? 1 : neg.get(nums.get(i))+1;
                neg.put(nums.get(i), val);
            }
            else if(nums.get(i)>0){
                int val = pos.get(nums.get(i))==null ? 1 : pos.get(nums.get(i))+1;
                pos.put(nums.get(i),val);
            }
            else{
                zeroCount++;
            }
        }
        if(n==zeroCount){
            System.out.println("No");
            return;
        }
        else{
            System.out.println("Yes");
        }
        List<Integer> ans = new ArrayList<>();
        long sum = 0;
        for(int i=0;i<n;i++){
            if(zeroCount>0){
                zeroCount--;
                ans.add(0);
                sum+=0;
            }
            else if(sum==0){
                if(Math.abs(neg.firstKey())<pos.lastKey()){
                   ans.add(pos.lastKey());
                //    pos.get(pos.lastKey() 
                }
                else{

                }
                
            }
            
        }
    }
}