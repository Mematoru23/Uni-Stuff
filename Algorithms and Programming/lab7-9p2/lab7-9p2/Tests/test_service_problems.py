from unittest import TestCase
import importlib
pb = importlib.import_module('lab7-9p2.Domain.problem')
st = importlib.import_module('lab7-9p2.Domain.student')
val = importlib.import_module('lab7-9p2.Validators.validate_problem')
repo_st = importlib.import_module('lab7-9p2.Repo.repo_students')
repo_pb = importlib.import_module('lab7-9p2.Repo.repo_problems')
repo_serv = importlib.import_module('lab7-9p2.Service.service_problems')

class TestServiceProblems(TestCase):
    def test_get_problems(self):
        repoPB = repo_pb.RepoProblems()
        vp = val.ValidateProblem()
        servR = repo_serv.ServiceProblems(repoPB, vp)
        prob = pb.Problem(23, 'aa', 11)
        vp.validate(prob)
        servR.add_problem(prob.get_lab_number(), prob.get_description(), prob.get_deadline())
        self.assertEqual(len(servR.get_problems()), 1)
        with self.assertRaises(Exception):
            servR.add_problem(-1, '', -2)

    def test_add_problem(self):
        repoPB = repo_pb.RepoProblems()
        vp = val.ValidateProblem()
        servR = repo_serv.ServiceProblems(repoPB, vp)
        prob = pb.Problem(23, 'aa', 11)
        servR.add_problem(prob.get_lab_number(), prob.get_description(), prob.get_deadline())
        self.assertEqual(len(servR.get_problems()), 1)


    def test_delete_problem(self):
        repoPB = repo_pb.RepoProblems()
        vp = val.ValidateProblem()
        servR = repo_serv.ServiceProblems(repoPB, vp)
        prob = pb.Problem(23, 'aa', 11)
        servR.add_problem(prob.get_lab_number(), prob.get_description(), prob.get_deadline())
        self.assertEqual(len(servR.get_problems()), 1)
        servR.delete_problem(prob.get_lab_number(), prob.get_description(), prob.get_deadline())
        self.assertEqual(len(servR.get_problems()), 0)


    def test_modify_problem(self):
        repoPB = repo_pb.RepoProblems()
        vp = val.ValidateProblem()
        servR = repo_serv.ServiceProblems(repoPB, vp)
        prob = pb.Problem(23, 'aa', 11)
        servR.add_problem(prob.get_lab_number(), prob.get_description(), prob.get_deadline())
        self.assertEqual(len(servR.get_problems()), 1)
        servR.modify_problem(prob.get_lab_number(), prob.get_description(), prob.get_deadline(), 12, 'gg', 2)
        self.assertEqual(servR.get_problems()[0].get_deadline(), 2)
