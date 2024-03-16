from Domain.assignment import Assignment
from Domain.student import Student
from Domain.problem import Problem
from Repo.repo_assignments import RepoAssignments
from Repo.repo_problems import RepoProblems
from Repo.repo_students import RepoStudents

class RepoAssignmentsFile(RepoAssignments):
	def __init__(self, filename):
		super().__init__(RepoStudents, RepoProblems)
		self.__filename = filename
		self.__load_from_file()

	def get_assignments(self):
		return super().get_assignments()

	def get_size(self):
		return super().size()

	def __load_from_file(self):
		try:
			with open(self.__filename, "r") as f:
				for line in f:
					elems = line.strip().split('|')
					elem_stud = elems[0].strip().split(';')
					elem_prob = elems[1].strip().split(';')
					elem_grade = elems[2]
					stud = Student(elem_stud[1], elem_stud[2])
					prob = Problem(elem_prob[0], elem_prob[1], elem_prob[2])
					grade = int(elem_grade)
					assignment = Assignment(stud, prob, grade)
					super().add_assignment(assignment)
		except IOError:
			return

	def __save_to_file(self, assignment):
		with open(self.__filename, "a") as f:
			f.write(f'{assignment.get_student().get_studentID()};{assignment.get_student().get_name()};{assignment.get_student().get_group()}|'
		   '{assignment.get_problem().get_lab_number()};{assignment.get_problem().get_description()};{assignment.get_problem().get_deadline()}|{assignment.get_grade()}\n')

	def __save_to_file_all(self):
		with open(self.__filename, "w") as f:
			for problem in self.get_problems():
				f.write(f'{problem.get_lab_number()};{problem.get_description()};{problem.get_deadline()}\n')

	def add_assignment(self, assignment):
		super().add_assignment(assignment)
		self.__save_to_file(assignment)

	def delete_assignment(self, assign):
		super().delete_assignment(assign)
		self.__save_to_file_all()

	def modify_assignment(self, problem, new_problem):
		super().modify_problem(problem, new_problem)
		self.__save_to_file_all()



