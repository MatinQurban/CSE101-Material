# This script resets the setup, by repopulating the BST directory.
#
# USAGE: ./reset.sh
#
# C. Seshadhri, Jan 2020


read -p "Are you sure? You will lose all changes in the BST directory. Type Y if you wish to continue. " RESP # response of student
if [ "$RESP" = "Y" ]; then
    echo "Ok, resetting directory"
    rm BST/* # delete BST directory
    cp RoboGrader/AssnCode/* BST # copy code files
    cp RoboGrader/Rubric/Tests/simple* BST # copy test cases
else
    echo "You didn't say Y, so no change to BST directory"
fi


