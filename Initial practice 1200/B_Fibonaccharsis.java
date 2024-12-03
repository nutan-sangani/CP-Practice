import java.util.*;

public class B_Fibonaccharsis
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
            s.helper(n,k);
		}
        sc.close();
	}
}

class Solution {

    private boolean isValid(int i,int n,int depth,int desiredDepth)
    {
        if(depth==desiredDepth){
            return (i>=0 && n>=0);
        }
        else{
            int difference = n-i;
            if(difference>=0){
                return isValid(difference, i, depth+1, desiredDepth);
            }
            return false;
        }
    }

    public void helper(int n,int k)
    {
        long ans=0;
        for(int i=n;i>=0;i--)
            if(isValid(i, n, 1, k))
                ans+=1L;
        System.out.println(ans);
    }
}