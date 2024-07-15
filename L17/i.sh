# WASS to copy content of one file to another before copy check if the source file exists
if [ -e $1 ]
then
cp $1 $2
else
echo source file does not exists
fi