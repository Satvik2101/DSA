import os
import shutil

root = os.getcwd()

folders = [x for x in os.listdir() if os.path.isdir(x)==True]
print(folders[0])

def unpack(problemName):
    folderPath = os.path.join(root,problemName,"Accepted");
    if (not os.path.exists(folderPath)):
        return
    os.chdir(folderPath);
    suffix = "";
    if (len(os.listdir())>1):
        suffix = "_sol_1"
    i = 1;
    for solution in os.listdir():
        
        if (i>1) :
            suffix = "_sol_" +str(i)
        os.chdir(os.path.join(folderPath,solution));
        i = i+1
        shutil.move(os.path.join(folderPath,solution,"Solution.cpp"),os.path.join(root,problemName+suffix+".cpp"));
            
            
for folder in folders:
    unpack(folder)
