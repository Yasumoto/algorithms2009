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

# initialize graph with edges,
# including a source s and a sink t
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


total_flow = 0

# start at the source
node = graph['s']

for i in node:
        # find the least capacity in the path
        minimum_capacity = 9001
        path = []
        # Ensure the sink hasn't been reached,
        # and that there is more capacity available
        while (i.flow < i.capacity and i.u != 't'):
                flow_available = i.capacity - i.flow
                if(minimum_capacity > flow_available):
                        minimum_capacity = flow_available
                path.append(i)
                # stop before the sink
                if (i.v != 't'):
                        i = graph[i.v][0]
                else:
                        break
        total_flow += minimum_capacity

        # update the flow values for each node
        for i in path:
                i.flow += minimum_capacity

print total_flow

