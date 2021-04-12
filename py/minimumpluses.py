# Given an equation "x=y", for example, "111=12", you need to add pluses inside x
# to make the equation correct. In our example "111=12", we can add one plus "11+1=12"
# and the equation becomes correct. You need to find the minimum number of pluses to add
# to x to make the equation correct. If there is no answer print -1.

def minimum_pluses(a):
	equalpos = a.find("=")
	right = a[equalpos+1:]
	left = a[0:equalpos]
	rlen = len(right)
	llen = len(left)
	sum = 0
	while sum != right:





string = input()
print(minimum_pluses(string))