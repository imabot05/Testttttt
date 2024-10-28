
from collections import defaultdict, deque
import queue

def add_edge(graph, u, v, capacity):
    graph[u][v] = capacity
    graph[v][u] = 0


def bfs(graph, source, target, parent):
    visited = set([source])
    queue = deque([source])
    while queue:
        u = queue.popleft()
        for v, capacity in graph[u].items():
            if v not in visited and capacity > 0:
                visited.add(v)
                parent[v] = u

                queue.append(v)
                if v == target:
                    return True
    return False

def ford_fulkerson(n, graph, source, target):
    parent = [-1 for _ in range(n)]
    max_flow = 0

    while bfs(graph, source, target, parent):
        path_flow = float('inf')
        s = target
        while s != source:
            path_flow = min(path_flow, graph[parent[s]][s])
            s = parent[s]

        max_flow += path_flow
        v = target

        while v != source:
            u = parent[v]
            graph[u][v] = graph[u][v] - path_flow
            graph[v][u] = graph[v][u] + path_flow
            v = parent[v]

    return max_flow

n, m = map(int, input().split())
s, t = map(int, input().split())
graph = [defaultdict(int) for _ in range(n)]
for _ in range(m):
    u, v, capacity = map(int, input().split())
    add_edge(graph, u - 1, v - 1, capacity)

max_flow = ford_fulkerson(n, graph, s - 1, t - 1)
print(max_flow)
