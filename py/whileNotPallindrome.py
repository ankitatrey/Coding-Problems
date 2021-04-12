def _getReverse(n):
	num = 0
	while n!=0:
		num = num*10 + (n%10)
		n//=10
	return num

def ispallindrome(n):
	if(n==_getReverse(n)):
		return True
	return False


def wnp(n):
	while True:
		sum = n + _getReverse(n)
		if(ispallindrome(sum)):
			return sum
		else:
			n = sum

print(wnp(124))