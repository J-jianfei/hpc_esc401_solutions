
RE="the number of particles is ([0-9]+),calculated in ([0-9]+\.[0-9]+) sec"
while read A;do
if [[ "$A" =~ $RE ]] ; then
echo -e "${BASH_REMATCH[1]} ${BASH_REMATCH[2]} \n"
fi
done

