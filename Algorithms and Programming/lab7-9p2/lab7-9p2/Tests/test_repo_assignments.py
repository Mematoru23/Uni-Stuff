from unittest import TestCase
import importlib
assign = importlib.import_module('lab7-9p2.Domain.assignment')
pb = importlib.import_module('lab7-9p2.Domain.problem')
st = importlib.import_module('lab7-9p2.Domain.student')
repo_st = importlib.import_module('lab7-9p2.Repo.repo_students')
repo_pb = importlib.import_module('lab7-9p2.Repo.repo_problems')
repo_ass = importlib.import_module('lab7-9p2.Repo.repo_assignments')

class TestRepoAssignments(TestCase):
    def test_size(self):
        repoST = repo_st.RepoStudents()
        repoPB = repo_pb.RepoProblems()
        repoASS = repo_ass.RepoAssignments(repoST, repoPB)
        stud = st.Student('da', 23)
        prob = pb.Problem(23, 'aa', 11)
        grade = 10
        ass = assign.Assignment(stud, prob, grade)
        repoST.add_student(stud)
        repoPB.add_problem(prob)
        repoASS.add_assignment(ass)
        self.assertEqual(repoASS.size(), 1)

    def test_find_assignment(self):
        repoST = repo_st.RepoStudents()
        repoPB = repo_pb.RepoProblems()
        repoASS = repo_ass.RepoAssignments(repoST, repoPB)
        stud = st.Student('da', 23)
        prob = pb.Problem(23, 'aa', 11)
        grade = 10
        ass = assign.Assignment(stud, prob, grade)
        repoST.add_student(stud)
        repoPB.add_problem(prob)
        repoASS.add_assignment(ass)
        self.assertEqual(repoASS.find_assignment(stud, prob), True)
        with self.assertRaises(ValueError):
            repoASS.find_assignment(st.Student('daaa', 13), prob)
        with self.assertRaises(ValueError):
            repoASS.find_assignment(stud, pb.Problem(5, 'hfg', 21))

    def test_clear(self):
        repoST = repo_st.RepoStudents()
        repoPB = repo_pb.RepoProblems()
        repoASS = repo_ass.RepoAssignments(repoST, repoPB)
        stud = st.Student('da', 23)
        prob = pb.Problem(23, 'aa', 11)
        grade = 10
        ass = assign.Assignment(stud, prob, grade)
        repoST.add_student(stud)
        repoPB.add_problem(prob)
        repoASS.add_assignment(ass)
        self.assertEqual(repoASS.clear(), None)

    def test_get_assignments(self):
        repoST = repo_st.RepoStudents()
        repoPB = repo_pb.RepoProblems()
        repoASS = repo_ass.RepoAssignments(repoST, repoPB)
        stud = st.Student('da', 23)
        prob = pb.Problem(23, 'aa', 11)
        grade = 10
        ass = assign.Assignment(stud, prob, grade)
        repoST.add_student(stud)
        repoPB.add_problem(prob)
        repoASS.add_assignment(ass)
        self.assertEqual(repoASS.get_assignments()[0].get_grade(), 10)

    def test_add_assignment(self):
        repoST = repo_st.RepoStudents()
        repoPB = repo_pb.RepoProblems()
        repoASS = repo_ass.RepoAssignments(repoST, repoPB)
        stud = st.Student('da', 23)
        prob = pb.Problem(23, 'aa', 11)
        grade = 10
        ass = assign.Assignment(stud, prob, grade)
        repoST.add_student(stud)
        repoPB.add_problem(prob)
        repoASS.add_assignment(ass)
        self.assertEqual(repoASS.get_assignments()[0].get_student().get_name(), 'da')
