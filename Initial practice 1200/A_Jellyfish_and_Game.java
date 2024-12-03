import java.util.*;

public class A_Jellyfish_and_Game
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
            int n,m,k;
            n=sc.nextInt();
            m=sc.nextInt();
            k=sc.nextInt();
            int[] j = new int[n];
            int[] g = new int[m];
            for(int i=0;i<n;i++)
                j[i]=sc.nextInt();
            for(int i=0;i<m;i++)
                g[i]=sc.nextInt();
            s.helper(n,m,k,j,g);
        }
        sc.close();
    }
}

class Solution {
    public void helper(int n,int m,int k,int[] jelly,int[] gelly)
    {
        long sum=0L;
        Arrays.sort(jelly);
        Arrays.sort(gelly);
        int whoHasMax;
        for(int i=0;i<n;i++)
        {
            sum+=(jelly[i])*1L;
        }
        if(jelly[n-1]>gelly[m-1])
        {
            whoHasMax=1;
        }
        else{
            whoHasMax=2;
        }
        if(k%2!=0)
        {
            if(jelly[0]<gelly[m-1]){
                sum-=(jelly[0]*1L);
                sum+=(gelly[m-1]*1L);  
            }
            System.out.println(sum);
            return;
        }
        else{
            int globalMax,globalMin;
            globalMax = Math.max(jelly[n-1], gelly[m-1]);
            globalMin = Math.min(jelly[0], gelly[0]);
            if(jelly[0]<gelly[m-1]){
                sum-=(jelly[0]*1L);
                sum+=(gelly[m-1]*1L);  
            }
            sum-=(globalMax*1L);
            sum+=(globalMin*1L);
            System.out.println(sum);
            return;
        }
        
        
    }
}