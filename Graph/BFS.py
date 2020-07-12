'''
Test Driver for BFS implementation of ListGraph class in Graph.py
'''

from Graph import ListGraph

graph = ListGraph(weighted=False)
# add vertices
graph.addVertex('a')
graph.addVertex('b')
graph.addVertex('c')
graph.addVertex('d')
graph.addVertex('e')
# add edges
graph.addEdge('a', 'b')
graph.addEdge('a', 'e')
graph.addEdge('b', 'c')
graph.addEdge('b', 'd')
graph.addEdge('c', 'a')
graph.addEdge('d', 'c')
graph.addEdge('d', 'e')
graph.addEdge('e', 'd')
# print
print(graph)
# BFS test
bfs = graph.BFS()
print(bfs)
