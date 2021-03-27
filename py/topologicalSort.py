order = []
def dfs_visit(graph, s, visited):
	visited[s-1] = True

	for v in graph[s]:
		if visited[v-1] == False:
			dfs_visit(graph, v, visited)
	order.append(s)


def dfs(V, graph):
	visited = [False] * len(V)

	for s in V:
		if visited[s-1] == False:
			dfs_visit(graph, s, visited)


# main driver code
graph = {}
V = list()

n, m = [int(x) for x in input().split()]

for i in range(1,n+1):
	graph[i] = []
	V.append(i)

for _ in range(m):
	u, v = [int(value) for value in input().split()]
	graph[u].append(v)
	# graph[v].append(u) // for undirected graphs	

dfs(V, graph)
print(order[::-1]) # printing topological order in reverse order 
