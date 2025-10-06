def dfs(visit, current):
        visit[current] = True
        # do something
        for adjacent in graph[current]:
                if visit[adjacent]: continue
                dfs(visit, adjacent)