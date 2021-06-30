def countSubstrs(str, i, j, n):
        print(str[i:n],"\n",i,j,n)
        if (n == 1):
            return 1
        if (n <= 0):
            return 0
        res = (countSubstrs(str, i + 1, j, n - 1) 
		+ countSubstrs(str, i, j - 1, n - 1) 
		- countSubstrs(str, i + 1, j - 1, n - 2))
        if (str[i] == str[j]):
            res += 1
        return res 
str = "abca"
n = len(str) 
print(countSubstrs(str, 0, n - 1, n))

