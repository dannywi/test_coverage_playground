#!/bin/bash
mkdir lcov-report
lcov --capture --directory . --output-file lcov-report/coverage.info
genhtml lcov-report/coverage.info --branch-coverage --output-directory lcov-report
