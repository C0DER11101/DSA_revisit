# combinations of 1, 2 and 3

echo "Combinations of 1, 2 and 3"

for (( i=1; i<=3; i++ ))
do
	for (( j=1; j<=3; j++ ))
	do
		for (( k=1; k<=3; k++ ))
		do
			echo $i$j$k
		done
	done
done
