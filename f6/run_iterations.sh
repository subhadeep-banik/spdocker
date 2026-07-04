EXECUTABLE=" ./bitslice ffffffffffffffff aaaaaaaaaaaaaaaa input.txt output.txt"
ITERATIONS=50000

# Run the C program for 1000 iterations
for ((i = 1; i <= ITERATIONS; i++)); do
    echo "Running iteration $i"
    $EXECUTABLE
done