## Warning: The provided tests contain a Makefile, be careful not to overwrite your own!

Recommended way to unzip the file:
- mkdir tmp
- mv Makefile tmp
- unzip IJC2024_tests_marocc.zip
- make help

## Warning: wordcount-test.sh tests only the static part of the project, to test the dynamic part you need to:
  - change every './wordcount' line to ' 'LD_LIBRARY_PATH="." ./wordcount-dynamic'
