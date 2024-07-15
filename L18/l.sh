cd $1
fc=0
for i in *
do
if [ -f $i ]
then
    fc=$(($fc+1))
fi
done
echo "Total Dir File = $fc"