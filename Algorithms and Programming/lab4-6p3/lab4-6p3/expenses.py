"""
Add expense in list
param lst: list of dict
param day: day
param total: total expense
param exp_type: expense type
:return: none
"""
def add_expense_(lst, day, total, exp_type):
	expense = {
		'day': day, 
		'total': total,
		'exp_type': exp_type
		}
	lst.append(expense)

"""
Modify expense in list
param lst: list of dicts
param day: day
param total: total expense
param exp_type: expense type
param new_day: day modified to new_day
param new_total: total modified to new_total
param new_exp_type: expense type modifie to new_exp_type
:return: True if mod happens, else False
"""
def mod_expense_(lst, day, total, exp_type, new_day, new_total, new_exp_day):
	for i in lst:
		if i['day'] == day and i['total'] == total and i['exp_type'] == exp_type:
			i['day'] = new_day
			i['total'] = new_total
			i['exp_type'] = new_exp_day
			return True
	return False

"""
Delete all expenses by day
param lst: list of dicts
param day: remove expenses by day
:return: none
"""
def del_all_by_day_(lst, day):
	for i in lst:
		if i['day'] == day:
			lst.remove(i)

"""
Delete expenses from interval by time 
param lst: list of dicts
param first: starting position
param last: ending position
:return: none
"""
def del_from_interval_(lst, first, last):
	if first > last or last > len(lst) - 1:
		return
	if first == last:
		del lst[first]
		return
	del lst[first:last + 1]

"""
Delete all expenses by type
param lst: list of dicts
param exp_type: expense type
:return: none
"""
def del_all_by_type_(lst, exp_type):
	for i in lst:
		if i['exp_type'] == exp_type:
			lst.remove(i)

"""
Show expenses higher than a total
param lst: list of dicts
param total: total expense
:return: 
"""
def show_expenses_higher_(lst, total):
	l = [x for x in lst if x['total'] > total]
	return l

"""
Show expensers that are before a day and smaller than a total
param lst: list of dicts
param total: total expense
param day: day
:return: list of specific elems
"""
def show_expenses_before_day_smaller_(lst, total, day):
	l = [x for x in lst if x['total'] < total and x['day'] < day]
	return l

"""
Show expenses by type
param lst: list of dicts
param exp_type: expense type
:return: list of specific elems
"""
def show_expenses_by_type_(lst, exp_type):
	l = [x for x in lst if x['exp_type'] == exp_type]
	return l

"""
Show sum of totals of specific types
param lst: list of dicts
param exp_type: expense type
:return: sum of totals of specific types
"""
def show_total_sum_for_type_(lst, exp_type):
	total = 0
	for exp in lst:
		if exp['exp_type'] == exp_type:
			total += exp['total']
	return total

def show_day_of_max_expense_spent_(lst):
	day = 0
	mx = -1
	for exp in lst:
		if exp['total'] > mx:
			mx = exp['total']
			day = exp['day']
	return day

def show_all_expenses_of_specific_total_(lst, total):
	l = [x for x in lst if x['total'] == total]
	return l

def show_expenses_sorted_by_type_(lst):
	l = sorted(lst, key = lambda exp: exp['exp_type'])
	return l

def filter_expenses_by_type_(lst, exp_type):
	#for exp in lst:
	#	if exp['exp_type'] == exp_type:
	#		lst.remove(exp)
	l = [x for x in lst if x['exp_type'] != exp_type]
	return l

def filter_expenses_lower_than_total_(lst, total):
	#for exp in lst:
	#	if exp['total'] == total:
	#		lst.remove(exp)
	l = [x for x in lst if x['total'] > total]
	return l
