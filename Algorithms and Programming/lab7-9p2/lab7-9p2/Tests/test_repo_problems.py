from unittest import TestCase
import importlib
assign = importlib.import_module('lab7-9p2.Domain.assignment')
pb = importlib.import_module('lab7-9p2.Domain.problem')
st = importlib.import_module('lab7-9p2.Domain.student')
repo_pb = importlib.import_module('lab7-9p2.Repo.repo_problems')

class TestRepoProblems(TestCase):
    def test_size(self):
        repo = repo_pb.RepoProblems()
        self.assertEqual(repo.size(), 0)

    def test_clear(self):
        repo = repo_pb.RepoProblems()
        self.assertEqual(repo.clear(), None)

    def test_get_problems(self):
        repo = repo_pb.RepoProblems()
        prb = pb.Problem(23, 'aa', 23)
        repo.add_problem(prb)
        self.assertEqual(repo.size(), 1)
        self.assertEqual(repo.get_problems()[0].get_deadline(), 23)

    def test_find_problem(self):
        repo = repo_pb.RepoProblems()
        prb = pb.Problem(23, 'aa', 23)
        prb1 = pb.Problem(11, 'aad', 23)
        repo.add_problem(prb)
        self.assertEqual(repo.find_problem(prb), prb)
        self.assertEqual(repo.find_problem(prb1), -1)

    def test_add_problem(self):
        repo = repo_pb.RepoProblems()
        prb = pb.Problem(23, 'aa', 23)
        repo.add_problem(prb)
        with self.assertRaises(ValueError):
            repo.add_problem(prb)
        self.assertEqual(repo.size(), 1)

    def test_delete_problem(self):
        repo = repo_pb.RepoProblems()
        prb = pb.Problem(23, 'aa', 23)
        repo.add_problem(prb)
        self.assertEqual(repo.size(), 1)
        repo.delete_problem(prb)
        with self.assertRaises(ValueError):
            repo.delete_problem(prb)
        self.assertEqual(repo.size(), 0)

    def test_modify_problem(self):
        repo = repo_pb.RepoProblems()
        prb = pb.Problem(23, 'aa', 23)
        prb1 = pb.Problem(11, 'da', 13)
        prb2 = pb.Problem(1, 'da', 3)
        repo.add_problem(prb)
        self.assertEqual(repo.size(), 1)
        repo.modify_problem(prb, prb1)
        self.assertEqual(repo.get_problems()[0].get_deadline(), 13)
        with self.assertRaises(ValueError):
            repo.modify_problem(prb2, prb)
