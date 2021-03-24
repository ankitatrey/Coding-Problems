# program to find the number of ways any number 
# can be represented as the sum of consecutive numbers

def countConsecutive(N):
	k = 1
	count = 0

	while (k*(k+1) < 2*N):
		a = (1.0 * N - (k * (k+1))/2) / (k+1)
		if(a - int(a) == 0.0):
			count = count + 1
		k = k+1
	return count

# N = a + (a+1) + (a+2) + ... + (a+k)
#   = (k+1)a + 1+2+3+...+k
#   = (k+1)a + k(k+1)/2

# a = N - k(k+1)/2 / (k+1)
# we will count all integer values of a

n = 15
print(countConsecutive(n))
n = 10
print(countConsecutive(n))