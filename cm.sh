#compile c programs

thirdArg=0 # in case you need to compile a c++ file

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

		elif [ $3 == "nil" ]
		then
			echo "invalid third argument!!"
		fi

	else
		echo "$1 is not a file!!"

	fi

else
	echo "$1 doesnot exist!!"

fi
