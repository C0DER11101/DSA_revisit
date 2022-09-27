#compile c/c++ programs

if [ -e $1 ]
then
	if [ -f $1 ]
	then
		while read p
		do
			if [ $p=="iostream" ]
			then
				echo "G++"
				g++ $1 -o $2
				break

			elif [ $p=="stdio.h" ]
			then
				echo "GCC"
				gcc $1 -o $2
				break

			fi

		done < $1
	else
		echo "$1 is not a file!!"

	fi

else
	echo "$1 doesnot exist!!"

fi
