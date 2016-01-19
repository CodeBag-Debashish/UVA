import os,sys
from os import listdir
from os.path import isfile, join

def FileNmaeloader(path,nameFormat,this_file,extension):
	filenames = [f for f in listdir(path) if isfile(join(path,f)) and f != this_file]
	num = 1
	L_digits = len(str(len(filenames)))
	
	for old_name in filenames:
		if ( L_digits - len(str(num)) ) > 0 :
			zeros="0" * ( L_digits - len(str(num)) )
			endnum = zeros + str(num)
		else: 
			endnum = str(num)
		new_name = nameFormat+endnum+extension
		os.rename(old_name,new_name)
		num += 1

def main():
	this_file = sys.argv[0]
	extension = ".pdf"
	path = os.getcwd()
	nameFormat = raw_input("enter required name : ")
	FileNmaeloader(path,nameFormat,this_file,extension)
	
main()
