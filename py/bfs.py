from collections import defaultdict

class Graph:
	def __init__(self):
		self.graph = defaultdict(list)	

	def addEdge(self, u, v):
		self.graph[u].append(v)

	def BFS(self,s):
		level = {s:0}
		parent = {s:None}

		frontier = [s]
		i = 1

		while frontier:
			next = []
			for u in frontier:
				print(u, end=' ')
				for v in self.graph[u]:
					if v not in level:
						level[v] = i
						parent[v] = u
						next.append(v)
			frontier = next
			i += 1
		print()
		print(level)
		print(parent)



g = Graph()
n,m = [int(value) for value in input().split()]
for i in range(m):
	x, y = [int(x) for x in input().split()]
	g.addEdge(x, y)
s = int(input())
g.BFS(s)
# g.addEdge(0, 1)
# g.addEdge(0, 2)
# g.addEdge(1, 2)
# g.addEdge(2, 0)
# g.addEdge(2, 3)

g.BFS(1)

# graph = {}
#     for i in range(n+1):
#         graph[i+1] = []
#     for i in range(m):
#         u,v = [int(x) for x in input().split()]
#         graph[u].append(v)
#         graph[v].append(u)

