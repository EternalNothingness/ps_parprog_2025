#!/bin/bash

module load gcc/12.2.0-gcc-8.5.0-p4pe45v
make clean
make 2> output.log # redirect stderr
