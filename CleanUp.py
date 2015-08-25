'''Cleans up the files in a given directory
	
	This module will delete copied files and get rid of '(#) - Copy' appended to file names
	
	Improvements: Fix the CleanUp function
				  
'''

import os 
import sys
from collections import OrderedDict
import re
import filecmp



def walk_files(path):

	'''Fill a dictionary with the filenames and sizes, sort the dictionary and send it to delete_dups'''

	try:
			os.chdir(path)
	except:
		print "There was an error. Check your path name." + path 	
		main()


	filename = ""
	counter_outer = 0
	

	#use os.walk to sort by size
	for root, dir, f in os.walk(path):		
	
		for filename1 in f:
			counter_inner = 0
			if os.path.isfile(filename1):
				for filename2 in f:
					if os.path.isfile(filename2):
						if counter_outer != counter_inner:
						#Check that the files are in the current working directory
							if root == os.getcwd():
								#print "File1: ", filename1, counter_outer, " File2: ", filename2, counter_inner
						
								if os.path.getsize(filename1) == os.path.getsize(filename2):						

									if filecmp.cmp(filename1, filename2, shallow=False):
										os.remove(filename2)
										print "File ", filename2, "removed"			

							#if the files are nested in a folder, go into that folder and delete duplicates (recursive call)
							else:
								folder_files = walk_files(root)
								#delete_dups(folder_files)
								#clean_up(root)
								os.chdir(original_path)
					
					counter_inner += 1
			counter_outer += 1

def clean_up(path):

	'''Clean up file names by removing (#)'s and - Copy 's.'''

	for root, dir, f in os.walk(path):
		for name in f:
			if root == path:
				if "(" and "copy" in name:
					print "hit!"
					currentNameFixed = re.sub(r'\s+\([^)]*\)| ?\s+- Copy', '', name)
					try:
						os.rename(name, currentNameFixed)
					except:
						print "System could not find filename ", name, " in order to rename it."


def main():

	'''Prompt user for input and call the functions'''
	
	#global variable declared in order to recall the original path if we drill down into a directory
	global original_path
	original_path = raw_input("Please enter the folder you want cleaned: ")
	walk_files(original_path)
	clean_up(original_path)

	user_input = raw_input("Your files have been cleaned! Would you like to run again? (y/n)")
	if user_input == 'y':
		main()
	if user_input == 'n':
		exit()


if __name__ == "__main__":

	main()
