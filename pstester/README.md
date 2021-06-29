# pstester
This is a tester for the 42 School project "Push Swap".
It is useful during the first steps of writing the code, but not for the final tests,<br />
as it does not test enough combinations.

## Installation
Clone this repo inside the root folder of your project:
```
sudo git clone git@github.com:daisvke/pstester.git
```
(or anywhere as long as you can set your own values in the config file)

## Commands
* Show number of moves for each test:
```
./pstester -m
```
* Show moves for all tested number sets:
```
./pstester -a
```
* Show moves and all outputs for errors only
(this is usefull when debugging):
```
./pstester -e
```
* Show help section:
```
./pstester -h
```

## Description
* You can set your own values in config.sh.
* A log is generated for each test and is saved n the "log" file.
* No +500 elements combinations are tested.
