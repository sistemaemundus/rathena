// Criado por Alek Emundus
// Gold Room - VIP

-	script	GoldRoom	-1,{
	OnThisMobDeath:
		getitem 969,1;
	end;
}

prontera,147,202,3	script	Gold Room	2248,{
	mes "^C9CB1B[Gold Room]^000000";
	mes "Bem vindo, gostaria de ir para Gold Room?";
	switch(select("- Bora!:- Deixa pra depois..."))
	{
		case 1:
			if(vip_status(VIP_STATUS_ACTIVE)){
				clear;
				mes "^C9CB1B[Gold Room]^000000";
				mes "Aproveite!";
				next;
				warp "1@def01",49,50;
			} else {
				clear;
				mes "^C9CB1B[Gold Room]^000000";
				mes "Você não tem VIP Ativo!";
				end;
			}
		case 2:
			clear;
			mes "^C9CB1B[Gold Room]^000000";
			mes "Tudo bem, até mais!";
			close;
	}
	
	OnPCLogoutEvent:
	getmapxy .@map$,.@x,.@y;
	if (.@map$ == "1@def01")
	{
		warp "prontera",156,191;
		end;
	} else {
		end;
	}
}

// Leveling Area 1 - Nível 1 a 40
1@def01,0,0	monster	Poring de Ouro	1002,100,1000,1000,"GoldRoom::OnThisMobDeath"

// Mapflags
1@def01	mapflag	noloot	on
1@def01	mapflag	noteleport	on
1@def01	mapflag	nosave	on
1@def01	mapflag	nomemo	on
1@def01	mapflag	nowarpto	on