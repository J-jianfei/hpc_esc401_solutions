EX1:
$SCRATCH directory is rwx for the user and only read and execute for group members and others
$HOME is only rwx for the user, no access to others and group members since the permission is drwx------
a new file created in home directory has default permission read and write for the user, and read only for others and group members, same in $SCRATCH
the directory /users/hlascomb is executable for group members, full permissions for the user, and no permission for others.
I cannot even acess the directory, no matter what is inside the directory.

chmod 700 file_name 

command: touch textfile.txt
command: chmod 760 textfile.txt
result -rwxrw----

If permission is 000, then I cannot open it. But I did not lost that file because I can change the permission for the owner.
