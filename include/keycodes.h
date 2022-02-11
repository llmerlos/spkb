#ifndef KEYCODES_H
#define KEYCODES_H

enum keycode_spec {
    KB_NOEV = 0x00, /* Reserved ( No event indicated) */
    KB_ERRO	= 0x01,	/* ErrorRollOver */
	KB_PSTF	= 0x02,	/* POSTFail */
	KB_ERUN	= 0x03,	/* ErrorUndefined */
	KB_A	= 0x04,	/* a or A */
	KB_B	= 0x05,	/* b or B */
	KB_C	= 0x06,	/* c or C */
	KB_D	= 0x07,	/* d or D */
	KB_E	= 0x08,	/* e or E */
	KB_F	= 0x09,	/* f or F */
	KB_G	= 0x0A,	/* g or G */
	KB_H	= 0x0B,	/* h or H */
	KB_I	= 0x0C,	/* i or I */
	KB_J	= 0x0D,	/* j or J */
	KB_K	= 0x0E,	/* k or K */
	KB_L	= 0x0F,	/* l or L */
	KB_M	= 0x10,	/* m or M */
	KB_N	= 0x11,	/* n or N */
	KB_O	= 0x12,	/* o or O */
	KB_P	= 0x13,	/* p or P */
	KB_Q	= 0x14,	/* q or Q */
	KB_R	= 0x15,	/* r or R */
	KB_S	= 0x16,	/* s or S */
	KB_T	= 0x17,	/* t or T */
	KB_U	= 0x18,	/* u or U */
	KB_V	= 0x19,	/* v or V */
	KB_W	= 0x1A,	/* w or W */
	KB_X	= 0x1B,	/* x or X */
	KB_Y	= 0x1C,	/* y or Y */
	KB_Z	= 0x1D,	/* z or Z */
	KB_1	= 0x1E,	/* 1 or ! */
	KB_2	= 0x1F,	/* 2 or @ */
	KB_3	= 0x20,	/* 3 or # */
	KB_4	= 0x21,	/* 4 or $ */
	KB_5	= 0x22,	/* 5 or % */
	KB_6	= 0x23,	/* 6 or ^ */
	KB_7	= 0x24,	/* 7 or & */
	KB_8	= 0x25,	/* 8 or * */
	KB_9	= 0x26,	/* 9 or ( */
	KB_0	= 0x27,	/* 0 or ) */
	KB_ENTR	= 0x28,	/* Return (Enter) */
	KB_ESCP	= 0x29,	/* Escape */
	KB_BCKS	= 0x2A,	/* Delete (Backspace) */
	KB_TAB 	= 0x2B,	/* Tab */
	KB_SPCB	= 0x2C,	/* Spacebar */
	KB_MINS	= 0x2D,	/* - or _ */
	KB_EQUL	= 0x2E,	/* = or + */
	KB_LBRC	= 0x2F,	/* [ or { */
	KB_RBRC	= 0x30,	/* ] or } */
	KB_BSLH	= 0x31,	/* \ or | */
	KB_NSHR	= 0x32,	/* Non-US # or _ */
	KB_SCLN	= 0x33,	/* ; or : */
	KB_APOS	= 0x34,	/* ' or " */
	KB_GRAC	= 0x35,	/* Grave Accent and Tilde */
	KB_CMMA	= 0x36,	/* , or < */
	KB_PERD	= 0x37,	/* . or > */
	KB_SLSH	= 0x38,	/* / or ? */
	KB_CLCK	= 0x39,	/* Caps Lock */
	KB_F1	= 0x3A,	/* F1 */
	KB_F2	= 0x3B,	/* F2 */
	KB_F3	= 0x3C,	/* F3 */
	KB_F4	= 0x3D,	/* F4 */
	KB_F5	= 0x3E,	/* F5 */
	KB_F6	= 0x3F,	/* F6 */
	KB_F7	= 0x40,	/* F7 */
	KB_F8	= 0x41,	/* F8 */
	KB_F9	= 0x42,	/* F9 */
	KB_F10	= 0x43,	/* F10 */
	KB_F11	= 0x44,	/* F11 */
	KB_F12	= 0x45,	/* F12 */
	KB_PRSC	= 0x46,	/* Print Screen */
	KB_SLCK	= 0x47,	/* Scroll Lock */
	KB_PAUS	= 0x48,	/* Pause */
	KB_INSR	= 0x49,	/* Insert */
	KB_HOME	= 0x4A,	/* Home */
	KB_PGUP	= 0x4B,	/* Page Up */
	KB_DLFW	= 0x4C,	/* Delete Forward */
	KB_END	= 0x4D,	/* End */
	KB_PGDW	= 0x4E,	/* Page Down */
	KB_RARR	= 0x4F,	/* Right Arrow */
	KB_LARR	= 0x50,	/* Left Arrow */
	KB_DARR	= 0x51,	/* Down Arrow */
	KB_UARR	= 0x52,	/* Up Arrow */
	KP_NLCK	= 0x53,	/* Keypad NumLock or Clear */
	KP_SLSH	= 0x54,	/* Keypad / */
	KP_ASTX	= 0x55,	/* Keypad * */
	KP_MINS	= 0x56,	/* Keypad - */
	KP_PLUS	= 0x57,	/* Keypad + */
	KP_ENTR	= 0x58,	/* Keypad Enter */
	KP_1	= 0x59,	/* Keypad 1 or End */
	KP_2	= 0x5A,	/* Keypad 2 or Down Arrow */
	KP_3	= 0x5B,	/* Keypad 3 or Page Down */
	KP_4	= 0x5C,	/* Keypad 4 or Left Arrow */
	KP_5	= 0x5D,	/* Keypad 5 */
	KP_6	= 0x5E,	/* Keypad 6 or Right Arrow */
	KP_7	= 0x5F,	/* Keypad 7 or Home */
	KP_8	= 0x60,	/* Keypad 8 or Up Arrow */
	KP_9	= 0x61,	/* Keypad 9 or Page Up */
	KP_0	= 0x62,	/* Keypad 0 or Insert */
	KP_PERD	= 0x63,	/* Keypad . or Delete */
	KB_NUBS	= 0x64,	/* Non-US \ or | */
	KB_APPL	= 0x65,	/* Application */
	KB_POWR	= 0x66,	/* Power */
	KP_EQUL	= 0x67,	/* Keypad = */
	KB_F13	= 0x68,	/* F13 */
	KB_F14	= 0x69,	/* F14 */
	KB_F15	= 0x6A,	/* F15 */
	KB_F16	= 0x6B,	/* F16 */
	KB_F17	= 0x6C,	/* F17 */
	KB_F18	= 0x6D,	/* F18 */
	KB_F19	= 0x6E,	/* F19 */
	KB_F20	= 0x6F,	/* F20 */
	KB_F21	= 0x70,	/* F21 */
	KB_F22	= 0x71,	/* F22 */
	KB_F23	= 0x72,	/* F23 */
	KB_F24	= 0x73,	/* F24 */
	KB_EXEC	= 0x74,	/* Execute */
	KB_HELP	= 0x75,	/* Help */
	KB_MENU	= 0x76,	/* Menu */
	KB_SLCT	= 0x77,	/* Select */
	KB_STOP	= 0x78,	/* Stop */
	KB_AGIN	= 0x79,	/* Again */
	KB_UNDO	= 0x7A,	/* Undo */
	KB_CUT	= 0x7B,	/* Cut */
	KB_COPY	= 0x7C,	/* Copy */
	KB_PSTE	= 0x7D,	/* Paste */
	KB_FIND	= 0x7E,	/* Find */
	KB_MUTE	= 0x7F,	/* Mute */
	KB_VOUP	= 0x80,	/* Volume Up */
	KB_VODW	= 0x81,	/* Volume Down */
	KB_LCLC	= 0x82,	/* Locking Caps Lock */
	KB_LNLC	= 0x83,	/* Locking Num Lock */
	KB_LSLC	= 0x84,	/* Locking Scroll Lock */
	KP_CMMA	= 0x85,	/* Keypad Comma */
	KP_EQAS	= 0x86,	/* Keypad Equal Sign for AS/400 */
	KB_INT1	= 0x87,	/* International1 */
	KB_INT2	= 0x88,	/* International2 */
	KB_INT3	= 0x89,	/* International3 */
	KB_INT4	= 0x8A,	/* International4 */
	KB_INT5	= 0x8B,	/* International5 */
	KB_INT6	= 0x8C,	/* International6 */
	KB_INT7	= 0x8D,	/* International7 */
	KB_INT8	= 0x8E,	/* International8 */
	KB_INT9	= 0x8F,	/* International9 */
	KB_LNG1	= 0x90,	/* LANG1 */
	KB_LNG2	= 0x91,	/* LANG2 */
	KB_LNG3	= 0x92,	/* LANG3 */
	KB_LNG4	= 0x93,	/* LANG4 */
	KB_LNG5	= 0x94,	/* LANG5 */
	KB_LNG6	= 0x95,	/* LANG6 */
	KB_LNG7	= 0x96,	/* LANG7 */
	KB_LNG8	= 0x97,	/* LANG8 */
	KB_LNG9	= 0x98,	/* LANG9 */
	KB_ALER	= 0x99,	/* AlternateErase */
	KB_SYRQ	= 0x9A,	/* SysReq/Attention */
	KB_CNCL	= 0x9B,	/* Cancel */
	KB_CLAR	= 0x9C,	/* Clear */
	KB_PRIR	= 0x9D,	/* Prior */
	KB_RTRN	= 0x9E,	/* Return */
	KB_SEPR	= 0x9F,	/* Separator */
	KB_OUT	= 0xA0,	/* Out */
	KB_OPER	= 0xA1,	/* Oper */
	KB_CLAG	= 0xA2,	/* Clear/Again */
	KB_CRPR	= 0xA3,	/* CrSel/Props */
	KB_EXSL	= 0xA4,	/* ExSel */
	/* 0xA5-0xDF Reserved */
	KB_LCTL	= 0xE0,	/* Left Control */
	KB_LSHF	= 0xE1,	/* Left Shift */
	KB_LALT	= 0xE2,	/* Left Alt */
	KB_LGUI	= 0xE3,	/* Left GUI */
	KB_RCTL	= 0xE4,	/* Right Control */
	KB_RSHF	= 0xE5,	/* Right Shift */
	KB_RALT	= 0xE6,	/* Right Alt */
	KB_RGUI	= 0xE7,	/* Right GUI */
	/* 0xE8-0xFFFF Reserved */
	KB_RSRV = 0xFFFF
};

enum keycode_custom {
    KC_NTH = 0xE8, /* No Key */
    /* Layer Function Keys */
    KC_LFK1, /* Layer Function Key 1 */
    KC_LFK2, /* Layer Function Key 2 */
    KC_LFK3, /* Layer Function Key 3 */
    /* LED Functions */
    KC_LEDU, /* LED Brightness Up */
    KC_LEDD, /* LED Brightness Down */
    /* Mouse */
    MS_LCLK, /* Mouse Left Click */
    MS_RCLK, /* Mouse Right Click */
    MS_MCLK  /* Mouse Middle Click */
};




#endif
