Jacob (JT) Fox
02/07/2024

This program takes user input and constructs a k-tree using the first letter of each word as the node value. If two words start with the same letter, then they are connected through a middle link. After the tree is built, preorder, inorder, and postorder traversals of tree are printed to the terminal as well as into individual files. If the user has supplied a file for input, then the output files will retain the same file name with ".preorder", ".inorder", and ".postorder" as file extensions. If input has been supplied through the keyboard, then the output files will simply be named "output" with the same file extensions as described above.

It can be compiled using the included makefile. Simply type "make" into the terminal.

After compilation, this program can be run in three different ways:
The first way is to type "./p0" with no arguments, then type out your desired input.
The second way is to supply a text file as an argument. Example: "./p0 test.txt".
The third way is to redirect a file into the program, in which case its contents are treated as keyboard input. Example: "./p0 < test.txt".

User input cannot include special characters or numbers. If it does, the program will produce an error message and terminate.