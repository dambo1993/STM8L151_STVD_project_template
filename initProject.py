# script to generate STM8L151 project with SPL library.
import sys
import os
from distutils.dir_util import copy_tree

if len(sys.argv) < 2:
	print("No project name in parameters!!!")
	exit()

projectName = str(sys.argv[1])

fromDirectory = "stm8_template"
toDirectory = projectName

# copy all content from template folder to project folder
copy_tree(fromDirectory, toDirectory)

# we need to change some project definitions:
newText = ""

FileName=toDirectory+"\\stm8_template.stp"

with open(FileName) as f:
	newText=f.read().replace('stm8_template', projectName)

with open(FileName, "w") as f:
	f.write(newText)
	
os.rename(FileName, toDirectory+"\\" + toDirectory+".stp")

print("Completed!")
	