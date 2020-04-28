//
// Created by amagood on 2020/4/21.
//

#include "Color.h"
#include <cmath>

#define CLAMP0255_XY(x, y) (((x) < 0) ? 0 : ((x) > (y) ? (y) : (x)))

double cauchyRefractionIndex(double lambda, double B, double C)
{
    return  B + C / pow(lambda, 2.0);
}


void RGB2XYZ(float R, float G, float B, float *X, float *Y, float *Z)
{
    *X = 0.412453f * R + 0.357580f * G + 0.180423f * B;
    *Y = 0.212671f * R + 0.715160f * G + 0.072169f * B;
    *Z = 0.019334f * R + 0.119193f * G + 0.950227f * B;
}


void XYZ2RGB(float X, float Y, float Z, float *R, float *G, float *B)
{
    float RR, GG, BB;
    RR =  3.240479f * X - 1.537150f * Y - 0.498535f * Z;
    GG = -0.969256f * X + 1.875992f * Y + 0.041556f * Z;
    BB =  0.055648f * X - 0.204043f * Y + 1.057311f * Z;

    *R = CLAMP0255_XY(RR, 1.0f);
    *G = CLAMP0255_XY(GG, 1.0f);
    *B = CLAMP0255_XY(BB, 1.0f);
}

vec3 spectralTable::getXYZ(int lambda)
{
    return table[lambda];
}

spectralTable::spectralTable()
{
    table[380] = vec3(0.0014, 0.0000, 0.0065);
    table[381] = vec3(0.0015, 0.0000, 0.0070);
    table[382] = vec3(0.0016, 0.0000, 0.0077);
    table[383] = vec3(0.0018, 0.0001, 0.0085);
    table[384] = vec3(0.0020, 0.0001, 0.0094);
    table[385] = vec3(0.0022, 0.0001, 0.0105);
    table[386] = vec3(0.0025, 0.0001, 0.0120);
    table[387] = vec3(0.0029, 0.0001, 0.0136);
    table[388] = vec3(0.0033, 0.0001, 0.0155);
    table[389] = vec3(0.0037, 0.0001, 0.0177);
    table[390] = vec3(0.0042, 0.0001, 0.0201);
    table[391] = vec3(0.0048, 0.0001, 0.0225);
    table[392] = vec3(0.0053, 0.0002, 0.0252);
    table[393] = vec3(0.0060, 0.0002, 0.0284);
    table[394] = vec3(0.0068, 0.0002, 0.0320);
    table[395] = vec3(0.0077, 0.0002, 0.0362);
    table[396] = vec3(0.0088, 0.0002, 0.0415);
    table[397] = vec3(0.0100, 0.0003, 0.0473);
    table[398] = vec3(0.0113, 0.0003, 0.0536);
    table[399] = vec3(0.0128, 0.0004, 0.0605);
    table[400] = vec3(0.0143, 0.0004, 0.0679);
    table[401] = vec3(0.0156, 0.0004, 0.0741);
    table[402] = vec3(0.0171, 0.0005, 0.0810);
    table[403] = vec3(0.0188, 0.0005, 0.0891);
    table[404] = vec3(0.0208, 0.0006, 0.0988);
    table[405] = vec3(0.0232, 0.0006, 0.1102);
    table[406] = vec3(0.0263, 0.0007, 0.1249);
    table[407] = vec3(0.0298, 0.0008, 0.1418);
    table[408] = vec3(0.0339, 0.0009, 0.1612);
    table[409] = vec3(0.0384, 0.0011, 0.1830);
    table[410] = vec3(0.0435, 0.0012, 0.2074);
    table[411] = vec3(0.0489, 0.0014, 0.2334);
    table[412] = vec3(0.0550, 0.0015, 0.2625);
    table[413] = vec3(0.0618, 0.0017, 0.2949);
    table[414] = vec3(0.0693, 0.0019, 0.3311);
    table[415] = vec3(0.0776, 0.0022, 0.3713);
    table[416] = vec3(0.0871, 0.0025, 0.4170);
    table[417] = vec3(0.0976, 0.0028, 0.4673);
    table[418] = vec3(0.1089, 0.0031, 0.5221);
    table[419] = vec3(0.1212, 0.0035, 0.5815);
    table[420] = vec3(0.1344, 0.0040, 0.6456);
    table[421] = vec3(0.1497, 0.0046, 0.7201);
    table[422] = vec3(0.1657, 0.0052, 0.7980);
    table[423] = vec3(0.1820, 0.0058, 0.8780);
    table[424] = vec3(0.1985, 0.0065, 0.9588);
    table[425] = vec3(0.2148, 0.0073, 1.0391);
    table[426] = vec3(0.2299, 0.0081, 1.1141);
    table[427] = vec3(0.2445, 0.0089, 1.1868);
    table[428] = vec3(0.2584, 0.0098, 1.2566);
    table[429] = vec3(0.2716, 0.0107, 1.3230);
    table[430] = vec3(0.2839, 0.0116, 1.3856);
    table[431] = vec3(0.2948, 0.0126, 1.4419);
    table[432] = vec3(0.3047, 0.0136, 1.4939);
    table[433] = vec3(0.3136, 0.0146, 1.5414);
    table[434] = vec3(0.3216, 0.0157, 1.5844);
    table[435] = vec3(0.3285, 0.0168, 1.6230);
    table[436] = vec3(0.3343, 0.0180, 1.6561);
    table[437] = vec3(0.3391, 0.0192, 1.6848);
    table[438] = vec3(0.3430, 0.0204, 1.7094);
    table[439] = vec3(0.3461, 0.0217, 1.7301);
    table[440] = vec3(0.3483, 0.0230, 1.7471);
    table[441] = vec3(0.3496, 0.0243, 1.7599);
    table[442] = vec3(0.3501, 0.0256, 1.7695);
    table[443] = vec3(0.3500, 0.0270, 1.7763);
    table[444] = vec3(0.3493, 0.0284, 1.7805);
    table[445] = vec3(0.3481, 0.0298, 1.7826);
    table[446] = vec3(0.3464, 0.0313, 1.7833);
    table[447] = vec3(0.3444, 0.0329, 1.7823);
    table[448] = vec3(0.3420, 0.0345, 1.7800);
    table[449] = vec3(0.3392, 0.0362, 1.7765);
    table[450] = vec3(0.3362, 0.0380, 1.7721);
    table[451] = vec3(0.3333, 0.0398, 1.7688);
    table[452] = vec3(0.3301, 0.0418, 1.7647);
    table[453] = vec3(0.3267, 0.0438, 1.7593);
    table[454] = vec3(0.3229, 0.0458, 1.7525);
    table[455] = vec3(0.3187, 0.0480, 1.7441);
    table[456] = vec3(0.3140, 0.0502, 1.7335);
    table[457] = vec3(0.3089, 0.0526, 1.7208);
    table[458] = vec3(0.3033, 0.0550, 1.7060);
    table[459] = vec3(0.2973, 0.0574, 1.6889);
    table[460] = vec3(0.2908, 0.0600, 1.6692);
    table[461] = vec3(0.2839, 0.0626, 1.6473);
    table[462] = vec3(0.2766, 0.0653, 1.6226);
    table[463] = vec3(0.2687, 0.0680, 1.5946);
    table[464] = vec3(0.2602, 0.0709, 1.5632);
    table[465] = vec3(0.2511, 0.0739, 1.5281);
    table[466] = vec3(0.2406, 0.0770, 1.4849);
    table[467] = vec3(0.2297, 0.0803, 1.4386);
    table[468] = vec3(0.2184, 0.0837, 1.3897);
    table[469] = vec3(0.2069, 0.0872, 1.3392);
    table[470] = vec3(0.1954, 0.0910, 1.2876);
    table[471] = vec3(0.1844, 0.0949, 1.2382);
    table[472] = vec3(0.1735, 0.0991, 1.1887);
    table[473] = vec3(0.1628, 0.1034, 1.1394);
    table[474] = vec3(0.1523, 0.1079, 1.0904);
    table[475] = vec3(0.1421, 0.1126, 1.0419);
    table[476] = vec3(0.1322, 0.1175, 0.9943);
    table[477] = vec3(0.1226, 0.1226, 0.9474);
    table[478] = vec3(0.1133, 0.1279, 0.9015);
    table[479] = vec3(0.1043, 0.1334, 0.8567);
    table[480] = vec3(0.0956, 0.1390, 0.8130);
    table[481] = vec3(0.0873, 0.1446, 0.7706);
    table[482] = vec3(0.0793, 0.1504, 0.7296);
    table[483] = vec3(0.0718, 0.1564, 0.6902);
    table[484] = vec3(0.0646, 0.1627, 0.6523);
    table[485] = vec3(0.0580, 0.1693, 0.6162);
    table[486] = vec3(0.0519, 0.1763, 0.5825);
    table[487] = vec3(0.0463, 0.1836, 0.5507);
    table[488] = vec3(0.0412, 0.1913, 0.5205);
    table[489] = vec3(0.0364, 0.1994, 0.4920);
    table[490] = vec3(0.0320, 0.2080, 0.4652);
    table[491] = vec3(0.0279, 0.2171, 0.4399);
    table[492] = vec3(0.0241, 0.2267, 0.4162);
    table[493] = vec3(0.0207, 0.2368, 0.3939);
    table[494] = vec3(0.0175, 0.2474, 0.3730);
    table[495] = vec3(0.0147, 0.2586, 0.3533);
    table[496] = vec3(0.0121, 0.2702, 0.3349);
    table[497] = vec3(0.0099, 0.2824, 0.3176);
    table[498] = vec3(0.0079, 0.2952, 0.3014);
    table[499] = vec3(0.0063, 0.3087, 0.2862);
    table[500] = vec3(0.0049, 0.3230, 0.2720);
    table[501] = vec3(0.0037, 0.3385, 0.2588);
    table[502] = vec3(0.0029, 0.3548, 0.2464);
    table[503] = vec3(0.0024, 0.3717, 0.2346);
    table[504] = vec3(0.0022, 0.3893, 0.2233);
    table[505] = vec3(0.0024, 0.4073, 0.2123);
    table[506] = vec3(0.0029, 0.4256, 0.2010);
    table[507] = vec3(0.0038, 0.4443, 0.1899);
    table[508] = vec3(0.0052, 0.4635, 0.1790);
    table[509] = vec3(0.0070, 0.4830, 0.1685);
    table[510] = vec3(0.0093, 0.5030, 0.1582);
    table[511] = vec3(0.0122, 0.5237, 0.1481);
    table[512] = vec3(0.0156, 0.5447, 0.1384);
    table[513] = vec3(0.0195, 0.5658, 0.1290);
    table[514] = vec3(0.0240, 0.5870, 0.1201);
    table[515] = vec3(0.0291, 0.6082, 0.1117);
    table[516] = vec3(0.0349, 0.6293, 0.1040);
    table[517] = vec3(0.0412, 0.6502, 0.0968);
    table[518] = vec3(0.0480, 0.6707, 0.0901);
    table[519] = vec3(0.0554, 0.6906, 0.0839);
    table[520] = vec3(0.0633, 0.7100, 0.0782);
    table[521] = vec3(0.0716, 0.7280, 0.0733);
    table[522] = vec3(0.0805, 0.7453, 0.0687);
    table[523] = vec3(0.0898, 0.7619, 0.0646);
    table[524] = vec3(0.0995, 0.7778, 0.0608);
    table[525] = vec3(0.1096, 0.7932, 0.0573);
    table[526] = vec3(0.1202, 0.8082, 0.0539);
    table[527] = vec3(0.1311, 0.8225, 0.0507);
    table[528] = vec3(0.1423, 0.8363, 0.0477);
    table[529] = vec3(0.1538, 0.8495, 0.0449);
    table[530] = vec3(0.1655, 0.8620, 0.0422);
    table[531] = vec3(0.1772, 0.8738, 0.0395);
    table[532] = vec3(0.1891, 0.8849, 0.0369);
    table[533] = vec3(0.2011, 0.8955, 0.0344);
    table[534] = vec3(0.2133, 0.9054, 0.0321);
    table[535] = vec3(0.2257, 0.9149, 0.0298);
    table[536] = vec3(0.2383, 0.9237, 0.0277);
    table[537] = vec3(0.2511, 0.9321, 0.0257);
    table[538] = vec3(0.2640, 0.9399, 0.0238);
    table[539] = vec3(0.2771, 0.9472, 0.0220);
    table[540] = vec3(0.2904, 0.9540, 0.0203);
    table[541] = vec3(0.3039, 0.9602, 0.0187);
    table[542] = vec3(0.3176, 0.9660, 0.0172);
    table[543] = vec3(0.3314, 0.9712, 0.0159);
    table[544] = vec3(0.3455, 0.9760, 0.0146);
    table[545] = vec3(0.3597, 0.9803, 0.0134);
    table[546] = vec3(0.3741, 0.9841, 0.0123);
    table[547] = vec3(0.3886, 0.9874, 0.0113);
    table[548] = vec3(0.4034, 0.9904, 0.0104);
    table[549] = vec3(0.4183, 0.9929, 0.0095);
    table[550] = vec3(0.4334, 0.9950, 0.0087);
    table[551] = vec3(0.4488, 0.9967, 0.0080);
    table[552] = vec3(0.4644, 0.9981, 0.0074);
    table[553] = vec3(0.4801, 0.9992, 0.0068);
    table[554] = vec3(0.4960, 0.9998, 0.0062);
    table[555] = vec3(0.5121, 1.0000, 0.0057);
    table[556] = vec3(0.5283, 0.9998, 0.0053);
    table[557] = vec3(0.5447, 0.9993, 0.0049);
    table[558] = vec3(0.5612, 0.9983, 0.0045);
    table[559] = vec3(0.5778, 0.9969, 0.0042);
    table[560] = vec3(0.5945, 0.9950, 0.0039);
    table[561] = vec3(0.6112, 0.9926, 0.0036);
    table[562] = vec3(0.6280, 0.9897, 0.0034);
    table[563] = vec3(0.6448, 0.9865, 0.0031);
    table[564] = vec3(0.6616, 0.9827, 0.0029);
    table[565] = vec3(0.6784, 0.9786, 0.0027);
    table[566] = vec3(0.6953, 0.9741, 0.0026);
    table[567] = vec3(0.7121, 0.9692, 0.0024);
    table[568] = vec3(0.7288, 0.9639, 0.0023);
    table[569] = vec3(0.7455, 0.9581, 0.0022);
    table[570] = vec3(0.7621, 0.9520, 0.0021);
    table[571] = vec3(0.7785, 0.9454, 0.0020);
    table[572] = vec3(0.7948, 0.9385, 0.0019);
    table[573] = vec3(0.8109, 0.9312, 0.0019);
    table[574] = vec3(0.8268, 0.9235, 0.0018);
    table[575] = vec3(0.8425, 0.9154, 0.0018);
    table[576] = vec3(0.8579, 0.9070, 0.0018);
    table[577] = vec3(0.8731, 0.8983, 0.0017);
    table[578] = vec3(0.8879, 0.8892, 0.0017);
    table[579] = vec3(0.9023, 0.8798, 0.0017);
    table[580] = vec3(0.9163, 0.8700, 0.0017);
    table[581] = vec3(0.9298, 0.8598, 0.0016);
    table[582] = vec3(0.9428, 0.8494, 0.0016);
    table[583] = vec3(0.9553, 0.8386, 0.0015);
    table[584] = vec3(0.9672, 0.8276, 0.0015);
    table[585] = vec3(0.9786, 0.8163, 0.0014);
    table[586] = vec3(0.9894, 0.8048, 0.0013);
    table[587] = vec3(0.9996, 0.7931, 0.0013);
    table[588] = vec3(1.0091, 0.7812, 0.0012);
    table[589] = vec3(1.0181, 0.7692, 0.0012);
    table[590] = vec3(1.0263, 0.7570, 0.0011);
    table[591] = vec3(1.0340, 0.7448, 0.0011);
    table[592] = vec3(1.0410, 0.7324, 0.0011);
    table[593] = vec3(1.0471, 0.7200, 0.0010);
    table[594] = vec3(1.0524, 0.7075, 0.0010);
    table[595] = vec3(1.0567, 0.6949, 0.0010);
    table[596] = vec3(1.0597, 0.6822, 0.0010);
    table[597] = vec3(1.0617, 0.6695, 0.0009);
    table[598] = vec3(1.0628, 0.6567, 0.0009);
    table[599] = vec3(1.0630, 0.6439, 0.0008);
    table[600] = vec3(1.0622, 0.6310, 0.0008);
    table[601] = vec3(1.0608, 0.6182, 0.0008);
    table[602] = vec3(1.0585, 0.6053, 0.0007);
    table[603] = vec3(1.0552, 0.5925, 0.0007);
    table[604] = vec3(1.0509, 0.5796, 0.0006);
    table[605] = vec3(1.0456, 0.5668, 0.0006);
    table[606] = vec3(1.0389, 0.5540, 0.0005);
    table[607] = vec3(1.0313, 0.5411, 0.0005);
    table[608] = vec3(1.0226, 0.5284, 0.0004);
    table[609] = vec3(1.0131, 0.5157, 0.0004);
    table[610] = vec3(1.0026, 0.5030, 0.0003);
    table[611] = vec3(0.9914, 0.4905, 0.0003);
    table[612] = vec3(0.9794, 0.4781, 0.0003);
    table[613] = vec3(0.9665, 0.4657, 0.0003);
    table[614] = vec3(0.9529, 0.4534, 0.0003);
    table[615] = vec3(0.9384, 0.4412, 0.0002);
    table[616] = vec3(0.9232, 0.4291, 0.0002);
    table[617] = vec3(0.9072, 0.4170, 0.0002);
    table[618] = vec3(0.8904, 0.4050, 0.0002);
    table[619] = vec3(0.8728, 0.3930, 0.0002);
    table[620] = vec3(0.8544, 0.3810, 0.0002);
    table[621] = vec3(0.8349, 0.3689, 0.0002);
    table[622] = vec3(0.8148, 0.3568, 0.0002);
    table[623] = vec3(0.7941, 0.3447, 0.0001);
    table[624] = vec3(0.7729, 0.3328, 0.0001);
    table[625] = vec3(0.7514, 0.3210, 0.0001);
    table[626] = vec3(0.7296, 0.3094, 0.0001);
    table[627] = vec3(0.7077, 0.2979, 0.0001);
    table[628] = vec3(0.6858, 0.2867, 0.0001);
    table[629] = vec3(0.6640, 0.2757, 0.0001);
    table[630] = vec3(0.6424, 0.2650, 0.0000);
    table[631] = vec3(0.6217, 0.2548, 0.0000);
    table[632] = vec3(0.6013, 0.2450, 0.0000);
    table[633] = vec3(0.5812, 0.2354, 0.0000);
    table[634] = vec3(0.5614, 0.2261, 0.0000);
    table[635] = vec3(0.5419, 0.2170, 0.0000);
    table[636] = vec3(0.5226, 0.2081, 0.0000);
    table[637] = vec3(0.5035, 0.1995, 0.0000);
    table[638] = vec3(0.4847, 0.1911, 0.0000);
    table[639] = vec3(0.4662, 0.1830, 0.0000);
    table[640] = vec3(0.4479, 0.1750, 0.0000);
    table[641] = vec3(0.4298, 0.1672, 0.0000);
    table[642] = vec3(0.4121, 0.1596, 0.0000);
    table[643] = vec3(0.3946, 0.1523, 0.0000);
    table[644] = vec3(0.3775, 0.1451, 0.0000);
    table[645] = vec3(0.3608, 0.1382, 0.0000);
    table[646] = vec3(0.3445, 0.1315, 0.0000);
    table[647] = vec3(0.3286, 0.1250, 0.0000);
    table[648] = vec3(0.3131, 0.1188, 0.0000);
    table[649] = vec3(0.2980, 0.1128, 0.0000);
    table[650] = vec3(0.2835, 0.1070, 0.0000);
    table[651] = vec3(0.2696, 0.1015, 0.0000);
    table[652] = vec3(0.2562, 0.0962, 0.0000);
    table[653] = vec3(0.2432, 0.0911, 0.0000);
    table[654] = vec3(0.2307, 0.0863, 0.0000);
    table[655] = vec3(0.2187, 0.0816, 0.0000);
    table[656] = vec3(0.2071, 0.0771, 0.0000);
    table[657] = vec3(0.1959, 0.0728, 0.0000);
    table[658] = vec3(0.1852, 0.0687, 0.0000);
    table[659] = vec3(0.1748, 0.0648, 0.0000);
    table[660] = vec3(0.1649, 0.0610, 0.0000);
    table[661] = vec3(0.1554, 0.0574, 0.0000);
    table[662] = vec3(0.1462, 0.0539, 0.0000);
    table[663] = vec3(0.1375, 0.0507, 0.0000);
    table[664] = vec3(0.1291, 0.0475, 0.0000);
    table[665] = vec3(0.1212, 0.0446, 0.0000);
    table[666] = vec3(0.1136, 0.0418, 0.0000);
    table[667] = vec3(0.1065, 0.0391, 0.0000);
    table[668] = vec3(0.0997, 0.0366, 0.0000);
    table[669] = vec3(0.0934, 0.0342, 0.0000);
    table[670] = vec3(0.0874, 0.0320, 0.0000);
    table[671] = vec3(0.0819, 0.0300, 0.0000);
    table[672] = vec3(0.0768, 0.0281, 0.0000);
    table[673] = vec3(0.0721, 0.0263, 0.0000);
    table[674] = vec3(0.0677, 0.0247, 0.0000);
    table[675] = vec3(0.0636, 0.0232, 0.0000);
    table[676] = vec3(0.0598, 0.0218, 0.0000);
    table[677] = vec3(0.0563, 0.0205, 0.0000);
    table[678] = vec3(0.0529, 0.0193, 0.0000);
    table[679] = vec3(0.0498, 0.0181, 0.0000);
    table[680] = vec3(0.0468, 0.0170, 0.0000);
    table[681] = vec3(0.0437, 0.0159, 0.0000);
    table[682] = vec3(0.0408, 0.0148, 0.0000);
    table[683] = vec3(0.0380, 0.0138, 0.0000);
    table[684] = vec3(0.0354, 0.0128, 0.0000);
    table[685] = vec3(0.0329, 0.0119, 0.0000);
    table[686] = vec3(0.0306, 0.0111, 0.0000);
    table[687] = vec3(0.0284, 0.0103, 0.0000);
    table[688] = vec3(0.0264, 0.0095, 0.0000);
    table[689] = vec3(0.0245, 0.0088, 0.0000);
    table[690] = vec3(0.0227, 0.0082, 0.0000);
    table[691] = vec3(0.0211, 0.0076, 0.0000);
    table[692] = vec3(0.0196, 0.0071, 0.0000);
    table[693] = vec3(0.0182, 0.0066, 0.0000);
    table[694] = vec3(0.0170, 0.0061, 0.0000);
    table[695] = vec3(0.0158, 0.0057, 0.0000);
    table[696] = vec3(0.0148, 0.0053, 0.0000);
    table[697] = vec3(0.0138, 0.0050, 0.0000);
    table[698] = vec3(0.0129, 0.0047, 0.0000);
    table[699] = vec3(0.0121, 0.0044, 0.0000);
    table[700] = vec3(0.0114, 0.0041, 0.0000);
    table[701] = vec3(0.0106, 0.0038, 0.0000);
    table[702] = vec3(0.0099, 0.0036, 0.0000);
    table[703] = vec3(0.0093, 0.0034, 0.0000);
    table[704] = vec3(0.0087, 0.0031, 0.0000);
    table[705] = vec3(0.0081, 0.0029, 0.0000);
    table[706] = vec3(0.0076, 0.0027, 0.0000);
    table[707] = vec3(0.0071, 0.0026, 0.0000);
    table[708] = vec3(0.0066, 0.0024, 0.0000);
    table[709] = vec3(0.0062, 0.0022, 0.0000);
    table[710] = vec3(0.0058, 0.0021, 0.0000);
    table[711] = vec3(0.0054, 0.0020, 0.0000);
    table[712] = vec3(0.0051, 0.0018, 0.0000);
    table[713] = vec3(0.0047, 0.0017, 0.0000);
    table[714] = vec3(0.0044, 0.0016, 0.0000);
    table[715] = vec3(0.0041, 0.0015, 0.0000);
    table[716] = vec3(0.0038, 0.0014, 0.0000);
    table[717] = vec3(0.0036, 0.0013, 0.0000);
    table[718] = vec3(0.0033, 0.0012, 0.0000);
    table[719] = vec3(0.0031, 0.0011, 0.0000);
    table[720] = vec3(0.0029, 0.0010, 0.0000);
    table[721] = vec3(0.0027, 0.0010, 0.0000);
    table[722] = vec3(0.0025, 0.0009, 0.0000);
    table[723] = vec3(0.0024, 0.0008, 0.0000);
    table[724] = vec3(0.0022, 0.0008, 0.0000);
    table[725] = vec3(0.0020, 0.0007, 0.0000);
    table[726] = vec3(0.0019, 0.0007, 0.0000);
    table[727] = vec3(0.0018, 0.0006, 0.0000);
    table[728] = vec3(0.0017, 0.0006, 0.0000);
    table[729] = vec3(0.0015, 0.0006, 0.0000);
    table[730] = vec3(0.0014, 0.0005, 0.0000);
    table[731] = vec3(0.0013, 0.0005, 0.0000);
    table[732] = vec3(0.0012, 0.0004, 0.0000);
    table[733] = vec3(0.0012, 0.0004, 0.0000);
    table[734] = vec3(0.0011, 0.0004, 0.0000);
    table[735] = vec3(0.0010, 0.0004, 0.0000);
    table[736] = vec3(0.0009, 0.0003, 0.0000);
    table[737] = vec3(0.0009, 0.0003, 0.0000);
    table[738] = vec3(0.0008, 0.0003, 0.0000);
    table[739] = vec3(0.0007, 0.0003, 0.0000);
    table[740] = vec3(0.0007, 0.0002, 0.0000);
    table[741] = vec3(0.0006, 0.0002, 0.0000);
    table[742] = vec3(0.0006, 0.0002, 0.0000);
    table[743] = vec3(0.0006, 0.0002, 0.0000);
    table[744] = vec3(0.0005, 0.0002, 0.0000);
    table[745] = vec3(0.0005, 0.0002, 0.0000);
    table[746] = vec3(0.0004, 0.0002, 0.0000);
    table[747] = vec3(0.0004, 0.0001, 0.0000);
    table[748] = vec3(0.0004, 0.0001, 0.0000);
    table[749] = vec3(0.0004, 0.0001, 0.0000);
    table[750] = vec3(0.0003, 0.0001, 0.0000);
    table[751] = vec3(0.0003, 0.0001, 0.0000);
    table[752] = vec3(0.0003, 0.0001, 0.0000);
    table[753] = vec3(0.0003, 0.0001, 0.0000);
    table[754] = vec3(0.0003, 0.0001, 0.0000);
    table[755] = vec3(0.0002, 0.0001, 0.0000);
    table[756] = vec3(0.0002, 0.0001, 0.0000);
    table[757] = vec3(0.0002, 0.0001, 0.0000);
    table[758] = vec3(0.0002, 0.0001, 0.0000);
    table[759] = vec3(0.0002, 0.0001, 0.0000);
    table[760] = vec3(0.0002, 0.0001, 0.0000);
    table[761] = vec3(0.0002, 0.0001, 0.0000);
    table[762] = vec3(0.0001, 0.0001, 0.0000);
    table[763] = vec3(0.0001, 0.0000, 0.0000);
    table[764] = vec3(0.0001, 0.0000, 0.0000);
    table[765] = vec3(0.0001, 0.0000, 0.0000);
    table[766] = vec3(0.0001, 0.0000, 0.0000);
    table[767] = vec3(0.0001, 0.0000, 0.0000);
    table[768] = vec3(0.0001, 0.0000, 0.0000);
    table[769] = vec3(0.0001, 0.0000, 0.0000);
    table[770] = vec3(0.0001, 0.0000, 0.0000);
    table[771] = vec3(0.0001, 0.0000, 0.0000);
    table[772] = vec3(0.0001, 0.0000, 0.0000);
    table[773] = vec3(0.0001, 0.0000, 0.0000);
    table[774] = vec3(0.0001, 0.0000, 0.0000);
    table[775] = vec3(0.0001, 0.0000, 0.0000);
    table[776] = vec3(0.0001, 0.0000, 0.0000);
    table[777] = vec3(0.0001, 0.0000, 0.0000);
    table[778] = vec3(0.0000, 0.0000, 0.0000);
    table[779] = vec3(0.0000, 0.0000, 0.0000);
    table[780] = vec3(0.0000, 0.0000, 0.0000);
}