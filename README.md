# 42sh
## Table of Contents
1. [General Info](#general-info)
2. [Technologies](#technologies)
3. [Installation](#installation)
4. [Overview](#Overview)

### General Info
***
A Unix command interpreter. This is the last step to have a complete one.

## Technologies
***
A list of technologies used within the project:
* [execve]: Execute binaries
* [fork]: Duplicate the calling process
* [dup]: redirect output of a function

## Installation
***
A little intro about the installation. 
```
$ git clone git@github.com:EpitechPromo2027/B-PSU-200-BDX-2-1-42sh-arthur.gauffre.git
$ cd B-PSU-200-2-1-42sh-arthur.gauffre
$ make
$ ./42sh
```

## Overview
***
Some examples of what the program should return, and all the differents interractions
```
∼/B-PSU-101> ./42sh
$> ./my_ls .
dir my_ls ‘#test#’ test
```

```
∼/B-PSU-101> ./42sh
$> pwd
/tmp
$> cd test
$> pwd
/tmp/test
```

```
∼/B-PSU-101> ./42sh
$> ls /
/tmp
$> cd test
$> pwd
/tmp/test
```

```
∼/B-PSU-101> echo “ls” | ./42sh
tata
∼/B-PSU-101> echo $?
0
∼/B-PSU-101> echo “ls nofile” | ./42sh
∼/B-PSU-101> echo $?
2
```