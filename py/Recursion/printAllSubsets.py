def print_subset(subset):
	for i in range(len(subset)):
		if subset[i]!=None:
			print(f'{subset[i]},',end=" ")
	print()


def helper(array, subset, i):
	if i==len(array):
		print_subset(subset)
	else:
		subset[i] = None
		helper(array, subset, i+1)
		subset[i] = array[i]
		helper(array, subset, i+1)



def all_subsets(array):
	subset = [None] * len(array)
	helper(array, subset, 0)


print(all_subsets([1,2]))
# o/p - _,
# 	  1,	
# 	  2,
# 	  1,2, i.e. all the subsets of the given array.