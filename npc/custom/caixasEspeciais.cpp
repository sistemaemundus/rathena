//= Criado por Alek Emundus
//= Fun��o para a caixaBeta & caixaStreamer

function	script	caixasEspeciais	{
    if(BaseLevel <= 98){
        mes "^FF0000===[Escolha sabiamente!]===^000000";
        mes "Gostaria de ir para o n�vel 99?";
		mes "^FF0000===[Escolha sabiamente!]===^000000";
        if(select("- Sim!:- N�o...") == 2) {
            close;
        } else {
            BaseLevel = 99;
            close;
        }
    }
}

function	script	caixasBooster	{
	mes "^FF0000===[Escolha sabiamente!]===^000000";
    mes "Qual caixa BOOSTER voc� gostaria de obter?";
	mes "^FF0000===[Escolha sabiamente!]===^000000";
	switch(select("- Caixa Attacker.:- Caixa Ranged.:- Caixa Elemental.:- Caixa Defender.")){
		case 1:
			getitem 100046,1;
			close2;
			break;
		case 2:
			getitem 100047,1;
			close2;
			break;
		case 3:
			getitem 100048,1;
			close2;
			break;
		case 4:
			getitem 100049,1;
			close2;
			break;
	}
}