from ui import *
from tests import *
from console import *
import os

if __name__ == '__main__':
	tests()
	lst = []
	undo_lst = []
	func_list = {}
	menu(func_list)
	render_welcome()
	while True:
		cmd = input('>> ')
		if cmd == 'help':
			render_help(func_list)
		elif cmd == 'exit':
			break
		elif cmd == 'list':
			show_list(lst)
		elif cmd == 'clear':
			clear_list(lst, undo_lst)
		elif cmd == '1':
			add_expense(lst, undo_lst)
		elif cmd == '2':
			mod_expense(lst, undo_lst)
		elif cmd == '3':
			del_all_by_day(lst, undo_lst)
		elif cmd == '4':
			del_from_interval(lst, undo_lst)
		elif cmd == '5':
			del_all_by_type(lst, undo_lst)
		elif cmd == '6':
			show_expenses_higher(lst)
		elif cmd == '7':
			show_expenses_before_day_smaller(lst)
		elif cmd == '8':
			show_expenses_by_type(lst)
		elif cmd == '9':
			show_total_sum_for_type(lst)
		elif cmd == '10':
			show_day_of_max_expense_spent(lst)
		elif cmd == '11':
			show_all_expenses_by_specific_total(lst)
		elif cmd == '12':
			show_expenses_sorted_by_type(lst)
		elif cmd == '13':
			filter_expenses_by_type(lst)
		elif cmd == '14':
			filter_expenses_lower_than_total(lst)
		elif cmd == 'undo':
			lst = undo(lst, undo_lst)
		elif cmd == 'cls':
			os.system('cls')
			render_help(func_list)
		elif cmd == '':
			continue
		else:
			render_not_found(cmd)
