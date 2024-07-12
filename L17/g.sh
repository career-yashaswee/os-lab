echo enter file name
read f
if [ -e $f ]
then
echo file exists
else
echo file does not exists
fi