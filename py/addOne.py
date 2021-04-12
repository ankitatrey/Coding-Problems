def add_one(array):
	carry = 1
	result = [0] * len(array)
	for i in range(len(array)-1, -1, -1):
		total = array[i] + carry
		if total==10:
			carry = 1
		else:
			carry = 0
		result[i] = total%10
	if carry == 1:
		result = [0] * (len(array)+1)
		result[0] = 1
	return result


print(add_one([1,9,9,9]))
print(add_one([1,2,3,9]))
# print(add_one([1]))