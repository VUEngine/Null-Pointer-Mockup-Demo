
//{{BLOCK(Keypad)

//======================================================================
//
//	Keypad, 16x8@2,
//	+ 3 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 2x1 
//	Total size: 48 + 4 = 52
//
//	Time-stamp: 2015-11-12, 21:48:30
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned int KeypadTiles[12] __attribute__((aligned(4)))=
{
	0x00000000,0x00000000,0x00000000,0x00000000,0xAAA0AA80,0xAAA8BEE8,0xAAA0EEE8,0x0000AA80,
	0x02AA00AA,0x0AAA0ABB,0x02AA0ABE,0x000000AA,
};

const unsigned short KeypadMap[2] __attribute__((aligned(4)))=
{
	0x0001,0x0002,
};

//}}BLOCK(Keypad)
