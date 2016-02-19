
import sys, os import re import csv

from math import sqrt, log, exp from random import random
from collections import defaultdict

EPS = 20

CONF_LEVEL = 1.96

def fisher_z(x):

	z = .5*( log((1+x)/(1-x)) ) return z

def inverse_fisher_z(x):

	zi = (exp(2*x)-1)/(exp(2*x)+1) return zi

def fisher_sigma(n): sigma = 1/(sqrt(n-3)) return sigma
 

def pearsonr(sum_xx, sum_x, sum_xy, sum_y, sum_yy, n): r_num = n * sum_xy - sum_x*sum_y

	r_denom = sqrt((n *sum_xx - sum_x**2)*(n *sum_yy - sum_y**2)) 
	if r_denom == 0.0:

		return 0.0 
	else:

		return round(r_num / float(r_denom), 4)

def calc_similarity(sum_xx, sum_x, sum_xy, sum_y, sum_yy, n, N): 
	pearson = pearsonr(sum_xx, sum_x, sum_xy, sum_y, sum_yy, n) 
	if n < 4:
		return 0

	if pearson > .9999: pearson = .9999
	if pearson < -.9999: pearson = -.9999
	fisher_lower = inverse_ fisher_z( fisher_z(pearson) - fisher_sigma(n)*CONF_LEVEL)

	fisher_upper = inverse_ fisher_z( fisher_z(pearson) + fisher_sigma(n)*CONF_LEVEL)

	if pearson >= 0 and fisher_lower < 0: 
		fisher_lower = 0

	if pearson <= 0 and fisher_lower > 0: 
		fisher_lower = 0

	if fisher_lower*fisher_upper < 0:

		fisher_lower = min(abs(fisher_lower),abs(fisher_upper)) else:

		fisher_lower = min(fisher_lower,fisher_upper)

	return fisher_lower * (n/(float(n + EPS )))**2 * (log(n)/log(N))



def P(item, user_count, item_counts, cutoff): item_count = float(item_counts[item])
 
	if item_count > 0:
 
	return max(cutoff/float(user_count), cutoff/item_count) return cutoff/float(user_count)

 
def mapper(cutoff, itemcountfile, args): cutoff = int(cutoff)
 
	reader = csv.reader(open(itemcountfile, 'rb'), delimiter='\t') item_counts = defaultdict(int)
	 
	for item, count in reader: item_counts[item]=int(count)
	 
		for line in sys.stdin:
		 
			(user, vals) = line.strip().split("\t")
			 
			(user_count, user_ sum, item_ratings) = vals.split('|') items = [x.split(',') for x in item_ratings.split() if \
			random() < P(x.split(',')[0], user_count, item_counts, cutoff)] for i, y in enumerate(items):
	 
	for x in items[:i]:
	 
		sys.stdout.write("%s %s\t%s %s\n" % (x[0], y[0], x[1], y[1]))
	 

