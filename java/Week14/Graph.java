import java.util.ArrayList;
import java.util.List;

public class Graph {
    private int V;
    private ArrayList<Integer>[] adjList;

    private void initAdjList(){
        adjList = new ArrayList[V];
        for (int i = 0; i < V; i++){
            adjList[i] = new ArrayList<>();
        }
    }

    public Graph(int V) {
        this.V = V;
        initAdjList();
    }

    public void addEdge(int u, int v){
        adjList[u].add(v);
    }


    private void dfs(Integer u, Integer d, boolean[] isVisited, List<Integer> localPathList){
        if (u.equals(d)){
            System.out.println(localPathList);
            return;
        }
        isVisited[u] = true;
        for (Integer v : adjList[u]){
            if (!isVisited[v]){
                localPathList.add(v);
                dfs(v, d, isVisited, localPathList);
                localPathList.remove(v);
            }
        }
        isVisited[u] = false;
    }

    public void printAllPaths(int start, int dest){
        boolean[] isVisited = new boolean[V];
        ArrayList<Integer> localPathList = new ArrayList<>();
        localPathList.add(start);
        dfs(start, dest, isVisited, localPathList);

    }

    public static void main(String[] args)
    {
        Graph g = new Graph(4);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(0, 3);
        g.addEdge(2, 0);
        g.addEdge(2, 1);
        g.addEdge(1, 3);

        int s = 2;
        int d = 3;

        System.out.println(
                "Following are all different paths from "
                        + s + " to " + d);
        g.printAllPaths(s, d);
    }

}
/*
Following are all different paths from 2 to 3
[2, 0, 1, 3]
[2, 0, 3]
[2, 1, 3]
 */
