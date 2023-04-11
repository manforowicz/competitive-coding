for n in range(100):
	count = 0
	for b in range(2, n+1):
		tmp = n
		valid = 1
		while tmp > 0:
			if tmp % b != 0 and tmp % b != 1:
				valid = 0
				break
			tmp //= b
		count += valid
	
	print("n:", n, "count", count, end = '')
	for i in range(count):
		print('-', end='')
	print()
