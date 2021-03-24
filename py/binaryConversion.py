def toBinary(N):
	array = []
	result = 0
	while N >= 1:
		result = int(N%2)
		array.append(result)
		N /= 2
	array.reverse()
	return array

output = toBinary(24)
print(output)