// Criado por Alek Emundus
// comando @conquista
// Dá a conquista especificada para o player especificado

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
			mes "Informe o nick do Usuário.";
			next;
			input .@Name;
			next;
			clear;
			mes "[Conquistas]";
			mes "Confira se os dados estão corretos.";
			mes "Conquista: "+.@Value;
			mes "Usuário: " +.@Name;
			switch(select("1- Sim.:2- Cancelar.")){
				case 1:
					if(achievementexists(.@Value,.@Name) == false){
						achievementadd(.@Value,.@Name);
						mes "^00FF04Concluído!^000000";
						close;
					} else {
						mes "^FF0000O usuário já possui este achievement!^000000";
						close;
					}
				case 2:
					clear;
					mes "[Conquistas]";
					mes "Ok, até mais!";
					close;
					
			}
		}
}