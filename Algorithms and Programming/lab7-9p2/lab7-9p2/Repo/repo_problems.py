from Domain.problem import Problem

class RepoProblems:
	def __init__(self):
		self.__problems = []

	def size(self):
		return len(self.__problems)

	def clear(self):
		self.__problems = []

	def get_problems(self):
		return self.__problems

	def find_problem(self, problem):
		for prob in self.__problems:
			if prob.get_lab_number() == problem.get_lab_number() and prob.get_deadline() == problem.get_deadline():
				return prob
		return -1

	def add_problem(self, problem):
		if problem in self.__problems:
			raise ValueError('existing problem')
		self.__problems.append(problem)

	def delete_problem(self, problem):
		if self.find_problem(problem) != -1:
			for indx, prob in enumerate(self.__problems):
				if prob.get_lab_number() == problem.get_lab_number() and prob.get_deadline() == problem.get_deadline() and prob.get_description() == problem.get_description():
					self.__problems.pop(indx)
					return True
		raise ValueError('problem not found')

	def modify_problem(self, problem, new_problem):
		if self.find_problem(problem) != -1:
			for prob in self.__problems:
				if prob.get_lab_number() == problem.get_lab_number() and prob.get_deadline() == problem.get_deadline() and prob.get_description() == problem.get_description():
					prob.set_lab_number(new_problem.get_lab_number())
					prob.set_description(new_problem.get_description())
					prob.set_deadline(new_problem.get_deadline())
					return True
		raise ValueError('problem not found')