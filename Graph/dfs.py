import collections

def dfs(g,start, visited = None):
	if visited is None:
		visited = set()
	visited.add(start)
	print(start)

	for next in graph[start] - visited:
		dfs(graph,next,visited)
	return visited
	

if __name__ == '__main__':
	graph = {'0': set(['1','2']),
			 '1': set(['0','3', '4']),
			 '2': set(['0']),
			 '3': set(['1']),
			 '4': set(['2','3'])
			 	}
	print("DFS of graph is:")
	dfs(graph,'0');
