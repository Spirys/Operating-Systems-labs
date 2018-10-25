rm _ex2.txt ../../week1/file.txt
> ../../week1/file.txt

link ../../week1/file.txt _ex2.txt > ex2.txt

inode="$(ls -i ../../week1/file.txt | grep -oP '\b\d+\b')"

sfind ../../week1/file.txt -inum ${inode} >> ex2.txt
find ../../week1/file.txt -inum ${inode} -exec rm {} \; >> ex2.txt