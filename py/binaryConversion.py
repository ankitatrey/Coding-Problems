def toBinary(N):
	array = []
	while N >= 1:
		result = int(N%2)
		array.append(result)
		N /= 2

	return array.reverse()

output = toBinary(24)
print(output)