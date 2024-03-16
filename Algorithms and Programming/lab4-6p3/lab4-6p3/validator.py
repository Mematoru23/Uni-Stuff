from domain import *

def validate_day(day):
	if day < 1 or day > 31:
		raise Exception("[1, 31] = value needed")
	return True

def validate_type(type):
	if not (type ==  "mancare") or not (type ==  "intretinere") or not (type ==  "imbracaminte") or not (type ==  "telefon") or not (type ==  "altele"):
		raise Exception("incorrect type")
	return True

