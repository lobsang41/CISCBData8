#! /usr/bin/env python

import sys


# -- Stadium Data
# Stadium
# Stadium Capacity    
# expanded capacity (standing)   
# Location    
# Playing surface 
# Is Artificial Turf  
# Team    
# Opened  
# Weather 
# Station Roof Type
# elevation


for line in sys.stdin:
    line = line.strip()
    unpacked = line.split()
    stadium, capacity, expanded, location, surface, turf, team, opened, weather, roof, elevation = line.split(",")
    results = [turf, "1"]
    last_item, item_count = None


for line in sys.stdin:


	item = line.strip(',').split('\t')
	if last_item != item and last_item is not None: 
		print '%s\t%s' % (last _item, item_count)
		last_item, item_count = None
	last_item = item 
	item_count += 1
print '%s\t%s' % (last_item, item_count)

print("\t".join(results))
