
./corewar ../CHAMPS/Douceur_power.cor ../CHAMPS/Kitty_Miaou.cor ../CHAMPS/Kittystrophic.cor ../CHAMPS/ultima.cor > ../LOG/RES_RUS_CRG ;
../../FR/Corewar/corewar ../CHAMPS/Douceur_power.cor ../CHAMPS/Kitty_Miaou.cor ../CHAMPS/Kittystrophic.cor ../CHAMPS/ultima.cor > ../LOG/RES_FR_CRG ;
diff ../LOG/RES_FR_CRG  ../LOG/RES_RUS_CRG  > ../LOG/DIFF_CRG.diff;

# ./corewar ../CHAMPS/zork.cor ../CHAMPS/jumper.cor ../CHAMPS/fluttershy.cor ../CHAMPS/bee_gees.cor > ../LOG/RES_RUS_CRG ;