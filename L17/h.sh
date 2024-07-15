echo enter file name
if [ -s $1 ]
then
echo "file not empty"
else
echo "file empty"
fi