import collections

def bfs(g,root):
	visited, queue = set(), collections.deque([root])
	visited.add(root)
	while(queue):
		# dequeue a vertex from the queue
		vertex = queue.popleft()
		print(str(vertex) + " ", end = "")
		for neighbour in graph[vertex]:
			if neighbour not in visited:
				# not visited yet
				#add in queue
				#add in visited
				visited.add(neighbour)
				queue.append(neighbour)

if __name__ == '__main__':
	graph = {0:[1,2], 1:[2], 2:[3], 3:[1,2]}
	print("BFS of graph is:")
	bfs(graph,0);
