# Given an m x n 2D binary grid grid which represents a map of '1's 
# (land) and '0's (water), return the number of islands.

# An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
# You may assume all four edges of the grid are all surrounded by water
def mark_island(mat, i, j, r, c):
	if (i<0 or i>=r or j<0 or j>=c or mat[i][j]!=1):
		return
	else:
		mat[i][j] = 2
		mark_island(mat, i+1,j, r, c)
		mark_island(mat, i-1,j, r, c)
		mark_island(mat, i, j-1, r, c)
		mark_island(mat, i, j+1, r, c)

def numberOfIslands(mat, r, c):
	count = 0
	for i in range(r):
		for j in range(c):
			if mat[i][j] == 1:
				count += 1
				mark_island(mat, i, j, 5, 5)
	print(count)


mat = [ [0,0,0,0,0],
		[0,1,1,1,0],
		[0,1,0,1,0],
		[0,0,0,0,1],
		[0,1,1,0,1] ]
numberOfIslands(mat, 5, 5)
