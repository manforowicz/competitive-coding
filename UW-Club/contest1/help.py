
a = 5
for x in range(50):
	f = x // 5 + x % a
	print("({:2d} / {:2d}) -> {:3d}".format(x, a, f), end=' ')
	for i in range(f):
		print('*', end='')
	print()
	
