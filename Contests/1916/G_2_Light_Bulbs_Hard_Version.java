import java.util.*;
 
public class G_2_Light_Bulbs_Hard_Version
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
		    int[] nums = new int[2*n];
		    for(int i=0;i<2*n;i++)
		    {
		        int a;
		        a = sc.nextInt();
		        nums[i]=a;
		    }
		    s.helper(nums,n);
		}
        sc.close(); 
	}
}
 
class Solution {

    private long help(int[] nums,int i,int j,long[] random)
    {
        HashMap<Long,Integer> map=new HashMap<>();
        HashMap<Integer,Integer> endOfSeq=new HashMap<>();
        // Random rand = new Random();
        long sum=0;
        int k=i;
        for(;k<j;k++)
        {
            sum = sum^random[nums[k]];
            if(map.get(sum)!=null)
            {
                endOfSeq.put((map.get(sum)+1),k);
            }
            map.put(sum,k);
        }
        k=i;
        long size=0L;
        for(;k<=j;k++)
        {
            if(endOfSeq.get(k)!=null && k!=0)
            {
                k=endOfSeq.get(k);
            }
            else size+=1L;
        }
        // System.out.println("j "+j);
        return (size);
    }
    
    public void helper(int[] nums,int bulbs)
    {
        int n = nums.length;
        HashMap<Integer,Integer> lastOccurence = new HashMap<>();
        int[] doesReach = new int[bulbs+1];
        Random rand = new Random();
        long[] random = new long[bulbs+1];
        for(int i=0;i<n;i++)
        {
            lastOccurence.put(nums[i],i);
        }
        HashSet<Long> randomNo=new HashSet<>();
        randomNo.add(0L);
        for(int i=0;i<=bulbs;i++)
        {
            doesReach[i]=-1;
            long randInt=rand.nextLong();
            while(randomNo.contains(randInt))
            {
                randInt=rand.nextLong();
            }
            random[i]=randInt;
            randomNo.add(randInt);
        }
        int reach=lastOccurence.get(nums[0]);
        int count=1;
        ArrayList<Integer> breaks = new ArrayList<>();
        breaks.add(0); //our first break
        for(int i=1;i<n;i++)
        {
            if(i>reach)
            {
                breaks.add(i);
                count++;
            }
            if(lastOccurence.get(nums[i])>reach)
                reach = lastOccurence.get(nums[i]);
            if(reach==n-1) break;
        }
        long ans = 1L;
        long mod = 998244353;
        breaks.add(n);
        for(int i=0;i<breaks.size()-1;i++)
        {
            int start = breaks.get(i);
            int end = breaks.get(i+1)-1;
            long countOfNonStartings = (this.help(nums,start,end,random)%mod);
            ans*=countOfNonStartings;
            ans%=mod;
        }
        System.out.println(count+" "+ans);
    }  
}