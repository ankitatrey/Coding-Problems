# kmp string matching algorithm

def computeLPSArray(pat, m ,lps):
	len = 0
	i = 1
	lps[0]
	while i < m:
		if pat[i] == pat[len]:
			lps[i] = len+1
			len +=1
			i +=1
		else:
			if len !=0:
				len = lps[len-1]
			else:
				lps[i] = 0
				i +=1
	return lps


def KMPSearch(pat, txt):
	N = len(txt)
	M = len(pat)
	lps = [0] * M
	lps = computeLPSArray(pat, M, lps)
	print(lps)
	i = 0
	j = 0
	while i < N-M+1:
		if txt[i] == pat[j]:
			i += 1
			j += 1

		if j == M:
			print("Pattern found at ", str(i-j))
			j = lps[j-1]

		elif i < N and txt[i] != pat[j]:
			if j!= 0:
				j = lps[j-1]
			else:
				i += 1


txt = "abaabababbaa"
pat = "abab"
KMPSearch(pat, txt)