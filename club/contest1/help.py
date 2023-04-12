n = 36

for b in range(2, n+1):
	tmp = n
	digits = []
	while tmp > 0:
		digits.append(tmp % b)
		tmp //= b
	digits.reverse()

	print(digits)
	if digits.count(1) + digits.count(0) == len(digits):
		print("woho")


	# for i in range(n // b % b):
		# print('-', end='')
	# print()
