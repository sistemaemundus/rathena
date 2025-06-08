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
		switch(select("- Quests/Trocas.:- Local de Treino.:- Área GM.:- Cancelar")){
			case 1:
				warp "mall01",99,76;
				end;
			case 2:
				warp "prontera",233,80;
				end;
			case 3:
				if((getgroupid() == 99)){
					warp "vip_lounge",150,131;
					end;
				} else {
					clear;
					mes "[Guia]";
					mes "Indisponível, você não é GM!";
					close2;
					end;
				}
			case 4:
				clear;
				mes "[Guia]";
				mes "Até mais!";
				close2;
				end;
		}
}
//= NPC Guias SmokeRO
prontera,154,187,5	script	Guia	619,{
	mes "[Guia]";
		mes "Olá, " + strcharinfo(0) + " serei seu guia para sua aventura!";
		mes "Escolha para onde deseja ir:";
		switch(select("- Quests/Trocas.:- Local de Treino.:- Área GM.:- Cancelar")){
			case 1:
				warp "mall01",99,76;
				end;
			case 2:
				warp "prontera",233,80;
				end;
			case 3:
				if((getgroupid() == 99)){
					warp "vip_lounge",150,131;
					end;
				} else {
					clear;
					mes "[Guia]";
					mes "Indisponível, você não é GM!";
					close2;
					end;
				}
			case 4:
				clear;
				mes "[Guia]";
				mes "Até mais!";
				close2;
				end;
		}
}