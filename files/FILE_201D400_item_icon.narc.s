	.include "asm/macros.inc"
	.text
	; NARC header
	.ascii "NARC"
	.short 0xFFFE ; byte order
	.short 0x0100 ; version
	.word 0x000608B0 ; size
	.short 0x0010 ; chunk size
	.short 3 ; number following chunks

	; BTAF header
	.ascii "BTAF"
	.word 0x00001604 ; chunk size
	.short 703 ; number of files
	.balign 4
	.word 0x00000000, 0x0000006F
	.word 0x00000070, 0x000000DB
	.word 0x000000DC, 0x0000030C
	.word 0x0000030C, 0x00000534
	.word 0x00000534, 0x00000764
	.word 0x00000764, 0x0000098C
	.word 0x0000098C, 0x00000BBC
	.word 0x00000BBC, 0x00000DE4
	.word 0x00000DE4, 0x00001014
	.word 0x00001014, 0x0000123C
	.word 0x0000123C, 0x0000146C
	.word 0x0000146C, 0x00001694
	.word 0x00001694, 0x000018C4
	.word 0x000018C4, 0x00001AEC
	.word 0x00001AEC, 0x00001D1C
	.word 0x00001D1C, 0x00001F44
	.word 0x00001F44, 0x00002174
	.word 0x00002174, 0x0000239C
	.word 0x0000239C, 0x000025CC
	.word 0x000025CC, 0x000027F4
	.word 0x000027F4, 0x00002A24
	.word 0x00002A24, 0x00002C54
	.word 0x00002C54, 0x00002E7C
	.word 0x00002E7C, 0x000030AC
	.word 0x000030AC, 0x000032DC
	.word 0x000032DC, 0x00003504
	.word 0x00003504, 0x00003734
	.word 0x00003734, 0x0000395C
	.word 0x0000395C, 0x00003B84
	.word 0x00003B84, 0x00003DAC
	.word 0x00003DAC, 0x00003FDC
	.word 0x00003FDC, 0x00004204
	.word 0x00004204, 0x0000442C
	.word 0x0000442C, 0x0000465C
	.word 0x0000465C, 0x00004884
	.word 0x00004884, 0x00004AAC
	.word 0x00004AAC, 0x00004CD4
	.word 0x00004CD4, 0x00004EFC
	.word 0x00004EFC, 0x0000512C
	.word 0x0000512C, 0x00005354
	.word 0x00005354, 0x00005584
	.word 0x00005584, 0x000057B4
	.word 0x000057B4, 0x000059DC
	.word 0x000059DC, 0x00005C0C
	.word 0x00005C0C, 0x00005E34
	.word 0x00005E34, 0x00006064
	.word 0x00006064, 0x0000628C
	.word 0x0000628C, 0x000064BC
	.word 0x000064BC, 0x000066E4
	.word 0x000066E4, 0x00006914
	.word 0x00006914, 0x00006B3C
	.word 0x00006B3C, 0x00006D6C
	.word 0x00006D6C, 0x00006F94
	.word 0x00006F94, 0x000071C4
	.word 0x000071C4, 0x000073EC
	.word 0x000073EC, 0x00007614
	.word 0x00007614, 0x00007844
	.word 0x00007844, 0x00007A6C
	.word 0x00007A6C, 0x00007C9C
	.word 0x00007C9C, 0x00007EC4
	.word 0x00007EC4, 0x000080EC
	.word 0x000080EC, 0x00008314
	.word 0x00008314, 0x0000853C
	.word 0x0000853C, 0x0000876C
	.word 0x0000876C, 0x00008994
	.word 0x00008994, 0x00008BC4
	.word 0x00008BC4, 0x00008DEC
	.word 0x00008DEC, 0x00009014
	.word 0x00009014, 0x0000923C
	.word 0x0000923C, 0x00009464
	.word 0x00009464, 0x0000968C
	.word 0x0000968C, 0x000098BC
	.word 0x000098BC, 0x00009AE4
	.word 0x00009AE4, 0x00009D14
	.word 0x00009D14, 0x00009F3C
	.word 0x00009F3C, 0x0000A164
	.word 0x0000A164, 0x0000A394
	.word 0x0000A394, 0x0000A5BC
	.word 0x0000A5BC, 0x0000A7EC
	.word 0x0000A7EC, 0x0000AA14
	.word 0x0000AA14, 0x0000AC3C
	.word 0x0000AC3C, 0x0000AE64
	.word 0x0000AE64, 0x0000B08C
	.word 0x0000B08C, 0x0000B2BC
	.word 0x0000B2BC, 0x0000B4E4
	.word 0x0000B4E4, 0x0000B714
	.word 0x0000B714, 0x0000B93C
	.word 0x0000B93C, 0x0000BB64
	.word 0x0000BB64, 0x0000BD8C
	.word 0x0000BD8C, 0x0000BFB4
	.word 0x0000BFB4, 0x0000C1E4
	.word 0x0000C1E4, 0x0000C40C
	.word 0x0000C40C, 0x0000C63C
	.word 0x0000C63C, 0x0000C864
	.word 0x0000C864, 0x0000CA8C
	.word 0x0000CA8C, 0x0000CCBC
	.word 0x0000CCBC, 0x0000CEE4
	.word 0x0000CEE4, 0x0000D10C
	.word 0x0000D10C, 0x0000D334
	.word 0x0000D334, 0x0000D55C
	.word 0x0000D55C, 0x0000D78C
	.word 0x0000D78C, 0x0000D9B4
	.word 0x0000D9B4, 0x0000DBDC
	.word 0x0000DBDC, 0x0000DE04
	.word 0x0000DE04, 0x0000E02C
	.word 0x0000E02C, 0x0000E25C
	.word 0x0000E25C, 0x0000E484
	.word 0x0000E484, 0x0000E6B4
	.word 0x0000E6B4, 0x0000E8DC
	.word 0x0000E8DC, 0x0000EB0C
	.word 0x0000EB0C, 0x0000ED34
	.word 0x0000ED34, 0x0000EF5C
	.word 0x0000EF5C, 0x0000F18C
	.word 0x0000F18C, 0x0000F3B4
	.word 0x0000F3B4, 0x0000F5DC
	.word 0x0000F5DC, 0x0000F80C
	.word 0x0000F80C, 0x0000FA34
	.word 0x0000FA34, 0x0000FC64
	.word 0x0000FC64, 0x0000FE8C
	.word 0x0000FE8C, 0x000100BC
	.word 0x000100BC, 0x000102E4
	.word 0x000102E4, 0x00010514
	.word 0x00010514, 0x0001073C
	.word 0x0001073C, 0x0001096C
	.word 0x0001096C, 0x00010B94
	.word 0x00010B94, 0x00010DC4
	.word 0x00010DC4, 0x00010FEC
	.word 0x00010FEC, 0x0001121C
	.word 0x0001121C, 0x0001144C
	.word 0x0001144C, 0x00011674
	.word 0x00011674, 0x000118A4
	.word 0x000118A4, 0x00011ACC
	.word 0x00011ACC, 0x00011CFC
	.word 0x00011CFC, 0x00011F2C
	.word 0x00011F2C, 0x00012154
	.word 0x00012154, 0x00012384
	.word 0x00012384, 0x000125B4
	.word 0x000125B4, 0x000127DC
	.word 0x000127DC, 0x00012A0C
	.word 0x00012A0C, 0x00012C34
	.word 0x00012C34, 0x00012E64
	.word 0x00012E64, 0x0001308C
	.word 0x0001308C, 0x000132BC
	.word 0x000132BC, 0x000134E4
	.word 0x000134E4, 0x00013714
	.word 0x00013714, 0x0001393C
	.word 0x0001393C, 0x00013B6C
	.word 0x00013B6C, 0x00013D94
	.word 0x00013D94, 0x00013FC4
	.word 0x00013FC4, 0x000141EC
	.word 0x000141EC, 0x0001441C
	.word 0x0001441C, 0x00014644
	.word 0x00014644, 0x00014874
	.word 0x00014874, 0x00014A9C
	.word 0x00014A9C, 0x00014CCC
	.word 0x00014CCC, 0x00014EF4
	.word 0x00014EF4, 0x00015124
	.word 0x00015124, 0x0001534C
	.word 0x0001534C, 0x0001557C
	.word 0x0001557C, 0x000157A4
	.word 0x000157A4, 0x000159D4
	.word 0x000159D4, 0x00015BFC
	.word 0x00015BFC, 0x00015E2C
	.word 0x00015E2C, 0x00016054
	.word 0x00016054, 0x00016284
	.word 0x00016284, 0x000164AC
	.word 0x000164AC, 0x000166DC
	.word 0x000166DC, 0x00016904
	.word 0x00016904, 0x00016B34
	.word 0x00016B34, 0x00016D5C
	.word 0x00016D5C, 0x00016F8C
	.word 0x00016F8C, 0x000171B4
	.word 0x000171B4, 0x000173E4
	.word 0x000173E4, 0x0001760C
	.word 0x0001760C, 0x0001783C
	.word 0x0001783C, 0x00017A64
	.word 0x00017A64, 0x00017C94
	.word 0x00017C94, 0x00017EBC
	.word 0x00017EBC, 0x000180EC
	.word 0x000180EC, 0x00018314
	.word 0x00018314, 0x00018544
	.word 0x00018544, 0x0001876C
	.word 0x0001876C, 0x0001899C
	.word 0x0001899C, 0x00018BC4
	.word 0x00018BC4, 0x00018DF4
	.word 0x00018DF4, 0x0001901C
	.word 0x0001901C, 0x0001924C
	.word 0x0001924C, 0x00019474
	.word 0x00019474, 0x000196A4
	.word 0x000196A4, 0x000198CC
	.word 0x000198CC, 0x00019AFC
	.word 0x00019AFC, 0x00019D24
	.word 0x00019D24, 0x00019F54
	.word 0x00019F54, 0x0001A17C
	.word 0x0001A17C, 0x0001A3AC
	.word 0x0001A3AC, 0x0001A5D4
	.word 0x0001A5D4, 0x0001A804
	.word 0x0001A804, 0x0001AA2C
	.word 0x0001AA2C, 0x0001AC5C
	.word 0x0001AC5C, 0x0001AE84
	.word 0x0001AE84, 0x0001B0B4
	.word 0x0001B0B4, 0x0001B2DC
	.word 0x0001B2DC, 0x0001B50C
	.word 0x0001B50C, 0x0001B734
	.word 0x0001B734, 0x0001B964
	.word 0x0001B964, 0x0001BB8C
	.word 0x0001BB8C, 0x0001BDBC
	.word 0x0001BDBC, 0x0001BFE4
	.word 0x0001BFE4, 0x0001C214
	.word 0x0001C214, 0x0001C43C
	.word 0x0001C43C, 0x0001C66C
	.word 0x0001C66C, 0x0001C894
	.word 0x0001C894, 0x0001CAC4
	.word 0x0001CAC4, 0x0001CCEC
	.word 0x0001CCEC, 0x0001CF1C
	.word 0x0001CF1C, 0x0001D144
	.word 0x0001D144, 0x0001D374
	.word 0x0001D374, 0x0001D59C
	.word 0x0001D59C, 0x0001D7CC
	.word 0x0001D7CC, 0x0001D9F4
	.word 0x0001D9F4, 0x0001DC24
	.word 0x0001DC24, 0x0001DE4C
	.word 0x0001DE4C, 0x0001E07C
	.word 0x0001E07C, 0x0001E2A4
	.word 0x0001E2A4, 0x0001E4D4
	.word 0x0001E4D4, 0x0001E6FC
	.word 0x0001E6FC, 0x0001E92C
	.word 0x0001E92C, 0x0001EB54
	.word 0x0001EB54, 0x0001ED84
	.word 0x0001ED84, 0x0001EFAC
	.word 0x0001EFAC, 0x0001F1DC
	.word 0x0001F1DC, 0x0001F404
	.word 0x0001F404, 0x0001F634
	.word 0x0001F634, 0x0001F85C
	.word 0x0001F85C, 0x0001FA8C
	.word 0x0001FA8C, 0x0001FCB4
	.word 0x0001FCB4, 0x0001FEE4
	.word 0x0001FEE4, 0x0002010C
	.word 0x0002010C, 0x0002033C
	.word 0x0002033C, 0x00020564
	.word 0x00020564, 0x00020794
	.word 0x00020794, 0x000209BC
	.word 0x000209BC, 0x00020BEC
	.word 0x00020BEC, 0x00020E14
	.word 0x00020E14, 0x00021044
	.word 0x00021044, 0x0002126C
	.word 0x0002126C, 0x0002149C
	.word 0x0002149C, 0x000216C4
	.word 0x000216C4, 0x000218F4
	.word 0x000218F4, 0x00021B1C
	.word 0x00021B1C, 0x00021D4C
	.word 0x00021D4C, 0x00021F74
	.word 0x00021F74, 0x000221A4
	.word 0x000221A4, 0x000223CC
	.word 0x000223CC, 0x000225FC
	.word 0x000225FC, 0x00022824
	.word 0x00022824, 0x00022A54
	.word 0x00022A54, 0x00022C7C
	.word 0x00022C7C, 0x00022EAC
	.word 0x00022EAC, 0x000230D4
	.word 0x000230D4, 0x00023304
	.word 0x00023304, 0x0002352C
	.word 0x0002352C, 0x00023754
	.word 0x00023754, 0x00023984
	.word 0x00023984, 0x00023BAC
	.word 0x00023BAC, 0x00023DDC
	.word 0x00023DDC, 0x00024004
	.word 0x00024004, 0x00024234
	.word 0x00024234, 0x0002445C
	.word 0x0002445C, 0x0002468C
	.word 0x0002468C, 0x000248B4
	.word 0x000248B4, 0x00024AE4
	.word 0x00024AE4, 0x00024D0C
	.word 0x00024D0C, 0x00024F3C
	.word 0x00024F3C, 0x00025164
	.word 0x00025164, 0x00025394
	.word 0x00025394, 0x000255BC
	.word 0x000255BC, 0x000257EC
	.word 0x000257EC, 0x00025A14
	.word 0x00025A14, 0x00025C44
	.word 0x00025C44, 0x00025E6C
	.word 0x00025E6C, 0x0002609C
	.word 0x0002609C, 0x000262C4
	.word 0x000262C4, 0x000264F4
	.word 0x000264F4, 0x0002671C
	.word 0x0002671C, 0x0002694C
	.word 0x0002694C, 0x00026B74
	.word 0x00026B74, 0x00026DA4
	.word 0x00026DA4, 0x00026FCC
	.word 0x00026FCC, 0x000271FC
	.word 0x000271FC, 0x00027424
	.word 0x00027424, 0x00027654
	.word 0x00027654, 0x0002787C
	.word 0x0002787C, 0x00027AAC
	.word 0x00027AAC, 0x00027CD4
	.word 0x00027CD4, 0x00027F04
	.word 0x00027F04, 0x0002812C
	.word 0x0002812C, 0x0002835C
	.word 0x0002835C, 0x00028584
	.word 0x00028584, 0x000287B4
	.word 0x000287B4, 0x000289DC
	.word 0x000289DC, 0x00028C0C
	.word 0x00028C0C, 0x00028E34
	.word 0x00028E34, 0x00029064
	.word 0x00029064, 0x0002928C
	.word 0x0002928C, 0x000294BC
	.word 0x000294BC, 0x000296EC
	.word 0x000296EC, 0x00029914
	.word 0x00029914, 0x00029B44
	.word 0x00029B44, 0x00029D6C
	.word 0x00029D6C, 0x00029F9C
	.word 0x00029F9C, 0x0002A1C4
	.word 0x0002A1C4, 0x0002A3F4
	.word 0x0002A3F4, 0x0002A61C
	.word 0x0002A61C, 0x0002A84C
	.word 0x0002A84C, 0x0002AA74
	.word 0x0002AA74, 0x0002ACA4
	.word 0x0002ACA4, 0x0002AECC
	.word 0x0002AECC, 0x0002B0FC
	.word 0x0002B0FC, 0x0002B324
	.word 0x0002B324, 0x0002B554
	.word 0x0002B554, 0x0002B77C
	.word 0x0002B77C, 0x0002B9AC
	.word 0x0002B9AC, 0x0002BBD4
	.word 0x0002BBD4, 0x0002BE04
	.word 0x0002BE04, 0x0002C02C
	.word 0x0002C02C, 0x0002C25C
	.word 0x0002C25C, 0x0002C484
	.word 0x0002C484, 0x0002C6B4
	.word 0x0002C6B4, 0x0002C8E4
	.word 0x0002C8E4, 0x0002CB0C
	.word 0x0002CB0C, 0x0002CD3C
	.word 0x0002CD3C, 0x0002CF64
	.word 0x0002CF64, 0x0002D194
	.word 0x0002D194, 0x0002D3BC
	.word 0x0002D3BC, 0x0002D5EC
	.word 0x0002D5EC, 0x0002D814
	.word 0x0002D814, 0x0002DA44
	.word 0x0002DA44, 0x0002DC6C
	.word 0x0002DC6C, 0x0002DE9C
	.word 0x0002DE9C, 0x0002E0C4
	.word 0x0002E0C4, 0x0002E2F4
	.word 0x0002E2F4, 0x0002E51C
	.word 0x0002E51C, 0x0002E744
	.word 0x0002E744, 0x0002E96C
	.word 0x0002E96C, 0x0002EB94
	.word 0x0002EB94, 0x0002EDBC
	.word 0x0002EDBC, 0x0002EFEC
	.word 0x0002EFEC, 0x0002F214
	.word 0x0002F214, 0x0002F444
	.word 0x0002F444, 0x0002F66C
	.word 0x0002F66C, 0x0002F89C
	.word 0x0002F89C, 0x0002FAC4
	.word 0x0002FAC4, 0x0002FCF4
	.word 0x0002FCF4, 0x0002FF1C
	.word 0x0002FF1C, 0x0003014C
	.word 0x0003014C, 0x00030374
	.word 0x00030374, 0x000305A4
	.word 0x000305A4, 0x000307CC
	.word 0x000307CC, 0x000309FC
	.word 0x000309FC, 0x00030C24
	.word 0x00030C24, 0x00030E54
	.word 0x00030E54, 0x0003107C
	.word 0x0003107C, 0x000312AC
	.word 0x000312AC, 0x000314D4
	.word 0x000314D4, 0x00031704
	.word 0x00031704, 0x0003192C
	.word 0x0003192C, 0x00031B5C
	.word 0x00031B5C, 0x00031D84
	.word 0x00031D84, 0x00031FB4
	.word 0x00031FB4, 0x000321DC
	.word 0x000321DC, 0x0003240C
	.word 0x0003240C, 0x00032634
	.word 0x00032634, 0x00032864
	.word 0x00032864, 0x00032A8C
	.word 0x00032A8C, 0x00032CBC
	.word 0x00032CBC, 0x00032EEC
	.word 0x00032EEC, 0x00033114
	.word 0x00033114, 0x00033344
	.word 0x00033344, 0x0003356C
	.word 0x0003356C, 0x00033794
	.word 0x00033794, 0x000339C4
	.word 0x000339C4, 0x00033BEC
	.word 0x00033BEC, 0x00033E1C
	.word 0x00033E1C, 0x00034044
	.word 0x00034044, 0x00034274
	.word 0x00034274, 0x0003449C
	.word 0x0003449C, 0x000346CC
	.word 0x000346CC, 0x000348FC
	.word 0x000348FC, 0x00034B2C
	.word 0x00034B2C, 0x00034D5C
	.word 0x00034D5C, 0x00034F8C
	.word 0x00034F8C, 0x000351BC
	.word 0x000351BC, 0x000353E4
	.word 0x000353E4, 0x00035614
	.word 0x00035614, 0x00035844
	.word 0x00035844, 0x00035A6C
	.word 0x00035A6C, 0x00035C9C
	.word 0x00035C9C, 0x00035EC4
	.word 0x00035EC4, 0x000360EC
	.word 0x000360EC, 0x00036314
	.word 0x00036314, 0x0003653C
	.word 0x0003653C, 0x00036764
	.word 0x00036764, 0x0003698C
	.word 0x0003698C, 0x00036BB4
	.word 0x00036BB4, 0x00036DDC
	.word 0x00036DDC, 0x00037004
	.word 0x00037004, 0x0003722C
	.word 0x0003722C, 0x00037454
	.word 0x00037454, 0x0003767C
	.word 0x0003767C, 0x000378A4
	.word 0x000378A4, 0x00037ACC
	.word 0x00037ACC, 0x00037CF4
	.word 0x00037CF4, 0x00037F1C
	.word 0x00037F1C, 0x0003814C
	.word 0x0003814C, 0x0003837C
	.word 0x0003837C, 0x000385A4
	.word 0x000385A4, 0x000387D4
	.word 0x000387D4, 0x000389FC
	.word 0x000389FC, 0x00038C2C
	.word 0x00038C2C, 0x00038E54
	.word 0x00038E54, 0x00039084
	.word 0x00039084, 0x000392AC
	.word 0x000392AC, 0x000394DC
	.word 0x000394DC, 0x00039704
	.word 0x00039704, 0x00039934
	.word 0x00039934, 0x00039B5C
	.word 0x00039B5C, 0x00039D8C
	.word 0x00039D8C, 0x00039FB4
	.word 0x00039FB4, 0x0003A1E4
	.word 0x0003A1E4, 0x0003A40C
	.word 0x0003A40C, 0x0003A63C
	.word 0x0003A63C, 0x0003A864
	.word 0x0003A864, 0x0003AA94
	.word 0x0003AA94, 0x0003ACBC
	.word 0x0003ACBC, 0x0003AEEC
	.word 0x0003AEEC, 0x0003B114
	.word 0x0003B114, 0x0003B344
	.word 0x0003B344, 0x0003B56C
	.word 0x0003B56C, 0x0003B79C
	.word 0x0003B79C, 0x0003B9C4
	.word 0x0003B9C4, 0x0003BBF4
	.word 0x0003BBF4, 0x0003BE1C
	.word 0x0003BE1C, 0x0003C04C
	.word 0x0003C04C, 0x0003C274
	.word 0x0003C274, 0x0003C4A4
	.word 0x0003C4A4, 0x0003C6CC
	.word 0x0003C6CC, 0x0003C8FC
	.word 0x0003C8FC, 0x0003CB24
	.word 0x0003CB24, 0x0003CD54
	.word 0x0003CD54, 0x0003CF7C
	.word 0x0003CF7C, 0x0003D1AC
	.word 0x0003D1AC, 0x0003D3D4
	.word 0x0003D3D4, 0x0003D604
	.word 0x0003D604, 0x0003D82C
	.word 0x0003D82C, 0x0003DA5C
	.word 0x0003DA5C, 0x0003DC84
	.word 0x0003DC84, 0x0003DEB4
	.word 0x0003DEB4, 0x0003E0DC
	.word 0x0003E0DC, 0x0003E30C
	.word 0x0003E30C, 0x0003E534
	.word 0x0003E534, 0x0003E764
	.word 0x0003E764, 0x0003E98C
	.word 0x0003E98C, 0x0003EBB4
	.word 0x0003EBB4, 0x0003EDE4
	.word 0x0003EDE4, 0x0003F00C
	.word 0x0003F00C, 0x0003F23C
	.word 0x0003F23C, 0x0003F464
	.word 0x0003F464, 0x0003F694
	.word 0x0003F694, 0x0003F8BC
	.word 0x0003F8BC, 0x0003FAEC
	.word 0x0003FAEC, 0x0003FD14
	.word 0x0003FD14, 0x0003FF44
	.word 0x0003FF44, 0x0004016C
	.word 0x0004016C, 0x0004039C
	.word 0x0004039C, 0x000405C4
	.word 0x000405C4, 0x000407F4
	.word 0x000407F4, 0x00040A1C
	.word 0x00040A1C, 0x00040C4C
	.word 0x00040C4C, 0x00040E74
	.word 0x00040E74, 0x000410A4
	.word 0x000410A4, 0x000412CC
	.word 0x000412CC, 0x000414FC
	.word 0x000414FC, 0x00041724
	.word 0x00041724, 0x00041954
	.word 0x00041954, 0x00041B7C
	.word 0x00041B7C, 0x00041DAC
	.word 0x00041DAC, 0x00041FD4
	.word 0x00041FD4, 0x00042204
	.word 0x00042204, 0x0004242C
	.word 0x0004242C, 0x0004265C
	.word 0x0004265C, 0x00042884
	.word 0x00042884, 0x00042AB4
	.word 0x00042AB4, 0x00042CDC
	.word 0x00042CDC, 0x00042F0C
	.word 0x00042F0C, 0x00043134
	.word 0x00043134, 0x00043364
	.word 0x00043364, 0x0004358C
	.word 0x0004358C, 0x000437BC
	.word 0x000437BC, 0x000439E4
	.word 0x000439E4, 0x00043C14
	.word 0x00043C14, 0x00043E3C
	.word 0x00043E3C, 0x0004406C
	.word 0x0004406C, 0x00044294
	.word 0x00044294, 0x000444C4
	.word 0x000444C4, 0x000446EC
	.word 0x000446EC, 0x0004491C
	.word 0x0004491C, 0x00044B44
	.word 0x00044B44, 0x00044D74
	.word 0x00044D74, 0x00044F9C
	.word 0x00044F9C, 0x000451CC
	.word 0x000451CC, 0x000453F4
	.word 0x000453F4, 0x00045624
	.word 0x00045624, 0x0004584C
	.word 0x0004584C, 0x00045A7C
	.word 0x00045A7C, 0x00045CA4
	.word 0x00045CA4, 0x00045ED4
	.word 0x00045ED4, 0x000460FC
	.word 0x000460FC, 0x0004632C
	.word 0x0004632C, 0x00046554
	.word 0x00046554, 0x00046784
	.word 0x00046784, 0x000469AC
	.word 0x000469AC, 0x00046BDC
	.word 0x00046BDC, 0x00046E04
	.word 0x00046E04, 0x00047034
	.word 0x00047034, 0x0004725C
	.word 0x0004725C, 0x0004748C
	.word 0x0004748C, 0x000476B4
	.word 0x000476B4, 0x000478E4
	.word 0x000478E4, 0x00047B0C
	.word 0x00047B0C, 0x00047D3C
	.word 0x00047D3C, 0x00047F64
	.word 0x00047F64, 0x00048194
	.word 0x00048194, 0x000483BC
	.word 0x000483BC, 0x000485EC
	.word 0x000485EC, 0x00048814
	.word 0x00048814, 0x00048A44
	.word 0x00048A44, 0x00048C6C
	.word 0x00048C6C, 0x00048E9C
	.word 0x00048E9C, 0x000490C4
	.word 0x000490C4, 0x000492F4
	.word 0x000492F4, 0x0004951C
	.word 0x0004951C, 0x0004974C
	.word 0x0004974C, 0x00049974
	.word 0x00049974, 0x00049BA4
	.word 0x00049BA4, 0x00049DCC
	.word 0x00049DCC, 0x00049FFC
	.word 0x00049FFC, 0x0004A224
	.word 0x0004A224, 0x0004A454
	.word 0x0004A454, 0x0004A67C
	.word 0x0004A67C, 0x0004A8AC
	.word 0x0004A8AC, 0x0004AAD4
	.word 0x0004AAD4, 0x0004AD04
	.word 0x0004AD04, 0x0004AF2C
	.word 0x0004AF2C, 0x0004B15C
	.word 0x0004B15C, 0x0004B384
	.word 0x0004B384, 0x0004B5B4
	.word 0x0004B5B4, 0x0004B7DC
	.word 0x0004B7DC, 0x0004BA0C
	.word 0x0004BA0C, 0x0004BC34
	.word 0x0004BC34, 0x0004BE64
	.word 0x0004BE64, 0x0004C08C
	.word 0x0004C08C, 0x0004C2BC
	.word 0x0004C2BC, 0x0004C4E4
	.word 0x0004C4E4, 0x0004C714
	.word 0x0004C714, 0x0004C93C
	.word 0x0004C93C, 0x0004CB6C
	.word 0x0004CB6C, 0x0004CD94
	.word 0x0004CD94, 0x0004CFC4
	.word 0x0004CFC4, 0x0004D1EC
	.word 0x0004D1EC, 0x0004D41C
	.word 0x0004D41C, 0x0004D644
	.word 0x0004D644, 0x0004D874
	.word 0x0004D874, 0x0004DA9C
	.word 0x0004DA9C, 0x0004DCCC
	.word 0x0004DCCC, 0x0004DEF4
	.word 0x0004DEF4, 0x0004E124
	.word 0x0004E124, 0x0004E34C
	.word 0x0004E34C, 0x0004E57C
	.word 0x0004E57C, 0x0004E7A4
	.word 0x0004E7A4, 0x0004E9D4
	.word 0x0004E9D4, 0x0004EBFC
	.word 0x0004EBFC, 0x0004EE2C
	.word 0x0004EE2C, 0x0004F054
	.word 0x0004F054, 0x0004F284
	.word 0x0004F284, 0x0004F4AC
	.word 0x0004F4AC, 0x0004F6DC
	.word 0x0004F6DC, 0x0004F904
	.word 0x0004F904, 0x0004FB34
	.word 0x0004FB34, 0x0004FD5C
	.word 0x0004FD5C, 0x0004FF8C
	.word 0x0004FF8C, 0x000501B4
	.word 0x000501B4, 0x000503E4
	.word 0x000503E4, 0x0005060C
	.word 0x0005060C, 0x0005083C
	.word 0x0005083C, 0x00050A64
	.word 0x00050A64, 0x00050C94
	.word 0x00050C94, 0x00050EBC
	.word 0x00050EBC, 0x000510EC
	.word 0x000510EC, 0x00051314
	.word 0x00051314, 0x00051544
	.word 0x00051544, 0x0005176C
	.word 0x0005176C, 0x0005199C
	.word 0x0005199C, 0x00051BC4
	.word 0x00051BC4, 0x00051DF4
	.word 0x00051DF4, 0x0005201C
	.word 0x0005201C, 0x0005224C
	.word 0x0005224C, 0x00052474
	.word 0x00052474, 0x000526A4
	.word 0x000526A4, 0x000528CC
	.word 0x000528CC, 0x00052AF4
	.word 0x00052AF4, 0x00052D24
	.word 0x00052D24, 0x00052F4C
	.word 0x00052F4C, 0x0005317C
	.word 0x0005317C, 0x000533A4
	.word 0x000533A4, 0x000535D4
	.word 0x000535D4, 0x000537FC
	.word 0x000537FC, 0x00053A2C
	.word 0x00053A2C, 0x00053C54
	.word 0x00053C54, 0x00053E84
	.word 0x00053E84, 0x000540AC
	.word 0x000540AC, 0x000542D4
	.word 0x000542D4, 0x000544FC
	.word 0x000544FC, 0x00054724
	.word 0x00054724, 0x0005494C
	.word 0x0005494C, 0x00054B74
	.word 0x00054B74, 0x00054D9C
	.word 0x00054D9C, 0x00054FC4
	.word 0x00054FC4, 0x000551EC
	.word 0x000551EC, 0x00055414
	.word 0x00055414, 0x0005563C
	.word 0x0005563C, 0x00055864
	.word 0x00055864, 0x00055A8C
	.word 0x00055A8C, 0x00055CB4
	.word 0x00055CB4, 0x00055EDC
	.word 0x00055EDC, 0x00056104
	.word 0x00056104, 0x00056334
	.word 0x00056334, 0x0005655C
	.word 0x0005655C, 0x0005678C
	.word 0x0005678C, 0x000569B4
	.word 0x000569B4, 0x00056BE4
	.word 0x00056BE4, 0x00056E0C
	.word 0x00056E0C, 0x0005703C
	.word 0x0005703C, 0x00057264
	.word 0x00057264, 0x00057494
	.word 0x00057494, 0x000576BC
	.word 0x000576BC, 0x000578EC
	.word 0x000578EC, 0x00057B14
	.word 0x00057B14, 0x00057D44
	.word 0x00057D44, 0x00057F6C
	.word 0x00057F6C, 0x0005819C
	.word 0x0005819C, 0x000583C4
	.word 0x000583C4, 0x000585F4
	.word 0x000585F4, 0x0005881C
	.word 0x0005881C, 0x00058A4C
	.word 0x00058A4C, 0x00058C74
	.word 0x00058C74, 0x00058EA4
	.word 0x00058EA4, 0x000590CC
	.word 0x000590CC, 0x000592F4
	.word 0x000592F4, 0x00059524
	.word 0x00059524, 0x0005974C
	.word 0x0005974C, 0x0005997C
	.word 0x0005997C, 0x00059BA4
	.word 0x00059BA4, 0x00059DD4
	.word 0x00059DD4, 0x00059FFC
	.word 0x00059FFC, 0x0005A22C
	.word 0x0005A22C, 0x0005A454
	.word 0x0005A454, 0x0005A684
	.word 0x0005A684, 0x0005A8AC
	.word 0x0005A8AC, 0x0005AADC
	.word 0x0005AADC, 0x0005AD04
	.word 0x0005AD04, 0x0005AF34
	.word 0x0005AF34, 0x0005B15C
	.word 0x0005B15C, 0x0005B38C
	.word 0x0005B38C, 0x0005B5B4
	.word 0x0005B5B4, 0x0005B7E4
	.word 0x0005B7E4, 0x0005BA0C
	.word 0x0005BA0C, 0x0005BC3C
	.word 0x0005BC3C, 0x0005BE64
	.word 0x0005BE64, 0x0005C094
	.word 0x0005C094, 0x0005C2BC
	.word 0x0005C2BC, 0x0005C4EC
	.word 0x0005C4EC, 0x0005C714
	.word 0x0005C714, 0x0005C944
	.word 0x0005C944, 0x0005CB6C
	.word 0x0005CB6C, 0x0005CD9C
	.word 0x0005CD9C, 0x0005CFC4
	.word 0x0005CFC4, 0x0005D1F4
	.word 0x0005D1F4, 0x0005D41C
	.word 0x0005D41C, 0x0005D64C
	.word 0x0005D64C, 0x0005D874
	.word 0x0005D874, 0x0005DAA4
	.word 0x0005DAA4, 0x0005DCCC
	.word 0x0005DCCC, 0x0005DEFC
	.word 0x0005DEFC, 0x0005E124
	.word 0x0005E124, 0x0005E354
	.word 0x0005E354, 0x0005E57C
	.word 0x0005E57C, 0x0005E7AC
	.word 0x0005E7AC, 0x0005E9D4
	.word 0x0005E9D4, 0x0005EC04
	.word 0x0005EC04, 0x0005EE2C
	.word 0x0005EE2C, 0x0005F05C
	.word 0x0005F05C, 0x0005F284

	; BTNF header
	.ascii "BTNF"
	.word 0x00000010 ; chunk size
	.word 0x00000004 ; offset to first dir
	.short 0 ; first file
	.short 1 ; number of directories

	; GMIF header
	.ascii "GMIF"
	.word 0x0005F28C ; chunk size
	.incbin "baserom.nds", 0x201EA2C, 0x5F284
	.balign 512, 255