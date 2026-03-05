# This script resets the setup, by repopulating the StackRecursion directory.
#
# USAGE: ./reset.sh
#
# C. Seshadhri, Jan 2020


read -p "Are you sure? You will lose all changes in the StackRecursion directory. Type Y if you wish to continue. " RESP # response of student
if [ "$RESP" = "Y" ]; then
    echo "Ok, resetting directory"
    rm StackRecursion/* # delete StackRecursion directory
    cp RoboGrader/AssnCode/* StackRecursion # copy code files
    cp RoboGrader/Rubric/Tests/simple* StackRecursion # copy test cases
else
    echo "You didn't say Y, so no change to StackRecursion directory"
fi
