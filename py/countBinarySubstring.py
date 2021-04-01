def countSubs(str):
	m = 0
	for i in range(len(str)):
		if str[i] == '1':
			m += 1
	return m*(m-1) // 2


str = '1010100101'
print(countSubs(list(str)))


# Time Complexity of the above solution is O(n2).
# We can find count in O(n) using a single traversal of input string. Following are steps.

# a) Count the number of 1’s. Let the count of 1’s be m. 
# b) Return m(m-1)/2 

# The idea is to count total number of possible pairs of 1’s.