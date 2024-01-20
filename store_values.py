# interview question video: https://www.youtube.com/watch?v=46dZH7LDbf8&t=2474s

import random

class Store:
    def __init__(self):
        self.map = {}
        self.values = []
        
    def insert(self,value):

        self.values.append(value)
        if self.map.get(value, None) == None:
            self.map[value] = [(len(self.values) - 1)]
        else:
            self.map[value].append(len(self.values) - 1)
            
    
    def remove(self,value):
        if value not in self.map:
            return
        
        # index of the value to be removed
        index = self.map[value][0]
        # value at the end of array
        last_val = self.values[-1]
        # swap value at index with rail value        
        self.values[index] = last_val
        self.values[-1] = value

        # update the map        
        self.map[last_val].append(index)
        
        # remove from map and array
        self.values.pop()
        self.map[value].pop(0)
        
    def getRandom(self):
        return random.choice(self.values)
