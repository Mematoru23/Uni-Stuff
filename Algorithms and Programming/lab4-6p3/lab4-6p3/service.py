from domain import *
from repo import Repo

class Service:
	def __init__(self, repo):
		self.__repo = repo

	def add(self, day, sum, type):
		expense = Expense(day, sum, type)
		self.__repo.add(expense)
		return expense

	def show(self):
		self.__repo.show()