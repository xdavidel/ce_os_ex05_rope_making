# Rope-making

## Introduction
Rope-making is quite a simple task, or at least it seems like one. All you need is a few fibres/
threads, contained in a certain way all together, to create a strong, stable collection that acts as a
rope. Generally speaking, a rope could be created from ropes, no..?
It's important to mention that in the following exercise we will be using the previous’ exercise files.


## Make it ropes
As mentioned above, we are going to rely on your previously coded dynamic-count thread creator,
well, not on it’s code - but on it’s compiled .exe!
Minor code changes are of-course allowed, just keep in mind you going to use the final executable.
Create a new solution, that receives total count of threads to create N and the maximum threads
per process M as parameters.
The program will launch our previously compiled .exe N/M times with the correct parameters to
display N threads properly, as if it the previous program was launched given N as the threads count
and the starting number 0.
As before, the text shouldn’t be scrambled but properly synchronized.
All of the processes should run under the same console and not interfere!

## Remarks
* Only usage of WinAPI is allowed. You can use C-library for input/output only.
* Code should be organized, and API should be used as needed, go thoroughly through the
remarks sections and make sure you are supporting edge cases and failures.
* Your synchronization mechanism doesn’t have to be local, but can be global.
* Read about GetStdHandle, and STARTUPINFO


## Your Submission
Please submit the necessary code files, well-documented (and not the whole solution).
Attach a compiled .exe of your previous exercise along with it, including an execution example.
Two ropes are always better than one! !
References
* Your previous lesson.
* MSDN