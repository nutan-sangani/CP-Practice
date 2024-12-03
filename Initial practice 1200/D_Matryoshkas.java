import java.util.*;

public class D_Matryoshkas
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
        List<Integer> freq = new ArrayList<>();
        int i=0;
        int prev=-1;
        while(i<n){
            if(prev==-1 || prev==nums[i]-1)
            {
                int count=1;
                while((i<n-1 && nums[i]==nums[i+1])){
                    count++;
                    i++;
                }
                prev=nums[i];
                freq.add(count);
                i++;
            }
            else {
                prev=-1;
                freq.add(0);
            }
        }//this bit is working
        Stack<Integer> st = new Stack<>();
        int freqSize = freq.size();
        long ans=0;
        for(i=0;i<freqSize;i++){
            if(st.empty()){
                st.push(freq.get(i));
                ans+=(freq.get(i));
                continue;
            }
            else{
                if(st.peek()>=freq.get(i)){
                    st.push(freq.get(i));
                    continue;
                }
                else{
                    ans+=(freq.get(i)-st.peek());
                    st.push(freq.get(i));
                }
            }
        }
        System.out.println(ans);
        return;
    }
}
//1 2 2 3 3 4
//5 6 8 9 11 12 14 15
//1 