def fun(s):
	d = {}
	res = 0
	i= 0
	j = 0
	while j < len(s):
		if s[j] not in d or i > d[s[j]]:
			res = max(res, (j-i+1))
			d[s[j]] = j   #dictionary stores the index
		else:
			i = d[s[j]] +1  #starting index of the new window
			res = max(res, (j-i)+1)
			j = j - 1   #exclude the new value
		j = j + 1
	print(res)
	print()
	print(d)

s = input()
fun(s)
