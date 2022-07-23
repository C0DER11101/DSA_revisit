#compile c programs

if [ -e $1 ]
then
	if [ -f $1 ]
	then
		gcc $1 -o $2

	else
		echo "$1 is not a file!!"

	fi

else
	echo "$1 doesnot exist!!"

fi
