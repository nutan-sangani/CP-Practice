import java.util.*;

public class D_Apple_Tree
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
            int n,q;
            n=sc.nextInt();
            HashMap<Integer,List<Integer>> edges = new HashMap<>();
            for(int i=0;i<n-1;i++){
                int u=sc.nextInt();
                int v=sc.nextInt();
                if(edges.containsKey(u)){
                    List<Integer> nodes = edges.get(u);
                    nodes.add(v);
                    edges.put(u,nodes);
                }
                else{
                    List<Integer> nodes= new ArrayList<>();
                    nodes.add(v);
                    edges.put(u,nodes);
                }
            }
            q=sc.nextInt();
            int[][] queries=new int[q][2];
            for(int i=0;i<q;i++){
                queries[i][0]=sc.nextInt();
                queries[i][1]=sc.nextInt();
            }
            s.helper(n,q,edges,queries);
        }
        sc.close();
    }
}

class Solution {

    public int dfs(HashMap<Integer,Integer> subTreeSize,HashMap<Integer,List<Integer>> edges,int node){
        if(!edges.containsKey(node)){ //means it has no child
            subTreeSize.put(node,1);
            return 1;
        }
        else{
            List<Integer> nodes = edges.get(node);
            int size = nodes.size();
            int nodeCount=0;
            for(int i=0;i<size;i++){
                nodeCount+=(dfs(subTreeSize,edges,nodes.get(i)));
            }
            subTreeSize.put(node,nodeCount);
            return nodeCount;
        }
    }

    public void helper(int n,int q,HashMap<Integer,List<Integer>> edges,int[][] query)
    {
        HashMap<Integer,Integer> subTreeSize = new HashMap<>();
        dfs(subTreeSize,edges,1);
        for(int i=0;i<q;i++){
            long ans = 1;
            ans*=(subTreeSize.get(query[i][0])*1L);
            ans*=(subTreeSize.get(query[i][1])*1L);
            System.out.println(ans);
        }
        return;
    }
}