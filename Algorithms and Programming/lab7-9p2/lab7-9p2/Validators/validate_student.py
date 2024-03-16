from Errors.errors import ValidationError

class ValidateStudent:
	def validate(self, student):
		err = ''
		if student.get_name() == '':
			err += 'invalid name'
		if int(student.get_group()) < 1:
			err += 'invalid group'
		if len(err):
			raise ValidationError(err)
