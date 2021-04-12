def num_ways(N, X):
	if N==0:  return 1
	total = 0
	for i in X:
		if (N-i) >= 0:
			total += num_ways(N-i, X)
	return total


stepsAllowed = {1,2,3}
print(num_ways(5, stepsAllowed)) 
