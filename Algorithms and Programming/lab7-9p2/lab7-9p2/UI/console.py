import os

class Console:
	def __init__(self):
		self._func_list = {}
		self.cursor = '>> '
		self.exit_command = 'exit'
		self.help_command = 'help'
		self.clear_command = 'clear'
		self.no_command = ''

	def register_function(self, func, command, description = ''):
		self._func_list[command] = {'func': func, 'description': description}

	def _render_help(self):
		print('-----List of available commands-----')
		print('help - list all commands')
		print('exit - close the program')
		print('clear - clear the console\n')
		for command in self._func_list:
			print(f'{command} - {self._func_list[command]["description"]}')
			
	def _render_welcome(self):
		print('Algoritmi si programare -> Lab 7-9')
		
	def _clear(self):
		os.system('cls')
		self._render_welcome()

	def _exit(self):
		exit()

	@staticmethod
	def _render_not_found(command):
		print(f'command "{command}" not found')

	def _read_commands(self):
		commands = input(self.cursor).split(';')
		return commands

	def _parse_command(self, command_string):
		command_string = command_string.lstrip(' ')
		aux = command_string.split(' ')
		command = aux[0]
		params = aux[1:]
		params = list(filter(lambda x: x != '', params))
		return command, params

	def start(self):
		self._render_welcome()
		while True:
			commands = self._read_commands()
			for c in commands:
				command, params = self._parse_command(c)
				if command == self.exit_command:
					self._exit()
				elif command == self.clear_command:
					self._clear()
				elif command == self.help_command:
					self._render_help()
				elif command in self._func_list:
					try:
						self._func_list[command]['func'](params)
					except ValueError as e:
						print(str(e))
				elif command == self.no_command:
					continue
				else:
					self._render_not_found(command)
							
