cache = dict()
def stepPerms(n):
    if n == 1:
    	cache[n] = 1
    	return 1
    if n == 2: 
    	cache[n] = 2
    	return 2
    if n == 3:
    	cache[n] = 4
    	return 4
    if n not in cache:
        cache[n] = stepPerms(n-1)+stepPerms(n-2)+stepPerms(n-3)
    return cache[n]


stairs = 10
print(stepPerms(stairs))

# Davis has a number of staircases in his house and he likes to climb each staircase , , or steps at a time.
# Being a very precocious child, he wonders how many ways there are to reach the top of the staircase.

# Example - 

# The staircase has 5 steps. Davis can step on the following sequences of steps:

# 1 1 1 1 1
# 1 1 1 2
# 1 1 2 1 
# 1 2 1 1
# 2 1 1 1
# 1 2 2
# 2 2 1
# 2 1 2
# 1 1 3
# 1 3 1
# 3 1 1
# 2 3
# 3 2

# i.e. 13 possible ways to climb the staircase.