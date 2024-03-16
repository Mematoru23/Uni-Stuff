from Domain.student import Student
from Domain.problem import Problem
from Domain.assignment import Assignment

class ServiceAssignments:
	def __init__(self, repo_assignments):
		self.__repo_assignments = repo_assignments

	def get_assignments(self):
		return self.__repo_assignments.get_assignments()

	def add_assignment(self, name, group, lab_number, desc, deadline, grade):
		stud = Student(name, group)
		prob = Problem(lab_number, desc, deadline)
		#if self.__repo_assignments.find_assignment(stud, prob):
		assignment = Assignment(stud, prob, grade)
		self.__repo_assignments.add_assignment(assignment)
		#raise ValueError('invalid assignment')

	def stat_stud_grade(self):
		lst = sorted(self.get_assignments(), key = lambda x: (x.get_student().get_name(), x.get_grade()))
		return lst

	def stat_stud_average_lower_than_5(self):
		lst = []
		for ass in self.get_assignments():
			val = {'STUD': ass.get_student().get_name(), 'GRADE': ass.get_grade()}
			if ass.get_grade() < 5:
				lst.append(val)
			
		return lst
			