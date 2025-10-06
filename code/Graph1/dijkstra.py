import heapq

graph = [[(v, w)] for _ in range(N)]
# 양의 가중치 only

def dijkstra(init):
        dist = [float('inf') for _ in range(N)]
        prev = [None for _ in range(N)]
        dist[init] = 0
        
        heap = [(0, init)]
                
        while heap:
                newdst, node = heapq.heappop(heap)
                if newdst != dist[node]: continue
                
                for node, weight in graph[u]:
                        alt = newdst + weight
                        
                        if alt < dist[v]:
                                dist[v] = alt
                                prev[v] = u
                                heapq.heappush(heap, (alt, v))
                                
        return dist, prev