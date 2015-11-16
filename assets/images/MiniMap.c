
//{{BLOCK(MiniMap)

//======================================================================
//
//	MiniMap, 48x80@2,
//	+ 61 tiles not compressed
//	+ regular map (flat), not compressed, 6x10 
//	Total size: 976 + 120 = 1096
//
//	Time-stamp: 2015-11-12, 21:48:30
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned int MiniMapTiles[244] __attribute__((aligned(4)))=
{
	0x00000000,0x00000000,0x00000000,0x00000000,0x00015555,0x00010001,0x00010001,0x00010001,
	0x5640AA55,0x56405640,0x56405640,0x56405640,0x9555AAAA,0x95559555,0x95559555,0x95559555,
	0x00015555,0x00010001,0x00010001,0x00010001,0x5640AA55,0x56405640,0x56405640,0x56405640,
	0x9555AAAA,0x95559555,0x95559555,0x95559555,0x00010001,0x55550001,0x00015555,0x00010001,
	0x56405640,0xAA555640,0xAB40FF55,0xAB40AB40,0x95559555,0xAAAA9555,0xEAAAFFFF,0xAAAAAAAA,
	0x00010001,0x55550001,0xAAABFFFF,0xAAAAAAAA,0x56405640,0xAA555640,0xABEAFFFF,0xAAAAAAAA,
	0x95559555,0xAAAA9555,0xEAAAFFFF,0xEAAAEAAA,0x00010001,0x00010001,0x00010001,0x55550001,
	0xAB40AB40,0xAB40AB40,0xAB40AB40,0xFF55AB40,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xFFFFEAAA,

	0xFFAABEAA,0xBEAAFFAA,0xAAAAAAAA,0xFFFFAAAB,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xFFFFABEA,
	0xEAAAEAAA,0xEAAAEAAA,0xEAAAEAAA,0xFFFFEAAA,0x00015555,0x00010001,0x00010001,0x00010001,
	0x01405555,0x01400140,0x01400140,0x01400140,0x40005555,0x40004000,0x40004000,0x40004000,
	0x00015555,0x00010001,0x00010001,0x00010001,0x5640AA55,0x56405640,0x56405640,0x56405640,
	0x9555AAAA,0x95559555,0x95559555,0x95559555,0x00010001,0x55550001,0x00000000,0x00000000,
	0x01400140,0x55550140,0x00000000,0x00000000,0x40004000,0x55554000,0x00000000,0x00000000,
	0x00010001,0x55550001,0x00000000,0x00000000,0x56405640,0xAA555640,0x00000000,0x00000000,
	0x95559555,0xAAAA9555,0x00000000,0x00000000,0x00015555,0x00010001,0x00010001,0x00010001,

	0x5640AA55,0x56405640,0x56405640,0x56405640,0x9555AAAA,0x95559555,0x95559555,0x95559555,
	0x00015555,0x00010001,0x00010001,0x00010001,0x5640AA55,0x56405640,0x56405640,0x56405640,
	0x9555AAAA,0x95559555,0x95559555,0x95559555,0x00010001,0x55550001,0x00015555,0x00010001,
	0x56405640,0xAA555640,0xAB40FF55,0xAB40AB40,0x95559555,0xAAAA9555,0xEAAAFFFF,0xAAAAAAAA,
	0x00010001,0x55550001,0xAAABFFFF,0xAAAAAAAA,0x56405640,0xAA555640,0xABEAFFFF,0xAAAAAAAA,
	0x95559555,0xAAAA9555,0xEAAAFFFF,0xEAAAEAAA,0x00010001,0x00010001,0x00010001,0x55550001,
	0xAB40AB40,0xAB40AB40,0xAB40AB40,0xFF55AB40,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xFFFFEAAA,
	0xBEAAAAAA,0xAAAABEAA,0xAAAAAAAA,0xFFFFAAAB,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xFFFFABEA,

	0xEAAAEAAA,0xEAAAEAAA,0xEAAAEAAA,0xFFFFEAAA,0x00015555,0x00010001,0x00010001,0x00010001,
	0x01405555,0x01400140,0x01400140,0x01400140,0x40005555,0x40004000,0x40004000,0x40004000,
	0x00015555,0x00010001,0x00010001,0x00010001,0x5640AA55,0x56405640,0x56405640,0x56405640,
	0x9555AAAA,0x95559555,0x95559555,0x95559555,0x00010001,0x55550001,0x00000000,0x00000000,
	0x01400140,0x55550140,0x00000000,0x00000000,0x40004000,0x55554000,0x00000000,0x00000000,
	0x00010001,0x55550001,0x00000000,0x00000000,0x56405640,0xAA555640,0x00000000,0x00000000,
	0x95559555,0xAAAA9555,0x00000000,0x00000000,
};

const unsigned short MiniMapMap[60] __attribute__((aligned(4)))=
{
	0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,
	0x0009,0x000A,0x000B,0x000C,0x000D,0x000E,0x000F,0x0010,
	0x0011,0x0012,0x0013,0x0014,0x0015,0x0016,0x0017,0x0018,
	0x0019,0x001A,0x001B,0x001C,0x001D,0x001E,0x001F,0x0020,
	0x0021,0x0022,0x0023,0x0024,0x0025,0x0026,0x0027,0x0028,
	0x0029,0x002A,0x002B,0x002C,0x002D,0x002E,0x002F,0x0030,
	0x0031,0x0032,0x0033,0x0034,0x0035,0x0036,0x0037,0x0038,
	0x0039,0x003A,0x003B,0x003C,
};

//}}BLOCK(MiniMap)
