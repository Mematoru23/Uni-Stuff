# p4
def read():
    n = int(input())
    return n

def verifPrim(n):
    if n == 2:
        return 1
    if n == 1 or n % 2 == 0:
        return 0
    for i in range(2, int(n / 2) + 1):
        if n % i == 0:
            return 0
    return 1
def prob(n):
    v = [2, 3, 5, 7]
    p1, p2, ok = 0, 0, 0
    for i in range(4):
        p1 = v[i]
        p2 = int(n) - p1
        if verifPrim(p2):
            ok = 1
            break
        else:
            continue
    if ok:
        print(p1, p2)
    else:
        print("nu se poate")

n = read()
prob(n)

# p14
#def read():
#	n = int(input())
#	return n

#def perf(n):
#	x = 0
#	for i in range(1, n//2 + 1):
#		if n % i == 0:
#			x += i
#	if x == n:
#		return 1
#	return 0

#def verif(n):
#	n += 1
#	while perf(n) == 0:
#		n += 1
#	return n

#n = read()
#print(verif(n))
