//= Criado por Alek Emundus
//= Troca itens de Old Glast Heim por Manto Temporal
mall01,76,107,5	script	Senhora Temporal	633,{
	mes "[Senhora Temporal]";
	mes "Ol�, posso trocar itens de inst�ncias por Mantos Temporais, cada manto vai lhe custar:";
	mes "| "+mesitemlink(6608)+" x50 |";
	mes "| "+mesitemlink(6755)+" x15 |";
	mes "| "+mesitemlink(6607)+" x15 |";
	mes "O qu� voc� me diz?";
	next;
	switch(select("- Okay, eu aceito!:- Quais os Mantos voc� tem?:- Agora n�o...")){
		case 1:
			if(countitem(6608) >= 50 && countitem(6755) >= 15 && countitem(6607) >= 15){
				mes "[Senhora Temporal]";
				mes "Me parece que voc� tem o necess�rio...";
				next;
				clear;
				mes "[Senhora Temporal]";
				mes "Qual manto voc� gostaria?";
				next;
				switch(select("- FOR/STR.:- AGI.:- VIT.:- INT.:- DEX.:- SOR/LUK.:- Mudei de ideia...")){
					case 1:
						delitem 6608,50;
						delitem 6755,15;
						delitem 6607,15;
						getitem 20963,1;
						clear;
						mes "[Senhora Temporal]";
						mes "Aqui est�, obrigada e volte sempre!";
						close2;
						end;
					case 2:
						delitem 6608,50;
						delitem 6755,15;
						delitem 6607,15;
						getitem 20964,1;
						clear;
						mes "[Senhora Temporal]";
						mes "Aqui est�, obrigada e volte sempre!";
						close2;
						end;
					case 3:
						delitem 6608,50;
						delitem 6755,15;
						delitem 6607,15;
						getitem 20965,1;
						clear;
						mes "[Senhora Temporal]";
						mes "Aqui est�, obrigada e volte sempre!";
						close2;
						end;
					case 4:
						delitem 6608,50;
						delitem 6755,15;
						delitem 6607,15;
						getitem 20966,1;
						clear;
						mes "[Senhora Temporal]";
						mes "Aqui est�, obrigada e volte sempre!";
						close2;
						end;
					case 5:
						delitem 6608,50;
						delitem 6755,15;
						delitem 6607,15;
						getitem 20967,1;
						clear;
						mes "[Senhora Temporal]";
						mes "Aqui est�, obrigada e volte sempre!";
						close2;
						end;
					case 6:
						delitem 6608,50;
						delitem 6755,15;
						delitem 6607,15;
						getitem 20968,1;
						clear;
						mes "[Senhora Temporal]";
						mes "Aqui est�, obrigada e volte sempre!";
						close2;
						end;
					case 7:
						clear;
						mes "[Senhora Temporal]";
						mes "Tudo bem, at� logo!";
						close2;
						end;
				}
			} else {
				clear;
				mes "[Senhora Temporal]";
				mes "Poxa, me parece que est� faltando algo...";
				close2;
				end;
			}
		case 2:
			clear;
			mes "[Senhora Temporal]";
			mes "Tenho os seguintes Mantos Temporais:";
			mes "| "+mesitemlink(20963)+" |";
			mes "| "+mesitemlink(20964)+" |";
			mes "| "+mesitemlink(20965)+" |";
			mes "| "+mesitemlink(20966)+" |";
			mes "| "+mesitemlink(20967)+" |";
			mes "| "+mesitemlink(20968)+" |";
			close2;
			end;
		case 3:
			clear;
			mes "[Senhora Temporal]";
			mes "Tudo bem, at� logo!";
			close2;
			end;
	}
}