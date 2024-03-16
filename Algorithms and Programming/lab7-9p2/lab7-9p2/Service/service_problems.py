from Domain.problem import Problem

class ServiceProblems:
	def __init__(self, repo_problems, validator):
		self.__repo_problems = repo_problems
		self.__validator = validator

	def get_problems(self):
		return self.__repo_problems.get_problems()

	def add_problem(self, lab_number, description, deadline):
		problem = Problem(lab_number, description, deadline)
		self.__validator.validate(problem)
		self.__repo_problems.add_problem(problem)

	def delete_problem(self,  lab_number, description, deadline):
		problem = Problem(lab_number, description, deadline)
		self.__validator.validate(problem)
		self.__repo_problems.delete_problem(problem)

	def modify_problem(self, lab_number, description, deadline, new_lab_number, new_description, new_deadline):
		problem = Problem(lab_number, description, deadline)
		new_problem = Problem(new_lab_number, new_description, new_deadline)
		self.__validator.validate(problem)
		self.__validator.validate(new_problem)
		self.__repo_problems.modify_problem(problem, new_problem)
