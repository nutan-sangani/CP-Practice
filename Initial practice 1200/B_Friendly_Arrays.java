import java.util.*;

public class B_Friendly_Arrays
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
            int n,m;
            n=sc.nextInt();
            m=sc.nextInt();
            int[] a=new int[n];
            int[] b=new int[m];
            for(int i=0;i<n;i++)
                a[i]=sc.nextInt();
            for(int i=0;i<m;i++)
                b[i]=sc.nextInt();
            s.helper(a,b,n,m);
            
        }
        sc.close();
    }
}

class Solution {
    public void helper(int[] a,int[] b,int n,int m)
    {
        long temp=0;
        for(int i=0;i<m;i++)
        {
            temp = temp | b[i];
        }
        long exorOR,exor;
        exorOR=exor=0;
        for(int i=0;i<n;i++)
        {
            exor = exor ^ a[i];
            exorOR = exorOR ^ (a[i] | temp);
        }
        if(n%2==0)
        {
            System.out.println(exorOR+" "+exor);
            return;
        }
        System.out.println(exor+" "+exorOR);
        return;

    }
}