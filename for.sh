# MAPS="fluttershy.cor jumper.cor"
# NUM=24437
# MAPS="fluttershy.cor bee_gees.cor"
# NUM=25902
# MAPS="bee_gees.cor fluttershy.cor"
# NUM=25902
# MAPS="zork.cor zork.cor zork.cor"
# NUM=27432
MAPS="jumper.cor jumper.cor jumper.cor"
NUM=24401
# MAPS="fluttershy.cor fluttershy.cor fluttershy.cor"
# NUM=25902
# MAPS="bee_gees.cor bee_gees.cor bee_gees.cor"
# NUM=25902
# MAPS="zork.cor jumper.cor fluttershy.cor"
# NUM=24366
# MAPS="fluttershy.cor zork.cor jumper.cor"
# NUM=24366
# MAPS="zork.cor fluttershy.cor jumper.cor"
# NUM=24366
# MAPS="jumper.cor zork.cor fluttershy.cor"
# NUM=24366
# MAPS="jumper.cor bee_gees.cor fluttershy.cor"
# NUM=24366
# MAPS="bee_gees.cor fluttershy.cor zork.cor"
# NUM=24366
# MAPS="bee_gees.cor zork.cor jumper.cor"
# NUM=24366
# MAPS="bee_gees.cor bee_gees.cor fluttershy.cor"
# NUM=25902
# MAPS="zork.cor zork.cor zork.cor zork.cor"
# NUM=26689
# MAPS="jumper.cor jumper.cor jumper.cor jumper.cor"
# NUM=24401
# MAPS="fluttershy.cor fluttershy.cor fluttershy.cor fluttershy.cor"
# NUM=25902
# MAPS="bee_gees.cor bee_gees.cor bee_gees.cor bee_gees.cor"
# NUM=25902
# MAPS="zork.cor jumper.cor fluttershy.cor bee_gees.cor"
# NUM=24366
# MAPS="zork.cor bee_gees.cor jumper.cor fluttershy.cor"
# NUM=24366
# MAPS="zork.cor bee_gees.cor jumper.cor zork.cor"
# NUM=24366
# MAPS="zork.cor fluttershy.cor jumper.cor zork.cor"
# NUM=24366
# MAPS="helltrain.cor fluttershy.cor"
# NUM=25902
# MAPS="jumper.cor helltrain.cor fluttershy.cor"
# NUM=24366
# MAPS="zork.cor helltrain.cor jumper.cor fluttershy.cor"
# NUM=24366
# MAPS="zork.cor helltrain.cor jumper.cor helltrain.cor"
# NUM=24366
# MAPS="helltrain.cor"
# NUM=27438
# MAPS="Code_eater.cor Hidden.cor le_pet_de_nonne.cor sencha.cor"
# NUM=27713
# MAPS="tchupka.cor TheHarvester.cor wave.cor"
# NUM=55555
# MAPS="zork.cor Olezhka_super.cor"
# NUM=33060
# MAPS="Olezhka_super.cor zork.cor"
# NUM=33060
MIN=NUM
MAX=NUM+2
for (( i=$MIN; i <= $MAX; i++ ))
do
./corewar_def $MAPS -d $i > their;
./corewar $MAPS -dump $i > our;
diff their our >> diff.diff
done
