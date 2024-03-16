from unittest import TestCase
import importlib
pb = importlib.import_module('lab7-9p2.Domain.problem')
st = importlib.import_module('lab7-9p2.Domain.student')
val = importlib.import_module('lab7-9p2.Validators.validate_student')
repo_st = importlib.import_module('lab7-9p2.Repo.repo_students')
repo_pb = importlib.import_module('lab7-9p2.Repo.repo_problems')
repo_serv = importlib.import_module('lab7-9p2.Service.service_students')

class TestServiceStudents(TestCase):
    def test_get_students(self):
        repoST = repo_st.RepoStudents()
        vs = val.ValidateStudent()
        serv = repo_serv.ServiceStudents(repoST, vs)
        stud = st.Student('da', 23)
        repoST.add_student(stud)
        self.assertEqual(len(serv.get_students()), 1)
        with self.assertRaises(Exception):
            serv.add_student('', -1)

    def test_add_student(self):
        repoST = repo_st.RepoStudents()
        vs = val.ValidateStudent()
        serv = repo_serv.ServiceStudents(repoST, vs)
        stud = st.Student('da', 23)
        repoST.add_student(stud)
        serv.add_student('nu', 22)
        self.assertEqual(len(serv.get_students()), 2)

    def test_delete_student(self):
        repoST = repo_st.RepoStudents()
        vs = val.ValidateStudent()
        serv = repo_serv.ServiceStudents(repoST, vs)
        stud = st.Student('da', 23)
        repoST.add_student(stud)
        self.assertEqual(len(serv.get_students()), 1)
        serv.delete_student('da', 23)
        self.assertEqual(len(serv.get_students()), 0)


    def test_modify_student(self):
        repoST = repo_st.RepoStudents()
        vs = val.ValidateStudent()
        serv = repo_serv.ServiceStudents(repoST, vs)
        stud = st.Student('da', 23)
        repoST.add_student(stud)
        self.assertEqual(len(serv.get_students()), 1)
        serv.modify_student('da', 23, 'hh', 11)
        self.assertEqual(serv.get_students()[0].get_name(), 'hh')