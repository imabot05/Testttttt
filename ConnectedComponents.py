class Graph:
    def __init__(self, V):
        self.V = V
        self.adj = {i: set() for i in range(V)}

    def addEdge(self, u, v):
        self.adj[u].add(v)
        self.adj[v].add(u)

    def dfsUtil(self, v, visited):
        visited[v] = True
        for i in self.adj[v]:
            if not visited[i]:
                self.dfsUtil(i, visited)

    def countNumberOfConnectedComponents(self):
        visited = [False for i in range(self.V)]
        count = 0

        for v in range (self.V):
            if visited[v] == False:
                self.dfsUtil(v, visited)
                count += 1
        return count

def main():
    g = Graph(5)
    g.addEdge(0, 1)
    g.addEdge(2, 3)
    g.addEdge(3, 4)
    print('Number of connected components: ')
    print(g.countNumberOfConnectedComponents())

if __name__ == '__main__':
    main()
