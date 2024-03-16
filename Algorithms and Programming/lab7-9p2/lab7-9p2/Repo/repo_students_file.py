from Domain.student import Student
from Repo.repo_students import RepoStudents

class RepoStudentsFile(RepoStudents):
	def __init__(self, filename):
		super().__init__()
		self.__filename = filename
		self.__load_from_file()

	def get_students(self):
		return super().get_students()

	def get_size(self):
		return super().size()

	def __load_from_file(self):
		try:
			with open(self.__filename, "r") as f:
				for line in f:
					elems = line.strip().split(';')
					studentID = int(elems[0])
					name = elems[1]
					group = int(elems[2])
					stud = Student(name, group)
					super().add_student(stud)
		except IOError:
			return

	def __save_to_file(self, student):
		with open(self.__filename, "a") as f:
			f.write(f'{student.get_studentID()};{student.get_name()};{student.get_group()}\n')

	def __save_to_file_all(self):
		with open(self.__filename, "w") as f:
			for student in self.get_students():
				f.write(f'{student.get_studentID()};{student.get_name()};{student.get_group()}\n')

	def add_student(self, student):
		super().add_student(student)
		self.__save_to_file(student)

	def delete_student(self, student):
		super().delete_student(student)
		self.__save_to_file_all()

	def modify_student(self, student, new_student):
		super().modify_student(student, new_student)
		self.__save_to_file_all()


