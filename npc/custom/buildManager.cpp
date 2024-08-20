/*

DROP TABLE IF EXISTS `ero_buildmanager`;
CREATE TABLE IF NOT EXISTS `ero_buildmanager` (
  `id` int(11) unsigned NOT NULL auto_increment,
  `aid` int(11) NOT NULL default '0',
  `cid` int(11) NOT NULL default '0',
  `build_name` varchar(255) NOT NULL default '',
  `eaj_class` smallint(6) unsigned NOT NULL default '0',
  `base_level` smallint(6) unsigned NOT NULL default '1',
  `job_level` smallint(6) unsigned NOT NULL default '1',
  `str` smallint(4) unsigned NOT NULL default '0',
  `agi` smallint(4) unsigned NOT NULL default '0',
  `vit` smallint(4) unsigned NOT NULL default '0',
  `int` smallint(4) unsigned NOT NULL default '0',
  `dex` smallint(4) unsigned NOT NULL default '0',
  `luk` smallint(4) unsigned NOT NULL default '0',
  `pow` smallint(4) unsigned NOT NULL default '0',
  `sta` smallint(4) unsigned NOT NULL default '0',
  `wis` smallint(4) unsigned NOT NULL default '0',
  `spl` smallint(4) unsigned NOT NULL default '0',
  `con` smallint(4) unsigned NOT NULL default '0',
  `crt` smallint(4) unsigned NOT NULL default '0',
  `status_point` int(11) unsigned NOT NULL default '0',
  `skill_point` int(11) unsigned NOT NULL default '0',
  `trait_point` int(11) unsigned NOT NULL default '0',
  `created` datetime DEFAULT NULL,
  PRIMARY KEY  (`id`),
  INDEX (`aid`),
  INDEX (`cid`)
) ENGINE=MyISAM;
*/

prontera,172,182,3	script	Build Manager	615,{
	doevent "ero_buildmanager_main::OnTalk";
}

-	script	ero_buildmanager_main	-1,{
OnInit:
	.max_build = 5;
	.check_weight_limit = 1;
	bindatcmd "bm", strnpcinfo(3)+"::OnTalk";
	bindatcmd "buildmanager", strnpcinfo(3)+"::OnTalk";
	end;
	
OnTalk:
	.@aid = getcharid(3);
	.@cid = getcharid(0);
	.@size = query_sql("SELECT `id`, `build_name`, `eaj_class`, `base_level`, `job_level`, `str`, `agi`, `vit`, `int`, `dex`, `luk`, `pow`, `sta`, `wis`, `spl`, `con`, `crt`, `status_point`, `skill_point`, `trait_point` FROM `ero_buildmanager` WHERE `cid` = "+.@cid, .@id, .@build_name$, .@eaj_class, .@base_level, .@job_level, .@str, .@agi, .@vit, .@int, .@dex, .@luk, .@pow, .@sta, .@wis, .@spl, .@con, .@crt, .@status_point, .@skill_point, .@trait_point);
	switch (select(
		(.@size <= 0) ? "" : "Switch Build",
		(.max_build && .@size >= .max_build) ? "" : "Save Build",
		(.@size <= 0) ? "" : "Delete"
	)) {	
		case 1:
			for (.@i = 0; .@i < .@size; .@i++)
				.@menu$ = .@menu$ + .@build_name$[.@i] + ":";
			if (.@size > 1)
				.@index = select(.@menu$) - 1;
			mes "[" + .@build_name$[.@index]+"]";
			mes "Class: " + jobname(roclass(.@eaj_class[.@index]))+" ("+.@base_level[.@index]+"/"+.@job_level[.@index]+")";
			mes "Status Point: " + F_InsertComma(.@status_point[.@index]);
			mes "Skill Point: " + F_InsertComma(.@skill_point[.@index]);
			if (checkre(0))
				mes "Trait Point: " + F_InsertComma(.@trait_point[.@index]);
			mes "- - - - - - STATS - - - - - -";
			mes sprintf("STR ^ff9933[%03d]^000000 AGI ^ff9933[%03d]^000000 VIT ^ff9933[%03d]^000000", .@str[.@index], .@agi[.@index], .@vit[.@index]);
			mes sprintf("INT ^ff9933[%03d]^000000 DEX ^ff9933[%03d]^000000 LUK ^ff9933[%03d]^000000", .@int[.@index], .@dex[.@index], .@luk[.@index]);
			if (checkre(0)) {
				mes "- - - - - - TRAITS - - - - - -";
				mes sprintf("POW ^ff9933[%03d]^000000 STA ^ff9933[%03d]^000000 WIS ^ff9933[%03d]^000000", .@pow[.@index], .@sta[.@index], .@wis[.@index]);
				mes sprintf("SPL ^ff9933[%03d]^000000 CON ^ff9933[%03d]^000000 CRT ^ff9933[%03d]^000000", .@spl[.@index], .@con[.@index], .@crt[.@index]);
			}
			if (select("Load", "Cancel") == 2) 
				break;
			clear;
			if (BaseLevel < .@base_level[.@index] || JobLevel < .@job_level[.@index]) {
				mes "You're required to be at least " + .@base_level[.@index]+"/"+.@job_level[.@index] + " to load this build.";
				close;
			}
			if (.check_weight_limit && Weight && Weight >= (20000 + (.@str[.@index] * 300))) {
				mes "Your selected build have insufficient STR to handle your current inventory items ("+F_InsertComma(Weight/10)+"/"+F_InsertComma((20000 + (.@str[.@index] * 300)) / 10)+").";
				close;
			}
			resetstatus;
			resetskill;
			if (readparam(bStr) < .@str[.@index])
				statusup2 bStr, (.@str[.@index] - 1);
			if (readparam(bAgi) < .@agi[.@index])
				statusup2 bAgi, (.@agi[.@index] - 1);
			if (readparam(bVit) < .@vit[.@index])
				statusup2 bVit, (.@vit[.@index] - 1);
			if (readparam(bInt) < .@int[.@index])
				statusup2 bInt, (.@int[.@index] - 1);
			if (readparam(bDex) < .@dex[.@index])
				statusup2 bDex, (.@dex[.@index] - 1);
			if (readparam(bLuk) < .@luk[.@index])
				statusup2 bLuk, (.@luk[.@index] - 1);
			if (checkre(0)) {
				// TODO: reset traits
				if (readparam(bPow) < .@pow[.@index])
					statusup2 bPow, .@pow[.@index];
				if (readparam(bSta) < .@sta[.@index])
					statusup2 bSta, .@sta[.@index];
				if (readparam(bWis) < .@wis[.@index])
					statusup2 bWis, .@wis[.@index];
				if (readparam(bSpl) < .@spl[.@index])
					statusup2 bSpl, .@spl[.@index];
				if (readparam(bCon) < .@con[.@index])
					statusup2 bCon, .@con[.@index];
				if (readparam(bCrt) < .@crt[.@index])
					statusup2 bCrt, .@crt[.@index];
			}
			StatusPoint = .@status_point[.@index];
			SkillPoint = .@skill_point[.@index];
			if (checkre(0))
				TraitPoint = .@trait_point[.@index];
			mes "Build loaded.";
			specialeffect2 EF_ANGEL2;
			break;
		case 2:
			mes "Enter a name for your build?";
			input .@build_name$;
			.@build_name$ = replacestr(.@build_name$, ":", "");
			clear;
			mes "["+.@build_name$+"]";
			mes "Class: " +jobname(roclass(eaclass()))+" ("+BaseLevel+"/"+JobLevel+")";
			mes "Status Point: " + F_InsertComma(StatusPoint);
			mes "Skill Point: " + F_InsertComma(SkillPoint);
			if (checkre(0))
				mes "Trait Point: " + F_InsertComma(TraitPoint);
			mes "- - - - - - STATS - - - - - -";
			mes sprintf("STR ^ff9933[%03d]^000000 AGI ^ff9933[%03d]^000000 VIT ^ff9933[%03d]^000000", readparam(bStr), readparam(bAgi), readparam(bVit));
			mes sprintf("INT ^ff9933[%03d]^000000 DEX ^ff9933[%03d]^000000 LUK ^ff9933[%03d]^000000", readparam(bInt), readparam(bDex), readparam(bLuk));
			if (checkre(0)) {
				mes "- - - - - - TRAITS - - - - - -";
				mes sprintf("POW ^ff9933[%03d]^000000 STA ^ff9933[%03d]^000000 WIS ^ff9933[%03d]^000000", readparam(bPow), readparam(bSta), readparam(bWis));
				mes sprintf("SPL ^ff9933[%03d]^000000 CON ^ff9933[%03d]^000000 CRT ^ff9933[%03d]^000000", readparam(bSpl), readparam(bCon), readparam(bCrt));
			}
			if (select("Save", "Cancel") == 2) 
				break;
			
			if (checkre(0))
				.@sql$ = "INSERT INTO `ero_buildmanager` (`aid`, `cid`, `build_name`, `eaj_class`, `base_level`, `job_level`, `str`, `agi`, `vit`, `int`, `dex`, `luk`, `pow`, `sta`, `wis`, `spl`, `con`, `crt`, `status_point`, `skill_point`, `trait_point`, `created`) VALUES ("+.@aid+", "+.@cid+", '"+escape_sql(.@build_name$)+"', "+eaclass()+", "+BaseLevel+", "+JobLevel+", "+readparam(bStr)+", "+readparam(bAgi)+", "+readparam(bVit)+", "+readparam(bInt)+", "+readparam(bDex)+", "+readparam(bLuk)+", "+readparam(bPow)+", "+readparam(bSta)+", "+readparam(bWis)+", "+readparam(bSpl)+", "+readparam(bCon)+", "+readparam(bCrt)+", "+StatusPoint+", "+SkillPoint+", "+TraitPoint+", NOW())";
			else 
				.@sql$ = "INSERT INTO `ero_buildmanager` (`aid`, `cid`, `build_name`, `eaj_class`, `base_level`, `job_level`, `str`, `agi`, `vit`, `int`, `dex`, `luk`, `status_point`, `skill_point`, `created`) VALUES ("+.@aid+", "+.@cid+", '"+escape_sql(.@build_name$)+"', "+eaclass()+", "+BaseLevel+", "+JobLevel+", "+readparam(bStr)+", "+readparam(bAgi)+", "+readparam(bVit)+", "+readparam(bInt)+", "+readparam(bDex)+", "+readparam(bLuk)+", "+StatusPoint+", "+SkillPoint+", NOW())";
			query_sql(.@sql$);
			clear;
			mes "Build '"+.@build_name$+"' has been created.";
			break;
		case 3:
			for (.@i = 0; .@i < .@size; .@i++)
				.@menu$ = .@menu$ + .@build_name$[.@i] + ":";
			.@index = select(.@menu$) - 1;
			mes "["+.@build_name$[.@index]+"]";
			mes "Class: " +jobname(roclass(.@eaj_class[.@index]))+" ("+.@base_level[.@index]+"/"+.@job_level[.@index]+")";
			mes "Status Point: " + F_InsertComma(.@status_point[.@index]);
			mes "Skill Point: " + F_InsertComma(.@skill_point[.@index]);
			if (checkre(0))
				mes "Trait Point: " + F_InsertComma(.@trait_point[.@index]);
			mes "- - - - - - STATS - - - - - -";
			mes sprintf("STR ^ff9933[%03d]^000000 AGI ^ff9933[%03d]^000000 VIT ^ff9933[%03d]^000000", .@str[.@index], .@agi[.@index], .@vit[.@index]);
			mes sprintf("INT ^ff9933[%03d]^000000 DEX ^ff9933[%03d]^000000 LUK ^ff9933[%03d]^000000", .@int[.@index], .@dex[.@index], .@luk[.@index]);
			if (checkre(0)) {
				mes "- - - - - - TRAITS - - - - - -";
				mes sprintf("POW ^ff9933[%03d]^000000 STA ^ff9933[%03d]^000000 WIS ^ff9933[%03d]^000000", .@pow[.@index], .@sta[.@index], .@wis[.@index]);
				mes sprintf("SPL ^ff9933[%03d]^000000 CON ^ff9933[%03d]^000000 CRT ^ff9933[%03d]^000000", .@spl[.@index], .@con[.@index], .@crt[.@index]);
			}
			if (select("Confirm Delete", "Cancel") == 2) 
				break;
			clear;
			mes "Build deleted.";
			query_sql("DELETE FROM `ero_buildmanager` WHERE `id` = "+.@id[.@index]+" LIMIT 1");
			break;
	}
	end;
}