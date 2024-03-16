from Domain.student import Student

class ServiceStudents:
	def __init__(self, repo_students, validator):
		self.__repo_students = repo_students
		self.__validator = validator

	def get_students(self):
		return self.__repo_students.get_students()

	def add_student(self, name, group):
		student = Student(name, group)
		self.__validator.validate(student)
		self.__repo_students.add_student(student)

	def delete_student(self, name, group):
		student = Student(name, group)
		self.__validator.validate(student)
		self.__repo_students.delete_student(student)

	def modify_student(self, name, group, new_name, new_group):
		student = Student(name, group)
		new_student = Student(new_name, new_group)
		self.__validator.validate(student)
		self.__validator.validate(new_student)
		self.__repo_students.modify_student(student, new_student)
