
def Expense(day, sum, type):
	return {
		'day': day,
		'sum': sum, 
		'type': type
	}

def get_day(expense):
	return expense['day']

def get_sum(expense):
	return expense['sum']

def get_type(expense):
	return expense['type']

def set_day(expense, new_day):
	expense['day'] = new_day

def set_sum(expense, new_sum):
	expense['sum'] == new_sum

def set_type(expense, new_type):
	expense['type'] = new_type
