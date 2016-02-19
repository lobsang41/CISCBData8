#! /usr/bin/env python

import sys

import csv

for line in sys.stdin:
	user, item, rating = line.strip().split(",") 
	sys.stdout.write('%s,%s\t%s\n' % (user,item,rating))





