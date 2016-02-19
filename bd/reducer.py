
#! /usr/bin/env python

import sys

last_item, item_count = None
for line in sys.stdin:


	item = line.strip(',').split('\t')
	if last_item != item and last_item is not None: 
		print '%s\t%s' % (last _item, item_count)
		last_item, item_count = None
	last_item = item 
	item_count += 1
print '%s\t%s' % (last_item, item_count)




