for (( i=5000; i <= 10000; i++ ))
do

./corewar ../CHAMPS/bee_gees.cor ../CHAMPS/jumper.cor  -dump $i > ../LOG/RES_RUS ;
../../FR/Corewar/corewar ../CHAMPS/bee_gees.cor ../CHAMPS/jumper.cor -dump $i > ../LOG/RES_FR ;
diff ../LOG/RES_FR  ../LOG/RES_RUS  >> ../LOG/diff_fr.diff;

../../INTRA/corewar ../CHAMPS/bee_gees.cor ../CHAMPS/jumper.cor -d $i > ../LOG/RES_INTRA ;
diff ../LOG/RES_INTRA  ../LOG/RES_RUS  >> ../LOG/diff_intra.diff;

done
