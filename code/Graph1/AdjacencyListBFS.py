from collections import deque

def bfs(visit, init):
        queue = deque([init]) # mle: list로 바꿔볼 것
        visit[init] = True
        while queue:
                current = queue.popleft()
                # do something
                for adjacent in graph[current]:
                        if visit[adjacent]: continue
                        queue.append(adjacent)