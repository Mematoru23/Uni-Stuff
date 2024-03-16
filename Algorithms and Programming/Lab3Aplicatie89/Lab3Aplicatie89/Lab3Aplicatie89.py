import os
"""
create menu interface
:return: menu
"""
def menu():
	menu = ""
	menu += "1. Read list\n"
	menu += "2. Longest seq of elems from [0, 10]\n"
	menu += "3. In any 3 consec elems 2 elems are equal\n"
	menu += "3.1 Longest increasing seq\n"
	menu += "4. Show list\n"
	menu += "5. Clear list\n"
	menu += "0. Exit"

	return menu

"""
read the list
:param: lista - list of params
:return: list
"""
def read_list(lista):
	n = int(input("Number of elems to add = "))
	i = 0
	while i < n:
		x = input()
		if x.isdigit():
			lista.append(int(x))
			i += 1
		else:
			continue

	return lista

"""
print the list
"""
def print_list(lista):
	print(lista)

"""
clear list
:param: lista - list of elems 
:return: empty list
"""
def del_list(lista):
	lista.clear()

"""
return longest seq of elems from [0, 10]
:param: lista - list of elems
:return: longest seq
"""
def seq_2(lista):
	maxLen, currLen, first, last = 0, 0, 0, 0
	lst = []
	for i in range(len(lista)):
		if lista[i] >= 0 and lista[i] <= 10:
			currLen += 1
			if currLen > maxLen:
				maxLen = currLen
				first = i - currLen
				last = i
		else:
			currLen = 0
	
	for i in range(first + 1, last + 1):
		lst.append(lista[i])

	return lst
	
"""
return longest seq where in any 3 consec elems 2 of them are eq(3) OR longest increasing seq(3.1)
:param: lista - list of elems
:return: longest seq with 1st property or 2nd one if not
"""
def seq_3(lista):
	maxLen, currLen, first, last = 0, 0, 0, 0
	lst = []
	if len(lista) < 3:
		return -1
	for i in range(2, len(lista)):
		if lista[i] == lista[i - 2] or lista[i] == lista[i - 1] or lista[i - 1] == lista[i - 2]:
			currLen += 1
			if currLen > maxLen:
				maxLen = currLen
				first = i - currLen - 2
				last = i
		else:
			currLen = 0

	for i in range(first + 1, last + 1):
		lst.append(lista[i])
		
	return lst

def seq_3_1(lista):
	maxLen, currLen, first, last = 1, 1, 0, 0
	lst = []
	for i in range(1, len(lista)):
		if lista[i] > lista[i - 1]:
			currLen += 1
			if currLen > maxLen:
				maxLen = currLen
				first = i - currLen
				last = i
		else:
			currLen = 1

	for i in range(first + 1, last + 1):
		lst.append(lista[i])

	return lst

if __name__=="__main__":
	run = True
	lista = []
	print(menu())
	while run:
		cmd = input(">> ")
		if cmd == '1':
			lista = read_list(lista)
		elif cmd == '2':
			print("Longest seq of elems from [0, 10]:", seq_2(lista))
		elif cmd == '3':
			if seq_3(lista) == -1:
				print("need at least 3 elems in list")
			else:
				print("Longest seq where in any 3 consec elems 2 of them are eq:", seq_3(lista))
		elif cmd == '3.1':
			print("Longest increasing seq:", seq_3_1(lista))
		elif cmd == '4':
			print_list(lista)
		elif cmd == '5':
			del_list(lista)
		elif cmd == '0':
			run = False
		elif cmd == 'clear':
			os.system('cls')
			print(menu())
		elif cmd == '':
			continue
		else:
			print("cmd not found")