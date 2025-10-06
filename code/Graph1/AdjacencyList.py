graph = [[] for _ in range(N)]
def add(u, v): graph[u].append(v); graph[v].append(u)