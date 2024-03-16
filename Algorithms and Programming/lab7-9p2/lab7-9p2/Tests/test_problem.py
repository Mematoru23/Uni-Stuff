from unittest import TestCase
import importlib
pb = importlib.import_module('lab7-9p2.Domain.problem')

class TestProblem(TestCase):
    def test_get_lab_number(self):
        problem = pb.Problem(23, 'da', 2)
        self.assertEqual(problem.get_lab_number(), 23)

    def test_get_description(self):
        problem = pb.Problem(23, 'da', 2)
        self.assertEqual(problem.get_description(), 'da')

    def test_get_deadline(self):
        problem = pb.Problem(23, 'da', 2)
        self.assertEqual(problem.get_deadline(), 2)

    def test_set_lab_number(self):
        problem = pb.Problem(23, 'da', 2)
        problem.set_lab_number(10)
        self.assertEqual(problem.get_lab_number(), 10)
        with self.assertRaises(ValueError):
            problem.set_lab_number('')

    def test_set_description(self):
        problem = pb.Problem(23, 'da', 2)
        problem.set_description('nuu')
        self.assertEqual(problem.get_description(), 'nuu')
        with self.assertRaises(ValueError):
            problem.set_description('')

    def test_set_deadline(self):
        problem = pb.Problem(23, 'da', 2)
        problem.set_deadline(10)
        self.assertEqual(problem.get_deadline(), 10)
        with self.assertRaises(ValueError):
            problem.set_deadline('')

    def test_string(self):
        problem = pb.Problem(23, 'da', 2)
        self.assertEqual(str(problem), '<Lab number:23; Description:da; Deadline:2>')
