from expenses import *

def test_add():
	lst = []
	add_expense_(lst, 2, 3, 'mancare')
	assert (len(lst) == 1)
	assert (lst[0]['day'] == 2)

def test_modify():
	lst = [{'day': 4, 'total': 10, 'exp_type': 'mancare'}, {'day': 11, 'total': 20, 'exp_type': 'apa'}]
	var = mod_expense_(lst, 4, 10, 'mancare', 55, 23, 'apa')
	assert (len(lst) == 2)
	assert (var == True)
	var = mod_expense_(lst, 4, 10, 'mancare', 55, 23, 'apa')
	assert (var == False)

def test_del_by_day():
	lst = [{'day': 4, 'total': 10, 'exp_type': 'mancare'}, {'day': 11, 'total': 20, 'exp_type': 'apa'}, {'day': 1, 'total': 22, 'exp_type': 'apa'}]
	assert (len(lst) == 3)
	del_all_by_day_(lst, 11)
	assert (len(lst) == 2)
	del_all_by_day_(lst, 11)
	assert (len(lst) == 2)
	del_all_by_day_(lst, 4)
	assert (len(lst) == 1)

def test_del_from_interval():
	lst = [{'day': 4, 'total': 10, 'exp_type': 'mancare'}, {'day': 11, 'total': 20, 'exp_type': 'apa'}, {'day': 1, 'total': 22, 'exp_type': 'apa'}]
	assert (len(lst) == 3)
	del_from_interval_(lst, 0, 1)
	assert (len(lst) == 1)

def test_del_by_type():
	lst = [{'day': 4, 'total': 10, 'exp_type': 'mancare'}, {'day': 11, 'total': 20, 'exp_type': 'apa'}, {'day': 1, 'total': 22, 'exp_type': 'apa'}]
	assert (len(lst) == 3)
	del_all_by_type_(lst, 'apa')
	assert (len(lst) == 2)

def tests():
	test_add()
	test_modify()
	test_del_by_day()
	test_del_from_interval()
	test_del_by_type()
