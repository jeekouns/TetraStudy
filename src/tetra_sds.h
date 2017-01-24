/* tetra_sds.h - SDS helper stuff
 * 
 *
 * (C) 2014-2015 by Jacek Lipkowski <sq5bpf@lipkowski.org>
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <stdint.h>


#ifndef HAVE_TETRA_SDS_H
#define HAVE_TETRA_SDS_H

/* Table 29.21: Protocol identifier information element contents */
enum tetra_sds_protoid {
	/* These are from the ETSI Tetra specification */
	TETRA_SDS_PROTO_RESERVED	  = 0x00,
	TETRA_SDS_PROTO_OTAK       		= 0x01,
	TETRA_SDS_PROTO_SIMPLE_TXTMSG            = 0x02,
	TETRA_SDS_PROTO_SIMPLE_LOC            = 0x03,
	TETRA_SDS_PROTO_WAP            = 0x04,
	TETRA_SDS_PROTO_WCMP            = 0x05,
	TETRA_SDS_PROTO_MDMO            = 0x06,
	TETRA_SDS_PROTO_PINAUTH            = 0x07,
	TETRA_SDS_PROTO_EEENCR            = 0x08,
	TETRA_SDS_PROTO_SIMPLE_ITXTMSG            = 0x09,
	TETRA_SDS_PROTO_LIP            = 0x0a,
	TETRA_SDS_PROTO_NAP            = 0x0b,
	TETRA_SDS_PROTO_CONCAT_SDS            = 0x0c,
	TETRA_SDS_PROTO_DOTAM            = 0x0d,
	TETRA_SDS_PROTO_TXTMSG            = 0x82,
	TETRA_SDS_PROTO_LOCSYSTEM            = 0x83,
	TETRA_SDS_PROTO_WAP2            = 0x84,
	TETRA_SDS_PROTO_WCMP2            = 0x85,
	TETRA_SDS_PROTO_MDMO2            = 0x86,
	TETRA_SDS_PROTO_EEENCR2            = 0x88,
	TETRA_SDS_PROTO_ITXTMSG            = 0x89,
	TETRA_SDS_PROTO_MSMUSERHEAD            = 0x8a,
	TETRA_SDS_PROTO_CONCAT_SDS2            = 0x8c,

	/* Company-registered SDS protocol identifiers from 
	 * http://www.etsi.org/WebSite/document/SDS%20TL-Protocol-%20Identifiers.xls
	 * theoretically they are valid only when there is an SDS-TL header 
	 * is present (or at least the filename suggests this)
	 */
	TETRA_SDS_PROTO_TELTRONIC1 = 0x40 /* Teltronic */, 
	TETRA_SDS_PROTO_NOKIA1 = 0x41 /* Nokia */, 
	TETRA_SDS_PROTO_THALES1 = 0x42 /* Thales */, 
	TETRA_SDS_PROTO_TETRAMOU1 = 0x43 /* Tetra MoU */, 
	TETRA_SDS_PROTO_BICK1 = 0x44 /* R&S Bick Mobilfunk GmbH */, 
	TETRA_SDS_PROTO_BICK2 = 0x45 /* R&S Bick Mobilfunk GmbH */, 
	TETRA_SDS_PROTO_EADS1 = 0x46 /* EADS Secure Networks Oy */, 
	TETRA_SDS_PROTO_THALES2= 0x47 /* Thales UK */, 
	TETRA_SDS_PROTO_THORCOM1 = 0x49 /* Thorcom Systems Ltd */, 
	TETRA_SDS_PROTO_PMR1 = 0x4a /* PMR-R&D GmbH */, 
	TETRA_SDS_PROTO_RHEINMETALL1 = 0x50 /* Rheinmetall defence GmbH */, 
	TETRA_SDS_PROTO_TELTRONIC2 = 0xc0 /* Teltronic */, 
	TETRA_SDS_PROTO_TETRAMOU2 = 0xc1 /* Tetra Mou */, 
	TETRA_SDS_PROTO_EADS2 = 0xc2 /* EADS Secure Networks Oy */, 
	TETRA_SDS_PROTO_TETRAASS1 = 0xc3 /* Tetra Association */, 
	TETRA_SDS_PROTO_AIRWAVE1 = 0xc4 /* Airwave Solutions Ltd */, 
	TETRA_SDS_PROTO_AIRWAVE2 = 0xc5 /* Airwave Solutions Ltd */, 
	TETRA_SDS_PROTO_APD1 = 0xc6 /* APD Communications Ltd */, 
	TETRA_SDS_PROTO_SEPURA1 = 0xc8 /* Sepura Ltd */, 
	TETRA_SDS_PROTO_SEPURA2 = 0xc9 /* Sepura Ltd */, 
	TETRA_SDS_PROTO_RHEINMETALL2 = 0xd0 /* Rheinmetall defence GmbH */, 
	TETRA_SDS_PROTO_SEPURA3 = 0xd2 /* Sepura Ltd */, 
	TETRA_SDS_PROTO_MOTOROLA1 = 0xdc /* Motorola A/s */, 
	TETRA_SDS_PROTO_MOTOROLA2 = 0xdd /* Motorola A/s */, 
	TETRA_SDS_PROTO_MOTOROLA3 = 0xde /* Motorola A/s */, 
	TETRA_SDS_PROTO_MOTOROLA4 = 0xdf /* Motorola A/s */, 
	TETRA_SDS_PROTO_MOTOROLA5 = 0xe0 /* Motorola A/s */, 
	TETRA_SDS_PROTO_TERRAFIX1 = 0xe1 /* TERRAFIX Ltd */, 
	TETRA_SDS_PROTO_TERRAFIX2 = 0xe2 /* TERRAFIX Ltd */, 
	TETRA_SDS_PROTO_TERRAFIX3 = 0xe3 /* TERRAFIX Ltd */, 
	TETRA_SDS_PROTO_MOTOROLA6 = 0xe6 /* Motorola A/s */, 
	TETRA_SDS_PROTO_SEPURA4 = 0xec /* Sepura Plc. */, 
	TETRA_SDS_PROTO_3TC1 = 0xed /* 3tc Software Ltd */, 
	TETRA_SDS_PROTO_3TC2 = 0xee /* 3tc Software Ltd */, 
	TETRA_SDS_PROTO_MOTOROLA7 = 0xf0 /* Motorola A/s */, 
	TETRA_SDS_PROTO_THORCOM2 = 0xf4 /* Thorcom Systems Ltd. */, 
	TETRA_SDS_PROTO_THALES3 = 0xfa /* Thales UK LTD */, 

};


struct sds_type {
	uint8_t type;
	char * description;
};
static const struct sds_type sds_types[]=
{
	/* These are from the ETSI Tetra specification */
	{ TETRA_SDS_PROTO_RESERVED , "Reserved" },
	{ TETRA_SDS_PROTO_OTAK , "OTAK" },
	{ TETRA_SDS_PROTO_SIMPLE_TXTMSG , "Simple Text Messaging" },
	{ TETRA_SDS_PROTO_SIMPLE_LOC , "Simple location system" },
	{ TETRA_SDS_PROTO_WAP , "Wireless Datagram Protocol WAP" },
	{ TETRA_SDS_PROTO_WCMP , "Wireless Control Message Protocol WCMP" },
	{ TETRA_SDS_PROTO_MDMO , "M-DMO" },
	{ TETRA_SDS_PROTO_PINAUTH , "PIN authentication" },
	{ TETRA_SDS_PROTO_EEENCR , "End-to-end encrypted message" },
	{ TETRA_SDS_PROTO_SIMPLE_ITXTMSG , "Simple immediate text messaging" },
	{ TETRA_SDS_PROTO_LIP , "Location information protocol" },
	{ TETRA_SDS_PROTO_NAP , "Net Assist Protocol (NAP)" },
	{ TETRA_SDS_PROTO_CONCAT_SDS , "Concatenated SDS message" },
	{ TETRA_SDS_PROTO_DOTAM , "DOTAM, refer to TS 100 392-18-3" },
	{ TETRA_SDS_PROTO_TXTMSG , "Text Messaging" },
	{ TETRA_SDS_PROTO_LOCSYSTEM , "Location system" },
	{ TETRA_SDS_PROTO_WAP2 , "Wireless Datagram Protocol WAP" },
	{ TETRA_SDS_PROTO_WCMP2 , "Wireless Control Message Protocol WCMP" },
	{ TETRA_SDS_PROTO_MDMO2 , "M-DMO" },
	{ TETRA_SDS_PROTO_EEENCR2 , "End-to-end encrypted message" },
	{ TETRA_SDS_PROTO_ITXTMSG , "Immediate text messaging" },
	{ TETRA_SDS_PROTO_MSMUSERHEAD , "Message with User Data Header" },
	{ TETRA_SDS_PROTO_CONCAT_SDS2 , "Concatenated SDS message" },

	/* http://www.etsi.org/WebSite/document/SDS%20TL-Protocol-%20Identifiers.xls */
	{ TETRA_SDS_PROTO_TELTRONIC1, "Teltronic" },
	{ TETRA_SDS_PROTO_NOKIA1, "Nokia" },
	{ TETRA_SDS_PROTO_THALES1, "Thales" },
	{ TETRA_SDS_PROTO_TETRAMOU1, "Tetra MoU" },
	{ TETRA_SDS_PROTO_BICK1, "R&S Bick Mobilfunk GmbH" },
	{ TETRA_SDS_PROTO_BICK2, "R&S Bick Mobilfunk GmbH" },
	{ TETRA_SDS_PROTO_EADS1, "EADS Secure Networks Oy" },
	{ TETRA_SDS_PROTO_THALES2, "Thales UK" },
	{ TETRA_SDS_PROTO_THORCOM1, "Thorcom Systems Ltd" },
	{ TETRA_SDS_PROTO_PMR1, "PMR-R&D GmbH" },
	{ TETRA_SDS_PROTO_RHEINMETALL1, "Rheinmetall defence GmbH" },
	{ TETRA_SDS_PROTO_TELTRONIC2, "Teltronic" },
	{ TETRA_SDS_PROTO_TETRAMOU2, "Tetra Mou" },
	{ TETRA_SDS_PROTO_EADS2, "EADS Secure Networks Oy" },
	{ TETRA_SDS_PROTO_TETRAASS1, "Tetra Association" },
	{ TETRA_SDS_PROTO_AIRWAVE1, "Airwave Solutions Ltd" },
	{ TETRA_SDS_PROTO_AIRWAVE2, "Airwave Solutions Ltd" },
	{ TETRA_SDS_PROTO_APD1, "APD Communications Ltd" },
	{ TETRA_SDS_PROTO_SEPURA1, "Sepura Ltd" },
	{ TETRA_SDS_PROTO_SEPURA2, "Sepura Ltd" },
	{ TETRA_SDS_PROTO_RHEINMETALL2, "Rheinmetall defence GmbH" },
	{ TETRA_SDS_PROTO_SEPURA3, "Sepura Ltd" },
	{ TETRA_SDS_PROTO_MOTOROLA1, "Motorola A/s" },
	{ TETRA_SDS_PROTO_MOTOROLA2, "Motorola A/s" },
	{ TETRA_SDS_PROTO_MOTOROLA3, "Motorola A/s" },
	{ TETRA_SDS_PROTO_MOTOROLA4, "Motorola A/s" },
	{ TETRA_SDS_PROTO_MOTOROLA5, "Motorola A/s" },
	{ TETRA_SDS_PROTO_TERRAFIX1, "TERRAFIX Ltd" },
	{ TETRA_SDS_PROTO_TERRAFIX2, "TERRAFIX Ltd" },
	{ TETRA_SDS_PROTO_TERRAFIX3, "TERRAFIX Ltd" },
	{ TETRA_SDS_PROTO_MOTOROLA6, "Motorola A/s" },
	{ TETRA_SDS_PROTO_SEPURA4, "Sepura Plc." },
	{ TETRA_SDS_PROTO_3TC1, "3tc Software Ltd" },
	{ TETRA_SDS_PROTO_3TC2, "3tc Software Ltd" },
	{ TETRA_SDS_PROTO_MOTOROLA7, "Motorola A/s" },
	{ TETRA_SDS_PROTO_THORCOM2, "Thorcom Systems Ltd." },
	{ TETRA_SDS_PROTO_THALES3, "Thales UK LTD" },
	{ 0x0,0 }
};

char *get_sds_type(uint8_t type);
int decode_pdu(char *dec,unsigned char *enc,int len);


/*************   LIP   ****************/
/* LIP direction  of travel */
enum tetra_lip_dirtravelid {
	TETRA_LIP_DIRTRAVEL_N = 0 ,
	TETRA_LIP_DIRTRAVEL_NNE = 1 ,
	TETRA_LIP_DIRTRAVEL_NE = 2 ,
	TETRA_LIP_DIRTRAVEL_ENE = 3 ,
	TETRA_LIP_DIRTRAVEL_E = 4 ,
	TETRA_LIP_DIRTRAVEL_ESE = 5 ,
	TETRA_LIP_DIRTRAVEL_SE = 6 ,
	TETRA_LIP_DIRTRAVEL_SSE = 7 ,
	TETRA_LIP_DIRTRAVEL_S = 8 ,
	TETRA_LIP_DIRTRAVEL_SSW = 9 ,
	TETRA_LIP_DIRTRAVEL_SW = 10 ,
	TETRA_LIP_DIRTRAVEL_WSW = 11 ,
	TETRA_LIP_DIRTRAVEL_W = 12 ,
	TETRA_LIP_DIRTRAVEL_WNW = 13 ,
	TETRA_LIP_DIRTRAVEL_NW = 14 ,
	TETRA_LIP_DIRTRAVEL_NNW = 15 
};
struct lip_dirtravel_type {
	uint8_t type;
	char * description;
};
static const struct lip_dirtravel_type lip_dirtravel_types[]=
{
	{ TETRA_LIP_DIRTRAVEL_N , "N" },
	{ TETRA_LIP_DIRTRAVEL_NNE , "NNE" },
	{ TETRA_LIP_DIRTRAVEL_NE , "NE" },
	{ TETRA_LIP_DIRTRAVEL_ENE , "ENE" },
	{ TETRA_LIP_DIRTRAVEL_E , "E" },
	{ TETRA_LIP_DIRTRAVEL_ESE , "ESE" },
	{ TETRA_LIP_DIRTRAVEL_SE , "SE" },
	{ TETRA_LIP_DIRTRAVEL_SSE , "SSE" },
	{ TETRA_LIP_DIRTRAVEL_S , "S" },
	{ TETRA_LIP_DIRTRAVEL_SSW , "SSW" },
	{ TETRA_LIP_DIRTRAVEL_SW , "SW" },
	{ TETRA_LIP_DIRTRAVEL_WSW , "WSW" },
	{ TETRA_LIP_DIRTRAVEL_W , "W" },
	{ TETRA_LIP_DIRTRAVEL_WNW , "WNW" },
	{ TETRA_LIP_DIRTRAVEL_NW , "NW" },
	{ TETRA_LIP_DIRTRAVEL_NNW , "NNW" },
	{ 0x0,0 }
};

static const char* const  lip_position_errors[]={ "<2m", "<20m", "<200m", "<2km", "<20km", "=<200km", ">200km", "unknown" };


enum tetra_lip_longpduexttypes {
	TETRA_LIP_LONGPDUEXT_IMMLOCREPREQ = 1,
	TETRA_LIP_LONGPDUEXT_LONGLOCREP = 3,
	TETRA_LIP_LONGPDUEXT_LOCREPACK = 4,
	TETRA_LIP_LONGPDUEXT_BASICLOCREPREQ = 5,
	TETRA_LIP_LONGPDUEXT_MODTRIGGER = 6,
	TETRA_LIP_LONGPDUEXT_REMTRIGGER = 7,
	TETRA_LIP_LONGPDUEXT_REPTRIGGER = 8,
	TETRA_LIP_LONGPDUEXT_REPBASICLOC = 9,
	TETRA_LIP_LONGPDUEXT_LOCREPORENABLE = 10,
	TETRA_LIP_LONGPDUEXT_LOCREPORTTMPCONTROL = 11,
	TETRA_LIP_LONGPDUEXT_BACKLOGREQRESP = 12
};
static const char* const  lip_longpdu_extensions[]={ 
	"Reserved_0", /* 0 */
	"Immediate location report request", /* 1 */
	"Reserved_2", /* 2 */
	"Long location report", /* 3 */
	"Location report acknowledgement", /* 4 */
	"Basic location parameters request/response", /* 5 */
	"Add/modify trigger request/response", /* 6 */
	"Remove trigger request/response", /* 7 */
	"Report trigger request/response", /* 8 */
	"Report basic location parameters request/response", /* 9 */
	"Location reporting enable/disable request/response", /* 10 */
	"Location reporting temporary control request/response", /* 11 */
	"Backlog request/response", /* 12 */
	"Reserved_13", /* 13 */
	"Reserved_14", /* 14 */
	"Reserved_15" /* 15 */ }; 

/* Table 6.79: Location shape information element contents */
enum tetra_lip_locshapetypes {
	TETRA_LIP_SHAPE_NOSHAPE = 0,
	TETRA_LIP_SHAPE_POINT = 1,
	TETRA_LIP_SHAPE_CIRCLE = 2,
	TETRA_LIP_SHAPE_ELLIPSE = 3,
	TETRA_LIP_SHAPE_POINT_ALTITUDE = 4,
	TETRA_LIP_SHAPE_CIRCLE_ALTITUDE = 5,
	TETRA_LIP_SHAPE_ELLIPSE_ALTITUDE = 6,
	TETRA_LIP_SHAPE_CIRCLE_ALTITUDE_ALTUNC = 7,
	TETRA_LIP_SHAPE_ARC = 9,
	TETRA_LIP_SHAPE_POINT_POSERR = 10,
	TETRA_LIP_SHAPE_RESERVED11 = 11,
	TETRA_LIP_SHAPE_RESERVED12 = 12,
	TETRA_LIP_SHAPE_RESERVED13 = 13,
	TETRA_LIP_SHAPE_RESERVED15 = 14,
	TETRA_LIP_SHAPE_LOCSHAPE_EXTENSION = 15
};

/* Table 6.124: Velocity type information element contents */
enum tetra_lip_velocitytypes {
	TETRA_LIP_VELOCITY_NONE = 0,
	TETRA_LIP_VELOCITY_HORIZ_VELOCITY = 1,
	TETRA_LIP_VELOCITY_HORIZ_VELOCITY_UNC = 2,
	TETRA_LIP_VELOCITY_HORIZ_VELOCITY_VERT = 3,
	TETRA_LIP_VELOCITY_HORIZ_VELOCITY_VERT_UNC = 4,
	TETRA_LIP_VELOCITY_HORIZ_VELOCITY_DIRTRAVEL = 5,
	TETRA_LIP_VELOCITY_HORIZ_VELOCITY_DIRTRAVEL_UNC = 6,
	TETRA_LIP_VELOCITY_HORIZ_VELOCITY_VERT_DIRTRAVEL_UNC = 7

};

unsigned int parse_d_sds_data(struct tetra_mac_state *tms, struct msgb *msg, unsigned int len);


int decode_lip(char *out, int outlen,uint8_t *bits,int datalen);

/**************   Location System   **************/
int decode_locsystem(char *out, int outlen,uint8_t *bits,int datalen);
int decode_simplelocsystem(char *out, int outlen,uint8_t *bits,int datalen);

#endif
