import java.util.*;

public class A_We_Got_Everything_Covered
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
	}
}

class Solution {
    public void helper(int n,int k)
    {
        String ans="";
        for(int i=0;i<n;i++){
            String temp="";
            for(int j=0;j<k;j++){
                temp+=(char)(('a'+j));
            }
            ans+=temp;
        }
        System.out.println(ans);
        return;
    }
}