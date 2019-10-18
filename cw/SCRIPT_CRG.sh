
./corewar ../CHAMPS/bee_gees.cor ../CHAMPS/jumper.cor > ../LOG/RES_RUS_CRG ;
../../FR/Corewar/corewar ../CHAMPS/bee_gees.cor ../CHAMPS/jumper.cor > ../LOG/RES_FR_CRG ;
diff ../LOG/RES_FR_CRG  ../LOG/RES_RUS_CRG  > ../LOG/DIFF_CRG.diff;
