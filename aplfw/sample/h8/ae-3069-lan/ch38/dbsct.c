
#pragma section $DSEC

static const struct
{
	unsigned char *rom_s;
	unsigned char *rom_e;
	unsigned char *ram_s;
} DTBL[] =
	{
		{
			__sectop("D"),
			__secend("D"),
			__sectop("R"),
		},
	};



#pragma section $BSEC

static const struct
{
	unsigned char *b_s;
	unsigned char *b_e;
} BTBL[] =
	{
		{
			__sectop("B"),
			__secend("B"),
		},
	};
