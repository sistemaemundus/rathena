// Criado por Alek Emundus
// comando @conquista
// D� a conquista especificada para o player especificado

-	script	Conquista	-1,{
	OnInit:
		bindatcmd "conquista",strnpcinfo(3) + "::OnAtcommand",99,99;
		end;
	OnAtcommand:
		mes "[Conquistas]";
		mes "Especifique qual o ID da Conquista.";
		next;
		input .@Value;
		if(.@Value == 0){
			end;
		} else {
			next;
			mes "Informe o nick do Usu�rio.";
			next;
			input .@Name;
			next;
			clear;
			mes "[Conquistas]";
			mes "Confira se os dados est�o corretos.";
			mes "Conquista: "+.@Value;
			mes "Usu�rio: " +.@Name;
			switch(select("1- Sim.:2- Cancelar.")){
				case 1:
					if(achievementexists(.@Value,.@Name) == false){
						achievementadd(.@Value,.@Name);
						mes "^00FF04Conclu�do!^000000";
						close;
					} else {
						mes "^FF0000O usu�rio j� possui este achievement!^000000";
						close;
					}
				case 2:
					clear;
					mes "[Conquistas]";
					mes "Ok, at� mais!";
					close;
					
			}
		}
}