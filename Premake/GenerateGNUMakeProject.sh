architecture=x86_64

if [ -n "$1" ]; then
    architecture=$1
fi

./premake5 gmake --architecture=$architecture