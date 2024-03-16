from Domain.problem import Problem
from Repo.repo_problems import RepoProblems

class RepoProblemsFile(RepoProblems):
	def __init__(self, filename):
		super().__init__()
		self.__filename = filename
		self.__load_from_file()

	def get_problems(self):
		return super().get_problems()

	def get_size(self):
		return super().size()

	def __load_from_file(self):
		try:
			with open(self.__filename, "r") as f:
				for line in f:
					elems = line.strip().split(';')
					lab_number = int(elems[0])
					desc = elems[1]
					deadline = int(elems[2])
					pb = Problem(lab_number, desc, deadline)
					super().add_problem(pb)
		except IOError:
			return

	def __save_to_file(self, problem):
		with open(self.__filename, "a") as f:
			f.write(f'{problem.get_lab_number()};{problem.get_description()};{problem.get_deadline()}\n')

	def __save_to_file_all(self):
		with open(self.__filename, "w") as f:
			for problem in self.get_problems():
				f.write(f'{problem.get_lab_number()};{problem.get_description()};{problem.get_deadline()}\n')

	def add_problem(self, problem):
		super().add_problem(problem)
		self.__save_to_file(problem)

	def delete_problem(self, problem):
		super().delete_problem(problem)
		self.__save_to_file_all()

	def modify_problem(self, problem, new_problem):
		super().modify_problem(problem, new_problem)
		self.__save_to_file_all()



