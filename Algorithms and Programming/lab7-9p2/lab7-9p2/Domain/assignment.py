from Domain.student import Student
from Domain.problem import Problem

class Assignment:
	def __init__(self, student: Student, problem: Problem, grade):
		self.__student = student
		self.__problem = problem
		self.__grade = grade

	def get_student(self):
		return self.__student

	def get_problem(self):
		return self.__problem

	def get_grade(self):
		return self.__grade

	def set_student(self, value):
		if value == '':
			raise ValueError('invalid data')
		self.__student = value

	def set_problem(self, value):
		if value == '':
			raise ValueError('invalid data')
		self.__problem = value

	def set_grade(self, value):
		if value == '':
			raise ValueError('invalid data')
		self.__grade = value

	def __str__(self):
		return f'<<STUD:{self.__student.get_studentID()}; {self.__student.get_name()}; {self.__student.get_group()} | PROB:{self.__problem.get_lab_number()}; {self.__problem.get_description()}; {self.__problem.get_deadline()} | GRADE:{self.get_grade()}>>'
	
