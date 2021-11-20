EXEC=$1
TMP_OUT=$2

for i in {1..4..1}; do
  testname_input=$(printf "%01d-input.txt" $i)
  testname_output=$(printf "%01d-output.txt" $i)
  $EXEC < tests/$testname_input > $TMP_OUT
  if ! diff -qwB tests/$testname_output $TMP_OUT &>/dev/null; then
    echo "Test $testname_input failed"
  else
    echo "Test $testname_input passed"
  fi
done