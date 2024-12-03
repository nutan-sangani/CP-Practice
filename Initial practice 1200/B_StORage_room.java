import java.util.*;

public class B_StORage_room
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
            int[][] mat=new int[n][n];
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    mat[i][j]=sc.nextInt();
            s.helper(mat,n);
		}
	}
}

class Solution {
    public void helper(int[][] m,int n)
    {
        int[] ans=new int[n];
        for(int i=0;i<n;i++)
        {
            int andVal = -1;
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                else
                {
                    if(andVal==-1)
                    {
                        andVal=m[i][j];
                    }
                    else
                    {
                        andVal = andVal & m[i][j];
                    }
                }
            }
            ans[i]=andVal;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                else
                {
                    int orVal = ans[i] | ans[j];
                    if(orVal != m[i][j])
                    {
                        System.out.println("NO");
                        return;
                    } 
                }
            }
        }
        System.out.println("YES");
        if(n==1) System.out.println("7");
        else{
              for(int i=0;i<n;i++)
                System.out.print(ans[i]+" ");
              System.out.println();
        }
    }
}