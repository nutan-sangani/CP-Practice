import java.util.*;

public class B_Monsters_Attack
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
            long n,k;
            n=sc.nextLong();
            k=sc.nextLong();
            long[] a=new long[(int)n];
            long[] x=new long[(int)n];
            for(int i=0;i<n;i++){
                a[i]=sc.nextLong();
            }
            for(int i=0;i<n;i++){
                x[i]=sc.nextLong();
            }
            s.helper(a,x,n,k);
        }
    }
}

class Solution {
    public void helper(long[] a,long[] x,long n,long k)
    {
        TreeMap<Long,Long> pos=new TreeMap<>();
        TreeMap<Long,Long> neg = new TreeMap<>();
        for(int i=0;i<n;i++){
            if(x[i]>0){
                pos.put(x[i], (long)i);
            }
            else{
                neg.put(x[i], (long)i);
            }
        }
        long time=0;
        long remk=k;
        // System.out.println(pos);
        // System.out.println(neg);
        //2,3
        //-1
        while(!pos.isEmpty() || !neg.isEmpty()){
            if((!pos.isEmpty() && neg.isEmpty()) || (!pos.isEmpty() && pos.firstKey()<Math.abs(neg.lastKey()))){
                int i=(int)(long)pos.get(pos.firstKey());
                long health = a[i]; 
                long distanceRem = x[i]-time;
                if(distanceRem<=0){
                    System.out.println("NO");
                    return;
                }
                if(remk>=health){
                    remk-=health;
                    health=0;
                }
                while(health>0){
                    if(health>remk){
                        health-=remk;
                        remk=k;
                        time++;
                        distanceRem = x[i]-time;
                        if(distanceRem<=0){
                            System.out.println("NO");
                            return;
                        }
                    }
                    else{
                        remk-=health;
                        health=0;
                    }
                }
                pos.remove(pos.firstKey());
            }//1  rk=0   k=1
            else{
                int i=(int)(long)neg.get(neg.lastKey());
                long health = a[i]; 
                long distanceRem = (-1*x[i])-time;
                if(distanceRem<=0){
                    System.out.println("NO");
                    return;
                }
                if(remk>=health){
                    remk-=health;
                    health=0;
                }
                while(health>0){
                    if(health>remk){
                        health-=remk;
                        remk=k;
                        time++;
                        distanceRem = (-1*x[i])-time;
                        if(distanceRem<=0){
                            System.out.println("NO");
                            return;
                        }
                    }
                    else{
                        remk-=health;
                        health=0;
                    }
                }
                neg.remove(neg.lastKey());
            }
        }
        System.out.println("YES");
        return;
    }
}