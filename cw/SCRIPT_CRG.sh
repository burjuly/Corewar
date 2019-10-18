
./corewar ../jumper.cor ../jumper.cor ../jumper.cor > ../LOG/RES_RUS_CRG ;
../../FR/Corewar/corewar ../jumper.cor ../jumper.cor ../jumper.cor > ../LOG/RES_FR_CRG ;
diff ../LOG/RES_FR_CRG  ../LOG/RES_RUS_CRG  > ../LOG/DIFF_CRG.diff;
