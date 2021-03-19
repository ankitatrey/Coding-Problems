n = int(input("Size of array: "))
arr = []


for _ in range(n):
	element = int(input())
	arr.append(element)

d = int(input("No. of left shift operations: "))

i=1
while(i<=d):
	temp = arr[0]
	for j in range(len(arr)-1):
		arr[j] = arr[j+1]
	arr[n-1] = temp
	i = i+1

# return list[k:] + list[0:k]
print(arr)