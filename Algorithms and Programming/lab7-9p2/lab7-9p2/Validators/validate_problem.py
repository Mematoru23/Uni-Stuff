from Errors.errors import ValidationError

class ValidateProblem:
	def validate(self, problem):
		err = ''
		if problem.get_lab_number() < 1:
			err += 'invalid lab number\n'
		if problem.get_description() == '':
			err += 'invalid description\n'
		if problem.get_deadline() < 1:
			err += 'invalid deadline'
		if len(err):
			raise ValidationError(err)

