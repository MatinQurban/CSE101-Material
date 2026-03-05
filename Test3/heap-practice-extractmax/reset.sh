# This script resets the setup, by repopulating the BinHeap directory.
#
# USAGE: ./reset.sh
#
# C. Seshadhri, Jan 2020


read -p "Are you sure? You will lose all changes in the BinHeap directory. Type Y if you wish to continue. " RESP # response of student
if [ "$RESP" = "Y" ]; then
    echo "Ok, resetting directory"
    rm BinHeap/* # delete BinHeap directory
    cp RoboGrader/AssnCode/* BinHeap # copy code files
    cp RoboGrader/Rubric/Tests/simple* BinHeap # copy test cases
else
    echo "You didn't say Y, so no change to BinHeap directory"
fi
