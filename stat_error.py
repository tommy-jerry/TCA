import os
import sys
import re

def stat_file(filename):
    str_arr = filename.split("_")
    if len(str_arr) != 4:
        return None
    name = str_arr[0] + "_" + str_arr[1]
    name = name.replace("error.", "")
    seed = str_arr[2]
    tuple_size = str_arr[3]
    t = None
    s = None
    with open(filename, "r") as fh:
        last_line = ""
        for line in fh.readlines():
            line = line.strip()
            if line.find("CoveringArray::optimize") > 0:
		t, s = re.split("\s+", last_line)
                #t, s = last_line.split(" ")
                print name, seed, tuple_size, t , s
                break
            last_line = line
    return [name, seed, tuple_size, t, s] 

for filename in os.listdir(os.getcwd()):
    if not filename.startswith("error"):
        continue
    stat_file(filename)

