import java.util.*;

public class B_Stone_Age_Problem
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n,q;
        n=sc.nextInt();
        q=sc.nextInt();
        HashMap<Long,Long> map = new HashMap<>();
        long prev=-1;
        long sum=0;
        int[] time=new int[n+1];
        for(int i=0;i<n;i++){
            long val = sc.nextLong();
            time[i+1]=0;
            map.put((long)(i+1), val);
            sum+=val;
        }
        int lastSecond=-1;
        int i=0;
        while(i<q){
            int t=sc.nextInt();
            if(t==1){
                int j,x;
                j=sc.nextInt();
                x=sc.nextInt();
                if(time[j]<=lastSecond){ //means naye val ko hi lena h, and prev ko delete kr
                    sum-=prev;
                    sum+=(long)x;
                    map.put((long)(j), (long)x);
                }
                else{
                    sum-=map.get((long)j);
                    sum+=(long)x;
                    map.put((long)(j), (long)x);
                    time[j]=i;
                }
                System.out.println(sum);
            }
            else{
                int x=sc.nextInt();
                sum=(long)x*n;
                lastSecond=i;
                prev=x;
                System.out.println(sum);
            }
            i++;
        }
        sc.close();
    }
}