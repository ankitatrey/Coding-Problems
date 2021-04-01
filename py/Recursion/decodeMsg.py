def helper(data, k):
	if k == 0: return 1

	s = len(data) - k
	if data[s] == '0':
		return 0
	result = helper(data, k-1)
	if k>=2 and int(data[s:s+2]) <= 26:
		result += helper(data, k-2)
	return result


def num_ways(data):
	return helper(data, len(data))


data = '011'    #expected o/p: 0
data = '123'    #expected o/p: 3 
print(num_ways(data))
