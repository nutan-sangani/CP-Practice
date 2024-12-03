import java.util.*;

public class E_Good_Triples
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
            s.helper(n);
		}
	}
}

class Solution {
    public void helper(int n)
    {
        long ans=1L;
        while(n>0)
        {
            int digit = n%10;
            n/=10;
            long temp=0L;
            for(int i=0;i<=digit;i++) //choosing 1st number
            {
                for(int j=0;j<=digit;j++) //choosing 2nd number
                {
                    if(digit-i-j>=0) //the mandatory 3rd number
                        temp+=1L;
                }
            }
            ans*=temp;
        }
        System.out.println(ans);
    }
}

