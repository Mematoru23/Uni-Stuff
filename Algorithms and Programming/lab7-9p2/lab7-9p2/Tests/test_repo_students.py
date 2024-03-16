from unittest import TestCase
import importlib
assign = importlib.import_module('lab7-9p2.Domain.assignment')
pb = importlib.import_module('lab7-9p2.Domain.problem')
st = importlib.import_module('lab7-9p2.Domain.student')
repo_st = importlib.import_module('lab7-9p2.Repo.repo_students')

class TestRepoStudents(TestCase):
    def test_size(self):
        repo = repo_st.RepoStudents()
        self.assertEqual(repo.size(), 0)

    def test_get_students(self):
        repo = repo_st.RepoStudents()
        self.assertEqual(repo.size(), 0)
        stud = st.Student('da', 23)
        repo.add_student(stud)
        self.assertEqual(repo.size(), 1)
        self.assertEqual(repo.get_students()[0].get_name(), 'da')

    def test_find_student(self):
        repo = repo_st.RepoStudents()
        self.assertEqual(repo.size(), 0)
        stud = st.Student('da', 23)
        stud1 = st.Student('daa', 233)
        repo.add_student(stud)
        self.assertEqual(repo.size(), 1)
        self.assertEqual(repo.find_student(stud), stud)
        self.assertEqual(repo.find_student(stud1), -1)

    def test_add_student(self):
        repo = repo_st.RepoStudents()
        self.assertEqual(repo.size(), 0)
        stud = st.Student('da', 23)
        repo.add_student(stud)
        self.assertEqual(repo.size(), 1)
        self.assertEqual(repo.get_students()[0].get_name(), 'da')

    def test_delete_student(self):
        repo = repo_st.RepoStudents()
        self.assertEqual(repo.size(), 0)
        stud = st.Student('da', 23)
        stud1 = st.Student('daaa', 23)
        repo.add_student(stud)
        self.assertEqual(repo.size(), 1)
        with self.assertRaises(ValueError):
            repo.delete_student(stud1)
        repo.delete_student(stud)
        self.assertEqual(repo.size(), 0)

    def test_modify_student(self):
        repo = repo_st.RepoStudents()
        self.assertEqual(repo.size(), 0)
        stud = st.Student('da', 23)
        stud1 = st.Student('ada', 23)
        stud2 = st.Student('aada', 23)
        repo.add_student(stud)
        self.assertEqual(repo.size(), 1)
        repo.modify_student(stud, stud1)
        self.assertEqual(repo.get_students()[0].get_name(), 'ada')
        with self.assertRaises(ValueError):
            repo.modify_student(stud2, stud1)

