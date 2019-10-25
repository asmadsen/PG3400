# Setup Instructions

See platform specific instructions further down

## Get Exam into CLion

### Set up where you will build
> Windows: Start WSL (Ubuntu) on Windows and *inside* WSL run this command
~~~~
git config --global core.autocrlf input
~~~~

> Mac: Start the [Docker container](https://github.com/patricia-gallardo/c_on_linux/blob/master/toolchain/Dockerfile)

### Check out the exam in CLion

* Start CLion - close open projects

* *Welcome to CLion* dialog > Check out from Version Control > Git > Log into GitHub

* Log in using your github account

* Paste in the GitHub link to the project that was created for you

* Click *clone*

* Click *yes* to opening the project in the dialog that appears

* Check that the toolchain works in *Settings > Toolchain* 
([Windows Instructions](https://www.jetbrains.com/help/clion/how-to-use-wsl-development-environment-in-clion.html),
[Mac Instructions](https://www.jetbrains.com/help/clion/remote-projects-support.html))

* In *Settings > CMake* change the one that is there to point to your toolchain and **make sure it's called 'Debug'**

* __Write your name and student id in the README.md__

* *Commit and push.* This can be done inside CLion

* Build everything : *Build > Build All in 'Debug'*

## Run the setup.sh script

Find where you are building in WSL Ubuntu (Windows) or Docker (Mac): 
Scroll up in the build output in the lower pane of CLion. 

### Windows
Example:
~~~~
====================[ Build | all | Debug ]=====================================
/usr/bin/cmake --build /mnt/c/Users/<build directory in WSL Ubuntu> --target all -- -j 4
~~~~
In WSL Ubuntu:
~~~~
cd /mnt/c/Users/<build directory in WSL Ubuntu>
cd ..
sudo apt-get install dos2unix
dos2unix ./setup.sh
./setup.sh
ls -ltr
~~~~

The files you see with arrows are symbolic links to the **tool** binary in your build folder. 
They are discussed further in the [README](README.md).

In this directory in WSL Ubuntu you can run your binaries from the commandline.

### Mac
Example
~~~~
====================[ Build | all | Debug ]=====================================
/usr/bin/cmake --build /tmp/tmp.<some random characters>/cmake-build-debug --target all -- -j 2
~~~~

~~~~
ssh root@localhost -p2222
<password is conlinux>
cd /tmp/tmp.<some random characters>/cmake-build-debug
cd ..
bash setup.sh
ls -ltr
~~~~

The files you see with arrows are symbolic links to the **tool** binary in your build folder.
They are discussed further in the [README](README.md).

In this directory inside Docker you can run your binaries from the commandline. You get in by doing
~~~~
ssh root@localhost -p2222
<password is conlinux>
cd /tmp/tmp.<some random characters>/cmake-build-debug
cd ..
~~~~

### Linux
~~~~
cd <where your code is>
run ./setup.sh
~~~~

The files you see with arrows are symbolic links to the **tool** binary in your build folder. 
They are discussed further in the [README](README.md).

In this directory you can run your binaries from the commandline.

## Troubleshooting
If CLion doesn't seem to run what you think try:
* Tools > CMake > Reload CMake Project
* Build > Clean
* Build > Build Project
* Tools > Resync with Remote Hosts

## Do the exam
__Read the [README.md](README.md)__
