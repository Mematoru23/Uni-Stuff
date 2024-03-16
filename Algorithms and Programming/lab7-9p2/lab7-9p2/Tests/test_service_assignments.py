from unittest import TestCase
import importlib
assign = importlib.import_module('lab7-9p2.Domain.assignment')
pb = importlib.import_module('lab7-9p2.Domain.problem')
st = importlib.import_module('lab7-9p2.Domain.student')
repo_st = importlib.import_module('lab7-9p2.Repo.repo_students')
repo_pb = importlib.import_module('lab7-9p2.Repo.repo_problems')
repo_ass = importlib.import_module('lab7-9p2.Repo.repo_assignments')
repo_serv = importlib.import_module('lab7-9p2.Service.service_assignments')

class TestServiceAssignments(TestCase):
    def test_add_assignments(self):
        repoST = repo_st.RepoStudents()
        repoPB = repo_pb.RepoProblems()
        repoASS = repo_ass.RepoAssignments(repoST, repoPB)
        servAss = repo_serv.ServiceAssignments(repoASS)
        stud = st.Student('da', 23)
        stud1 = st.Student('a', 23)
        prob = pb.Problem(23, 'aa', 11)
        prob1 = pb.Problem(3, 'ha', 11)
        repoST.add_student(stud)
        repoST.add_student(stud1)
        repoPB.add_problem(prob)
        repoPB.add_problem(prob1)
        grade = 9
        grade1 = 10
        servAss.add_assignment(stud.get_name(), stud.get_group(), prob.get_lab_number(), prob.get_description(),
                               prob.get_deadline(), grade)
        servAss.add_assignment(stud1.get_name(), stud1.get_group(), prob1.get_lab_number(), prob1.get_description(),
                               prob1.get_deadline(), grade1)
        self.assertEqual(len(servAss.get_assignments()), 2)

    def test_stat_stud_grade(self):
        repoST = repo_st.RepoStudents()
        repoPB = repo_pb.RepoProblems()
        repoASS = repo_ass.RepoAssignments(repoST, repoPB)
        servAss = repo_serv.ServiceAssignments(repoASS)
        stud = st.Student('da', 23)
        stud1 = st.Student('a', 23)
        prob = pb.Problem(23, 'aa', 11)
        prob1 = pb.Problem(23, 'aa', 11)
        repoST.add_student(stud)
        repoST.add_student(stud1)
        repoPB.add_problem(prob)
        repoPB.add_problem(prob1)
        grade = 9
        grade1 = 10
        ass = assign.Assignment(stud, prob, grade)
        ass1 = assign.Assignment(stud1, prob1, grade1)
        repoASS.add_assignment(ass)
        repoASS.add_assignment(ass1)
        self.assertEqual(len(servAss.get_assignments()), 2)
        lst = servAss.stat_stud_grade()
        self.assertEqual(len(lst), 2)
        self.assertEqual(lst[0].get_student().get_name(), 'a')

    def test_stat_stud_average_lower_than_5(self):
        repoST = repo_st.RepoStudents()
        repoPB = repo_pb.RepoProblems()
        repoASS = repo_ass.RepoAssignments(repoST, repoPB)
        servAss = repo_serv.ServiceAssignments(repoASS)
        stud = st.Student('da', 23)
        stud1 = st.Student('a', 23)
        stud2 = st.Student('a', 23)
        prob = pb.Problem(23, 'aa', 11)
        prob1 = pb.Problem(23, 'aa', 11)
        prob2 = pb.Problem(23, 'aa', 11)
        repoST.add_student(stud)
        repoST.add_student(stud1)
        repoST.add_student(stud2)
        repoPB.add_problem(prob)
        repoPB.add_problem(prob1)
        repoPB.add_problem(prob2)
        grade = 9
        grade1 = 10
        grade2 = 4
        ass = assign.Assignment(stud, prob, grade)
        ass1 = assign.Assignment(stud1, prob1, grade1)
        repoASS.add_assignment(ass)
        repoASS.add_assignment(ass1)
        self.assertEqual(len(servAss.get_assignments()), 2)
        lst = servAss.stat_stud_average_lower_than_5()
        self.assertEqual(len(lst), 0)
        ass2 = assign.Assignment(stud2, prob2, grade2)
        repoASS.add_assignment(ass2)
        self.assertEqual(len(servAss.get_assignments()), 3)
        lst = servAss.stat_stud_average_lower_than_5()
        self.assertEqual(len(lst), 1)
