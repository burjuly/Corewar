MAPS="jumper.cor jumper.cor"
NUM=24401
MIN=NUM
MAX=NUM+2
# MAX=NUM+2
for (( i=$MIN; i <= $MAX; i++ ))
do
./corewar_def $MAPS -d $i > their;
./corewar $MAPS -dump $i > our;
diff their our >> diff.diff
done
# for (( i=24688; i <= 24692; i++ ))
# do
# ../../corewar_def ../../jumper.cor -d $i > ../../their; ./corewar ../../jumper.cor -dump $i > ../../our; diff ../../their ../../our >> ../../diff.diff
# done
# ../../corewar_def ../../jumper.cor ../../zork.cor -d $i > ../../their; ./corewar ../../jumper.cor ../../zork.cor -dump $i > ../../our; diff ../../their ../../our >> ../../diff.diff

# ../../corewar_def ../../fluttershy.cor  -d $i > ../../their;
# ./corewar ../../fluttershy.cor  -dump $i > ../../our;
# diff ../../their ../../our >> ../../diff.diff
