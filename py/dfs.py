# DFS implementation for disconnected graph
# which traverses all the vertices.

order = list()
def dfs_visit(graph, s, parent):
	order.append(s)
	for v in graph[s]:
		if v not in parent:
			parent[v] = s
			dfs_visit(graph, v,parent)

def dfs(V, graph):
	parent = {}
	for s in V:
		if s not in parent:
			parent[s] = None
			dfs_visit(graph, s, parent)
	print(parent)

graph = {}
n, m = [int(x) for x in input().split()]
for i in range(1,n+1):
	graph[i] = []

for _ in range(m):
	u, v = [int(value) for value in input().split()]
	graph[u].append(v)
	graph[v].append(u)


V = []
for i in range(1, n+1):
	V.append(i)

dfs(V, graph)
print(order)
