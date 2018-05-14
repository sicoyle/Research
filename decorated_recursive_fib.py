#!/usr/bin/python
from functools import wraps
#def cache(f):
#	cache = { }
#	@wraps(f)
#	def wrap(*arg):
#		if arg not in cache: cache[arg] = f(*arg)
#		return cache[arg]
#	return wrap	


#@cache
def fibRec(n):
	if n < 2:
		return n
	else:
		return fibRec(n-1) + fibRec(n-2)


from datetime import datetime
tstart = datetime.now()
fibRec(1)
tend = datetime.now()
print tend - tstart

