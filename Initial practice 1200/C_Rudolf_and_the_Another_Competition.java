import java.util.*;

public class C_Rudolf_and_the_Another_Competition
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
            long n=sc.nextLong();
            long m=sc.nextLong();
            long h = sc.nextLong();
            long[][] time = new long[(int)n][(int)m];
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    time[i][j]=sc.nextLong();
            s.helper(time,n,m,h);
        }
        sc.close();
    }
}

class Pair{
    long points;
    long penalty;
    public Pair(long points,long penalty){
        this.points=points;
        this.penalty=penalty;
    }

    public String toString(){
        return this.points+" "+this.penalty;
    }
}

class MyComp implements Comparator<Pair>{

    @Override
    public int compare(Pair o1, Pair o2) {
        if(o1.points<o2.points) return -1;
        else if(o1.points>o2.points) return 1;
        else{
            if(o1.penalty>o2.penalty) return -1;
            else if(o1.penalty<o2.penalty) return 1;
            else return 0;
        }
    }

}

class Solution {

    public boolean equals(Pair p1, Pair p2){
        if(p1.points==p2.points && p1.penalty==p2.penalty) return true;
        return false;
    }

    public void helper(long[][] time,long n,long m,long h)
    {
        List<Pair> scores = new ArrayList<>();
        for(int i=0;i<n;i++)
        {
            long[] playersTime = time[i];
            Arrays.sort(playersTime);
            long sumOfTime=0;
            long points=0;
            long penalty=0;
            for(int j=0;j<m;j++)
            {
                sumOfTime+=playersTime[j];
                if(sumOfTime<=h){
                    points++;
                    penalty+=sumOfTime;
                }
                else break;
            }
            scores.add(new Pair(points, penalty));
        }
        Pair rudolfScore = scores.get(0);
        Collections.sort(scores,new MyComp());
        Collections.reverse(scores);
        int rank=0;
        for(int i=0;i<n;i++){
            if(equals(rudolfScore, scores.get(i)))
            {
                // System.out.println(scores.get(i));
                rank=i;
                // System.out.println(rudolfScore);
                break;
            }
            // System.out.println(scores.get(i));
        }
        System.out.println(rank+1);
    }
}