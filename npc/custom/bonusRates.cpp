prontera,139,177,5	script	Brambati	630,{
	mes "[Brambati]";
	mes "Ol�, eu sou o Brambati!";
	next;
	mes "Eu posso lhe dar alguns itens que auxiliaram na sua jornada, dependendo das rates que voc� selecionou!";
	mes "E a�, o qu� voc� me diz?";
	switch(select("Gostaria de ver meus benef�cios!:N�o estou afim...")){
		case 1: // Gostaria de ver meus benef�cios
			clear;
			mes "[Brambati]";
			mes "Pois bem, caso voc� tenha selecionado 1x como suas rates individuais, voc� ir� ganhar as seguintes recompensas:";
			mes "No Base Level 10: Um cachecol especial!";
			mes "No Base Level 99: Archangel Wing, "+mesitemlink(20500);
			next;
			switch(select("Level 10:Level 99:N�o, obrigado...")){
				case 1: //Level 10
					if(individual_rate == 1 && @recompensa10 == 0){
						if(BaseLevel >= 10){
							mes "[Brambati]";
							mes "Escolha um cachecol, sendo: ";
							mes "1�: " +mesitemlink(840029);
							mes "2�: " +mesitemlink(840030);
							mes "3�: " +mesitemlink(840031);
							next;
							mes "[Brambati]";
							mes "4�: " +mesitemlink(840032);
							mes "5�: " +mesitemlink(840033);
							mes "6�: " +mesitemlink(840034);
							next;
							mes "[Brambati]";
							mes "7�: " +mesitemlink(840035);
							mes "8�: " +mesitemlink(840036);
							mes "9�: " +mesitemlink(840037);
							next;
							mes "[Brambati]";
							mes "E a�, qual vai querer?";
							switch(select("Quero o Black!:Quero o Blue!:Quero o Cyan!:Quero o Foil!:Quero o Gold!:Quero o Green!:Quero o Pink!:Quero o Purple!:Quero o White!:Ainda n�o decidi...")){
								case 1:
									getitembound 840029,1,BOUND_CHAR;
									@recompensa10 = 1;
									break;
								case 2:
									getitembound 840030,1,BOUND_CHAR;
									@recompensa10 = 1;
									break;
								case 3:
									getitembound 840031,1,BOUND_CHAR;
									@recompensa10 = 1;
									break;
								case 4:
									getitembound 840032,1,BOUND_CHAR;
									@recompensa10 = 1;
									break;
								case 5:
									getitembound 840033,1,BOUND_CHAR;
									@recompensa10 = 1;
									break;
								case 6:
									getitembound 840034,1,BOUND_CHAR;
									@recompensa10 = 1;
									break;
								case 7:
									getitembound 840035,1,BOUND_CHAR;
									@recompensa10 = 1;
									break;
								case 8:
									getitembound 840036,1,BOUND_CHAR;
									@recompensa10 = 1;
									break;
								case 9:
									getitembound 840037,1,BOUND_CHAR;
									@recompensa10 = 1;
									break;
								case 10:
									clear;
									mes "[Brambati]";
									mes "Ok, fico no aguardo!";
									end;
							}
							clear;
							mes "[Brambati]";
							mes "Obrigado, at� a pr�xima!";
							//@recompensa10 = 1;
							end;
						} else {
							mes "[Brambati]";
							mes "Me parece que voc� n�o tem os requisitos, ou j� pegou sua recompensa...";
							end;
						}
					} else if(@recompensa10 == 1){
						clear;
						mes "[Brambati]";
						mes "Voc� j� pegou sua recompensa!";
						end;
					} else {
						clear;
						mes "[Brambati]";
						mes "Voc� n�o selecionou 1x...";
						end;
					}
				case 2: //Level 99
					if(BaseLevel >=99 && @recompensa99 == 0){
						getitembound 20500,1,BOUND_CHAR;
						clear;
						mes "[Brambati]";
						mes "Obrigado, at� a pr�xima!";
						@recompensa99 = 1;
						end;
					} else {
							mes "[Brambati]";
							mes "Me parece que voc� n�o tem Base Level 99, ou j� pegou sua recompensas...";
							end;
						}
				case 3: //N�o, obrigado...
					clear;
					mes "[Brambati]";
					mes "Ok, at� a pr�xima!";
					end;
			}
		case 2: //N�o estou afim
			clear;
			mes "[Brambati]";
			mes "Ok, at� a pr�xima!";
			end;
	}
}