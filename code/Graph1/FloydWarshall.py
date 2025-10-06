# 가중 그래프
graph = [[] for _ in range(N)]

def add(src, dst, weight):
        graph[src].append((dst, weight))

def floyd_warshall():
        result = [[float('inf') for _ in range(N)] for _ in range(N)]
        
        # same node
        for n in range(N): result[n][n] = 0
        
        for u in range(N):
                for v, w in graph[u]:
                        result[u][v] = w
        
        # for 문 순서 중요! 바꾸지 말 것!
        for m in range(N):
                for s in range(N):
                        for e in range(N):
                                result[s][e] = min(result[s][e], result[s][m] + result[m][e])
        
        return result