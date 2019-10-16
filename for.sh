for (( i=25902; i <= 25903; i++ ))
do
../../corewar_def ../../fluttershy.cor ../../bee_gees.cor  -d $i > ../../their; 
./corewar ../../fluttershy.cor ../../bee_gees.cor  -dump $i > ../../our;
diff ../../their ../../our >> ../../diff.diff
done
# for (( i=24688; i <= 24692; i++ ))
# do
# ../../corewar_def ../../jumper.cor -d $i > ../../their; ./corewar ../../jumper.cor -dump $i > ../../our; diff ../../their ../../our >> ../../diff.diff
# done
# ../../corewar_def ../../jumper.cor ../../zork.cor -d $i > ../../their; ./corewar ../../jumper.cor ../../zork.cor -dump $i > ../../our; diff ../../their ../../our >> ../../diff.diff
