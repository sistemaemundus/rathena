// = Modificado & adaptado para Massacre do Santu�rio por Alek Emundus

prontera,166,188,4	script	Massacre do Santuario	637,{
    function GrantExp;

    while (1) {
        mes "[Massacre do Santu�rio]";
        mes "Como posso te ajudar?";
        switch (select("- Informa��es:- Entrar")) {
            Case 1:
                clear;
                mes "[Massacre do Santu�rio]";
                mes "Bem-vindo ao Massacre do Santu�rio!";
                mes "Voc� pode ca�ar monstros dentro desta sala e ganhar EXP proporcional ao seu n�vel.";
                mes "Sala normal: ^0066ffEXP padr�o.^000000";
                mes "Sala elite: ^ff0000EXP aumentada!^000000";
                next;
                mes "Regras:";
                mes "- Voc� s� pode entrar ^FF0000uma vez a cada " + .RoomCleanMin + " minutos.^000000";
                mes "- M�ximo de ^FF0000" + .MaxPlayers + " jogadores^000000 por vez.";
                mes "- Limite de monstros mortos: ^FF0000" + .MaxKillLimit + "^000000";
                next;
                break;

            Case 2:
                if (#HuntRoomDelay > gettimetick(2)) {
                    set .last, #HuntRoomDelay - gettimetick(2);
                    set .@min, .last % (24 * 3600) % 3600 / 60;
                    mes "Espere por ^FF0000" + .@min + " minutos^000000.";
                    close;
                } else if (getarraysize(.Players) >= .MaxPlayers) {
                    mes "A sala est� cheia no momento. Volte mais tarde.";
                    close;
                } else {
                    warp .Map$, 0, 0;
                    set .Players[getarraysize(.Players)], strcharinfo(0);
                    set #HuntRoomDelay, gettimetick(2) + (.DelayMin * 60);
                    set @SantuarioKills, 0;
                    end;
                }
        }
    }
}

OnInit:
    // Configura��es da Sala
    set .MaxPlayers, 10; // Jogadores por vez
    set .DelayMin, 30; // Minutos de espera entre entradas
    set .MaxKillLimit, 200; // M�ximo de monstros mortos por entrada
    set .RoomCleanMin, 15; // Minutos para limpar a sala
    set .Map$,"06guild_01"; // Sala normal
    set .EliteMap$,"06guild_02"; // Sala elite
    setmapflag .Map$, mf_nowarpto;
    setmapflag .Map$, mf_nogo;
    setmapflag .Map$, mf_nomobloot;
    setmapflag .Map$, mf_nobaseexp;
    setmapflag .EliteMap$, mf_nowarpto;
    setmapflag .EliteMap$, mf_nogo;
    setmapflag .EliteMap$, mf_nomobloot;
    setmapflag .EliteMap$, mf_nobaseexp;

    // Limpa a sala periodicamente
    while (1) {
        killmonster .Map$, "All";
        killmonster .EliteMap$, "All";
        mapwarp .Map$, "prontera", 155, 181;
        mapwarp .EliteMap$, "prontera", 155, 181;
        deletearray .Players, getarraysize(.Players);
        announce "[Massacre do Santu�rio]: A sala foi limpa e est� pronta para novos jogadores!", bc_blue;
        sleep (.RoomCleanMin * 60000);
    }
end;

OnNormalKill:
    GrantExp("normal");
	set #SantuarioPoints, #SantuarioPoints + 1;
	dispbottom "[ Massacre do Santu�rio ] : 1 SantuarioPoints ganha, total: "+#SantuarioPoints;
    set @SantuarioKills, @SantuarioKills + 1;
    if (@SantuarioKills >= .MaxKillLimit) {
        warp "prontera", 155, 181;
        dispbottom "[Massacre do Santu�rio]: Voc� atingiu o limite de monstros. Volte depois.";
    }
    end;

OnEliteKill:
    GrantExp("elite");
	set #SantuarioPoints, #SantuarioPoints + 5;
	dispbottom "[ Massacre do Santu�rio ] : 5 SantuarioPoints ganha, total: "+#SantuarioPoints;
    set @SantuarioKills, @SantuarioKills + 1;
    if (@SantuarioKills >= .MaxKillLimit) {
        warp "prontera", 155, 181;
        dispbottom "[Massacre do Santu�rio]: Voc� atingiu o limite de monstros. Volte depois.";
    }
    end;

function GrantExp {
    set .@expMultiplier, 1;
    if (getarg(0) == "elite") {
        .@expMultiplier = 2; // Dobra a EXP na sala elite
    }
    set @exp_gain, ((BaseLevel / 10) * .@expMultiplier * @exp_rate);
    getexp2 @exp_gain, 0, 0;
    dispbottom "[Massacre do Santu�rio]: Voc� ganhou " + @exp_gain + " de EXP.";
    return;
}

monster .Map$,0,0,"[ Massacre do Santu�rio ] Cobaia",1002,1000,strnpcinfo(0)+"::OnNormalKill"; // 1000 Porings no mapa
monster .EliteMap$,0,0,"[ Massacre do Santu�rio ] Elite",1039,1000,strnpcinfo(0)+"::OnBossKill";     // 5 Baphomets no mapa
