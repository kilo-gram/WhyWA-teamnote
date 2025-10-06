graph = [[w for _ in range(N)] for _ in range(N)]

def bellman_ford(init):
        dist = [float('inf' for _ in range(N)]
        parent = [None for _ in range(N)]
        
        dist[init] = 0
        
        for u in range(N):
                for v in graph[u]:
                         if dist[u] + graph[u][v] < dist[v]:
                                 dist[v] = dist[u] + graph[u][v]
                                 parent[v] = u
        
        for u in range(N):
                for v in range(N):
                        if not graph[u][v]: continue
                        
                        if dist[u] + graph[u][v] < dist[v]:
                                raise NegativeWeight
        
        return dist, parent