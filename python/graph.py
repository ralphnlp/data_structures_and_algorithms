import os
import queue
import time
import numpy as np


class Graph:

    def __init__(self) -> None:
        self.G = {}
    
    def addNode(self, nameNode):
        self.G[str(nameNode)] = []
    
    def addEdge(self, nameNodes, distance):
        nameNode_1, nameNode_2 = nameNodes
        if nameNode_1 not in self.G or nameNode_2 not in self.G:
            return False
        else:
            self.G[nameNode_1].append((nameNode_2, distance))
            self.G[nameNode_2].append((nameNode_1, distance))
            return True
    
    def removeEdge(self, nameNodes):
        nameNode_1, nameNode_2 = nameNodes
        if nameNode_1 not in self.G or nameNode_2 not in self.G:
            return False
        else:
            
            for i, item in enumerate(self.G[nameNode_1]):
                if item[0] == nameNode_2:
                    self.G[nameNode_1].pop(i)
                    break

            for i, item in enumerate(self.G[nameNode_2]):
                if item[0] == nameNode_1:
                    self.G[nameNode_2].pop(i)
                    break
            return True

    def removeNode(self, nameNode):
        if nameNode not in self.G:
            return False
        else:
            adjNodes = [node[0] for node in self.G[nameNode]]
            for adj_nameNode in adjNodes:
                self.removeEdge((nameNode, adj_nameNode))
            self.G.pop(nameNode)
            return True


    def BFS(self, start_nameNode):

        if start_nameNode not in self.G:
            return None
        gone, queue = {}, [(start_nameNode, 0)]
        for nameNode in self.G:
            gone[nameNode] = 0
        while len(queue) != 0:
            start_nameNode = queue.pop(0)[0]
            #time.sleep(0.5)
            if gone[start_nameNode] == 0:
                print(start_nameNode, end='\t')
                queue.extend(self.G[start_nameNode])
                gone[start_nameNode] = 1
            else:
                pass

    
    def __str__(self) -> str:
        for element in self.G.items():
            print(element)
        return ''


graph = Graph()
graph.addNode('hochiminh')
graph.addNode('binhduong')
graph.addNode('tiengiang')
graph.addNode('longan')
graph.addNode('bentre')

graph.addEdge(('hochiminh', 'binhduong'), 20)
graph.addEdge(('hochiminh', 'longan'), 45)
graph.addEdge(('hochiminh', 'tiengiang'), 36)
graph.addEdge(('longan', 'tiengiang'), 5)
graph.addEdge(('longan', 'bentre'), 80)
graph.addEdge(('tiengiang', 'bentre'), 55)

print(graph)
graph.BFS('hochiminh')
print('')


