//= Criado por Alek Emundus - @sistemaemundus
//= Troca de Black Gemstone (7710) por itens Dark GodLike
//= Te levar� para Ayothaya Field (ayo_fild02 49, 62)
//= Para farmar Black Gemstone (7710)
mall01,66,105,5	script	Kerovel Siannodel	494,{	
	mes "[Kerovel Siannodel]";
	mes "Gostaria de dar uma olhada no que tenho � propor?";
	switch(select("- Sim.:- Por agora n�o...:- O qu� voc� faz mesmo?:- Como conseguir o material?")){
		case 1:
			clear;
			mes "[Kerovel Siannodel]";
			mes "Pois bem, aqui est�!";
			close2;
			callshop "itensDarkGodLike";
			end;
		case 2:
			clear;
			mes "[Kerovel Siannodel]";
			mes "Ok, at� a pr�xima, aventureiro!";
			close2;
			end;
		case 3:
			clear;
			mes "[Kerovel Siannodel]";
			mes "Boas vindas, meu nome � Kerovel Siannodel, e eu estou aqui para lhe ajudar!";
			mes "Posso lhe fornecer alguns equipamentos, desde que voc� me traga o necess�rio...";
			mes "Posso trocar " +mesitemlink(840051)+ ", que cont�m um poder imenso e obscuro...";
			mes "Trocarei-os por equipamentos de mesma magnitude, onde aumentar� sua for�a e sabedoria..";
			mes "O qu� voc� acha?";
			close2;
			end;
		case 4:
			clear;
			mes "[Kerovel Siannodel]";
			mes "Muito simples, basta dizer que voc� quer ir e eu te levo ao local!";
			switch(select("- Ok, vamos l�!:- Vou pensar...")){
				case 1:
					warp "ayo_fild02",49,62;
					end;
				case 2:
					clear;
					mes "[Kerovel Siannodel]";
					mes "At� a pr�xima!";
					close2;
					end;
			}
	}
}