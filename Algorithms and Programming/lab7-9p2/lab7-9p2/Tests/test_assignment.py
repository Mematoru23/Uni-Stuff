from unittest import TestCase
import importlib
assign = importlib.import_module('lab7-9p2.Domain.assignment')
pb = importlib.import_module('lab7-9p2.Domain.problem')
st = importlib.import_module('lab7-9p2.Domain.student')

class TestAssignment(TestCase):
    def test_get_student(self):
        prob = pb.Problem(123, 'da', 23)
        stud = st.Student('aa', 11)
        grade = 10
        ass = assign.Assignment(stud, prob, grade)
        self.assertEqual(ass.get_student().get_name(), 'aa')

    def test_get_problem(self):
        prob = pb.Problem(123, 'da', 23)
        stud = st.Student('aa', 11)
        grade = 10
        ass = assign.Assignment(stud, prob, grade)
        self.assertEqual(ass.get_problem().get_description(), 'da')

    def test_get_grade(self):
        prob = pb.Problem(123, 'da', 23)
        stud = st.Student('aa', 11)
        grade = 10
        ass = assign.Assignment(stud, prob, grade)
        self.assertEqual(ass.get_grade(), 10)

    def test_set_student(self):
        prob = pb.Problem(123, 'da', 23)
        stud = st.Student('aa', 11)
        grade = 10
        ass = assign.Assignment(stud, prob, grade)
        ass.set_student(stud)
        self.assertEqual(ass.get_student().get_name(), 'aa')
        with self.assertRaises(ValueError):
            ass.set_student('')

    def test_set_problem(self):
        prob = pb.Problem(123, 'da', 23)
        stud = st.Student('aa', 11)
        grade = 10
        ass = assign.Assignment(stud, prob, grade)
        ass.set_problem(prob)
        self.assertEqual(ass.get_problem().get_description(), 'da')
        with self.assertRaises(ValueError):
            ass.set_problem('')

    def test_set_grade(self):
        prob = pb.Problem(123, 'da', 23)
        stud = st.Student('aa', 11)
        grade = 10
        ass = assign.Assignment(stud, prob, grade)
        ass.set_grade(grade)
        self.assertEqual(ass.get_grade(), 10)
        with self.assertRaises(ValueError):
            ass.set_grade('')

    def test_string(self):
        prob = pb.Problem(123, 'da', 23)
        stud = st.Student('aa', 11)
        grade = 10
        ass = assign.Assignment(stud, prob, grade)
        self.assertEqual(str(ass), '<<STUD:7; aa; 11 | PROB:123; da; 23 | GRADE:10>>')
