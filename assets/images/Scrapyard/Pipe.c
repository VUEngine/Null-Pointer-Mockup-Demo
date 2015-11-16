
//{{BLOCK(Pipe)

//======================================================================
//
//	Pipe, 96x16@2, 
//	+ 8 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 12x2 
//	Total size: 128 + 48 = 176
//
//	Time-stamp: 2015-11-12, 21:48:30
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned int PipeTiles[32] __attribute__((aligned(4)))=
{
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0xA9405400,0xEE94AA90,0xFBA4AAA4,
	0x00000000,0xAAAA5555,0xFFFFFFFF,0xFFFFAAAA,0x00000000,0xA9AA5555,0xFEFFFEFF,0xFEFFA9AA,
	0xAA54AAA4,0xA9505554,0x54009540,0x00000000,0xAAAAAAAA,0xAAAA5555,0x55559999,0x00000000,
	0xA9AAA9AA,0xA9AA5555,0x55559999,0x00000000,0x15AA1AAA,0x056A1555,0x00150159,0x00000000,
};

const unsigned short PipeMap[24] __attribute__((aligned(4)))=
{
	0x0001,0x0002,0x0003,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x2001,0x0004,0x0005,0x0006,0x0005,
	0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0007,
};

//}}BLOCK(Pipe)
