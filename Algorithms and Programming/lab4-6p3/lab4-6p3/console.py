def register_function(_func_list, command, func, description=''):
    """
    Add a functionality in list of functionalities
    """
    _func_list[command] = {'func': func, 'description': description}
    
def render_help(_func_list):
    """
    Print in console all available commands
    :return: None
    """
    print('-----List of available commands-----')
    print('help - list all commands')
    print('exit - close the program')
    print('cls - clear console')
    for command in _func_list:
        print(f'{command} - {_func_list[command]["description"]}')
            
def render_not_found(command):
    """
    Warn user that he try to use a command that not exist
    Required: name of not found command
    :return: None
    """
    print(f'command "{command}" not found')
        
def render_welcome():
    print('Algoritmi si programare -> Lab4-6')

def read_command():
    """
    Read next command from terminal
    :return: command: str
    """
    aux = input('>> ').split(' ')
    return aux[0], aux[1:]

def start(_func_list):
    """
    This function start the console
    """
    render_welcome()
    while True:
        command, params = read_command()
        if command == 'exit':
            break
        elif command == 'help':
            render_help(_func_list)
        elif command in _func_list:
            try:
                _func_list[command]['func'](params)
            except Exception as e:
                print(str(e))
        elif command == "":
            continue
        else:
            render_not_found(command)


