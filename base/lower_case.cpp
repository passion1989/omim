#include "string_utils.hpp"

namespace strings
{

static uint16_t const small00[] = {0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xa,0xb,0xc,0xd,0xe,0xf,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3a,0x3b,0x3c,0x3d,0x3e,0x3f,0x40,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6a,0x6b,0x6c,0x6d,0x6e,0x6f,0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7a,0x5b,0x5c,0x5d,0x5e,0x5f,0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6a,0x6b,0x6c,0x6d,0x6e,0x6f,0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7a,0x7b,0x7c,0x7d,0x7e,0x7f,0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,0x98,0x99,0x9a,0x9b,0x9c,0x9d,0x9e,0x9f,0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,0x3bc,0xb6,0xb7,0xb8,0xb9,0xba,0xbb,0xbc,0xbd,0xbe,0xbf,0xe0,0xe1,0xe2,0xe3,0xe4,0xe5,0xe6,0xe7,0xe8,0xe9,0xea,0xeb,0xec,0xed,0xee,0xef,0xf0,0xf1,0xf2,0xf3,0xf4,0xf5,0xf6,0xd7,0xf8,0xf9,0xfa,0xfb,0xfc,0xfd,0xfe,0x0,0xe0,0xe1,0xe2,0xe3,0xe4,0xe5,0xe6,0xe7,0xe8,0xe9,0xea,0xeb,0xec,0xed,0xee,0xef,0xf0,0xf1,0xf2,0xf3,0xf4,0xf5,0xf6,0xf7,0xf8,0xf9,0xfa,0xfb,0xfc,0xfd,0xfe,0xff};
static uint16_t const small01[] = {0x101,0x101,0x103,0x103,0x105,0x105,0x107,0x107,0x109,0x109,0x10b,0x10b,0x10d,0x10d,0x10f,0x10f,0x111,0x111,0x113,0x113,0x115,0x115,0x117,0x117,0x119,0x119,0x11b,0x11b,0x11d,0x11d,0x11f,0x11f,0x121,0x121,0x123,0x123,0x125,0x125,0x127,0x127,0x129,0x129,0x12b,0x12b,0x12d,0x12d,0x12f,0x12f,0x0,0x131,0x133,0x133,0x135,0x135,0x137,0x137,0x138,0x13a,0x13a,0x13c,0x13c,0x13e,0x13e,0x140,0x140,0x142,0x142,0x144,0x144,0x146,0x146,0x148,0x148,0x0,0x14b,0x14b,0x14d,0x14d,0x14f,0x14f,0x151,0x151,0x153,0x153,0x155,0x155,0x157,0x157,0x159,0x159,0x15b,0x15b,0x15d,0x15d,0x15f,0x15f,0x161,0x161,0x163,0x163,0x165,0x165,0x167,0x167,0x169,0x169,0x16b,0x16b,0x16d,0x16d,0x16f,0x16f,0x171,0x171,0x173,0x173,0x175,0x175,0x177,0x177,0xff,0x17a,0x17a,0x17c,0x17c,0x17e,0x17e,0x73,0x180,0x253,0x183,0x183,0x185,0x185,0x254,0x188,0x188,0x256,0x257,0x18c,0x18c,0x18d,0x1dd,0x259,0x25b,0x192,0x192,0x260,0x263,0x195,0x269,0x268,0x199,0x199,0x19a,0x19b,0x26f,0x272,0x19e,0x275,0x1a1,0x1a1,0x1a3,0x1a3,0x1a5,0x1a5,0x280,0x1a8,0x1a8,0x283,0x1aa,0x1ab,0x1ad,0x1ad,0x288,0x1b0,0x1b0,0x28a,0x28b,0x1b4,0x1b4,0x1b6,0x1b6,0x292,0x1b9,0x1b9,0x1ba,0x1bb,0x1bd,0x1bd,0x1be,0x1bf,0x1c0,0x1c1,0x1c2,0x1c3,0x1c6,0x1c6,0x1c6,0x1c9,0x1c9,0x1c9,0x1cc,0x1cc,0x1cc,0x1ce,0x1ce,0x1d0,0x1d0,0x1d2,0x1d2,0x1d4,0x1d4,0x1d6,0x1d6,0x1d8,0x1d8,0x1da,0x1da,0x1dc,0x1dc,0x1dd,0x1df,0x1df,0x1e1,0x1e1,0x1e3,0x1e3,0x1e5,0x1e5,0x1e7,0x1e7,0x1e9,0x1e9,0x1eb,0x1eb,0x1ed,0x1ed,0x1ef,0x1ef,0x0,0x1f3,0x1f3,0x1f3,0x1f5,0x1f5,0x195,0x1bf,0x1f9,0x1f9,0x1fb,0x1fb,0x1fd,0x1fd,0x1ff,0x1ff};
static uint16_t const small02[] = {0x201,0x201,0x203,0x203,0x205,0x205,0x207,0x207,0x209,0x209,0x20b,0x20b,0x20d,0x20d,0x20f,0x20f,0x211,0x211,0x213,0x213,0x215,0x215,0x217,0x217,0x219,0x219,0x21b,0x21b,0x21d,0x21d,0x21f,0x21f,0x19e,0x221,0x223,0x223,0x225,0x225,0x227,0x227,0x229,0x229,0x22b,0x22b,0x22d,0x22d,0x22f,0x22f,0x231,0x231,0x233,0x233,0x234,0x235,0x236,0x237,0x238,0x239,0x2c65,0x23c,0x23c,0x19a,0x2c66,0x23f,0x240,0x242,0x242,0x180,0x289,0x28c,0x247,0x247,0x249,0x249,0x24b,0x24b,0x24d,0x24d,0x24f,0x24f,0x250,0x251,0x252,0x253,0x254,0x255,0x256,0x257,0x258,0x259,0x25a,0x25b,0x25c,0x25d,0x25e,0x25f,0x260,0x261,0x262,0x263,0x264,0x265,0x266,0x267,0x268,0x269,0x26a,0x26b,0x26c,0x26d,0x26e,0x26f,0x270,0x271,0x272,0x273,0x274,0x275,0x276,0x277,0x278,0x279,0x27a,0x27b,0x27c,0x27d,0x27e,0x27f,0x280,0x281,0x282,0x283,0x284,0x285,0x286,0x287,0x288,0x289,0x28a,0x28b,0x28c,0x28d,0x28e,0x28f,0x290,0x291,0x292,0x293,0x294,0x295,0x296,0x297,0x298,0x299,0x29a,0x29b,0x29c,0x29d,0x29e,0x29f,0x2a0,0x2a1,0x2a2,0x2a3,0x2a4,0x2a5,0x2a6,0x2a7,0x2a8,0x2a9,0x2aa,0x2ab,0x2ac,0x2ad,0x2ae,0x2af,0x2b0,0x2b1,0x2b2,0x2b3,0x2b4,0x2b5,0x2b6,0x2b7,0x2b8,0x2b9,0x2ba,0x2bb,0x2bc,0x2bd,0x2be,0x2bf,0x2c0,0x2c1,0x2c2,0x2c3,0x2c4,0x2c5,0x2c6,0x2c7,0x2c8,0x2c9,0x2ca,0x2cb,0x2cc,0x2cd,0x2ce,0x2cf,0x2d0,0x2d1,0x2d2,0x2d3,0x2d4,0x2d5,0x2d6,0x2d7,0x2d8,0x2d9,0x2da,0x2db,0x2dc,0x2dd,0x2de,0x2df,0x2e0,0x2e1,0x2e2,0x2e3,0x2e4,0x2e5,0x2e6,0x2e7,0x2e8,0x2e9,0x2ea,0x2eb,0x2ec,0x2ed,0x2ee,0x2ef,0x2f0,0x2f1,0x2f2,0x2f3,0x2f4,0x2f5,0x2f6,0x2f7,0x2f8,0x2f9,0x2fa,0x2fb,0x2fc,0x2fd,0x2fe,0x2ff};
static uint16_t const small03[] = {0x300,0x301,0x302,0x303,0x304,0x305,0x306,0x307,0x308,0x309,0x30a,0x30b,0x30c,0x30d,0x30e,0x30f,0x310,0x311,0x312,0x313,0x314,0x315,0x316,0x317,0x318,0x319,0x31a,0x31b,0x31c,0x31d,0x31e,0x31f,0x320,0x321,0x322,0x323,0x324,0x325,0x326,0x327,0x328,0x329,0x32a,0x32b,0x32c,0x32d,0x32e,0x32f,0x330,0x331,0x332,0x333,0x334,0x335,0x336,0x337,0x338,0x339,0x33a,0x33b,0x33c,0x33d,0x33e,0x33f,0x340,0x341,0x342,0x343,0x344,0x3b9,0x346,0x347,0x348,0x349,0x34a,0x34b,0x34c,0x34d,0x34e,0x34f,0x350,0x351,0x352,0x353,0x354,0x355,0x356,0x357,0x358,0x359,0x35a,0x35b,0x35c,0x35d,0x35e,0x35f,0x360,0x361,0x362,0x363,0x364,0x365,0x366,0x367,0x368,0x369,0x36a,0x36b,0x36c,0x36d,0x36e,0x36f,0x371,0x371,0x373,0x373,0x374,0x375,0x377,0x377,0x378,0x379,0x37a,0x37b,0x37c,0x37d,0x37e,0x37f,0x380,0x381,0x382,0x383,0x384,0x385,0x3ac,0x387,0x3ad,0x3ae,0x3af,0x38b,0x3cc,0x38d,0x3cd,0x3ce,0x0,0x3b1,0x3b2,0x3b3,0x3b4,0x3b5,0x3b6,0x3b7,0x3b8,0x3b9,0x3ba,0x3bb,0x3bc,0x3bd,0x3be,0x3bf,0x3c0,0x3c1,0x3a2,0x3c3,0x3c4,0x3c5,0x3c6,0x3c7,0x3c8,0x3c9,0x3ca,0x3cb,0x3ac,0x3ad,0x3ae,0x3af,0x0,0x3b1,0x3b2,0x3b3,0x3b4,0x3b5,0x3b6,0x3b7,0x3b8,0x3b9,0x3ba,0x3bb,0x3bc,0x3bd,0x3be,0x3bf,0x3c0,0x3c1,0x3c3,0x3c3,0x3c4,0x3c5,0x3c6,0x3c7,0x3c8,0x3c9,0x3ca,0x3cb,0x3cc,0x3cd,0x3ce,0x3d7,0x3b2,0x3b8,0x3d2,0x3d3,0x3d4,0x3c6,0x3c0,0x3d7,0x3d9,0x3d9,0x3db,0x3db,0x3dd,0x3dd,0x3df,0x3df,0x3e1,0x3e1,0x3e3,0x3e3,0x3e5,0x3e5,0x3e7,0x3e7,0x3e9,0x3e9,0x3eb,0x3eb,0x3ed,0x3ed,0x3ef,0x3ef,0x3ba,0x3c1,0x3f2,0x3f3,0x3b8,0x3b5,0x3f6,0x3f8,0x3f8,0x3f2,0x3fb,0x3fb,0x3fc,0x37b,0x37c,0x37d};
static uint16_t const small04[] = {0x450,0x451,0x452,0x453,0x454,0x455,0x456,0x457,0x458,0x459,0x45a,0x45b,0x45c,0x45d,0x45e,0x45f,0x430,0x431,0x432,0x433,0x434,0x435,0x436,0x437,0x438,0x439,0x43a,0x43b,0x43c,0x43d,0x43e,0x43f,0x440,0x441,0x442,0x443,0x444,0x445,0x446,0x447,0x448,0x449,0x44a,0x44b,0x44c,0x44d,0x44e,0x44f,0x430,0x431,0x432,0x433,0x434,0x435,0x436,0x437,0x438,0x439,0x43a,0x43b,0x43c,0x43d,0x43e,0x43f,0x440,0x441,0x442,0x443,0x444,0x445,0x446,0x447,0x448,0x449,0x44a,0x44b,0x44c,0x44d,0x44e,0x44f,0x450,0x451,0x452,0x453,0x454,0x455,0x456,0x457,0x458,0x459,0x45a,0x45b,0x45c,0x45d,0x45e,0x45f,0x461,0x461,0x463,0x463,0x465,0x465,0x467,0x467,0x469,0x469,0x46b,0x46b,0x46d,0x46d,0x46f,0x46f,0x471,0x471,0x473,0x473,0x475,0x475,0x477,0x477,0x479,0x479,0x47b,0x47b,0x47d,0x47d,0x47f,0x47f,0x481,0x481,0x482,0x483,0x484,0x485,0x486,0x487,0x488,0x489,0x48b,0x48b,0x48d,0x48d,0x48f,0x48f,0x491,0x491,0x493,0x493,0x495,0x495,0x497,0x497,0x499,0x499,0x49b,0x49b,0x49d,0x49d,0x49f,0x49f,0x4a1,0x4a1,0x4a3,0x4a3,0x4a5,0x4a5,0x4a7,0x4a7,0x4a9,0x4a9,0x4ab,0x4ab,0x4ad,0x4ad,0x4af,0x4af,0x4b1,0x4b1,0x4b3,0x4b3,0x4b5,0x4b5,0x4b7,0x4b7,0x4b9,0x4b9,0x4bb,0x4bb,0x4bd,0x4bd,0x4bf,0x4bf,0x4cf,0x4c2,0x4c2,0x4c4,0x4c4,0x4c6,0x4c6,0x4c8,0x4c8,0x4ca,0x4ca,0x4cc,0x4cc,0x4ce,0x4ce,0x4cf,0x4d1,0x4d1,0x4d3,0x4d3,0x4d5,0x4d5,0x4d7,0x4d7,0x4d9,0x4d9,0x4db,0x4db,0x4dd,0x4dd,0x4df,0x4df,0x4e1,0x4e1,0x4e3,0x4e3,0x4e5,0x4e5,0x4e7,0x4e7,0x4e9,0x4e9,0x4eb,0x4eb,0x4ed,0x4ed,0x4ef,0x4ef,0x4f1,0x4f1,0x4f3,0x4f3,0x4f5,0x4f5,0x4f7,0x4f7,0x4f9,0x4f9,0x4fb,0x4fb,0x4fd,0x4fd,0x4ff,0x4ff};
static uint16_t const small05[] = {0x501,0x501,0x503,0x503,0x505,0x505,0x507,0x507,0x509,0x509,0x50b,0x50b,0x50d,0x50d,0x50f,0x50f,0x511,0x511,0x513,0x513,0x515,0x515,0x517,0x517,0x519,0x519,0x51b,0x51b,0x51d,0x51d,0x51f,0x51f,0x521,0x521,0x523,0x523,0x525,0x525,0x527,0x527,0x528,0x529,0x52a,0x52b,0x52c,0x52d,0x52e,0x52f,0x530,0x561,0x562,0x563,0x564,0x565,0x566,0x567,0x568,0x569,0x56a,0x56b,0x56c,0x56d,0x56e,0x56f,0x570,0x571,0x572,0x573,0x574,0x575,0x576,0x577,0x578,0x579,0x57a,0x57b,0x57c,0x57d,0x57e,0x57f,0x580,0x581,0x582,0x583,0x584,0x585,0x586,0x557,0x558,0x559,0x55a,0x55b,0x55c,0x55d,0x55e,0x55f,0x560,0x561,0x562,0x563,0x564,0x565,0x566,0x567,0x568,0x569,0x56a,0x56b,0x56c,0x56d,0x56e,0x56f,0x570,0x571,0x572,0x573,0x574,0x575,0x576,0x577,0x578,0x579,0x57a,0x57b,0x57c,0x57d,0x57e,0x57f,0x580,0x581,0x582,0x583,0x584,0x585,0x586,0x0,0x588,0x589,0x58a,0x58b,0x58c,0x58d,0x58e,0x58f,0x590,0x591,0x592,0x593,0x594,0x595,0x596,0x597,0x598,0x599,0x59a,0x59b,0x59c,0x59d,0x59e,0x59f,0x5a0,0x5a1,0x5a2,0x5a3,0x5a4,0x5a5,0x5a6,0x5a7,0x5a8,0x5a9,0x5aa,0x5ab,0x5ac,0x5ad,0x5ae,0x5af,0x5b0,0x5b1,0x5b2,0x5b3,0x5b4,0x5b5,0x5b6,0x5b7,0x5b8,0x5b9,0x5ba,0x5bb,0x5bc,0x5bd,0x5be,0x5bf,0x5c0,0x5c1,0x5c2,0x5c3,0x5c4,0x5c5,0x5c6,0x5c7,0x5c8,0x5c9,0x5ca,0x5cb,0x5cc,0x5cd,0x5ce,0x5cf,0x5d0,0x5d1,0x5d2,0x5d3,0x5d4,0x5d5,0x5d6,0x5d7,0x5d8,0x5d9,0x5da,0x5db,0x5dc,0x5dd,0x5de,0x5df,0x5e0,0x5e1,0x5e2,0x5e3,0x5e4,0x5e5,0x5e6,0x5e7,0x5e8,0x5e9,0x5ea,0x5eb,0x5ec,0x5ed,0x5ee,0x5ef,0x5f0,0x5f1,0x5f2,0x5f3,0x5f4,0x5f5,0x5f6,0x5f7,0x5f8,0x5f9,0x5fa,0x5fb,0x5fc,0x5fd,0x5fe,0x5ff};
static uint16_t const small10[] = {0x1000,0x1001,0x1002,0x1003,0x1004,0x1005,0x1006,0x1007,0x1008,0x1009,0x100a,0x100b,0x100c,0x100d,0x100e,0x100f,0x1010,0x1011,0x1012,0x1013,0x1014,0x1015,0x1016,0x1017,0x1018,0x1019,0x101a,0x101b,0x101c,0x101d,0x101e,0x101f,0x1020,0x1021,0x1022,0x1023,0x1024,0x1025,0x1026,0x1027,0x1028,0x1029,0x102a,0x102b,0x102c,0x102d,0x102e,0x102f,0x1030,0x1031,0x1032,0x1033,0x1034,0x1035,0x1036,0x1037,0x1038,0x1039,0x103a,0x103b,0x103c,0x103d,0x103e,0x103f,0x1040,0x1041,0x1042,0x1043,0x1044,0x1045,0x1046,0x1047,0x1048,0x1049,0x104a,0x104b,0x104c,0x104d,0x104e,0x104f,0x1050,0x1051,0x1052,0x1053,0x1054,0x1055,0x1056,0x1057,0x1058,0x1059,0x105a,0x105b,0x105c,0x105d,0x105e,0x105f,0x1060,0x1061,0x1062,0x1063,0x1064,0x1065,0x1066,0x1067,0x1068,0x1069,0x106a,0x106b,0x106c,0x106d,0x106e,0x106f,0x1070,0x1071,0x1072,0x1073,0x1074,0x1075,0x1076,0x1077,0x1078,0x1079,0x107a,0x107b,0x107c,0x107d,0x107e,0x107f,0x1080,0x1081,0x1082,0x1083,0x1084,0x1085,0x1086,0x1087,0x1088,0x1089,0x108a,0x108b,0x108c,0x108d,0x108e,0x108f,0x1090,0x1091,0x1092,0x1093,0x1094,0x1095,0x1096,0x1097,0x1098,0x1099,0x109a,0x109b,0x109c,0x109d,0x109e,0x109f,0x2d00,0x2d01,0x2d02,0x2d03,0x2d04,0x2d05,0x2d06,0x2d07,0x2d08,0x2d09,0x2d0a,0x2d0b,0x2d0c,0x2d0d,0x2d0e,0x2d0f,0x2d10,0x2d11,0x2d12,0x2d13,0x2d14,0x2d15,0x2d16,0x2d17,0x2d18,0x2d19,0x2d1a,0x2d1b,0x2d1c,0x2d1d,0x2d1e,0x2d1f,0x2d20,0x2d21,0x2d22,0x2d23,0x2d24,0x2d25,0x10c6,0x10c7,0x10c8,0x10c9,0x10ca,0x10cb,0x10cc,0x10cd,0x10ce,0x10cf,0x10d0,0x10d1,0x10d2,0x10d3,0x10d4,0x10d5,0x10d6,0x10d7,0x10d8,0x10d9,0x10da,0x10db,0x10dc,0x10dd,0x10de,0x10df,0x10e0,0x10e1,0x10e2,0x10e3,0x10e4,0x10e5,0x10e6,0x10e7,0x10e8,0x10e9,0x10ea,0x10eb,0x10ec,0x10ed,0x10ee,0x10ef,0x10f0,0x10f1,0x10f2,0x10f3,0x10f4,0x10f5,0x10f6,0x10f7,0x10f8,0x10f9,0x10fa,0x10fb,0x10fc,0x10fd,0x10fe,0x10ff};
static uint16_t const small1e[] = {0x1e01,0x1e01,0x1e03,0x1e03,0x1e05,0x1e05,0x1e07,0x1e07,0x1e09,0x1e09,0x1e0b,0x1e0b,0x1e0d,0x1e0d,0x1e0f,0x1e0f,0x1e11,0x1e11,0x1e13,0x1e13,0x1e15,0x1e15,0x1e17,0x1e17,0x1e19,0x1e19,0x1e1b,0x1e1b,0x1e1d,0x1e1d,0x1e1f,0x1e1f,0x1e21,0x1e21,0x1e23,0x1e23,0x1e25,0x1e25,0x1e27,0x1e27,0x1e29,0x1e29,0x1e2b,0x1e2b,0x1e2d,0x1e2d,0x1e2f,0x1e2f,0x1e31,0x1e31,0x1e33,0x1e33,0x1e35,0x1e35,0x1e37,0x1e37,0x1e39,0x1e39,0x1e3b,0x1e3b,0x1e3d,0x1e3d,0x1e3f,0x1e3f,0x1e41,0x1e41,0x1e43,0x1e43,0x1e45,0x1e45,0x1e47,0x1e47,0x1e49,0x1e49,0x1e4b,0x1e4b,0x1e4d,0x1e4d,0x1e4f,0x1e4f,0x1e51,0x1e51,0x1e53,0x1e53,0x1e55,0x1e55,0x1e57,0x1e57,0x1e59,0x1e59,0x1e5b,0x1e5b,0x1e5d,0x1e5d,0x1e5f,0x1e5f,0x1e61,0x1e61,0x1e63,0x1e63,0x1e65,0x1e65,0x1e67,0x1e67,0x1e69,0x1e69,0x1e6b,0x1e6b,0x1e6d,0x1e6d,0x1e6f,0x1e6f,0x1e71,0x1e71,0x1e73,0x1e73,0x1e75,0x1e75,0x1e77,0x1e77,0x1e79,0x1e79,0x1e7b,0x1e7b,0x1e7d,0x1e7d,0x1e7f,0x1e7f,0x1e81,0x1e81,0x1e83,0x1e83,0x1e85,0x1e85,0x1e87,0x1e87,0x1e89,0x1e89,0x1e8b,0x1e8b,0x1e8d,0x1e8d,0x1e8f,0x1e8f,0x1e91,0x1e91,0x1e93,0x1e93,0x1e95,0x1e95,0x0,0x0,0x0,0x0,0x0,0x1e61,0x1e9c,0x1e9d,0x0,0x1e9f,0x1ea1,0x1ea1,0x1ea3,0x1ea3,0x1ea5,0x1ea5,0x1ea7,0x1ea7,0x1ea9,0x1ea9,0x1eab,0x1eab,0x1ead,0x1ead,0x1eaf,0x1eaf,0x1eb1,0x1eb1,0x1eb3,0x1eb3,0x1eb5,0x1eb5,0x1eb7,0x1eb7,0x1eb9,0x1eb9,0x1ebb,0x1ebb,0x1ebd,0x1ebd,0x1ebf,0x1ebf,0x1ec1,0x1ec1,0x1ec3,0x1ec3,0x1ec5,0x1ec5,0x1ec7,0x1ec7,0x1ec9,0x1ec9,0x1ecb,0x1ecb,0x1ecd,0x1ecd,0x1ecf,0x1ecf,0x1ed1,0x1ed1,0x1ed3,0x1ed3,0x1ed5,0x1ed5,0x1ed7,0x1ed7,0x1ed9,0x1ed9,0x1edb,0x1edb,0x1edd,0x1edd,0x1edf,0x1edf,0x1ee1,0x1ee1,0x1ee3,0x1ee3,0x1ee5,0x1ee5,0x1ee7,0x1ee7,0x1ee9,0x1ee9,0x1eeb,0x1eeb,0x1eed,0x1eed,0x1eef,0x1eef,0x1ef1,0x1ef1,0x1ef3,0x1ef3,0x1ef5,0x1ef5,0x1ef7,0x1ef7,0x1ef9,0x1ef9,0x1efb,0x1efb,0x1efd,0x1efd,0x1eff,0x1eff};
static uint16_t const small1f[] = {0x1f00,0x1f01,0x1f02,0x1f03,0x1f04,0x1f05,0x1f06,0x1f07,0x1f00,0x1f01,0x1f02,0x1f03,0x1f04,0x1f05,0x1f06,0x1f07,0x1f10,0x1f11,0x1f12,0x1f13,0x1f14,0x1f15,0x1f16,0x1f17,0x1f10,0x1f11,0x1f12,0x1f13,0x1f14,0x1f15,0x1f1e,0x1f1f,0x1f20,0x1f21,0x1f22,0x1f23,0x1f24,0x1f25,0x1f26,0x1f27,0x1f20,0x1f21,0x1f22,0x1f23,0x1f24,0x1f25,0x1f26,0x1f27,0x1f30,0x1f31,0x1f32,0x1f33,0x1f34,0x1f35,0x1f36,0x1f37,0x1f30,0x1f31,0x1f32,0x1f33,0x1f34,0x1f35,0x1f36,0x1f37,0x1f40,0x1f41,0x1f42,0x1f43,0x1f44,0x1f45,0x1f46,0x1f47,0x1f40,0x1f41,0x1f42,0x1f43,0x1f44,0x1f45,0x1f4e,0x1f4f,0x0,0x1f51,0x0,0x1f53,0x0,0x1f55,0x0,0x1f57,0x1f58,0x1f51,0x1f5a,0x1f53,0x1f5c,0x1f55,0x1f5e,0x1f57,0x1f60,0x1f61,0x1f62,0x1f63,0x1f64,0x1f65,0x1f66,0x1f67,0x1f60,0x1f61,0x1f62,0x1f63,0x1f64,0x1f65,0x1f66,0x1f67,0x1f70,0x1f71,0x1f72,0x1f73,0x1f74,0x1f75,0x1f76,0x1f77,0x1f78,0x1f79,0x1f7a,0x1f7b,0x1f7c,0x1f7d,0x1f7e,0x1f7f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1fb0,0x1fb1,0x0,0x0,0x0,0x1fb5,0x0,0x0,0x1fb0,0x1fb1,0x1f70,0x1f71,0x0,0x1fbd,0x3b9,0x1fbf,0x1fc0,0x1fc1,0x0,0x0,0x0,0x1fc5,0x0,0x0,0x1f72,0x1f73,0x1f74,0x1f75,0x0,0x1fcd,0x1fce,0x1fcf,0x1fd0,0x1fd1,0x0,0x0,0x1fd4,0x1fd5,0x0,0x0,0x1fd0,0x1fd1,0x1f76,0x1f77,0x1fdc,0x1fdd,0x1fde,0x1fdf,0x1fe0,0x1fe1,0x0,0x0,0x0,0x1fe5,0x0,0x0,0x1fe0,0x1fe1,0x1f7a,0x1f7b,0x1fe5,0x1fed,0x1fee,0x1fef,0x1ff0,0x1ff1,0x0,0x0,0x0,0x1ff5,0x0,0x0,0x1f78,0x1f79,0x1f7c,0x1f7d,0x0,0x1ffd,0x1ffe,0x1fff};
static uint16_t const small21[] = {0x2100,0x2101,0x2102,0x2103,0x2104,0x2105,0x2106,0x2107,0x2108,0x2109,0x210a,0x210b,0x210c,0x210d,0x210e,0x210f,0x2110,0x2111,0x2112,0x2113,0x2114,0x2115,0x2116,0x2117,0x2118,0x2119,0x211a,0x211b,0x211c,0x211d,0x211e,0x211f,0x2120,0x2121,0x2122,0x2123,0x2124,0x2125,0x3c9,0x2127,0x2128,0x2129,0x6b,0xe5,0x212c,0x212d,0x212e,0x212f,0x2130,0x2131,0x214e,0x2133,0x2134,0x2135,0x2136,0x2137,0x2138,0x2139,0x213a,0x213b,0x213c,0x213d,0x213e,0x213f,0x2140,0x2141,0x2142,0x2143,0x2144,0x2145,0x2146,0x2147,0x2148,0x2149,0x214a,0x214b,0x214c,0x214d,0x214e,0x214f,0x2150,0x2151,0x2152,0x2153,0x2154,0x2155,0x2156,0x2157,0x2158,0x2159,0x215a,0x215b,0x215c,0x215d,0x215e,0x215f,0x2170,0x2171,0x2172,0x2173,0x2174,0x2175,0x2176,0x2177,0x2178,0x2179,0x217a,0x217b,0x217c,0x217d,0x217e,0x217f,0x2170,0x2171,0x2172,0x2173,0x2174,0x2175,0x2176,0x2177,0x2178,0x2179,0x217a,0x217b,0x217c,0x217d,0x217e,0x217f,0x2180,0x2181,0x2182,0x2184,0x2184,0x2185,0x2186,0x2187,0x2188,0x2189,0x218a,0x218b,0x218c,0x218d,0x218e,0x218f,0x2190,0x2191,0x2192,0x2193,0x2194,0x2195,0x2196,0x2197,0x2198,0x2199,0x219a,0x219b,0x219c,0x219d,0x219e,0x219f,0x21a0,0x21a1,0x21a2,0x21a3,0x21a4,0x21a5,0x21a6,0x21a7,0x21a8,0x21a9,0x21aa,0x21ab,0x21ac,0x21ad,0x21ae,0x21af,0x21b0,0x21b1,0x21b2,0x21b3,0x21b4,0x21b5,0x21b6,0x21b7,0x21b8,0x21b9,0x21ba,0x21bb,0x21bc,0x21bd,0x21be,0x21bf,0x21c0,0x21c1,0x21c2,0x21c3,0x21c4,0x21c5,0x21c6,0x21c7,0x21c8,0x21c9,0x21ca,0x21cb,0x21cc,0x21cd,0x21ce,0x21cf,0x21d0,0x21d1,0x21d2,0x21d3,0x21d4,0x21d5,0x21d6,0x21d7,0x21d8,0x21d9,0x21da,0x21db,0x21dc,0x21dd,0x21de,0x21df,0x21e0,0x21e1,0x21e2,0x21e3,0x21e4,0x21e5,0x21e6,0x21e7,0x21e8,0x21e9,0x21ea,0x21eb,0x21ec,0x21ed,0x21ee,0x21ef,0x21f0,0x21f1,0x21f2,0x21f3,0x21f4,0x21f5,0x21f6,0x21f7,0x21f8,0x21f9,0x21fa,0x21fb,0x21fc,0x21fd,0x21fe,0x21ff};
static uint16_t const small24[] = {0x2400,0x2401,0x2402,0x2403,0x2404,0x2405,0x2406,0x2407,0x2408,0x2409,0x240a,0x240b,0x240c,0x240d,0x240e,0x240f,0x2410,0x2411,0x2412,0x2413,0x2414,0x2415,0x2416,0x2417,0x2418,0x2419,0x241a,0x241b,0x241c,0x241d,0x241e,0x241f,0x2420,0x2421,0x2422,0x2423,0x2424,0x2425,0x2426,0x2427,0x2428,0x2429,0x242a,0x242b,0x242c,0x242d,0x242e,0x242f,0x2430,0x2431,0x2432,0x2433,0x2434,0x2435,0x2436,0x2437,0x2438,0x2439,0x243a,0x243b,0x243c,0x243d,0x243e,0x243f,0x2440,0x2441,0x2442,0x2443,0x2444,0x2445,0x2446,0x2447,0x2448,0x2449,0x244a,0x244b,0x244c,0x244d,0x244e,0x244f,0x2450,0x2451,0x2452,0x2453,0x2454,0x2455,0x2456,0x2457,0x2458,0x2459,0x245a,0x245b,0x245c,0x245d,0x245e,0x245f,0x2460,0x2461,0x2462,0x2463,0x2464,0x2465,0x2466,0x2467,0x2468,0x2469,0x246a,0x246b,0x246c,0x246d,0x246e,0x246f,0x2470,0x2471,0x2472,0x2473,0x2474,0x2475,0x2476,0x2477,0x2478,0x2479,0x247a,0x247b,0x247c,0x247d,0x247e,0x247f,0x2480,0x2481,0x2482,0x2483,0x2484,0x2485,0x2486,0x2487,0x2488,0x2489,0x248a,0x248b,0x248c,0x248d,0x248e,0x248f,0x2490,0x2491,0x2492,0x2493,0x2494,0x2495,0x2496,0x2497,0x2498,0x2499,0x249a,0x249b,0x249c,0x249d,0x249e,0x249f,0x24a0,0x24a1,0x24a2,0x24a3,0x24a4,0x24a5,0x24a6,0x24a7,0x24a8,0x24a9,0x24aa,0x24ab,0x24ac,0x24ad,0x24ae,0x24af,0x24b0,0x24b1,0x24b2,0x24b3,0x24b4,0x24b5,0x24d0,0x24d1,0x24d2,0x24d3,0x24d4,0x24d5,0x24d6,0x24d7,0x24d8,0x24d9,0x24da,0x24db,0x24dc,0x24dd,0x24de,0x24df,0x24e0,0x24e1,0x24e2,0x24e3,0x24e4,0x24e5,0x24e6,0x24e7,0x24e8,0x24e9,0x24d0,0x24d1,0x24d2,0x24d3,0x24d4,0x24d5,0x24d6,0x24d7,0x24d8,0x24d9,0x24da,0x24db,0x24dc,0x24dd,0x24de,0x24df,0x24e0,0x24e1,0x24e2,0x24e3,0x24e4,0x24e5,0x24e6,0x24e7,0x24e8,0x24e9,0x24ea,0x24eb,0x24ec,0x24ed,0x24ee,0x24ef,0x24f0,0x24f1,0x24f2,0x24f3,0x24f4,0x24f5,0x24f6,0x24f7,0x24f8,0x24f9,0x24fa,0x24fb,0x24fc,0x24fd,0x24fe,0x24ff};
static uint16_t const small2c[] = {0x2c30,0x2c31,0x2c32,0x2c33,0x2c34,0x2c35,0x2c36,0x2c37,0x2c38,0x2c39,0x2c3a,0x2c3b,0x2c3c,0x2c3d,0x2c3e,0x2c3f,0x2c40,0x2c41,0x2c42,0x2c43,0x2c44,0x2c45,0x2c46,0x2c47,0x2c48,0x2c49,0x2c4a,0x2c4b,0x2c4c,0x2c4d,0x2c4e,0x2c4f,0x2c50,0x2c51,0x2c52,0x2c53,0x2c54,0x2c55,0x2c56,0x2c57,0x2c58,0x2c59,0x2c5a,0x2c5b,0x2c5c,0x2c5d,0x2c5e,0x2c2f,0x2c30,0x2c31,0x2c32,0x2c33,0x2c34,0x2c35,0x2c36,0x2c37,0x2c38,0x2c39,0x2c3a,0x2c3b,0x2c3c,0x2c3d,0x2c3e,0x2c3f,0x2c40,0x2c41,0x2c42,0x2c43,0x2c44,0x2c45,0x2c46,0x2c47,0x2c48,0x2c49,0x2c4a,0x2c4b,0x2c4c,0x2c4d,0x2c4e,0x2c4f,0x2c50,0x2c51,0x2c52,0x2c53,0x2c54,0x2c55,0x2c56,0x2c57,0x2c58,0x2c59,0x2c5a,0x2c5b,0x2c5c,0x2c5d,0x2c5e,0x2c5f,0x2c61,0x2c61,0x26b,0x1d7d,0x27d,0x2c65,0x2c66,0x2c68,0x2c68,0x2c6a,0x2c6a,0x2c6c,0x2c6c,0x251,0x271,0x250,0x252,0x2c71,0x2c73,0x2c73,0x2c74,0x2c76,0x2c76,0x2c77,0x2c78,0x2c79,0x2c7a,0x2c7b,0x2c7c,0x2c7d,0x23f,0x240,0x2c81,0x2c81,0x2c83,0x2c83,0x2c85,0x2c85,0x2c87,0x2c87,0x2c89,0x2c89,0x2c8b,0x2c8b,0x2c8d,0x2c8d,0x2c8f,0x2c8f,0x2c91,0x2c91,0x2c93,0x2c93,0x2c95,0x2c95,0x2c97,0x2c97,0x2c99,0x2c99,0x2c9b,0x2c9b,0x2c9d,0x2c9d,0x2c9f,0x2c9f,0x2ca1,0x2ca1,0x2ca3,0x2ca3,0x2ca5,0x2ca5,0x2ca7,0x2ca7,0x2ca9,0x2ca9,0x2cab,0x2cab,0x2cad,0x2cad,0x2caf,0x2caf,0x2cb1,0x2cb1,0x2cb3,0x2cb3,0x2cb5,0x2cb5,0x2cb7,0x2cb7,0x2cb9,0x2cb9,0x2cbb,0x2cbb,0x2cbd,0x2cbd,0x2cbf,0x2cbf,0x2cc1,0x2cc1,0x2cc3,0x2cc3,0x2cc5,0x2cc5,0x2cc7,0x2cc7,0x2cc9,0x2cc9,0x2ccb,0x2ccb,0x2ccd,0x2ccd,0x2ccf,0x2ccf,0x2cd1,0x2cd1,0x2cd3,0x2cd3,0x2cd5,0x2cd5,0x2cd7,0x2cd7,0x2cd9,0x2cd9,0x2cdb,0x2cdb,0x2cdd,0x2cdd,0x2cdf,0x2cdf,0x2ce1,0x2ce1,0x2ce3,0x2ce3,0x2ce4,0x2ce5,0x2ce6,0x2ce7,0x2ce8,0x2ce9,0x2cea,0x2cec,0x2cec,0x2cee,0x2cee,0x2cef,0x2cf0,0x2cf1,0x2cf2,0x2cf3,0x2cf4,0x2cf5,0x2cf6,0x2cf7,0x2cf8,0x2cf9,0x2cfa,0x2cfb,0x2cfc,0x2cfd,0x2cfe,0x2cff};
static uint16_t const smalla6[] = {0xa600,0xa601,0xa602,0xa603,0xa604,0xa605,0xa606,0xa607,0xa608,0xa609,0xa60a,0xa60b,0xa60c,0xa60d,0xa60e,0xa60f,0xa610,0xa611,0xa612,0xa613,0xa614,0xa615,0xa616,0xa617,0xa618,0xa619,0xa61a,0xa61b,0xa61c,0xa61d,0xa61e,0xa61f,0xa620,0xa621,0xa622,0xa623,0xa624,0xa625,0xa626,0xa627,0xa628,0xa629,0xa62a,0xa62b,0xa62c,0xa62d,0xa62e,0xa62f,0xa630,0xa631,0xa632,0xa633,0xa634,0xa635,0xa636,0xa637,0xa638,0xa639,0xa63a,0xa63b,0xa63c,0xa63d,0xa63e,0xa63f,0xa641,0xa641,0xa643,0xa643,0xa645,0xa645,0xa647,0xa647,0xa649,0xa649,0xa64b,0xa64b,0xa64d,0xa64d,0xa64f,0xa64f,0xa651,0xa651,0xa653,0xa653,0xa655,0xa655,0xa657,0xa657,0xa659,0xa659,0xa65b,0xa65b,0xa65d,0xa65d,0xa65f,0xa65f,0xa661,0xa661,0xa663,0xa663,0xa665,0xa665,0xa667,0xa667,0xa669,0xa669,0xa66b,0xa66b,0xa66d,0xa66d,0xa66e,0xa66f,0xa670,0xa671,0xa672,0xa673,0xa674,0xa675,0xa676,0xa677,0xa678,0xa679,0xa67a,0xa67b,0xa67c,0xa67d,0xa67e,0xa67f,0xa681,0xa681,0xa683,0xa683,0xa685,0xa685,0xa687,0xa687,0xa689,0xa689,0xa68b,0xa68b,0xa68d,0xa68d,0xa68f,0xa68f,0xa691,0xa691,0xa693,0xa693,0xa695,0xa695,0xa697,0xa697,0xa698,0xa699,0xa69a,0xa69b,0xa69c,0xa69d,0xa69e,0xa69f,0xa6a0,0xa6a1,0xa6a2,0xa6a3,0xa6a4,0xa6a5,0xa6a6,0xa6a7,0xa6a8,0xa6a9,0xa6aa,0xa6ab,0xa6ac,0xa6ad,0xa6ae,0xa6af,0xa6b0,0xa6b1,0xa6b2,0xa6b3,0xa6b4,0xa6b5,0xa6b6,0xa6b7,0xa6b8,0xa6b9,0xa6ba,0xa6bb,0xa6bc,0xa6bd,0xa6be,0xa6bf,0xa6c0,0xa6c1,0xa6c2,0xa6c3,0xa6c4,0xa6c5,0xa6c6,0xa6c7,0xa6c8,0xa6c9,0xa6ca,0xa6cb,0xa6cc,0xa6cd,0xa6ce,0xa6cf,0xa6d0,0xa6d1,0xa6d2,0xa6d3,0xa6d4,0xa6d5,0xa6d6,0xa6d7,0xa6d8,0xa6d9,0xa6da,0xa6db,0xa6dc,0xa6dd,0xa6de,0xa6df,0xa6e0,0xa6e1,0xa6e2,0xa6e3,0xa6e4,0xa6e5,0xa6e6,0xa6e7,0xa6e8,0xa6e9,0xa6ea,0xa6eb,0xa6ec,0xa6ed,0xa6ee,0xa6ef,0xa6f0,0xa6f1,0xa6f2,0xa6f3,0xa6f4,0xa6f5,0xa6f6,0xa6f7,0xa6f8,0xa6f9,0xa6fa,0xa6fb,0xa6fc,0xa6fd,0xa6fe,0xa6ff};
static uint16_t const smalla7[] = {0xa700,0xa701,0xa702,0xa703,0xa704,0xa705,0xa706,0xa707,0xa708,0xa709,0xa70a,0xa70b,0xa70c,0xa70d,0xa70e,0xa70f,0xa710,0xa711,0xa712,0xa713,0xa714,0xa715,0xa716,0xa717,0xa718,0xa719,0xa71a,0xa71b,0xa71c,0xa71d,0xa71e,0xa71f,0xa720,0xa721,0xa723,0xa723,0xa725,0xa725,0xa727,0xa727,0xa729,0xa729,0xa72b,0xa72b,0xa72d,0xa72d,0xa72f,0xa72f,0xa730,0xa731,0xa733,0xa733,0xa735,0xa735,0xa737,0xa737,0xa739,0xa739,0xa73b,0xa73b,0xa73d,0xa73d,0xa73f,0xa73f,0xa741,0xa741,0xa743,0xa743,0xa745,0xa745,0xa747,0xa747,0xa749,0xa749,0xa74b,0xa74b,0xa74d,0xa74d,0xa74f,0xa74f,0xa751,0xa751,0xa753,0xa753,0xa755,0xa755,0xa757,0xa757,0xa759,0xa759,0xa75b,0xa75b,0xa75d,0xa75d,0xa75f,0xa75f,0xa761,0xa761,0xa763,0xa763,0xa765,0xa765,0xa767,0xa767,0xa769,0xa769,0xa76b,0xa76b,0xa76d,0xa76d,0xa76f,0xa76f,0xa770,0xa771,0xa772,0xa773,0xa774,0xa775,0xa776,0xa777,0xa778,0xa77a,0xa77a,0xa77c,0xa77c,0x1d79,0xa77f,0xa77f,0xa781,0xa781,0xa783,0xa783,0xa785,0xa785,0xa787,0xa787,0xa788,0xa789,0xa78a,0xa78c,0xa78c,0x265,0xa78e,0xa78f,0xa791,0xa791,0xa792,0xa793,0xa794,0xa795,0xa796,0xa797,0xa798,0xa799,0xa79a,0xa79b,0xa79c,0xa79d,0xa79e,0xa79f,0xa7a1,0xa7a1,0xa7a3,0xa7a3,0xa7a5,0xa7a5,0xa7a7,0xa7a7,0xa7a9,0xa7a9,0xa7aa,0xa7ab,0xa7ac,0xa7ad,0xa7ae,0xa7af,0xa7b0,0xa7b1,0xa7b2,0xa7b3,0xa7b4,0xa7b5,0xa7b6,0xa7b7,0xa7b8,0xa7b9,0xa7ba,0xa7bb,0xa7bc,0xa7bd,0xa7be,0xa7bf,0xa7c0,0xa7c1,0xa7c2,0xa7c3,0xa7c4,0xa7c5,0xa7c6,0xa7c7,0xa7c8,0xa7c9,0xa7ca,0xa7cb,0xa7cc,0xa7cd,0xa7ce,0xa7cf,0xa7d0,0xa7d1,0xa7d2,0xa7d3,0xa7d4,0xa7d5,0xa7d6,0xa7d7,0xa7d8,0xa7d9,0xa7da,0xa7db,0xa7dc,0xa7dd,0xa7de,0xa7df,0xa7e0,0xa7e1,0xa7e2,0xa7e3,0xa7e4,0xa7e5,0xa7e6,0xa7e7,0xa7e8,0xa7e9,0xa7ea,0xa7eb,0xa7ec,0xa7ed,0xa7ee,0xa7ef,0xa7f0,0xa7f1,0xa7f2,0xa7f3,0xa7f4,0xa7f5,0xa7f6,0xa7f7,0xa7f8,0xa7f9,0xa7fa,0xa7fb,0xa7fc,0xa7fd,0xa7fe,0xa7ff};
static uint16_t const smallff[] = {0xff00,0xff01,0xff02,0xff03,0xff04,0xff05,0xff06,0xff07,0xff08,0xff09,0xff0a,0xff0b,0xff0c,0xff0d,0xff0e,0xff0f,0xff10,0xff11,0xff12,0xff13,0xff14,0xff15,0xff16,0xff17,0xff18,0xff19,0xff1a,0xff1b,0xff1c,0xff1d,0xff1e,0xff1f,0xff20,0xff41,0xff42,0xff43,0xff44,0xff45,0xff46,0xff47,0xff48,0xff49,0xff4a,0xff4b,0xff4c,0xff4d,0xff4e,0xff4f,0xff50,0xff51,0xff52,0xff53,0xff54,0xff55,0xff56,0xff57,0xff58,0xff59,0xff5a,0xff3b,0xff3c,0xff3d,0xff3e,0xff3f,0xff40,0xff41,0xff42,0xff43,0xff44,0xff45,0xff46,0xff47,0xff48,0xff49,0xff4a,0xff4b,0xff4c,0xff4d,0xff4e,0xff4f,0xff50,0xff51,0xff52,0xff53,0xff54,0xff55,0xff56,0xff57,0xff58,0xff59,0xff5a,0xff5b,0xff5c,0xff5d,0xff5e,0xff5f,0xff60,0xff61,0xff62,0xff63,0xff64,0xff65,0xff66,0xff67,0xff68,0xff69,0xff6a,0xff6b,0xff6c,0xff6d,0xff6e,0xff6f,0xff70,0xff71,0xff72,0xff73,0xff74,0xff75,0xff76,0xff77,0xff78,0xff79,0xff7a,0xff7b,0xff7c,0xff7d,0xff7e,0xff7f,0xff80,0xff81,0xff82,0xff83,0xff84,0xff85,0xff86,0xff87,0xff88,0xff89,0xff8a,0xff8b,0xff8c,0xff8d,0xff8e,0xff8f,0xff90,0xff91,0xff92,0xff93,0xff94,0xff95,0xff96,0xff97,0xff98,0xff99,0xff9a,0xff9b,0xff9c,0xff9d,0xff9e,0xff9f,0xffa0,0xffa1,0xffa2,0xffa3,0xffa4,0xffa5,0xffa6,0xffa7,0xffa8,0xffa9,0xffaa,0xffab,0xffac,0xffad,0xffae,0xffaf,0xffb0,0xffb1,0xffb2,0xffb3,0xffb4,0xffb5,0xffb6,0xffb7,0xffb8,0xffb9,0xffba,0xffbb,0xffbc,0xffbd,0xffbe,0xffbf,0xffc0,0xffc1,0xffc2,0xffc3,0xffc4,0xffc5,0xffc6,0xffc7,0xffc8,0xffc9,0xffca,0xffcb,0xffcc,0xffcd,0xffce,0xffcf,0xffd0,0xffd1,0xffd2,0xffd3,0xffd4,0xffd5,0xffd6,0xffd7,0xffd8,0xffd9,0xffda,0xffdb,0xffdc,0xffdd,0xffde,0xffdf,0xffe0,0xffe1,0xffe2,0xffe3,0xffe4,0xffe5,0xffe6,0xffe7,0xffe8,0xffe9,0xffea,0xffeb,0xffec,0xffed,0xffee,0xffef,0xfff0,0xfff1,0xfff2,0xfff3,0xfff4,0xfff5,0xfff6,0xfff7,0xfff8,0xfff9,0xfffa,0xfffb,0xfffc,0xfffd,0xfffe,0xffff};

/// @return 0 if char should be replaced with 2 or more chars
UniChar LowerUniChar(UniChar c)
{
  switch (c & 0xffffff00)
  {
    case 0x0000: return small00[static_cast<uint8_t>(c & 0x00ff)];
    case 0x0100: return small01[static_cast<uint8_t>(c & 0x00ff)];
    case 0x0200: return small02[static_cast<uint8_t>(c & 0x00ff)];
    case 0x0300: return small03[static_cast<uint8_t>(c & 0x00ff)];
    case 0x0400: return small04[static_cast<uint8_t>(c & 0x00ff)];
    case 0x0500: return small05[static_cast<uint8_t>(c & 0x00ff)];
    case 0x1000: return small10[static_cast<uint8_t>(c & 0x00ff)];
    case 0x1e00: return small1e[static_cast<uint8_t>(c & 0x00ff)];
    case 0x1f00: return small1f[static_cast<uint8_t>(c & 0x00ff)];
    case 0x2100: return small21[static_cast<uint8_t>(c & 0x00ff)];
    case 0x2400: return small24[static_cast<uint8_t>(c & 0x00ff)];
    case 0x2c00: return small2c[static_cast<uint8_t>(c & 0x00ff)];
    case 0xa600: return smalla6[static_cast<uint8_t>(c & 0x00ff)];
    case 0xa700: return smalla7[static_cast<uint8_t>(c & 0x00ff)];
    case 0xfb00:
    {
      if (c >= 0xfb00 && c <= 0xfb06)
        return 0;
      else if (c >= 0xfb13 && c <= 0xfb17)
        return 0;
      return c;
    }
    case 0xff00: return smallff[static_cast<uint8_t>(c & 0x00ff)];
    case 0x10400:
    {
      if (c >= 0x10400 && c <= 0x10427)
        return c + 0x28;
      return c;
    }
    default: return c;
  }
}

void MakeLowerCase(UniString & s)
{
  UniString r;
  for (UniString::iterator it = s.begin(); it != s.end(); ++it)
  {
    UniChar const c = LowerUniChar(*it);
    if (c != 0)
      r.push_back(c);
    else
    { // special case, replace this char with two or more chars for full case folding
      switch (*it)
      {
        case 0xdf: r.push_back(0x73); r.push_back(0x73); break;
        case 0x130: r.push_back(0x69); r.push_back(0x307); break;
        case 0x149: r.push_back(0x2bc); r.push_back(0x6e); break;
        case 0x1f0: r.push_back(0x6a); r.push_back(0x30c); break;
        case 0x390: r.push_back(0x3b9); r.push_back(0x308); r.push_back(0x301); break;
        case 0x3B0: r.push_back(0x3c5); r.push_back(0x308); r.push_back(0x301); break;
        case 0x587: r.push_back(0x565); r.push_back(0x582); break;
        case 0x1e96: r.push_back(0x68); r.push_back(0x331); break;
        case 0x1e97: r.push_back(0x74); r.push_back(0x308); break;
        case 0x1e98: r.push_back(0x77); r.push_back(0x30a); break;
        case 0x1e99: r.push_back(0x79); r.push_back(0x30a); break;
        case 0x1e9a: r.push_back(0x61); r.push_back(0x2be); break;
        case 0x1e9e: r.push_back(0x73); r.push_back(0x73); break;
        case 0x1f50: r.push_back(0x3c5); r.push_back(0x313); break;
        case 0x1f52: r.push_back(0x3c5); r.push_back(0x313); r.push_back(0x300); break;
        case 0x1f54: r.push_back(0x3c5); r.push_back(0x313); r.push_back(0x301); break;
        case 0x1f56: r.push_back(0x3c5); r.push_back(0x313); r.push_back(0x342); break;
        case 0x1f80: r.push_back(0x1f00); r.push_back(0x3b9); break;
        case 0x1f81: r.push_back(0x1f01); r.push_back(0x3b9); break;
        case 0x1f82: r.push_back(0x1f02); r.push_back(0x3b9); break;
        case 0x1f83: r.push_back(0x1f03); r.push_back(0x3b9); break;
        case 0x1f84: r.push_back(0x1f04); r.push_back(0x3b9); break;
        case 0x1f85: r.push_back(0x1f05); r.push_back(0x3b9); break;
        case 0x1f86: r.push_back(0x1f06); r.push_back(0x3b9); break;
        case 0x1f87: r.push_back(0x1f07); r.push_back(0x3b9); break;
        case 0x1f88: r.push_back(0x1f00); r.push_back(0x3b9); break;
        case 0x1f89: r.push_back(0x1f01); r.push_back(0x3b9); break;
        case 0x1f8a: r.push_back(0x1f02); r.push_back(0x3b9); break;
        case 0x1f8b: r.push_back(0x1f03); r.push_back(0x3b9); break;
        case 0x1f8c: r.push_back(0x1f04); r.push_back(0x3b9); break;
        case 0x1f8d: r.push_back(0x1f05); r.push_back(0x3b9); break;
        case 0x1f8e: r.push_back(0x1f06); r.push_back(0x3b9); break;
        case 0x1f8f: r.push_back(0x1f07); r.push_back(0x3b9); break;
        case 0x1f90: r.push_back(0x1f20); r.push_back(0x3b9); break;
        case 0x1f91: r.push_back(0x1f21); r.push_back(0x3b9); break;
        case 0x1f92: r.push_back(0x1f22); r.push_back(0x3b9); break;
        case 0x1f93: r.push_back(0x1f23); r.push_back(0x3b9); break;
        case 0x1f94: r.push_back(0x1f24); r.push_back(0x3b9); break;
        case 0x1f95: r.push_back(0x1f25); r.push_back(0x3b9); break;
        case 0x1f96: r.push_back(0x1f26); r.push_back(0x3b9); break;
        case 0x1f97: r.push_back(0x1f27); r.push_back(0x3b9); break;
        case 0x1f98: r.push_back(0x1f20); r.push_back(0x3b9); break;
        case 0x1f99: r.push_back(0x1f21); r.push_back(0x3b9); break;
        case 0x1f9a: r.push_back(0x1f22); r.push_back(0x3b9); break;
        case 0x1f9b: r.push_back(0x1f23); r.push_back(0x3b9); break;
        case 0x1f9c: r.push_back(0x1f24); r.push_back(0x3b9); break;
        case 0x1f9d: r.push_back(0x1f25); r.push_back(0x3b9); break;
        case 0x1f9e: r.push_back(0x1f26); r.push_back(0x3b9); break;
        case 0x1f9f: r.push_back(0x1f27); r.push_back(0x3b9); break;
        case 0x1fa0: r.push_back(0x1f60); r.push_back(0x3b9); break;
        case 0x1fa1: r.push_back(0x1f61); r.push_back(0x3b9); break;
        case 0x1fa2: r.push_back(0x1f62); r.push_back(0x3b9); break;
        case 0x1fa3: r.push_back(0x1f63); r.push_back(0x3b9); break;
        case 0x1fa4: r.push_back(0x1f64); r.push_back(0x3b9); break;
        case 0x1fa5: r.push_back(0x1f65); r.push_back(0x3b9); break;
        case 0x1fa6: r.push_back(0x1f66); r.push_back(0x3b9); break;
        case 0x1fa7: r.push_back(0x1f67); r.push_back(0x3b9); break;
        case 0x1fa8: r.push_back(0x1f60); r.push_back(0x3b9); break;
        case 0x1fa9: r.push_back(0x1f61); r.push_back(0x3b9); break;
        case 0x1faa: r.push_back(0x1f62); r.push_back(0x3b9); break;
        case 0x1fab: r.push_back(0x1f63); r.push_back(0x3b9); break;
        case 0x1fac: r.push_back(0x1f64); r.push_back(0x3b9); break;
        case 0x1fad: r.push_back(0x1f65); r.push_back(0x3b9); break;
        case 0x1fae: r.push_back(0x1f66); r.push_back(0x3b9); break;
        case 0x1faf: r.push_back(0x1f67); r.push_back(0x3b9); break;
        case 0x1fb2: r.push_back(0x1f70); r.push_back(0x3b9); break;
        case 0x1fb3: r.push_back(0x3b1); r.push_back(0x3b9); break;
        case 0x1fb4: r.push_back(0x3ac); r.push_back(0x3b9); break;
        case 0x1fb6: r.push_back(0x3b1); r.push_back(0x342); break;
        case 0x1fb7: r.push_back(0x3b1); r.push_back(0x342); r.push_back(0x3b9); break;
        case 0x1fbc: r.push_back(0x3b1); r.push_back(0x3b9); break;
        case 0x1fc2: r.push_back(0x1f74); r.push_back(0x3b9); break;
        case 0x1fc3: r.push_back(0x3b7); r.push_back(0x3b9); break;
        case 0x1fc4: r.push_back(0x3ae); r.push_back(0x3b9); break;
        case 0x1fc6: r.push_back(0x3b7); r.push_back(0x342); break;
        case 0x1fc7: r.push_back(0x3b7); r.push_back(0x342); r.push_back(0x3b9); break;
        case 0x1fcc: r.push_back(0x3b7); r.push_back(0x3b9); break;
        case 0x1fd2: r.push_back(0x3b9); r.push_back(0x308); r.push_back(0x300); break;
        case 0x1fd3: r.push_back(0x3b9); r.push_back(0x308); r.push_back(0x301); break;
        case 0x1fd6: r.push_back(0x3b9); r.push_back(0x342); break;
        case 0x1fd7: r.push_back(0x3b9); r.push_back(0x308); r.push_back(0x342); break;
        case 0x1fe2: r.push_back(0x3c5); r.push_back(0x308); r.push_back(0x300); break;
        case 0x1fe3: r.push_back(0x3c5); r.push_back(0x308); r.push_back(0x301); break;
        case 0x1fe4: r.push_back(0x3c1); r.push_back(0x313); break;
        case 0x1fe6: r.push_back(0x3c5); r.push_back(0x342); break;
        case 0x1fe7: r.push_back(0x3c5); r.push_back(0x308); r.push_back(0x342); break;
        case 0x1ff2: r.push_back(0x1f7c); r.push_back(0x3b9); break;
        case 0x1ff3: r.push_back(0x3c9); r.push_back(0x3b9); break;
        case 0x1ff4: r.push_back(0x3ce); r.push_back(0x3b9); break;
        case 0x1ff6: r.push_back(0x3c9); r.push_back(0x342); break;
        case 0x1ff7: r.push_back(0x3c9); r.push_back(0x342); r.push_back(0x3b9); break;
        case 0x1ffc: r.push_back(0x3c9); r.push_back(0x3b9); break;
        case 0xfb00: r.push_back(0x66); r.push_back(0x66); break;
        case 0xfb01: r.push_back(0x66); r.push_back(0x69); break;
        case 0xfb02: r.push_back(0x66); r.push_back(0x6c); break;
        case 0xfb03: r.push_back(0x66); r.push_back(0x66); r.push_back(0x69); break;
        case 0xfb04: r.push_back(0x66); r.push_back(0x66); r.push_back(0x6c); break;
        case 0xfb05: r.push_back(0x73); r.push_back(0x74); break;
        case 0xfb06: r.push_back(0x73); r.push_back(0x74); break;
        case 0xfb13: r.push_back(0x574); r.push_back(0x576); break;
        case 0xfb14: r.push_back(0x574); r.push_back(0x565); break;
        case 0xfb15: r.push_back(0x574); r.push_back(0x56b); break;
        case 0xfb16: r.push_back(0x57e); r.push_back(0x576); break;
        case 0xfb17: r.push_back(0x574); r.push_back(0x56d); break;
        default: ASSERT(false, ("Invalid UniChar", c));
      }
    }
  }
  s.swap(r);
}

} // namespace strings
