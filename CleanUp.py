'''Cleans up the files in a given directory
	
	This module will delete copied files and get rid of '(#) - Copy' appended to file names
	
	Improvements: Look into checksums
				  Look into saving memory space
				  
'''

import os 
import sys
from collections import OrderedDict
import re




def walk_files(path):

'''Fill a dictionary with the filenames and sizes, sort the dictionary and send it to delete_dups'''

	try:
		os.chdir(path)
	except:
		print "There was an error. Check your path name." + path 
		main()

	files_by_size = {}

	#use os.walk to sort by size
	for root, dir, f in os.walk(path):		
	
		for name in f:

			#Check that the files are in the current working directory
			if root == os.getcwd():
				statinfo = os.stat(name) 
				size = statinfo.st_size 
				files_by_size[name] = size 

			#if the files are nested in a folder, go into that folder and delete duplicates (recursive call)
			else:
				folder_files = walk_files(root)
				delete_dups(folder_files)
				clean_up(root)
				os.chdir(original_path)
			
	#use the sorted function to order the dictionary by alphabetical order and store it in an ordered dictionary
	sorted_files = OrderedDict(sorted(files_by_size.items(), key=lambda t: t[0])) 

	#sorted_files now contains the filenames and sizes, sorted by size. Call the delet_dups function to delete
	delete_dups(sorted_files)
	
	#this is here only for the else statement in the for loop, we need to keep a dictionary for within folders seperate so they dont get deleted twice
	return(sorted_files)

#Delete files with duplicate names and sizes

def delete_dups(files):

	'''Delete duplicate files based on name and file size'''
	
	names = files.keys()
	values = files.values()
	n = len(names)

	for i in range(n-1):
		m = values[i]
		n = values[i+1]

		if m == n:
			currentName = names[i]
			nextName = names[i+1]
			
			#remove parenthesis and everything in them and -Copy because duplicate files often have (#) at the end of them or  - Copy
			currentNameFixed = re.sub(r'\s+\([^)]*\)| ?\s+- Copy', '', currentName)
			nextNameFixed = re.sub(r'\s+\([^)]*\)| ?\s+- Copy', '', nextName)

			#check if the name is the same as the other name (a second check after size to really make sure they are the same file!)
			if currentNameFixed == nextNameFixed:
				try:
				#if it is the same file, remove it
					os.remove(nextName)

				#print a message 
					print "Duplicate file ", nextName, " removed."
				except:
					pass

def clean_up(path):

	'''Clean up file names by removing (#)'s and - Copy 's.'''

	for root, dir, f in os.walk(path):
		for name in f:
			if root == path:
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


if __name__ == "__main__":

	main()
