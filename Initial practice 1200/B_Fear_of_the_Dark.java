import java.util.*;

public class B_Fear_of_the_Dark
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
            int[] a=new int[2];
            int[] b = new int[2];
            int[] p = new int[2];
            for(int i=0;i<2;i++)
                p[i]=sc.nextInt();
            for(int i=0;i<2;i++)
                a[i]=sc.nextInt();
            for(int i=0;i<2;i++)
                b[i]=sc.nextInt();
            s.helper(a,b,p);
        }
        sc.close();
    }
}

class Solution {

    private double calculateDistance(int[] u,int[] v)
    {
        double distance = Math.sqrt(Math.pow(u[0]-v[0],2)+Math.pow(u[1]-v[1], 2));
        return distance;
    }

    public void helper(int[] a,int[] b,int[] p)
    {
        int[] o={0,0};
        double min_w = Double.MAX_VALUE;
        double temp = Math.max(calculateDistance(o,a),calculateDistance(p, a)); //case 1
        min_w = Math.min(temp,min_w);
        temp = Math.max(calculateDistance(o,b),calculateDistance(p, b));
        min_w = Math.min(temp,min_w);
        double dist_oa = Math.max(calculateDistance(o,a),(calculateDistance(a,b)/2d)); //case 2
        double dist_pb = Math.max(calculateDistance(p, b),(calculateDistance(a, b)/2f));
        temp = Math.max(dist_oa, dist_pb);
        min_w = Math.min(temp, min_w);
        //case 3
        double dist_ob = Math.max(calculateDistance(o,b),(calculateDistance(a,b)/2d));
        double dist_pa = Math.max(calculateDistance(p, a),(calculateDistance(a, b)/2f));
        temp = Math.max(dist_pa, dist_ob);
        min_w=Math.min(temp, min_w);
        System.out.println(min_w);
        return;
    }
}