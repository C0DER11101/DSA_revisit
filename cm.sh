#compile c programs

if [ -e $1 ]
then
	if [ -f $1 ]
	then
		if [ $3 == "c" ]
		then
			gcc $1 -o $2
		elif [ $3 == "cpp" ]
		then
			g++ $1 -o $2
		fi

	else
		echo "$1 is not a file!!"

	fi

else
	echo "$1 doesnot exist!!"

fi
