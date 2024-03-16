from console import *
from expenses import *

def menu(func_list):
	register_function(func_list, 'list', show_list, 'show the entire list')
	register_function(func_list, 'clear', clear_list, 'clear the entire list')
	register_function(func_list, '1', add_expense, 'add expense in list')
	register_function(func_list, '2', mod_expense, 'modify expense')
	register_function(func_list, '3', del_all_by_day, 'delete all expenses by specific day')
	register_function(func_list, '4', del_from_interval, 'delete expenses from specific interval')
	register_function(func_list, '5', del_all_by_type, 'del all expenses by type')
	register_function(func_list, '6', show_expenses_higher, 'show expenses higher than a total')
	register_function(func_list, '7', show_expenses_before_day_smaller, 'show expenses before specific day and smaller than a total')
	register_function(func_list, '8', show_expenses_by_type, 'show expenses by specific type')
	register_function(func_list, '9', show_total_sum_for_type, 'show total sum of expenses of same type')
	register_function(func_list, '10', show_day_of_max_expense_spent, 'show day of max expense spent')
	register_function(func_list, '11', show_all_expenses_by_specific_total, 'show all expenses by specific total')
	register_function(func_list, '12', show_expenses_sorted_by_type, 'show expenses sorted by type')
	register_function(func_list, '13', filter_expenses_by_type, 'filter expenses by type')
	register_function(func_list, '14', filter_expenses_lower_than_total, 'filter expenses by lower total')
	register_function(func_list, 'undo', undo, 'modify list to previous form')

def add_expense(lst, undo_lst):
	day = int(input('day = '))
	total = int(input('total = '))
	exp_type = input('expense type = ')
	undo_lst.append([el for el in lst])
	return add_expense_(lst, day, total, exp_type)

def clear_list(lst, undo_lst):
	undo_lst.append([el for el in lst])
	lst.clear()

def show_list(lst):
	#for exp in lst:
	#	print('day:', exp['day'], 'total:', exp['total'], 'exp_type:', exp['exp_type'])
	print(lst)

def mod_expense(lst, undo_lst):
	day = int(input('day = '))
	total = int(input('total = '))
	exp_type = input('expense type = ')
	new_day = int(input('new day = '))
	new_total = int(input('new total = '))
	new_exp_type = input('new expense type = ')
	undo_lst.append([el for el in lst])
	if mod_expense_(lst, day, total, exp_type, new_day, new_total, new_exp_type):
		print('expense modified!')
	else:
		print('nothing got modified')

def del_all_by_day(lst, undo_lst):
	day = int(input('day = '))
	undo_lst.append([el for el in lst])
	del_all_by_day_(lst, day)

def del_from_interval(lst, undo_lst):
	first = int(input('first poz = '))
	last = int(input('last poz  = '))
	undo_lst.append([el for el in lst])
	del_from_interval_(lst, first, last)

def del_all_by_type(lst, undo_lst):
	exp_type = input('expense type = ')
	undo_lst.append([el for el in lst])
	del_all_by_type_(lst, exp_type)

def show_expenses_higher(lst):
	total = int(input('total = '))
	l = show_expenses_higher_(lst, total)
	show_list(l)

def show_expenses_before_day_smaller(lst):
	total = int(input('total = '))
	day = int(input('day = '))
	l = show_expenses_before_day_smaller_(lst, total, day)
	show_list(l)

def show_expenses_by_type(lst):
	exp_type = input('expense type = ')
	l = show_expenses_by_type_(lst, exp_type)
	show_list(l)

def show_total_sum_for_type(lst):
	exp_type = input('expense type = ')
	total = show_total_sum_for_type_(lst, exp_type)
	print('total =', total)

def show_day_of_max_expense_spent(lst):
	day = show_day_of_max_expense_spent_(lst)
	print('day of max expense spent =', day)

def show_all_expenses_by_specific_total(lst):
	total = int(input('total = '))
	l = show_all_expenses_of_specific_total_(lst, total)
	show_list(l)

def show_expenses_sorted_by_type(lst):
	l = show_expenses_sorted_by_type_(lst)
	show_list(l)

def filter_expenses_by_type(lst):
	exp_type = input('expense type = ')
	l = filter_expenses_by_type_(lst, exp_type)
	show_list(l)

def filter_expenses_lower_than_total(lst):
	total = int(input('total = '))
	l = filter_expenses_lower_than_total_(lst, total)
	show_list(l)

def undo(lst, undo_lst):
	if len(undo_lst) > 0:
		lst = undo_lst.pop(len(undo_lst) - 1)
		return lst
	print('cant undo!')
	return lst
