def jumpGame(arr):
	reachable = 0
	if arr[0] == 0: return False

	for i in range(len(arr)):
		if i > reachable:
			return False
		reachable = max(arr[i]+i, reachable)
	return True


print(jumpGame([1,3,2,1,2]))
print(jumpGame([1,2,1,0,2]))
print(jumpGame([0,3,2]))