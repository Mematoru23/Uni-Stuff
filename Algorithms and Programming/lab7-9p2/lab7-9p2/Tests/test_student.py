from unittest import TestCase
import importlib
st = importlib.import_module('lab7-9p2.Domain.student')

class TestStudent(TestCase):
    def test_get_student_id(self):
        stud = st.Student('da', 23)
        self.assertEqual(stud.get_studentID(), 36)

    def test_get_name(self):
        stud = st.Student('da', 23)
        self.assertEqual(stud.get_name(), 'da')

    def test_get_group(self):
        stud = st.Student('da', 23)
        self.assertEqual(stud.get_group(), 23)

    def test_set_name(self):
        stud = st.Student('da', 23)
        stud.set_name('aaa')
        self.assertEqual(stud.get_name(), 'aaa')
        with self.assertRaises(ValueError):
            stud.set_name('')

    def test_set_group(self):
        stud = st.Student('da', 23)
        stud.set_group(14)
        self.assertEqual(stud.get_group(), 14)
        with self.assertRaises(ValueError):
            stud.set_group('')

    def test_string(self):
        stud = st.Student('da', 23)
        self.assertEqual(str(stud), '>ID:39 Name:da Group:23<')