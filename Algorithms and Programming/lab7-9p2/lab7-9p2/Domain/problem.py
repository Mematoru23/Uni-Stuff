
class Problem:
	def __init__(self, lab_number, description, deadline):
		self.__lab_number = lab_number
		self.__description = description
		self.__deadline = deadline

	def get_lab_number(self):
		return self.__lab_number

	def get_description(self):
		return self.__description

	def get_deadline(self):
		return self.__deadline

	def set_lab_number(self, value):
		if value == '':
			raise ValueError('invalid data')
		self.__lab_number = value

	def set_description(self, value):
		if value == '':
			raise ValueError('invalid data')
		self.__description = value

	def set_deadline(self, value):
		if value == '':
			raise ValueError('invalid data')
		self.__deadline = value

	def __str__(self):
		string = f'<Lab number:{self.get_lab_number()}; Description:{self.get_description()}; Deadline:{self.get_deadline()}>'
		return string
