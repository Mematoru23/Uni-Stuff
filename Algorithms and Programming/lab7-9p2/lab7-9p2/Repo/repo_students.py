from Domain.student import Student

class RepoStudents:
	def __init__(self):
		self.__students = []

	def size(self):
		return len(self.__students)

	def get_students(self):
		return self.__students

	def find_student(self, student):
		for stud in self.__students:
			if stud.get_name() == student.get_name() and stud.get_group() == student.get_group():
				return stud
		return -1

	def add_student(self, student):
		self.__students.append(student)

	def delete_student(self, student):
		if self.find_student(student) != -1:
			for indx, stud in enumerate(self.__students):
				if stud.get_name() == student.get_name() and stud.get_group() == student.get_group():
					self.__students.pop(indx)
					return True
		raise ValueError('student not found')

	def modify_student(self, student, new_student):
		if self.find_student(student) != -1:
			for stud in self.__students:
				if stud.get_name() == student.get_name() and stud.get_group() == student.get_group():
					stud.set_name(new_student.get_name())
					stud.set_group(new_student.get_group())
					return True
		raise ValueError('student not found')