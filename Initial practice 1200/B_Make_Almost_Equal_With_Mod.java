import java.util.*;

public class B_Make_Almost_Equal_With_Mod
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
            long[] nums = new long[n];
            for(int i=0;i<n;i++)
                nums[i]=sc.nextLong();
            s.helper(nums,n);
		}
        sc.close();
	}
}

class Solution {

	public boolean checkIfAllOdd(long[] nums,int n)
	{
		for(int i=0;i<n;i++)
			if(nums[i]%2L==0) return false;
		return true;
	}

	public boolean checkIfAllEven(long[] nums,int n)
	{
		for(int i=0;i<n;i++)
			if(nums[i]%2L!=0) return false;
		return true;
	}

	public long findPowerOf2(long[] nums,int n)
	{
		HashMap<Integer,Integer> powerOf2sCount = new HashMap<>();
		for(int i=0;i<n;i++)
		{
			long number = nums[i];
			int j=0;
			while(number>0L)
			{
				if((number & 1L) !=0)
				{
					if(powerOf2sCount.containsKey(j))
					{
						int count = powerOf2sCount.get(j);
						powerOf2sCount.put(j, count+1);
					}
					else
						powerOf2sCount.put(j, 1);
				}
				number>>=1;
				j++;
			}
		}
		boolean canMake2Distinct = false;
		for(int i=0;i<60;i++)
		{
			if(canMake2Distinct)
			{
				return (long)Math.pow(2,i);
			}
			if(powerOf2sCount.containsKey(i))
			{
				int countWithPowerI = powerOf2sCount.get(i);
				if(countWithPowerI == n)
					continue;
				else canMake2Distinct=true;
			}
		}
		return -1;
	}

    public void helper(long[] nums,int n)
    {
        Arrays.sort(nums);
		boolean allOdd = checkIfAllOdd(nums,n);
		boolean allEven = checkIfAllEven(nums,n);
		if(!allEven && !allOdd) 
		{
			System.out.println("2");
			return;
		}
		// System.out.println("this");
		long ans = findPowerOf2(nums, n);
		System.out.println(ans);
		return;
    }
}
//1,3
//1=2
//2=1
//4=0