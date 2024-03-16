from UI.console import Console
from UI.ui import UI
from Service.service_students import ServiceStudents
from Service.service_problems import ServiceProblems
from Service.service_assignments import ServiceAssignments
from Repo.repo_students import RepoStudents
from Repo.repo_problems import RepoProblems
from Repo.repo_assignments import RepoAssignments
from Repo.repo_problems_file import RepoProblemsFile
from Repo.repo_students_file import RepoStudentsFile
from Repo.repo_assignments_file import RepoAssignmentsFile
from Validators.validate_problem import ValidateProblem
from Validators.validate_student import ValidateStudent

if __name__ == '__main__':
	console = Console()

	#repo_students = RepoStudents()
	repo_students = RepoStudentsFile('Repo/file_repo_students.txt')
	validators = ValidateStudent()
	service_students = ServiceStudents(repo_students, validators)

	#repo_problems = RepoProblems()
	repo_problems = RepoProblemsFile('Repo/file_repo_problems.txt')
	validatorp = ValidateProblem()
	service_problems = ServiceProblems(repo_problems, validatorp)

	#repo_assignments = RepoAssignments(repo_students, repo_problems)
	repo_assignments = RepoAssignmentsFile('Repo/file_repo_assignments.txt')
	service_assignments = ServiceAssignments(repo_assignments)

	ui = UI(console, service_students, service_problems, service_assignments)
	ui.start()
	

