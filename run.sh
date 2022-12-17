#!/bin/bash
OUTDIR=out
FILE=$1
shift;
mkdir -p $OUTDIR

rm *.gcda *.gcno

g++ --std=c++17 -fprofile-arcs -ftest-coverage $FILE -o $OUTDIR/runner && ./$OUTDIR/runner $@
#clang++ --std=c++17 -Wunused-variable $FILE -o $OUTDIR/runner && ./$OUTDIR/runner $@
