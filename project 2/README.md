## How to run the tests
- mkdir tmp
- mv Makefile tmp
- unzip IJC2024_tests_marocc.zip
- make help

### Warning: the current script tests only the static wordcount, to test the dynamic part you need to:
  - change every `./wordcount` line in the **wordcount-test.sh** file to `LD_LIBRARY_PATH="." ./wordcount-dynamic`
