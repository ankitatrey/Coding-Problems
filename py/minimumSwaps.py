def minimumSwaps(arr):
	count = 0
	temp = [0] *len(arr)
	for index,value in enumerate(arr):
		temp[value-1] = index

	for i in range(len(arr)):
		if(arr[i] !=i+1):
			x = temp[i]
			arr[i], arr[x] = i+1, arr[i]
			temp[i], temp[arr[x]-1] = i ,x
			count+=1

	return count

print(minimumSwaps([2,3,1,4,5]))