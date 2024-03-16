from UI.console import Console
from Service.service_students import ServiceStudents
from Service.service_problems import ServiceProblems
from Service.service_assignments import ServiceAssignments
from Errors.errors import ValidationError

class UI:
	def __init__(self, console: Console, service_students: ServiceStudents, service_problems: ServiceProblems, service_assignments: ServiceAssignments):
		self.__console = console
		self.__service_students = service_students
		self.__service_problems = service_problems
		self.__service_assignments = service_assignments

		console.register_function(self.show_students, 'shows', 'show list of students')
		console.register_function(self.show_problems, 'showp', 'show list of problems')
		console.register_function(self.show_assignments, 'showass', 'show list of assignments')
		console.register_function(self.add_student, 'adds', 'add student in list')
		console.register_function(self.add_problem, 'addp', 'add problem in list')
		console.register_function(self.add_assignment, 'addass', 'add assignment in list')
		console.register_function(self.delete_student, 'dels', 'delete student from list')
		console.register_function(self.delete_problem, 'delp', 'delete problem from list')
		console.register_function(self.delete_assignment, 'dela', 'delete assignment from list')
		console.register_function(self.modify_student, 'mods', 'modify student from list')
		console.register_function(self.modify_problem, 'modp', 'modify problem from list')
		console.register_function(self.show_stat_stud_grade, 'statsg', 'show asc list of students and grades by name and grade')
		console.register_function(self.show_stat_stud_average_lower_than_5, 'statav', 'show students with and average below 5')

	def start(self):
		self.__console.start()

########## STUDENTS ###########
	def show_students(self, param: list):
		for stud in self.__service_students.get_students():
			print(stud)

	def add_student(self, param: list):
		try:
			name = input('enter name: ')
			group = input('enter group: ')
			self.__service_students.add_student(name, group)
		except ValidationError as e:
			print(str(e))

	def delete_student(self, param: list):
		try:
			name = input('enter name to delete: ')
			group = int(input('enter group to delete: '))
			self.__service_students.delete_student(name, group)
		except ValidationError as e:
			print(str(e))

	def modify_student(self, param: list):
		try:
			name = input('enter name to modify: ')
			group = int(input('enter group to modify: '))
			new_name = input('enter new name: ')
			new_group = int(input('enter new group: '))
			self.__service_students.modify_student(name, group, new_name, new_group)
		except ValidationError as e:
			print(str(e))

######## PROBLEMS #########
	def show_problems(self, param: list):
		for prob in self.__service_problems.get_problems():
			print(prob)

	def add_problem(self, param: list):
		try:
			lab_nr = int(input('enter lab number: '))
			desc = input('enter description: ')
			deadline = int(input('enter deadline: '))
			self.__service_problems.add_problem(lab_nr, desc, deadline)
		except ValidationError as e:
			print(str(e))

	def delete_problem(self, param: list):
		try:
			lab_nr = int(input('enter lab number: '))
			desc = input('enter description: ')
			deadline = int(input('enter deadline: '))
			self.__service_problems.delete_problem(lab_nr, desc, deadline)
		except ValidationError as e:
			print(str(e))

	def modify_problem(self, param: list):
		try:
			lab_nr = int(input('enter lab number: '))
			desc = input('enter description: ')
			deadline = int(input('enter deadline: '))
			new_lab_nr = int(input('new enter lab number: '))
			new_desc = input('new enter description: ')
			new_deadline = int(input('new enter deadline: '))
			self.__service_problems.modify_problem(lab_nr, desc, deadline, new_lab_nr, new_desc, new_deadline)
		except ValidationError as e:
			print(str(e))

######## Assignments #########
	def show_assignments(self, param: list):
		for ass in self.__service_assignments.get_assignments():
			print(ass)

	def add_assignment(self, param: list):
		try:
			print('Student:')
			name = input('  enter name: ')
			group = int(input('  enter group: '))
			print('Problem:')
			lab_nr = int(input('  enter lab number: '))
			desc = input('  enter description: ')
			deadline = int(input('  enter deadline: '))
			print('Grade:')
			grade = int(input('  enter grade: '))
			self.__service_assignments.add_assignment(name, group, lab_nr, desc, deadline, grade)
		except ValidationError as e:
			print(str(e))

	def delete_assignment(self, param: list):
		try:
			print('Student to delete:')
			name = input('  enter name: ')
			group = int(input('  enter group: '))
			print('Problem to delete:')
			lab_nr = int(input('  enter lab number: '))
			desc = input('  enter description: ')
			deadline = int(input('  enter deadline: '))
			print('Grade to delete:')
			grade = int(input('  enter grade: '))
			self.__service_assignments.delete_assignment(name, group, lab_nr, desc, deadline, grade)
		except ValidationError as e:
			print(str(e))

	def show_stat_stud_grade(self, param: list):
		for l in self.__service_assignments.stat_stud_grade():
			print(l)

	def show_stat_stud_average_lower_than_5(self, param: list):
		for l in self.__service_assignments.stat_stud_average_lower_than_5():
			print(l)

