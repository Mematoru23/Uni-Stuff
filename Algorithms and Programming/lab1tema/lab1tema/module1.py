# p14
def read():
	n = int(input)
	return n

def perf(n):
	x = 0
	for i in range(1, n//2 + 1):
		if n % i == 0:
			x += i
	if x == n:
		return 1
	return 0

def verif(n):
	n += 1
	while perf(n) == 0:
		n += 1
	return n

n = read()
print(verif(n))
