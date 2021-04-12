# Count all possible paths from top left to bottom right of a mXn matrix
# with the constraint that from each cell you can either move only to right or down


#recursive approach 1
def num_ways(m, n):
	if m==1 or n==1:
		return 1
	return num_ways(m-1,n) + num_ways(m, n-1)

m = 3
n = 3
print(num_ways(m, n))

# dp approach 2
def num_ways(m, n):
	count = [[0 for i in range(m)] for j in range(n)]

	for i in range(m):
		count[i][0] = 1
	for j in range(n):
		count[0][j] = 1

	for i in range(1, m):
		for j in range(1, n):
			count[i][j] = count[i-1][j] + count[i][j-1]
	return count[m-1][n-1]

m = 3
n = 3
print(num_ways(m, n))


# Space Optimization of DP solution.
def num_ways(m, n):
	dp = [1 for i in range(n)]

	for i in range(m-1):
		for j in range(1, n):
			dp[j] += dp[j-1]
	return dp[n-1]

print(num_ways(3, 3))

