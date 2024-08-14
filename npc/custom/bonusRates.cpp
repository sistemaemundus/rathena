prontera,139,177,5	script	Brambati	630,{
	mes "[Brambati]";
	mes "Olá, eu sou o Brambati!";
	next;
	mes "Eu posso lhe dar alguns itens que auxiliaram na sua jornada, dependendo das rates que você selecionou!";
	mes "E aí, o quê você me diz?";
	switch(select("Gostaria de ver meus benefícios!:Não estou afim...")){
		case 1: // Gostaria de ver meus benefícios
			clear;
			mes "[Brambati]";
			mes "Pois bem, caso você tenha selecionado 1x como suas rates individuais, você irá ganhar as seguintes recompensas:";
			mes "No Base Level 10: Um cachecol especial!";
			mes "No Base Level 99: Archangel Wing, "+mesitemlink(20500);
			next;
			switch(select("Level 10:Level 99:Não, obrigado...")){
				case 1: //Level 10
					if(individual_rate == 1 && @recompensa10 == 0){
						if(BaseLevel >= 10){
							mes "[Brambati]";
							mes "Escolha um cachecol, sendo: ";
							mes "1º: " +mesitemlink(840029);
							mes "2º: " +mesitemlink(840030);
							mes "3º: " +mesitemlink(840031);
							next;
							mes "[Brambati]";
							mes "4º: " +mesitemlink(840032);
							mes "5º: " +mesitemlink(840033);
							mes "6º: " +mesitemlink(840034);
							next;
							mes "[Brambati]";
							mes "7º: " +mesitemlink(840035);
							mes "8º: " +mesitemlink(840036);
							mes "9º: " +mesitemlink(840037);
							next;
							mes "[Brambati]";
							mes "E aí, qual vai querer?";
							switch(select("Quero o Black!:Quero o Blue!:Quero o Cyan!:Quero o Foil!:Quero o Gold!:Quero o Green!:Quero o Pink!:Quero o Purple!:Quero o White!:Ainda não decidi...")){
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
							mes "Obrigado, até a próxima!";
							//@recompensa10 = 1;
							end;
						} else {
							mes "[Brambati]";
							mes "Me parece que você não tem os requisitos, ou já pegou sua recompensa...";
							end;
						}
					} else if(@recompensa10 == 1){
						clear;
						mes "[Brambati]";
						mes "Você já pegou sua recompensa!";
						end;
					} else {
						clear;
						mes "[Brambati]";
						mes "Você não selecionou 1x...";
						end;
					}
				case 2: //Level 99
					if(BaseLevel >=99 && @recompensa99 == 0){
						getitembound 20500,1,BOUND_CHAR;
						clear;
						mes "[Brambati]";
						mes "Obrigado, até a próxima!";
						@recompensa99 = 1;
						end;
					} else {
							mes "[Brambati]";
							mes "Me parece que você não tem Base Level 99, ou já pegou sua recompensas...";
							end;
						}
				case 3: //Não, obrigado...
					clear;
					mes "[Brambati]";
					mes "Ok, até a próxima!";
					end;
			}
		case 2: //Não estou afim
			clear;
			mes "[Brambati]";
			mes "Ok, até a próxima!";
			end;
	}
}