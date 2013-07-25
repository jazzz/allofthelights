#ifndef NEUMARK_MACROS_H
#define NEUMARK_MACROS_H


//

//States
#define BUTTON_DOWN 127
#define BUTTON_UP     0


//ControlMappings

#define DIAL_GAIN_L			13
#define DIAL_TREBLE_L		16
#define DIAL_MID_L			18
#define DIAL_BASS_L 		20

#define DIAL_GAIN_R			14
#define DIAL_TREBLE_R		17
#define DIAL_MID_R			19
#define DIAL_BASS_R 		21		

#define JOG_L				24
#define JOG_R				25

#define INSIDE_SLIDER_L		8
#define INSIDE_SLIDER_R		9

#define OUTSIDE_SLIDER_L	11
#define OUTSIDE_SLIDER_R	12

#define DIAL_TRACK			26
#define BUTTON_LOADTRACK_L	75
#define BUTTON_LOADTRACK_R	52
#define BUTTON_PAGE			72


inline bool isTrebleDial(uint8_t control){
	return (control == DIAL_TREBLE_L || control == DIAL_TREBLE_R) ;
}
inline bool isMidDial(uint8_t control){
	return (control == DIAL_MID_L || control == DIAL_MID_R) ;
}
inline bool isBassDial(uint8_t control){
	return (control == DIAL_BASS_L || control == DIAL_BASS_R) ;
}
inline bool isOutsideSlider(uint8_t control){
	return (control == OUTSIDE_SLIDER_L || control == OUTSIDE_SLIDER_R) ;
}
inline bool isInsideSlider(uint8_t control){
	return (control == INSIDE_SLIDER_L || control == INSIDE_SLIDER_R) ;
}
inline bool isJogWheel(uint8_t control){
	return (control == JOG_L || control == JOG_R) ;
}

// Location 
#define LEFT 1
#define RIGHT 3
#define CENTER 0
#define DNE 2

const uint8_t locationMap[] = {
LEFT,	// 0
LEFT,	// 1
LEFT,	// 2
LEFT,	// 3
RIGHT,	// 4
RIGHT,	// 5
RIGHT,	// 6
RIGHT,	// 7
LEFT,	// 8
RIGHT,	// 9
CENTER,	// 10
LEFT,	// 11
RIGHT,	// 12
LEFT,	// 13
RIGHT,	// 14
CENTER,	// 15
LEFT,	// 16
RIGHT,	// 17
LEFT,	// 18
RIGHT,	// 19
LEFT,	// 20
RIGHT,	// 21
CENTER,	// 22
CENTER,	// 23
LEFT,	// 24
RIGHT,	// 25
CENTER,	// 26
DNE,	// 27
DNE,	// 28
DNE,	// 29
DNE,	// 30
DNE,	// 31
DNE,	// 32
DNE,	// 33
DNE,	// 34
DNE,	// 35
DNE,	// 36
DNE,	// 37
DNE,	// 38
DNE,	// 39
DNE,	// 40
DNE,	// 41
DNE,	// 42
DNE,	// 43
DNE,	// 44
DNE,	// 45
DNE,	// 46
DNE,	// 47
LEFT,	// 48
LEFT,	// 49
LEFT,	// 50
LEFT,	// 51
CENTER,	// 52
RIGHT,	// 53
RIGHT,	// 54
RIGHT,	// 55
LEFT,	// 56
LEFT,	// 57
LEFT,	// 58
LEFT,	// 59
RIGHT,	// 60
RIGHT,	// 61
RIGHT,	// 62
RIGHT,	// 63
LEFT,	// 64
LEFT,	// 65
LEFT,	// 66
LEFT,	// 67
RIGHT,	// 68
RIGHT,	// 69
RIGHT,	// 70
RIGHT,	// 71
CENTER,	// 72
LEFT,	// 73
LEFT,	// 74
CENTER,	// 75
RIGHT,	// 76
RIGHT,	// 77
RIGHT,	// 78
CENTER,	// 79
LEFT,	// 80
RIGHT,	// 81
RIGHT,	// 82
LEFT,	// 83
RIGHT,	// 84
LEFT,	// 85
DNE,	// 86
DNE,	// 87
DNE,	// 88
DNE,	// 89
DNE,	// 90
DNE,	// 91
DNE,	// 92
DNE,	// 93
DNE,	// 94
DNE,	// 95
DNE,	// 96
DNE,	// 97
DNE,	// 98
DNE,	// 99
DNE,	// 100
DNE,	// 101
DNE,	// 102
DNE,	// 103
DNE,	// 104
DNE,	// 105
DNE,	// 106
DNE,	// 107
DNE,	// 108
DNE,	// 109
DNE,	// 110
DNE,	// 111
DNE,	// 112
DNE,	// 113
DNE,	// 114
DNE,	// 115
DNE,	// 116
DNE,	// 117
DNE,	// 118
DNE,	// 119
DNE,	// 120
DNE,	// 121
DNE,	// 122
DNE,	// 123
DNE,	// 124
DNE,	// 125
DNE,	// 126
DNE,	// 127
DNE,	// 128
DNE,	// 129
DNE,	// 130
DNE,	// 131
DNE,	// 132
DNE,	// 133
DNE,	// 134
DNE,	// 135
DNE,	// 136
DNE,	// 137
DNE,	// 138
DNE,	// 139
DNE,	// 140
DNE,	// 141
DNE,	// 142
DNE,	// 143
DNE,	// 144
DNE,	// 145
DNE,	// 146
DNE,	// 147
DNE,	// 148
DNE,	// 149
DNE,	// 150
DNE,	// 151
DNE,	// 152
DNE,	// 153
DNE,	// 154
DNE,	// 155
DNE,	// 156
DNE,	// 157
DNE,	// 158
DNE,	// 159
DNE,	// 160
DNE,	// 161
DNE,	// 162
DNE,	// 163
DNE,	// 164
DNE,	// 165
DNE,	// 166
DNE,	// 167
DNE,	// 168
DNE,	// 169
DNE,	// 170
DNE,	// 171
DNE,	// 172
DNE,	// 173
DNE,	// 174
DNE,	// 175
DNE,	// 176
DNE,	// 177
DNE,	// 178
DNE,	// 179
DNE,	// 180
DNE,	// 181
DNE,	// 182
DNE,	// 183
DNE,	// 184
DNE,	// 185
DNE,	// 186
DNE,	// 187
DNE,	// 188
DNE,	// 189
DNE,	// 190
DNE,	// 191
DNE,	// 192
DNE,	// 193
DNE,	// 194
DNE,	// 195
DNE,	// 196
DNE,	// 197
DNE,	// 198
DNE,	// 199
DNE,	// 200
DNE,	// 201
DNE,	// 202
DNE,	// 203
DNE,	// 204
DNE,	// 205
DNE,	// 206
DNE,	// 207
DNE,	// 208
DNE,	// 209
DNE,	// 210
DNE,	// 211
DNE,	// 212
DNE,	// 213
DNE,	// 214
DNE,	// 215
DNE,	// 216
DNE,	// 217
DNE,	// 218
DNE,	// 219
DNE,	// 220
DNE,	// 221
DNE,	// 222
DNE,	// 223
DNE,	// 224
DNE,	// 225
DNE,	// 226
DNE,	// 227
DNE,	// 228
DNE,	// 229
DNE,	// 230
DNE,	// 231
DNE,	// 232
DNE,	// 233
DNE,	// 234
DNE,	// 235
DNE,	// 236
DNE,	// 237
DNE,	// 238
DNE,	// 239
DNE,	// 240
DNE,	// 241
DNE,	// 242
DNE,	// 243
DNE,	// 244
DNE,	// 245
DNE,	// 246
DNE,	// 247
DNE,	// 248
DNE,	// 249
DNE,	// 250
DNE,	// 251
DNE,	// 252
DNE,	// 253
DNE,	// 254
};

#define get_group(A) locationMap[A] 
// inline uint8_t get_group(uint8_t source){ 	// Shoudl be a marco Def
// 	return locationMap[source];
// }


#endif 