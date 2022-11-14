#compile c/c++ programs

if [ -e $1 ]
then
	case ${1##*.} in
		"c"))
			while read p
			do
				if [ $p == "math.h" ] -o [ $p == "cmath" ]
				then
					# code ;
