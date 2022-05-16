import os
import shutil

pre = """#include <bits/stdc++.h>
// kbx2157
using namespace std;"""
def line_prepender(filename):
    with open(filename, 'r+') as f:
        content = f.read()
        f.seek(0, 0)
        f.write(pre + '\n' + content)

files = [x for x in os.listdir() if x.split('.')[1]=='cpp']
print(files)

for file in files:
    line_prepender(file)
