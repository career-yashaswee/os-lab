a=$#


if [ $a -le 5 ]
then

    for i in $*
    do
        echo $i
    done
else
    echo Too Many Arguments
fi
