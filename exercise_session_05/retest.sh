
RE="Temperature: ([0-9]+\.[0-9]+) deg at time: ([0-9]+\.[0-9]+) sec"
n_values=0
Tot=0
while read A;do
if [[ "$A" =~ $RE ]] ; then
n_values=$(echo "$n_values + 1" | bc)
Tot=$(echo "$Tot + ${BASH_REMATCH[1]}" | bc)
echo -e "${BASH_REMATCH[1]} ${BASH_REMATCH[2]} \n"
fi
done

Avg_T=$(echo "$Tot / $n_values" | bc)
echo "average temperature is $Avg_T deg"

