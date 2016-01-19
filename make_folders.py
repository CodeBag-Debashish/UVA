#!/usr/bin/python
import os,sys
from os import listdir
from os.path import isfile, join


def main():
	root_path = os.path.dirname(os.path.abspath(__file__))

	nameFormat = raw_input("enter required name : ")
	nos = raw_input("How many ? : ")
	nos = int(nos)
	L_digits = len(str(nos))

	for x in range(1,nos+1):
		if ( L_digits - len(str(x)) ) > 0 :
			zeros="0" * ( L_digits - len(str(x)) )
			endnum = zeros + str(x)
		else:
			endnum = str(x)
 		folder_name = nameFormat + endnum 
		os.mkdir(os.path.join(root_path, folder_name))

main()
