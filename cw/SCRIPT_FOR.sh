for (( i=23810; i <= 23810; i++ ))
do

./corewar ../jumper.cor ../jumper.cor ../jumper.cor -dump $i > ../LOG/RES_RUS ;
../../FR/Corewar/corewar ../jumper.cor ../jumper.cor ../jumper.cor -dump $i > ../LOG/RES_FR ;
diff ../LOG/RES_FR  ../LOG/RES_RUS  > ../LOG/diff_fr.diff;

../../INTRA/corewar ../jumper.cor ../jumper.cor ../jumper.cor -d $i > ../LOG/RES_INTRA ;
diff ../LOG/RES_INTRA  ../LOG/RES_RUS  > ../LOG/diff_intra.diff;

done
