from collections import deque

def kahn():
        # build in-degrees
        indeg = [0 for _ in range(N)]
        for node in range(N):
                for adj in graph[node]:
                        indeg[adj] += 1

        queue = deque([])
        order = []
        
        # all nodes with 0-in-degree
        for node in range(N):
                if indeg[node] == 0: queue.append(node)
        
        while queue:
                curr = queue.popleft()
                order.append(curr)
                
                for node in graph[curr]:
                        indeg[node] -= 1
                        if indeg[node] == 0: queue.append(node)
                        
        # has cycle ?
        if len(order) != N: raise CycleError
                        
        return order
