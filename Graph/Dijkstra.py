# Given a weighted graph, a source vertex and a goal vertex,
# find the shortest distance from the source vertex to the goal vertex.
# Assume there IS a path between the source and the goal.
# Using Dijkstra's Algorithm:

from queue import PriorityQueue
from Graph import ListGraph


def dijkstra(graph, src, goal):
    visited = dict()
    minHeap = dict()   # minHeap simulation only
    # insert the src with 0 distance to minHeap
    minHeap[src] = 0
    while minHeap:
        # simulate minHeap by manually sorting with Python's array sorting O(n log n)
        minHeap = {vertex: distance for vertex, distance in sorted(
            minHeap.items(), key=lambda pair: pair[1])}
        min = list(minHeap.items())[0]
        minHeap.pop(min[0])
        closestVertex = min[0]
        traveledSoFar = min[1]
        visited[closestVertex] = traveledSoFar
        for neighbor in graph.neighbors(closestVertex):
            if neighbor not in visited.keys():
                distance = graph.getDistance(
                    closestVertex, neighbor) + traveledSoFar
                if neighbor in minHeap.keys():
                    if distance < minHeap.get(neighbor):
                        minHeap[neighbor] = distance
                else:
                    minHeap[neighbor] = distance

    print("visited:", visited)
    return visited.get(goal, -1)


# test driver
# rough graph visualization:
#  A -(6)- B
#  |     / | \(5)
# (1) (2) (2)  C
#  | /     | /(5)
#  D -(1)- E
graph = ListGraph(directed=False)
graph.addVertex('A')
graph.addVertex('B')
graph.addVertex('C')
graph.addVertex('D')
graph.addVertex('E')
graph.addEdge('A', 'B', 6)
graph.addEdge('A', 'D', 1)
graph.addEdge('B', 'C', 5)
graph.addEdge('B', 'D', 2)
graph.addEdge('B', 'E', 2)
graph.addEdge('C', 'E', 5)
graph.addEdge('D', 'E', 1)
print(graph)

print("shortest distance from 'A' to 'C' is:", dijkstra(graph, 'A', 'C'))
