if [ $# -eq 0 ]
then
    echo "Please give the command to run and title of ecna-23-24/ directory as arguments"
    exit
fi 

TO_INPUT="../icpc-problems/ecna-23-24/${2}/data/secret"

TIMEFORMAT=%R

#ls $TO_INPUT | grep .in

rm score.txt

CORRECT=0
AMOUNT=0
MAX_TIME=0

for ON_FILE in `ls $TO_INPUT | grep .in`
do 
    FILE_NAME=`echo $ON_FILE | cut -d '.' -f1`
    GOT_TIME=$(time ($1 < "${TO_INPUT}/${FILE_NAME}.in" > user-output.txt) 2>&1)
    FLOOR_TIME=`echo $GOT_TIME | cut -d '.' -f1`
    AMOUNT_WRONG=$(diff -y --suppress-common-lines user-output.txt "${TO_INPUT}/${FILE_NAME}.ans" | wc -l)
    echo "${FILE_NAME}.in: ${AMOUNT_WRONG} lines wrong. Runtime: ${GOT_TIME} seconds" >> score.txt

    AMOUNT=$(($AMOUNT+1))
    if [ $AMOUNT_WRONG -eq 0 ]
    then
        CORRECT=$(($CORRECT+1))
    fi

    if [ FLOOR_TIME -gt MAX_TIME ]
    then 
        MAX_TIME=$GOT_TIME 
    fi 
done

rm user-output.txt

echo "" >> score.txt
echo "${CORRECT}/${AMOUNT} correct" >> score.txt
echo "${CORRECT}/${AMOUNT} correct"
echo "Max time: ${MAX_TIME}"

