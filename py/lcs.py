import time

def longestCommonSequence(S1, S2, m, n):
    L = [[0 for x in range(n+1)] for x in range(m+1)]
    
    # Building the matrix 
    for i in range(m+1):
        for j in range(n+1):
            if i == 0 or j == 0:
                L[i][j] = 0
            elif S1[i-1] == S2[j-1]:
                L[i][j] = L[i-1][j-1] + 1
            else:
                L[i][j] = max(L[i-1][j], L[i][j-1])

    #print(L)


    num = L[m][n]

    lcs = [""] * (num)

    i = m
    j = n
    while i > 0 and j > 0:

        if S1[i-1] == S2[j-1]:
            lcs[num-1] = S1[i-1]
            #print(lcs)

            i -= 1
            j -= 1
            num -= 1

        elif L[i-1][j] > L[i][j-1]:
            i -= 1
        else:
            j -= 1
            
    # Printing the sub sequences
    print("S1 : " + S1 + "\nS2 : " + S2)
    print("LCS: " + "".join(lcs))
	

start_time = time.time()
S1 = "asbh"
S2 = "smaks"
m = len(S1)
n = len(S2)
longestCommonSequence(S1, S2, m, n)
print("Ended in:",time.time()-start_time,"s")

