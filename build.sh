FILES="./patterns/*.cpp"

for f in $FILES
    do
        echo "Building file..........."
        $eval("g++ $f -o ${f%%.*}.out")
        echo "Done processing $f"
    done
