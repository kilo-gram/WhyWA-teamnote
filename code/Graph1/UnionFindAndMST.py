# no cycle!

graph = [[(v, w)] for _ in range(N)]

def kruskal():
        cost, mst = 0, []
        
        for u in range(N):
                for v, w in graph[u]:
                        if disjoint.root(u) != disjoint.root(v):
                                disjoint.union(u, v)
                                mst.append((u, v))
                                cost += w
        
        
        return cost, mst