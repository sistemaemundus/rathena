//= Criado por Alek Emundus - @sistemaemundus
//= Guia para teleportar o jogador para locais custom
-	script	GuiasSmokeRO	-1,{
	OnInit:
		bindatcmd "guia",strnpcinfo(3) + "::OnAtcommand";
		end;
	OnAtcommand:
		mes "[Guia]";
		mes "Olá, " + strcharinfo(0) + " serei seu guia para sua aventura!";
		mes "Escolha para onde deseja ir:";
		switch(select("- Quests/Trocas.:- Local de Treino.:- Cancelar")){
			case 1:
				warp "mall01",99,76;
				end;
			case 2:
				warp "prontera",233,80;
				end;
			case 3:
				clear;
				mes "[Guia]";
				mes "Até mais!";
				close2;
				end;
		}
}