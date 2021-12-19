file = open("input.txt","r")

con = file.readlines();
file2=open("out.txt","a+")

for i in con:
    file2.write(i.strip("0123456789\t "))
    print(i.strip("0123456789\t "))
