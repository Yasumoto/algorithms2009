###
# Ford-Fulkerson Implementation in Python
# Written by Joe Smith
# Chapman University
# Algorithm Analysis
# Dr. Erik Linstead
# May 24, 2009
# Released under GPLv2
###

class edge(object):
	def __init__(self, u, v):
		self.capacity = 0
		self.flow = 0
		self.u, self.v = u, v

graph = {}

#    _A__C_
# s <_ __ _> t
#     B  D
graph['s'] = []
graph['s'].append(edge("s", "a"))
graph['s'].append(edge("s", "b"))
graph['s'][0].capacity = 2009
graph['s'][1].capacity = 1

graph['a'] = []
graph['a'].append(edge("a", "c"))
graph['a'][0].capacity = 1337

graph['b'] = []
graph['b'].append(edge("b", "d"))
graph['b'][0].capacity = 2

graph['c'] = []
graph['c'].append(edge("c", "t"))
graph['c'][0].capacity = 42

graph['d'] = []
graph['d'].append(edge("d", "t"))
graph['d'][0].capacity = 3

graph['t'] = []

# Discover a path    

total_flow = 0
path = []

minimum_capacity = 0

node = graph['s']
for i in node:         
	while (i.flow < i.capacity and i.u != 't'):
		flow_available = i.capacity - i.flow
		if(9001 > flow_available):
			minimum_capacity = flow_available
		path.append(i)
		if (i.v != 't'):
			i = graph[i.v][0]
		else:
			break
	total_flow += minimum_capacity 

	for i in path:
		i.flow += minimum_capacity

print total_flow

