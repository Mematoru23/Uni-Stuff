from Domain.assignment import Assignment

class RepoAssignments:
	def __init__(self, repo_students, repo_problems):
		self.__assignments = []
		self.__repo_students = repo_students
		self.__repo_problems = repo_problems

	def size(self):
		return len(self.__assignments)

	def find_assignment(self, student, problem):
		ok = False
		for ass in self.__assignments:
			if student.get_name() == ass.get_student().get_name() and student.get_group() == ass.get_student().get_group():
				ok = True
				break
		if ok is True:
			for ass in self.__assignments:
				if ass.get_problem().get_lab_number() == problem.get_lab_number() and ass.get_problem().get_deadline() == problem.get_deadline():
					return True
			raise ValueError('problem not found')
		raise ValueError('student not found')

	def clear(self):
		self.__assignments = []

	def get_assignments(self):
		return self.__assignments

	def add_assignment(self, assignment):
		self.__assignments.append(assignment)