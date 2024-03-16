from domain import *

class Repo:
	def __init__(self):
		self.lista = []

	def add(self, expense):
		if expense in self.lista:
			raise ValueError('already in list')
		self.lista.append(expense)

	def delete(self, expense):
		for exp in self.lista:
			if exp == expense:
				self.lista.remove(exp)

	def modify(self, day, sum, type, new_day, new_sum, new_type):
		for i in self.lista:
			if day == i.get_day() and sum == i.get_sum() and type == i.get_type():
				i.set_day(new_day)
				i.set_sum(new_sum)
				i.set_type(new_type)

	def show(self):
		return self.lista